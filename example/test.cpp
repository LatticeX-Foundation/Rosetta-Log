// ==============================================================================
// Copyright 2021 The LatticeX Foundation
// This file is part of the Rosetta library.
//
// The Rosetta library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The Rosetta library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with the Rosetta library. If not, see <http://www.gnu.org/licenses/>.
// ==============================================================================

#include "spdlog/loggers.h"
void print()
{
	ptlog_trace_(""), "log_trace", " python-style", " in the print !!!";
	ptlog_debug_(""), "log_debug", " python-style", " in the print !!!";
	ptlog_info_(""), "log_info", " python-style", " in the print !!!";
	ptlog_audit_(""), "log_audit", " python-style", " in the print !!!";
	ptlog_warn_(""), "log_warn", " python-style", " in the print !!!";
	ptlog_error_(""), "log_error", " python-style", " in the print !!!";
	ptlog_fatal_(""), "log_fatal", " python-style", " in the print !!!";

	ptlog_trace_("")<< "log_trace"<<" python-style", " in the print !!!";
	ptlog_debug_("")<< "log_debug"<<" python-style", " in the print !!!";
	ptlog_info_("")<<"log_info"<<" python-style", " in the print !!!";
	ptlog_audit_("")<< "log_audit"<<" python-style", " in the print !!!";
	ptlog_warn_("")<<"log_warn"<<" python-style", " in the print !!!";
	ptlog_error_("")<<"log_error"<< " python-style", " in the print !!!";
	ptlog_fatal_("")<< "log_fatal"<< " python-style", " in the print !!!";
}
/*
 *  if compiler in the command line,  for example, in current directory, please execute follow command 
 *  g++ -std=c++11 example.cpp ../src/loggers.cpp ../src/logger_stream.cpp -o example -I../include -lpthread
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
	tlog_debug_("")<<"log_debug "<<"tensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.htensorflow/core/framework/node_def_util.h";
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
	Logger::Get().log_to_stdout(false);
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
	ptlog_trace_(logger_sink), "log_trace", " python-style";
	print();
	//pptlog_trace_(logger_sink), "log_trace", " python-style";
	LogStream(logger_sink, spdlog::level::trace, spdlog::source_loc{"test.cpp", 26, __FUNCTION__}) == (LogLine(), "log_trace", "python-style");
	ptlog_trace_(logger_sink), "log_trace", " python-style", " in the print !!!";
	ptlog_debug_(logger_sink), "log_debug", " python-style", " in the print !!!";
	ptlog_info_(logger_sink), "log_info", " python-style", " in the print !!!";
	ptlog_audit_(logger_sink), "log_audit", " python-style", " in the print !!!";
	ptlog_warn_(logger_sink), "log_warn", " python-style", " in the print !!!";
	ptlog_error_(logger_sink), "log_error", " python-style", " in the print !!!";
	ptlog_fatal_(logger_sink), "log_fatal", " python-style", " in the print !!!";

	ptlog_trace_(logger_sink)<< "log_trace"<<" python-style", " in the print !!!";
	ptlog_debug_(logger_sink)<< "log_debug"<<" python-style", " in the print !!!";
	ptlog_info_(logger_sink)<<"log_info"<<" python-style", " in the print !!!";
	ptlog_audit_(logger_sink)<< "log_audit"<<" python-style", " in the print !!!";
	ptlog_warn_(logger_sink)<<"log_warn"<<" python-style", " in the print !!!";
	ptlog_error_(logger_sink)<<"log_error"<< " python-style", " in the print !!!";
	ptlog_fatal_(logger_sink)<< "log_fatal"<< " python-style", " in the print !!!";
	//ptlog_debug_(logger_sink), "log_debug";
	//ptlog_audit_(logger_sink), "log_audit";
	//ptlog_info_(logger_sink),  "log_info";
	//ptlog_warn_(logger_sink),  "log_warn";
	//ptlog_error_(logger_sink), "log_error";
	//ptlog_fatal_(logger_sink), "log_fatal";
	
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
	//Logger::Get().set_pattern("%+");
	//Logger::Get().log_to_stdout(false);
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
	Logger::Get().set_level(spdlog::level::info);
	tlog_trace_(logger_sink)<<"log_trace";
	tlog_debug_(logger_sink)<<"log_debug";
	tlog_audit_(logger_sink)<<"log_audit";
	tlog_info_(logger_sink)<<"log_info";
	tlog_warn_(logger_sink)<<"log_warn";
	tlog_error_(logger_sink)<<"log_error";
	tlog_fatal_(logger_sink)<<"log_fatal";

	//throw;

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
