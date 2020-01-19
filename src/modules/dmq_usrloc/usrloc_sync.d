usrloc_sync.o: usrloc_sync.c usrloc_sync.h ../dmq/bind_dmq.h \
 ../dmq/peer.h ../dmq/dmqnode.h ../dmq/../../core/lock_ops.h \
 ../dmq/../../core/futexlock.h ../dmq/../../core/atomic/atomic_common.h \
 ../dmq/../../core/atomic/atomic_native.h \
 ../dmq/../../core/atomic/atomic_x86.h ../dmq/../../core/compiler_opt.h \
 ../dmq/../../core/str.h ../dmq/../../core/mem/mem.h \
 ../dmq/../../core/mem/pkg.h ../dmq/../../core/mem/memapi.h \
 ../dmq/../../core/mem/src_loc.h ../dmq/../../core/mem/meminfo.h \
 ../dmq/../../core/mem/memdbg.h ../dmq/../../core/mem/../cfg/cfg.h \
 ../dmq/../../core/mem/../cfg/../str.h ../dmq/../../core/mem/../dprint.h \
 ../dmq/../../core/mem/../compiler_opt.h \
 ../dmq/../../core/mem/../cfg_core.h ../dmq/../../core/mem/../cfg/cfg.h \
 ../dmq/../../core/mem/shm_mem.h ../dmq/../../core/mem/shm.h \
 ../dmq/../../core/mem/../lock_ops.h ../dmq/../../core/parser/parse_uri.h \
 ../dmq/../../core/parser/../str.h \
 ../dmq/../../core/parser/../parser/msg_parser.h \
 ../dmq/../../core/parser/../parser/../comp_defs.h \
 ../dmq/../../core/parser/../parser/../str.h \
 ../dmq/../../core/parser/../parser/../lump_struct.h \
 ../dmq/../../core/parser/../parser/.././parser/hf.h \
 ../dmq/../../core/parser/../parser/.././parser/../str.h \
 ../dmq/../../core/parser/../parser/.././parser/../comp_defs.h \
 ../dmq/../../core/parser/../parser/../flags.h \
 ../dmq/../../core/parser/../parser/../ip_addr.h \
 ../dmq/../../core/parser/../parser/../str.h \
 ../dmq/../../core/parser/../parser/../compiler_opt.h \
 ../dmq/../../core/parser/../parser/../ut.h \
 ../dmq/../../core/parser/../parser/../comp_defs.h \
 ../dmq/../../core/parser/../parser/../config.h \
 ../dmq/../../core/parser/../parser/../crypto/md5utils.h \
 ../dmq/../../core/parser/../parser/../crypto/../str.h \
 ../dmq/../../core/parser/../parser/../dprint.h \
 ../dmq/../../core/parser/../parser/../mem/mem.h \
 ../dmq/../../core/parser/../parser/../mem/shm_mem.h \
 ../dmq/../../core/parser/../parser/../config.h \
 ../dmq/../../core/parser/../parser/parse_def.h \
 ../dmq/../../core/parser/../parser/parse_cseq.h \
 ../dmq/../../core/parser/../parser/parse_via.h \
 ../dmq/../../core/parser/../parser/parse_fline.h \
 ../dmq/../../core/parser/../parser/parse_retry_after.h \
 ../dmq/../../core/parser/../parser/hf.h \
 ../dmq/../../core/parser/../parser/../error.h \
 ../dmq/../../core/parser/parse_param.h \
 ../dmq/../../core/parser/msg_parser.h ../dmq/dmq_funcs.h \
 ../dmq/../../modules/tm/dlg.h ../dmq/../../modules/tm/../../core/str.h \
 ../dmq/../../modules/tm/../../core/ip_addr.h \
 ../dmq/../../modules/tm/../../core/parser/parse_rr.h \
 ../dmq/../../modules/tm/../../core/parser/msg_parser.h \
 ../dmq/../../modules/tm/../../core/parser/parse_nameaddr.h \
 ../dmq/../../modules/tm/../../core/parser/../str.h \
 ../dmq/../../modules/tm/../../core/parser/parse_param.h \
 ../dmq/../../modules/tm/../../core/parser/hf.h \
 ../dmq/../../modules/tm/../../core/parser/msg_parser.h \
 ../dmq/../../modules/tm/tm_load.h \
 ../dmq/../../modules/tm/../../core/sr_module.h \
 ../dmq/../../modules/tm/../../core/parser/msg_parser.h \
 ../dmq/../../modules/tm/../../core/ver_defs.h \
 ../dmq/../../modules/tm/../../core/rpc.h \
 ../dmq/../../modules/tm/../../core/route_struct.h \
 ../dmq/../../modules/tm/../../core/select.h \
 ../dmq/../../modules/tm/../../core/str.h \
 ../dmq/../../modules/tm/../../core/usr_avp.h \
 ../dmq/../../modules/tm/../../core/route.h \
 ../dmq/../../modules/tm/../../core/config.h \
 ../dmq/../../modules/tm/../../core/error.h \
 ../dmq/../../modules/tm/../../core/action.h \
 ../dmq/../../modules/tm/../../core/str_hash.h \
 ../dmq/../../modules/tm/../../core/hashes.h \
 ../dmq/../../modules/tm/../../core/mem/mem.h \
 ../dmq/../../modules/tm/../../core/clist.h \
 ../dmq/../../modules/tm/../../core/counters.h \
 ../dmq/../../modules/tm/../../core/pt.h \
 ../dmq/../../modules/tm/../../core/globals.h \
 ../dmq/../../modules/tm/../../core/ip_addr.h \
 ../dmq/../../modules/tm/../../core/poll_types.h \
 ../dmq/../../modules/tm/../../core/timer.h \
 ../dmq/../../modules/tm/../../core/dprint.h \
 ../dmq/../../modules/tm/../../core/timer_ticks.h \
 ../dmq/../../modules/tm/../../core/socket_info.h \
 ../dmq/../../modules/tm/../../core/locking.h \
 ../dmq/../../modules/tm/../../core/lock_ops.h \
 ../dmq/../../modules/tm/../../core/lock_alloc.h \
 ../dmq/../../modules/tm/../../core/mem/shm_mem.h \
 ../dmq/../../modules/tm/../../core/atomic_ops.h \
 ../dmq/../../modules/tm/../../core/atomic/atomic_common.h \
 ../dmq/../../modules/tm/../../core/atomic/atomic_native.h \
 ../dmq/../../modules/tm/../../core/pvar.h \
 ../dmq/../../modules/tm/t_hooks.h ../dmq/../../modules/tm/uac.h \
 ../dmq/../../modules/tm/dlg.h ../dmq/../../modules/tm/h_table.h \
 ../dmq/../../modules/tm/t_stats.h \
 ../dmq/../../modules/tm/../../core/rpc.h \
 ../dmq/../../modules/tm/../../core/pt.h \
 ../dmq/../../modules/tm/../../core/clist.h \
 ../dmq/../../modules/tm/../../core/usr_avp.h \
 ../dmq/../../modules/tm/../../core/xavp.h \
 ../dmq/../../modules/tm/../../core/str_list.h \
 ../dmq/../../modules/tm/../../core/timer.h \
 ../dmq/../../modules/tm/../../core/flags.h \
 ../dmq/../../modules/tm/../../core/atomic_ops.h \
 ../dmq/../../modules/tm/../../core/hash_func.h \
 ../dmq/../../modules/tm/config.h \
 ../dmq/../../modules/tm/../../core/cfg/cfg.h \
 ../dmq/../../modules/tm/../../core/mem/shm_mem.h \
 ../dmq/../../modules/tm/lock.h \
 ../dmq/../../modules/tm/../../core/dprint.h \
 ../dmq/../../modules/tm/../../core/locking.h \
 ../dmq/../../modules/tm/sip_msg.h \
 ../dmq/../../modules/tm/../../core/dns_cache.h \
 ../dmq/../../modules/tm/../../core/resolve.h \
 ../dmq/../../modules/tm/../../core/dns_func.h \
 ../dmq/../../modules/tm/../../core/dns_wrappers.h \
 ../dmq/../../modules/tm/t_fwd.h \
 ../dmq/../../modules/tm/../../core/proxy.h \
 ../dmq/../../modules/tm/t_lookup.h ../dmq/../../modules/tm/t_funcs.h \
 ../dmq/../../modules/tm/../../core/globals.h \
 ../dmq/../../modules/tm/../../core/udp_server.h \
 ../dmq/../../modules/tm/../../core/msg_translator.h \
 ../dmq/../../modules/tm/../../core/forward.h \
 ../dmq/../../modules/tm/../../core/proxy.h \
 ../dmq/../../modules/tm/../../core/udp_server.h \
 ../dmq/../../modules/tm/../../core/tcp_server.h \
 ../dmq/../../modules/tm/../../core/tcp_conn.h \
 ../dmq/../../modules/tm/../../core/tcp_init.h \
 ../dmq/../../modules/tm/../../core/tcp_options.h \
 ../dmq/../../modules/tm/../../core/sctp_core.h \
 ../dmq/../../modules/tm/../../core/compiler_opt.h \
 ../dmq/../../modules/tm/../../core/events.h \
 ../dmq/../../modules/tm/../../core/mem/mem.h \
 ../dmq/../../modules/tm/../../core/parser/parse_uri.h \
 ../dmq/../../modules/tm/timer.h \
 ../dmq/../../modules/tm/../../core/compiler_opt.h \
 ../dmq/../../modules/tm/ut.h ../dmq/../../modules/tm/../../core/ut.h \
 ../dmq/../../modules/tm/../../core/error.h \
 ../dmq/../../modules/tm/../../core/resolve.h \
 ../dmq/../../modules/tm/../../core/cfg_core.h \
 ../dmq/../../modules/tm/t_reply.h \
 ../dmq/../../modules/tm/../../core/tags.h \
 ../dmq/../../modules/tm/../../core/crc.h \
 ../dmq/../../modules/tm/callid.h ../dmq/../../modules/tm/t_cancel.h \
 ../dmq/../../modules/tm/t_suspend.h \
 ../dmq/../../modules/tm/t_append_branches.h \
 ../dmq/../../modules/tm/t_serial.h ../dmq/../../core/config.h \
 ../dmq/worker.h ../dmq/../../core/locking.h \
 ../dmq/../../core/atomic_ops.h ../../lib/srutils/srjson.h \
 ../../lib/srutils/../../core/str.h ../../core/parser/msg_parser.h \
 ../../core/parser/parse_content.h ../../core/parser/msg_parser.h \
 ../usrloc/usrloc.h ../usrloc/ul_callback.h ../usrloc/../../core/dprint.h \
 ../usrloc/../../core/qvalue.h ../usrloc/../../core/str.h \
 ../usrloc/../../core/xavp.h ../usrloc/ul_callback.h ../usrloc/dlist.h \
 ../usrloc/usrloc.h ../usrloc/udomain.h ../usrloc/../../core/locking.h \
 ../usrloc/../../core/counters.h ../usrloc/../../lib/srdb1/db.h \
 ../usrloc/../../lib/srdb1/db_key.h \
 ../usrloc/../../lib/srdb1/../../core/ut.h \
 ../usrloc/../../lib/srdb1/db_op.h ../usrloc/../../lib/srdb1/db_val.h \
 ../usrloc/../../lib/srdb1/db_con.h \
 ../usrloc/../../lib/srdb1/../../core/str.h \
 ../usrloc/../../lib/srdb1/db_res.h ../usrloc/../../lib/srdb1/db_cap.h \
 ../usrloc/../../lib/srdb1/db_row.h \
 ../usrloc/../../lib/srdb1/db_pooling.h \
 ../usrloc/../../lib/srdb1/db_locking.h ../usrloc/urecord.h \
 ../usrloc/hslot.h ../usrloc/ucontact.h ../../core/dprint.h \
 ../../core/ut.h ../../core/parser/parse_from.h \
 ../../core/parser/parse_to.h ../../core/parser/../str.h \
 ../../core/parser/parse_addr_spec.h ../../core/parser/parse_addr_spec.h

