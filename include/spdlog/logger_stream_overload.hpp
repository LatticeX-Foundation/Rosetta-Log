#pragma once

#define PP_CAT(A, B) A ## B
#define PP_EXPAND(...) __VA_ARGS__

#define PP_VA_ARG_SIZE(...) PP_EXPAND(PP_APPLY_ARG_N((PP_ZERO_ARGS_DETECT(__VA_ARGS__), PP_RSEQ_N)))

#define PP_ZERO_ARGS_DETECT(...) PP_EXPAND(PP_ZERO_ARGS_DETECT_PREFIX_ ## __VA_ARGS__ ## _ZERO_ARGS_DETECT_SUFFIX)
#define PP_ZERO_ARGS_DETECT_PREFIX__ZERO_ARGS_DETECT_SUFFIX ,,,,,,,,,,,0

#define PP_APPLY_ARG_N(ARGS) PP_EXPAND(PP_ARG_N ARGS)
#define PP_ARG_N(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N,...) N
#define PP_RSEQ_N 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define PP_OVERLOAD_SELECT(NAME, NUM) PP_CAT(NAME, NUM)
#define PP_MACRO_OVERLOAD(NAME, ...) PP_OVERLOAD_SELECT(NAME, PP_VA_ARG_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define tlog_trace_0()  tlog_trace_("")
#define tlog_debug_0()  tlog_debug_("")
#define tlog_audit_0()  tlog_audit_("")
#define tlog_info_0()   tlog_info_("")
#define tlog_warn_0()   tlog_warn_("")
#define tlog_error_0()  tlog_error_("")
#define tlog_fatal_0()  tlog_fatal_("")

#define tlog_trace_1(task_id)  tlog_trace_(task_id)
#define tlog_debug_1(task_id)  tlog_debug_(task_id)
#define tlog_audit_1(task_id)  tlog_audit_(task_id)
#define tlog_info_1(task_id)   tlog_info_(task_id)
#define tlog_warn_1(task_id)   tlog_warn_(task_id)
#define tlog_error_1(task_id)  tlog_error_(task_id)
#define tlog_fatal_1(task_id)  tlog_fatal_(task_id)

#define Trace(...)       PP_MACRO_OVERLOAD(tlog_trace_, __VA_ARGS__)
#define Deb(...)       PP_MACRO_OVERLOAD(tlog_debug_, __VA_ARGS__)
#define Audit(...)       PP_MACRO_OVERLOAD(tlog_audit_, __VA_ARGS__)
#define Info(...)       PP_MACRO_OVERLOAD(tlog_info_, __VA_ARGS__)
#define Warn(...)       PP_MACRO_OVERLOAD(tlog_warn_, __VA_ARGS__)
#define Error(...)       PP_MACRO_OVERLOAD(tlog_error_, __VA_ARGS__)
#define Fatal(...)       PP_MACRO_OVERLOAD(tlog_fatal_, __VA_ARGS__)
