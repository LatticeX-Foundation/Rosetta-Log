

[![github license](https://img.shields.io/badge/license-LGPLv3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0.en.html)

# 0 Wrap the fast logger of spdlog

LatticeX Foundation is pleased to support the open source community by making  Rosetta-Log available. 

* [Rosetta-Log GitHub](https://github.com/LatticeX-Foundation/Rosetta-Log)
  * [English](https://github.com/LatticeX-Foundation/Rosetta-Log)
  * [简体中文](https://github.com/LatticeX-Foundation/Rosetta-Log/blob/main/readme.zh-cn.md)
  * [spdlog](https://github.com/gabime/spdlog)

# 1 Introduction 

Rosetta-Log is base on the [spdlog](https://github.com/gabime/spdlog) which version is __1.6.1__, add/modify some features:

+ add aduit level: __spdlog::level::audit__
+ rename __critical__ to __fatal__
+ add __task_id__ as __logger's handler__
+ add __cpp-stream__ style 
+ __turn on console__ logger
+ set default __debug__  pattern for __console__ : __`%Y-%m-%d %H:%M:%S.%e|%^%l%$|%s:%#|%v`__ , meanwhile, the default __file logger__ 's pattern is __`%Y-%m-%d %H:%M:%S.%e|%l|%s:%#|%v`__
+ set default __release__ pattern for __console__ : __`%Y-%m-%d %H:%M:%S.%e|%^%l%$|%v`__ , meanwhile, the default __file logger__ 's pattern is __`%Y-%m-%d %H:%M:%S.%e|%l|%v`__
+ logfile sink  is __basic sink and  sync mode__ 



# 2 Install

Copy the source [Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log) to your build tree and use a C++11 compiler.

## 2.1 Head Only Version

[Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log)   suggested share library. If we want use Header only, please add two files for compiled: 

1. `src/loggers.cpp`
2. `src/logger_stream.cpp`

For example, if we compiled __`example/example.cpp`__ with command line, please use:

```bash
g++ -std=c++11 example.cpp ../src/loggers.cpp ../src/logger_stream.cpp -o example -I../include -lpthread
```



 ## 2.2 Share Library

[Rosetta-Log](https://github.com/LatticeX-Foundation/Rosetta-Log)  will create a  share library

```bash
$ git clone https://github.com/LatticeX-Foundation/Rosetta-Log
$ cd Rosetta-Log && mkdir build && cd build
$ cmake .. && make -j
```



## 2.3 Example

Directory example have two samples :

+ __example.cpp__:  spdlog orignal sample
+ __test.cpp__:  for Rosetta-Log sample

Two samples will be created when we execute root of CMakeLists.txt:

```bash
$ git clone https://github.com/LatticeX-Foundation/Rosetta-Log
$ cd Rosetta-Log && mkdir build && cd build
$ cmake .. && make -j
$ ./example/example 
$ ./example/test 
```



# 3 Usage Sample

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

# 4 Note

+ If use __cpp-style__ stream for logger, please __dont__ logger __std::endl__, Since the logger will newline for every logger message.  If we want a newline between logger message, please use __"\n"__.

+ If we set logger filename, all console messages will write to logger file.

  

More details, please  go to [spdlog](https://github.com/gabime/spdlog) and [wiki](https://github.com/gabime/spdlog/wiki/1.-QuickStart)