usrloc_sync.h:

../dmq/bind_dmq.h:

../dmq/peer.h:

../dmq/dmqnode.h:

../dmq/../../core/lock_ops.h:

../dmq/../../core/futexlock.h:

../dmq/../../core/atomic/atomic_common.h:

../dmq/../../core/atomic/atomic_native.h:

../dmq/../../core/atomic/atomic_x86.h:

../dmq/../../core/compiler_opt.h:

../dmq/../../core/str.h:

../dmq/../../core/mem/mem.h:

../dmq/../../core/mem/pkg.h:

../dmq/../../core/mem/memapi.h:

../dmq/../../core/mem/src_loc.h:

../dmq/../../core/mem/meminfo.h:

../dmq/../../core/mem/memdbg.h:

../dmq/../../core/mem/../cfg/cfg.h:

../dmq/../../core/mem/../cfg/../str.h:

../dmq/../../core/mem/../dprint.h:

../dmq/../../core/mem/../compiler_opt.h:

../dmq/../../core/mem/../cfg_core.h:

../dmq/../../core/mem/../cfg/cfg.h:

../dmq/../../core/mem/shm_mem.h:

../dmq/../../core/mem/shm.h:

../dmq/../../core/mem/../lock_ops.h:

../dmq/../../core/parser/parse_uri.h:

