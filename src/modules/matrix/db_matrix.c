
/*!
 * \file
 * \ingroup db
 * \brief Database support for modules.
 *
 * Database support functions for modules.
 *
 * @cond
 * WARNING:
 * This file was autogenerated from the XML source file
 * ../../modules/matrix/kamailio-matrix.xml.
 * It can be regenerated by running 'make modules' in the db/schema
 * directory of the source code. You need to have xsltproc and
 * docbook-xsl stylesheets installed.
 * ALL CHANGES DONE HERE WILL BE LOST IF THE FILE IS REGENERATED
 * @endcond
 */

#include "db_matrix.h"

/* database variables */
/* TODO assign read-write or read-only URI, introduce a parameter in XML */

//extern str matrix_db_url;
db1_con_t * matrix_dbh = NULL;
db_func_t matrix_dbf;

str matrix_table = str_init("matrix");

/* column names */
str matrix_first_col = str_init("first");
str matrix_second_col = str_init("second");
str matrix_res_col = str_init("res");

/* table version */
const unsigned int matrix_version = 1;


/*
 * Closes the DB connection.
 */
void matrix_db_close(void) {
	if (matrix_dbh) {
		matrix_dbf.close(matrix_dbh);
		matrix_dbh = NULL;
	}
}


/*!
 * Initialises the DB API, check the table version and closes the connection.
 * This should be called from the mod_init function.
 *
 * \return 0 means ok, -1 means an error occurred.
 */
int matrix_db_init(void) {
	if (!matrix_db_url.s || !matrix_db_url.len) {
		LM_ERR("you have to set the db_url module parameter.\n");
		return -1;
	}
	if (db_bind_mod(&matrix_db_url, &matrix_dbf) < 0) {
		LM_ERR("can't bind database module.\n");
		return -1;
	}
	if ((matrix_dbh = matrix_dbf.init(&matrix_db_url)) == NULL) {
		LM_ERR("can't connect to database.\n");
		return -1;
	}
	if (
	(db_check_table_version(&matrix_dbf, matrix_dbh, &matrix_table, matrix_version) < 0)
	) {
		DB_TABLE_VERSION_ERROR(matrix_table);
		matrix_db_close();
		return -1;
	}
	matrix_db_close();
	return 0;
}


/*!
 * Initialize the DB connection without checking the table version and DB URL.
 * This should be called from child_init. An already existing database
 * connection will be closed, and a new one created.
 *
 * \return 0 means ok, -1 means an error occurred.
 */
int matrix_db_open(void) {
	if (matrix_dbh) {
		matrix_dbf.close(matrix_dbh);
	}
	if ((matrix_dbh = matrix_dbf.init(&matrix_db_url)) == NULL) {
		LM_ERR("can't connect to database.\n");
		return -1;
	}
	return 0;
}
