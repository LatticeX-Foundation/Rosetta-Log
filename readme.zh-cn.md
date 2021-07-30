[![github license](https://img.shields.io/badge/license-LGPLv3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0.en.html)



# 0 Wrap the fast logger of spdlog

LatticeX Foundation 衷心支持开源, 并乐意为开源和开源社区的发展添砖加瓦. 并对项目Rosetta-Log提供支持. 

* [Rosetta-Log GitHub](https://github.com/LatticeX-Foundation/Rosetta-Log)
  * [English](https://github.com/LatticeX-Foundation/Rosetta-Log)
  * [简体中文](https://github.com/LatticeX-Foundation/Rosetta-Log/blob/main/readme.zh-cn.md)
  *  [spdlog](https://github.com/gabime/spdlog)

# 1 简介

Rosetta-Log 是在  [spdlog](https://github.com/gabime/spdlog)为 __1.6.1__ 的版本上进行的二次开发. 主要有以下特性:

+  新增审计日志级别: __spdlog::level::audit__
+ 修改致命日志的展示名称: 由 __critical__ 变为 __fatal__
+ 新增 __task_id__ 作为日志句柄
+ 新增 __c++ 流式日志__ 格式
+ 缺省开启 __屏幕日志__
+ Debug时, 缺省的屏幕日志模式为:  __`%Y-%m-%d %H:%M:%S.%e|%^%l%$|%s:%#|%v`__, 相对应的文件模式为: __`%Y-%m-%d %H:%M:%S.%e|%l|%s:%#|%v`__
+ Relase时, 缺省的屏幕日志模式为: __`%Y-%m-%d %H:%M:%S.%e|%^%l%$|%v`__, 相对应的文件模式为:  __`%Y-%m-%d %H:%M:%S.%e|%l|%v`__
+ 日志文件是 __同步的basic__ 日志



# 2  安装

克隆源码 [Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log)  到你的编译目录, 并使用支持 __c++11__ 特性的编译器.


## 2.1 头文件方式

推荐使用 [Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log) 的动态库形式. 如果我们仅需要头文件形式, 那么需要在编译的时候, 包含如下两个源文件:

1.  `src/loggers.cpp`
2.  `src/logger_stream.cpp`

以 __example/example.cpp__ 为例, 其编译的命令行命令为: 

```bash
g++ -std=c++11 example.cpp ../src/loggers.cpp ../src/logger_stream.cpp -o example -I../include -lpthread
```

## 2.2 共享库

[Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log)  的共享库生成方式为:

```bash
$ git clone https://github.com/LatticeX-Foundation/Rosetta-Log
$ cd Rosetta-Log && mkdir build && cd build
$ cmake .. && make -j
```



## 2.3 样例

__example__ 目录下, 有两份使用样例源码:

+ __example.cpp__:  spdlog官网上的使用样板源码
+ __test.cpp__:  Rostta-Log 日志的使用样板源码

以上两个样板, 可以在源码的根目录执行如下操作验证:

```bash
$ git clone https://github.com/LatticeX-Foundation/Rosetta-Log
$ cd Rosetta-Log && mkdir build && cd build
$ cmake .. && make -j
$ ./example/example 
$ ./example/test 
```



# 3 使用样例

```cpp
#include "spdlog/loggers.h"
/*
 *  if compiled in the command line,  for example, in current directory, please execute follow command 
 *  g++ -std=c++11 test.cpp ../src/loggers.cpp ../src/logger_stream.cpp -o test -I../include -lpthread
 **/
int main(int ac, char* av[])
{
	//spdlog::set_level(spdlog::level::trace); // Set global log level to info
	spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
	spdlog::trace("this trace should not be display because the default level is spdlog::info");  
	spdlog::debug("this debug should not be display because the default level is spdlog::info");  
	spdlog::audit("this audit should not be display because the default level is spdlog::info");  
	spdlog::info("this info should be display because the default level is spdlog::info");  
	spdlog::warn("this warn should be display because the default level is spdlog::info");  
	spdlog::error("this error should be display because the default level is spdlog::info");  
	spdlog::critical("this critical should be display because the default level is spdlog::info");  

	spdlog::set_level(spdlog::level::trace); // Set global log level to info
	spdlog::trace("this trace should be display because the level is spdlog::trace");  
	spdlog::debug("this debug should be display because the level is spdlog::trace");  
	spdlog::audit("this audit should be display because the level is spdlog::trace");  
	spdlog::trace("this info should be display because the level is spdlog::trace");  
	spdlog::warn("this warn should be display because the level is spdlog::trace");  
	spdlog::error("this error should be display because the level is spdlog::trace");  
	spdlog::critical("this critical should be display because the level is spdlog::trace");  

	// use the wrap fmt of  T*_ logger, all logger messages will display, begin 
	TTRACE_("", "hello world {} - {}", "again", 9909);
	TTRACE_("", "TRACE");
	TDEB_("", "DEB");
	TAUDIT_("","AUDIT {}", 123);
	TINFO_("", "INFO");
	TWARN_("", "WARN");
	TERROR_("", "ERROR");
	TFATAL_("", "FATAL");
	// use the wrap fmt of T*_ logger, all logger messages will display, end 

	// use the wrap cpp-stream of tlog_*_ logger, all logger messages will display, begin 
	tlog_trace_("")<<"log_trace";
	tlog_debug_("")<<"log_debug";
	tlog_audit_("")<<"log_audit";
	tlog_info_("")<<"log_info";
	tlog_warn_("")<<"log_warn";
	tlog_error_("")<<"log_error";
	tlog_fatal_("")<<"log_fatal";
	// use the wrap cpp-stream of tlog_*_ logger, all logger messages will display, end 
	
	// Set logger filename
	const char* logger_sink = "test_sink";
	Logger::Get().set_filename("log/test.log", logger_sink);
	Logger::Get().set_level(spdlog::level::trace);
	// use the wrap fmt of  T*_ logger, all logger messages not only display on console, but also write to file, begin 
	TTRACE_(logger_sink, "hello world {} - {}", "again", 9909);
	TTRACE_(logger_sink, "TRACE");
	TDEB_(logger_sink, "DEB");
	TAUDIT_(logger_sink,"AUDIT {}", 123);
	TINFO_(logger_sink, "INFO");
	TWARN_(logger_sink, "WARN");
	TERROR_(logger_sink, "ERROR");
	TFATAL_(logger_sink, "FATAL");
	// use the wrap fmt of T*_ logger, all logger messages not only display on console, but also write to file, end 

	// use the wrap cpp-stream of tlog_*_ logger, all logger messages not only display on console, bu also write to file, begin 
	tlog_trace_(logger_sink)<<"log_trace";
	tlog_debug_(logger_sink)<<"log_debug";
	tlog_audit_(logger_sink)<<"log_audit";
	tlog_info_(logger_sink)<<"log_info";
	tlog_warn_(logger_sink)<<"log_warn";
	tlog_error_(logger_sink)<<"log_error";
	tlog_fatal_(logger_sink)<<"log_fatal";
	// use the wrap cpp-stream of tlog_*_ logger, all logger messages not only display on console, but also write to file, end 
	
	// all logger message will write to console, begin 
	Trace()<<"ZERO Trace file and console";
	Deb()<<"ZERO Deb file and console";
	Audit()<<"ZERO Audit file and console";
	Info()<<"ZERO Info file and console";
	Warn()<<"ZERO Warn file and console";
	Error()<<"ZERO Error file and console";
	Fatal()<<"ZERO Fatal file and console";
	// all logger message will write to console, end 
	
	// all logger message will write to file and console, begin 
	Trace(logger_sink)<<"Trace file and console";
	Deb(logger_sink)<<"Deb file and console";
	Audit(logger_sink)<<"Audit file and console";
	Info(logger_sink)<<"Info file and console";
	Warn(logger_sink)<<"Warn file and console";
	Error(logger_sink)<<"Error file and console";
	Fatal(logger_sink)<<"Fatal file and console";
	// all logger message will write to file and console, end 

	// set pattern to spdlog's default formart
	Logger::Get().set_pattern("%+");
	Logger::Get().log_to_stdout(false);
	// use the wrap fmt of  T*_ logger, all logger messages will write to file, begin 
	TTRACE_(logger_sink, "hello world {} - {}", "again", 9909);
	TTRACE_(logger_sink, "TRACE");
	TDEB_(logger_sink, "DEB");
	TAUDIT_(logger_sink,"AUDIT {}", 123);
	TINFO_(logger_sink, "INFO");
	TWARN_(logger_sink, "WARN");
	TERROR_(logger_sink, "ERROR");
	TFATAL_(logger_sink, "FATAL");
	

	// use the wrap cpp-stream of tlog_*_ logger, all logger messages will write to file, begin 
	tlog_trace_(logger_sink)<<"log_trace";
	tlog_debug_(logger_sink)<<"log_debug";
	tlog_audit_(logger_sink)<<"log_audit";
	tlog_info_(logger_sink)<<"log_info";
	tlog_warn_(logger_sink)<<"log_warn";
	tlog_error_(logger_sink)<<"log_error";
	tlog_fatal_(logger_sink)<<"log_fatal";
	// use the wrap cpp-stream of tlog_*_ logger, all logger messages will write to file, end 


	// all logger message will write to console, begin 
	Trace()<<"ZERO Trace file";
	Deb()<<"ZERO Deb file";
	Audit()<<"ZERO Audit file";
	Info()<<"ZERO Info file";
	Warn()<<"ZERO Warn file";
	Error()<<"ZERO Error file";
	Fatal()<<"ZERO Fatal file";
	// all logger message will write to console, end 
	
	// all logger message will write to file and console, begin 
	Trace(logger_sink)<<"Trace file";
	Deb(logger_sink)<<"Deb file";
	Audit(logger_sink)<<"Audit file";
	Info(logger_sink)<<"Info file";
	Warn(logger_sink)<<"Warn file";
	Error(logger_sink)<<"Error file";
	Fatal(logger_sink)<<"Fatal file";
	// all logger message will write to file and console, end 

	return 0;
}
```



# 4 注意事项

+ 如果我们使用 cpp的流式日志, 请不要使用 __std::endl__, 因为日志本身会自动换行. 如果日志中途需要换行,  请使用c方式的 __"\n"__ 代替. 
+ 如果设置了日志文件, 缺省情况下, 所有的控制台日志也会写入日志文件



更多详情, 请往官网的 [spdlog](https://github.com/gabime/spdlog)  和 [wiki](https://github.com/gabime/spdlog/wiki/1.-QuickStart).