../dmq/../../core/parser/../str.h:

../dmq/../../core/parser/../parser/msg_parser.h:

../dmq/../../core/parser/../parser/../comp_defs.h:

../dmq/../../core/parser/../parser/../str.h:

../dmq/../../core/parser/../parser/../lump_struct.h:

../dmq/../../core/parser/../parser/.././parser/hf.h:

../dmq/../../core/parser/../parser/.././parser/../str.h:

../dmq/../../core/parser/../parser/.././parser/../comp_defs.h:

../dmq/../../core/parser/../parser/../flags.h:

../dmq/../../core/parser/../parser/../ip_addr.h:

../dmq/../../core/parser/../parser/../str.h:

../dmq/../../core/parser/../parser/../compiler_opt.h:

../dmq/../../core/parser/../parser/../ut.h:

../dmq/../../core/parser/../parser/../comp_defs.h:

../dmq/../../core/parser/../parser/../config.h:

../dmq/../../core/parser/../parser/../crypto/md5utils.h:

../dmq/../../core/parser/../parser/../crypto/../str.h:

../dmq/../../core/parser/../parser/../dprint.h:

../dmq/../../core/parser/../parser/../mem/mem.h:

../dmq/../../core/parser/../parser/../mem/shm_mem.h:

../dmq/../../core/parser/../parser/../config.h:

../dmq/../../core/parser/../parser/parse_def.h:

../dmq/../../core/parser/../parser/parse_cseq.h:

../dmq/../../core/parser/../parser/parse_via.h:

../dmq/../../core/parser/../parser/parse_fline.h:

../dmq/../../core/parser/../parser/parse_retry_after.h:

../dmq/../../core/parser/../parser/hf.h:

../dmq/../../core/parser/../parser/../error.h:

../dmq/../../core/parser/parse_param.h:

../dmq/../../core/parser/msg_parser.h:

../dmq/dmq_funcs.h:

../dmq/../../modules/tm/dlg.h:

../dmq/../../modules/tm/../../core/str.h:

../dmq/../../modules/tm/../../core/ip_addr.h:

../dmq/../../modules/tm/../../core/parser/parse_rr.h:

../dmq/../../modules/tm/../../core/parser/msg_parser.h:

../dmq/../../modules/tm/../../core/parser/parse_nameaddr.h:

../dmq/../../modules/tm/../../core/parser/../str.h:

../dmq/../../modules/tm/../../core/parser/parse_param.h:

../dmq/../../modules/tm/../../core/parser/hf.h:

../dmq/../../modules/tm/../../core/parser/msg_parser.h:

../dmq/../../modules/tm/tm_load.h:

../dmq/../../modules/tm/../../core/sr_module.h:

../dmq/../../modules/tm/../../core/parser/msg_parser.h:

../dmq/../../modules/tm/../../core/ver_defs.h:

../dmq/../../modules/tm/../../core/rpc.h:

../dmq/../../modules/tm/../../core/route_struct.h:

../dmq/../../modules/tm/../../core/select.h:

../dmq/../../modules/tm/../../core/str.h:

../dmq/../../modules/tm/../../core/usr_avp.h:

../dmq/../../modules/tm/../../core/route.h:

../dmq/../../modules/tm/../../core/config.h:

../dmq/../../modules/tm/../../core/error.h:

../dmq/../../modules/tm/../../core/action.h:

../dmq/../../modules/tm/../../core/str_hash.h:

../dmq/../../modules/tm/../../core/hashes.h:

../dmq/../../modules/tm/../../core/mem/mem.h:

../dmq/../../modules/tm/../../core/clist.h:

../dmq/../../modules/tm/../../core/counters.h:

../dmq/../../modules/tm/../../core/pt.h:

../dmq/../../modules/tm/../../core/globals.h:

../dmq/../../modules/tm/../../core/ip_addr.h:

../dmq/../../modules/tm/../../core/poll_types.h:

../dmq/../../modules/tm/../../core/timer.h:

../dmq/../../modules/tm/../../core/dprint.h:

../dmq/../../modules/tm/../../core/timer_ticks.h:

../dmq/../../modules/tm/../../core/socket_info.h:

../dmq/../../modules/tm/../../core/locking.h:

../dmq/../../modules/tm/../../core/lock_ops.h:

../dmq/../../modules/tm/../../core/lock_alloc.h:

../dmq/../../modules/tm/../../core/mem/shm_mem.h:

../dmq/../../modules/tm/../../core/atomic_ops.h:

../dmq/../../modules/tm/../../core/atomic/atomic_common.h:

../dmq/../../modules/tm/../../core/atomic/atomic_native.h:

../dmq/../../modules/tm/../../core/pvar.h:

../dmq/../../modules/tm/t_hooks.h:

../dmq/../../modules/tm/uac.h:

../dmq/../../modules/tm/dlg.h:

../dmq/../../modules/tm/h_table.h:

../dmq/../../modules/tm/t_stats.h:

../dmq/../../modules/tm/../../core/rpc.h:

../dmq/../../modules/tm/../../core/pt.h:

../dmq/../../modules/tm/../../core/clist.h:

../dmq/../../modules/tm/../../core/usr_avp.h:

../dmq/../../modules/tm/../../core/xavp.h:

../dmq/../../modules/tm/../../core/str_list.h:

../dmq/../../modules/tm/../../core/timer.h:

../dmq/../../modules/tm/../../core/flags.h:

../dmq/../../modules/tm/../../core/atomic_ops.h:

../dmq/../../modules/tm/../../core/hash_func.h:

../dmq/../../modules/tm/config.h:

../dmq/../../modules/tm/../../core/cfg/cfg.h:

../dmq/../../modules/tm/../../core/mem/shm_mem.h:

../dmq/../../modules/tm/lock.h:

../dmq/../../modules/tm/../../core/dprint.h:

../dmq/../../modules/tm/../../core/locking.h:

../dmq/../../modules/tm/sip_msg.h:

../dmq/../../modules/tm/../../core/dns_cache.h:

../dmq/../../modules/tm/../../core/resolve.h:

../dmq/../../modules/tm/../../core/dns_func.h:

../dmq/../../modules/tm/../../core/dns_wrappers.h:

../dmq/../../modules/tm/t_fwd.h:

../dmq/../../modules/tm/../../core/proxy.h:

../dmq/../../modules/tm/t_lookup.h:

../dmq/../../modules/tm/t_funcs.h:

../dmq/../../modules/tm/../../core/globals.h:

../dmq/../../modules/tm/../../core/udp_server.h:

../dmq/../../modules/tm/../../core/msg_translator.h:

../dmq/../../modules/tm/../../core/forward.h:

../dmq/../../modules/tm/../../core/proxy.h:

../dmq/../../modules/tm/../../core/udp_server.h:

../dmq/../../modules/tm/../../core/tcp_server.h:

../dmq/../../modules/tm/../../core/tcp_conn.h:

../dmq/../../modules/tm/../../core/tcp_init.h:

../dmq/../../modules/tm/../../core/tcp_options.h:

../dmq/../../modules/tm/../../core/sctp_core.h:

../dmq/../../modules/tm/../../core/compiler_opt.h:

../dmq/../../modules/tm/../../core/events.h:

../dmq/../../modules/tm/../../core/mem/mem.h:

../dmq/../../modules/tm/../../core/parser/parse_uri.h:

../dmq/../../modules/tm/timer.h:

../dmq/../../modules/tm/../../core/compiler_opt.h:

../dmq/../../modules/tm/ut.h:

../dmq/../../modules/tm/../../core/ut.h:

../dmq/../../modules/tm/../../core/error.h:

../dmq/../../modules/tm/../../core/resolve.h:

../dmq/../../modules/tm/../../core/cfg_core.h:

../dmq/../../modules/tm/t_reply.h:

../dmq/../../modules/tm/../../core/tags.h:

../dmq/../../modules/tm/../../core/crc.h:

../dmq/../../modules/tm/callid.h:

../dmq/../../modules/tm/t_cancel.h:

../dmq/../../modules/tm/t_suspend.h:

../dmq/../../modules/tm/t_append_branches.h:

../dmq/../../modules/tm/t_serial.h:

../dmq/../../core/config.h:

../dmq/worker.h:

../dmq/../../core/locking.h:

../dmq/../../core/atomic_ops.h:

../../lib/srutils/srjson.h:

../../lib/srutils/../../core/str.h:

../../core/parser/msg_parser.h:

../../core/parser/parse_content.h:

../../core/parser/msg_parser.h:

../usrloc/usrloc.h:

../usrloc/ul_callback.h:

../usrloc/../../core/dprint.h:

../usrloc/../../core/qvalue.h:

../usrloc/../../core/str.h:

../usrloc/../../core/xavp.h:

../usrloc/ul_callback.h:

../usrloc/dlist.h:

../usrloc/usrloc.h:

../usrloc/udomain.h:

../usrloc/../../core/locking.h:

../usrloc/../../core/counters.h:

../usrloc/../../lib/srdb1/db.h:

../usrloc/../../lib/srdb1/db_key.h:

../usrloc/../../lib/srdb1/../../core/ut.h:

../usrloc/../../lib/srdb1/db_op.h:

../usrloc/../../lib/srdb1/db_val.h:

../usrloc/../../lib/srdb1/db_con.h:

../usrloc/../../lib/srdb1/../../core/str.h:

../usrloc/../../lib/srdb1/db_res.h:

../usrloc/../../lib/srdb1/db_cap.h:

../usrloc/../../lib/srdb1/db_row.h:

../usrloc/../../lib/srdb1/db_pooling.h:

../usrloc/../../lib/srdb1/db_locking.h:

../usrloc/urecord.h:

../usrloc/hslot.h:

../usrloc/ucontact.h:

../../core/dprint.h:

../../core/ut.h:

../../core/parser/parse_from.h:

../../core/parser/parse_to.h:

../../core/parser/../str.h:

../../core/parser/parse_addr_spec.h:

../../core/parser/parse_addr_spec.h:
