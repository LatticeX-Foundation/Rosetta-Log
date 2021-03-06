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
#include"spdlog/logger_stream.h"
#include"spdlog/loggers.h"

//#include <spdlog/spdlog.h>
//#include <spdlog/async.h>
//#include <spdlog/sinks/basic_file_sink.h>
#include<iostream>

LogLine::LogLine(const char* task_id, spdlog::level::level_enum lvl, spdlog::source_loc loc) :log_{nullptr}
, lvl_{lvl}
, loc_{loc} {
	log_ = Logger::Get().get_logger(task_id);
}

LogLine::LogLine(const std::string& task_id, spdlog::level::level_enum lvl, spdlog::source_loc loc) :log_{nullptr}
, lvl_{lvl}
, loc_{loc} 
{
	log_ = Logger::Get().get_logger(task_id);
}

LogLine::~LogLine() {
	if (log_) {
		if (Logger::Get().get_log_to_stdout()) {
			g_default_logger->log(loc_, lvl_, "{}", ss_.str()); 
		}

		if (!log_ || log_ == g_default_logger) {
			// nothing todo
			return;
		}

		if (log_->should_log(lvl_)) {
			log_->log(loc_, lvl_, "{}", ss_.str()); 
		}
	}
}

LogStream::LogStream(const char* task_id, spdlog::level::level_enum lvl, spdlog::source_loc loc) :log_{nullptr}
, lvl_{lvl}
, loc_{loc} {
	log_ = Logger::Get().get_logger(task_id);
}

LogStream::LogStream(const std::string& task_id, spdlog::level::level_enum lvl, spdlog::source_loc loc) :log_{nullptr}
, lvl_{lvl}
, loc_{loc} 
{
	log_ = Logger::Get().get_logger(task_id);
}

bool LogStream::operator==(const LogLine& line) {
	if (Logger::Get().get_log_to_stdout()) {
		g_default_logger->log(loc_, lvl_, "{}", line.str()); 
	}

	if (!log_ || log_ == g_default_logger) {
		// nothing todo
		return true;
	}

	if (log_->should_log(lvl_)) {
		log_->log(loc_, lvl_, "{}", line.str()); 
	}

	return true;
}

template LogLine& LogLine::operator<< <std::string>(const std::string&);
template LogLine& LogLine::operator<< <char*>(char* const&);
template LogLine& LogLine::operator<< <unsigned char*>(unsigned char* const&);
template LogLine& LogLine::operator<< <char const*>(char const* const&);

template LogLine& LogLine::operator<< <bool>(bool const&);
template LogLine& LogLine::operator<< <char>(char const&);
template LogLine& LogLine::operator<< <short>(short const&);
template LogLine& LogLine::operator<< <int>(int const&);
template LogLine& LogLine::operator<< <float>(float const&);
template LogLine& LogLine::operator<< <double>(double const&);
template LogLine& LogLine::operator<< <long double>(long double const&);
template LogLine& LogLine::operator<< <long>(long const&);
template LogLine& LogLine::operator<< <long long>(long long const&);

template LogLine& LogLine::operator<< <unsigned char>  (unsigned char const&);
template LogLine& LogLine::operator<< <unsigned short> (unsigned short const&);
template LogLine& LogLine::operator<< <unsigned int>   (unsigned int const&);
template LogLine& LogLine::operator<< <unsigned long>  (unsigned long const&);
template LogLine& LogLine::operator<< <unsigned long long>  (unsigned long long const&);

template LogLine& LogLine::operator<< <char [1]>(char const (&) [1]);
template LogLine& LogLine::operator<< <char [2]>(char const (&) [2]);
template LogLine& LogLine::operator<< <char [3]>(char const (&) [3]);
template LogLine& LogLine::operator<< <char [4]>(char const (&) [4]);
template LogLine& LogLine::operator<< <char [5]>(char const (&) [5]);
template LogLine& LogLine::operator<< <char [6]>(char const (&) [6]);
template LogLine& LogLine::operator<< <char [7]>(char const (&) [7]);
template LogLine& LogLine::operator<< <char [8]>(char const (&) [8]);
template LogLine& LogLine::operator<< <char [9]>(char const (&) [9]);
template LogLine& LogLine::operator<< <char [10]>(char const (&) [10]);
template LogLine& LogLine::operator<< <char [11]>(char const (&) [11]);
template LogLine& LogLine::operator<< <char [12]>(char const (&) [12]);
template LogLine& LogLine::operator<< <char [13]>(char const (&) [13]);
template LogLine& LogLine::operator<< <char [14]>(char const (&) [14]);
template LogLine& LogLine::operator<< <char [15]>(char const (&) [15]);
template LogLine& LogLine::operator<< <char [16]>(char const (&) [16]);
template LogLine& LogLine::operator<< <char [17]>(char const (&) [17]);
template LogLine& LogLine::operator<< <char [18]>(char const (&) [18]);
template LogLine& LogLine::operator<< <char [19]>(char const (&) [19]);
template LogLine& LogLine::operator<< <char [20]>(char const (&) [20]);
template LogLine& LogLine::operator<< <char [21]>(char const (&) [21]);
template LogLine& LogLine::operator<< <char [22]>(char const (&) [22]);
template LogLine& LogLine::operator<< <char [23]>(char const (&) [23]);
template LogLine& LogLine::operator<< <char [24]>(char const (&) [24]);
template LogLine& LogLine::operator<< <char [25]>(char const (&) [25]);
template LogLine& LogLine::operator<< <char [26]>(char const (&) [26]);
template LogLine& LogLine::operator<< <char [27]>(char const (&) [27]);
template LogLine& LogLine::operator<< <char [28]>(char const (&) [28]);
template LogLine& LogLine::operator<< <char [29]>(char const (&) [29]);
template LogLine& LogLine::operator<< <char [30]>(char const (&) [30]);
template LogLine& LogLine::operator<< <char [31]>(char const (&) [31]);
template LogLine& LogLine::operator<< <char [32]>(char const (&) [32]);
template LogLine& LogLine::operator<< <char [33]>(char const (&) [33]);
template LogLine& LogLine::operator<< <char [34]>(char const (&) [34]);
template LogLine& LogLine::operator<< <char [35]>(char const (&) [35]);
template LogLine& LogLine::operator<< <char [36]>(char const (&) [36]);
template LogLine& LogLine::operator<< <char [37]>(char const (&) [37]);
template LogLine& LogLine::operator<< <char [38]>(char const (&) [38]);
template LogLine& LogLine::operator<< <char [39]>(char const (&) [39]);
template LogLine& LogLine::operator<< <char [40]>(char const (&) [40]);
template LogLine& LogLine::operator<< <char [41]>(char const (&) [41]);
template LogLine& LogLine::operator<< <char [42]>(char const (&) [42]);
template LogLine& LogLine::operator<< <char [43]>(char const (&) [43]);
template LogLine& LogLine::operator<< <char [44]>(char const (&) [44]);
template LogLine& LogLine::operator<< <char [45]>(char const (&) [45]);
template LogLine& LogLine::operator<< <char [46]>(char const (&) [46]);
template LogLine& LogLine::operator<< <char [47]>(char const (&) [47]);
template LogLine& LogLine::operator<< <char [48]>(char const (&) [48]);
template LogLine& LogLine::operator<< <char [49]>(char const (&) [49]);
template LogLine& LogLine::operator<< <char [50]>(char const (&) [50]);
template LogLine& LogLine::operator<< <char [51]>(char const (&) [51]);
template LogLine& LogLine::operator<< <char [52]>(char const (&) [52]);
template LogLine& LogLine::operator<< <char [53]>(char const (&) [53]);
template LogLine& LogLine::operator<< <char [54]>(char const (&) [54]);
template LogLine& LogLine::operator<< <char [55]>(char const (&) [55]);
template LogLine& LogLine::operator<< <char [56]>(char const (&) [56]);
template LogLine& LogLine::operator<< <char [57]>(char const (&) [57]);
template LogLine& LogLine::operator<< <char [58]>(char const (&) [58]);
template LogLine& LogLine::operator<< <char [59]>(char const (&) [59]);
template LogLine& LogLine::operator<< <char [60]>(char const (&) [60]);
template LogLine& LogLine::operator<< <char [61]>(char const (&) [61]);
template LogLine& LogLine::operator<< <char [62]>(char const (&) [62]);
template LogLine& LogLine::operator<< <char [63]>(char const (&) [63]);
template LogLine& LogLine::operator<< <char [64]>(char const (&) [64]);
template LogLine& LogLine::operator<< <char [65]>(char const (&) [65]);
template LogLine& LogLine::operator<< <char [66]>(char const (&) [66]);
template LogLine& LogLine::operator<< <char [67]>(char const (&) [67]);
template LogLine& LogLine::operator<< <char [68]>(char const (&) [68]);
template LogLine& LogLine::operator<< <char [69]>(char const (&) [69]);
template LogLine& LogLine::operator<< <char [70]>(char const (&) [70]);
template LogLine& LogLine::operator<< <char [71]>(char const (&) [71]);
template LogLine& LogLine::operator<< <char [72]>(char const (&) [72]);
template LogLine& LogLine::operator<< <char [73]>(char const (&) [73]);
template LogLine& LogLine::operator<< <char [74]>(char const (&) [74]);
template LogLine& LogLine::operator<< <char [75]>(char const (&) [75]);
template LogLine& LogLine::operator<< <char [76]>(char const (&) [76]);
template LogLine& LogLine::operator<< <char [77]>(char const (&) [77]);
template LogLine& LogLine::operator<< <char [78]>(char const (&) [78]);
template LogLine& LogLine::operator<< <char [79]>(char const (&) [79]);
template LogLine& LogLine::operator<< <char [80]>(char const (&) [80]);
template LogLine& LogLine::operator<< <char [81]>(char const (&) [81]);
template LogLine& LogLine::operator<< <char [82]>(char const (&) [82]);
template LogLine& LogLine::operator<< <char [83]>(char const (&) [83]);
template LogLine& LogLine::operator<< <char [84]>(char const (&) [84]);
template LogLine& LogLine::operator<< <char [85]>(char const (&) [85]);
template LogLine& LogLine::operator<< <char [86]>(char const (&) [86]);
template LogLine& LogLine::operator<< <char [87]>(char const (&) [87]);
template LogLine& LogLine::operator<< <char [88]>(char const (&) [88]);
template LogLine& LogLine::operator<< <char [89]>(char const (&) [89]);
template LogLine& LogLine::operator<< <char [90]>(char const (&) [90]);
template LogLine& LogLine::operator<< <char [91]>(char const (&) [91]);
template LogLine& LogLine::operator<< <char [92]>(char const (&) [92]);
template LogLine& LogLine::operator<< <char [93]>(char const (&) [93]);
template LogLine& LogLine::operator<< <char [94]>(char const (&) [94]);
template LogLine& LogLine::operator<< <char [95]>(char const (&) [95]);
template LogLine& LogLine::operator<< <char [96]>(char const (&) [96]);
template LogLine& LogLine::operator<< <char [97]>(char const (&) [97]);
template LogLine& LogLine::operator<< <char [98]>(char const (&) [98]);
template LogLine& LogLine::operator<< <char [99]>(char const (&) [99]);
template LogLine& LogLine::operator<< <char [100]>(char const (&) [100]);
// template LogLine& LogLine::operator<< <char [101]>(char const (&) [101]);
// template LogLine& LogLine::operator<< <char [102]>(char const (&) [102]);
// template LogLine& LogLine::operator<< <char [103]>(char const (&) [103]);
// template LogLine& LogLine::operator<< <char [104]>(char const (&) [104]);
// template LogLine& LogLine::operator<< <char [105]>(char const (&) [105]);
// template LogLine& LogLine::operator<< <char [106]>(char const (&) [106]);
// template LogLine& LogLine::operator<< <char [107]>(char const (&) [107]);
// template LogLine& LogLine::operator<< <char [108]>(char const (&) [108]);
// template LogLine& LogLine::operator<< <char [109]>(char const (&) [109]);
// template LogLine& LogLine::operator<< <char [110]>(char const (&) [110]);
// template LogLine& LogLine::operator<< <char [111]>(char const (&) [111]);
// template LogLine& LogLine::operator<< <char [112]>(char const (&) [112]);
// template LogLine& LogLine::operator<< <char [113]>(char const (&) [113]);
// template LogLine& LogLine::operator<< <char [114]>(char const (&) [114]);
// template LogLine& LogLine::operator<< <char [115]>(char const (&) [115]);
// template LogLine& LogLine::operator<< <char [116]>(char const (&) [116]);
// template LogLine& LogLine::operator<< <char [117]>(char const (&) [117]);
// template LogLine& LogLine::operator<< <char [118]>(char const (&) [118]);
// template LogLine& LogLine::operator<< <char [119]>(char const (&) [119]);
// template LogLine& LogLine::operator<< <char [120]>(char const (&) [120]);
// template LogLine& LogLine::operator<< <char [121]>(char const (&) [121]);
// template LogLine& LogLine::operator<< <char [122]>(char const (&) [122]);
// template LogLine& LogLine::operator<< <char [123]>(char const (&) [123]);
// template LogLine& LogLine::operator<< <char [124]>(char const (&) [124]);
// template LogLine& LogLine::operator<< <char [125]>(char const (&) [125]);
// template LogLine& LogLine::operator<< <char [126]>(char const (&) [126]);
// template LogLine& LogLine::operator<< <char [127]>(char const (&) [127]);
// template LogLine& LogLine::operator<< <char [128]>(char const (&) [128]);
// template LogLine& LogLine::operator<< <char [129]>(char const (&) [129]);
// template LogLine& LogLine::operator<< <char [130]>(char const (&) [130]);
// template LogLine& LogLine::operator<< <char [131]>(char const (&) [131]);
// template LogLine& LogLine::operator<< <char [132]>(char const (&) [132]);
// template LogLine& LogLine::operator<< <char [133]>(char const (&) [133]);
// template LogLine& LogLine::operator<< <char [134]>(char const (&) [134]);
// template LogLine& LogLine::operator<< <char [135]>(char const (&) [135]);
// template LogLine& LogLine::operator<< <char [136]>(char const (&) [136]);
// template LogLine& LogLine::operator<< <char [137]>(char const (&) [137]);
// template LogLine& LogLine::operator<< <char [138]>(char const (&) [138]);
// template LogLine& LogLine::operator<< <char [139]>(char const (&) [139]);
// template LogLine& LogLine::operator<< <char [140]>(char const (&) [140]);
// template LogLine& LogLine::operator<< <char [141]>(char const (&) [141]);
// template LogLine& LogLine::operator<< <char [142]>(char const (&) [142]);
// template LogLine& LogLine::operator<< <char [143]>(char const (&) [143]);
// template LogLine& LogLine::operator<< <char [144]>(char const (&) [144]);
// template LogLine& LogLine::operator<< <char [145]>(char const (&) [145]);
// template LogLine& LogLine::operator<< <char [146]>(char const (&) [146]);
// template LogLine& LogLine::operator<< <char [147]>(char const (&) [147]);
// template LogLine& LogLine::operator<< <char [148]>(char const (&) [148]);
// template LogLine& LogLine::operator<< <char [149]>(char const (&) [149]);
// template LogLine& LogLine::operator<< <char [150]>(char const (&) [150]);
// template LogLine& LogLine::operator<< <char [151]>(char const (&) [151]);
// template LogLine& LogLine::operator<< <char [152]>(char const (&) [152]);
// template LogLine& LogLine::operator<< <char [153]>(char const (&) [153]);
// template LogLine& LogLine::operator<< <char [154]>(char const (&) [154]);
// template LogLine& LogLine::operator<< <char [155]>(char const (&) [155]);
// template LogLine& LogLine::operator<< <char [156]>(char const (&) [156]);
// template LogLine& LogLine::operator<< <char [157]>(char const (&) [157]);
// template LogLine& LogLine::operator<< <char [158]>(char const (&) [158]);
// template LogLine& LogLine::operator<< <char [159]>(char const (&) [159]);
// template LogLine& LogLine::operator<< <char [160]>(char const (&) [160]);
// template LogLine& LogLine::operator<< <char [161]>(char const (&) [161]);
// template LogLine& LogLine::operator<< <char [162]>(char const (&) [162]);
// template LogLine& LogLine::operator<< <char [163]>(char const (&) [163]);
// template LogLine& LogLine::operator<< <char [164]>(char const (&) [164]);
// template LogLine& LogLine::operator<< <char [165]>(char const (&) [165]);
// template LogLine& LogLine::operator<< <char [166]>(char const (&) [166]);
// template LogLine& LogLine::operator<< <char [167]>(char const (&) [167]);
// template LogLine& LogLine::operator<< <char [168]>(char const (&) [168]);
// template LogLine& LogLine::operator<< <char [169]>(char const (&) [169]);
// template LogLine& LogLine::operator<< <char [170]>(char const (&) [170]);
// template LogLine& LogLine::operator<< <char [171]>(char const (&) [171]);
// template LogLine& LogLine::operator<< <char [172]>(char const (&) [172]);
// template LogLine& LogLine::operator<< <char [173]>(char const (&) [173]);
// template LogLine& LogLine::operator<< <char [174]>(char const (&) [174]);
// template LogLine& LogLine::operator<< <char [175]>(char const (&) [175]);
// template LogLine& LogLine::operator<< <char [176]>(char const (&) [176]);
// template LogLine& LogLine::operator<< <char [177]>(char const (&) [177]);
// template LogLine& LogLine::operator<< <char [178]>(char const (&) [178]);
// template LogLine& LogLine::operator<< <char [179]>(char const (&) [179]);
// template LogLine& LogLine::operator<< <char [180]>(char const (&) [180]);
// template LogLine& LogLine::operator<< <char [181]>(char const (&) [181]);
// template LogLine& LogLine::operator<< <char [182]>(char const (&) [182]);
// template LogLine& LogLine::operator<< <char [183]>(char const (&) [183]);
// template LogLine& LogLine::operator<< <char [184]>(char const (&) [184]);
// template LogLine& LogLine::operator<< <char [185]>(char const (&) [185]);
// template LogLine& LogLine::operator<< <char [186]>(char const (&) [186]);
// template LogLine& LogLine::operator<< <char [187]>(char const (&) [187]);
// template LogLine& LogLine::operator<< <char [188]>(char const (&) [188]);
// template LogLine& LogLine::operator<< <char [189]>(char const (&) [189]);
// template LogLine& LogLine::operator<< <char [190]>(char const (&) [190]);
// template LogLine& LogLine::operator<< <char [191]>(char const (&) [191]);
// template LogLine& LogLine::operator<< <char [192]>(char const (&) [192]);
// template LogLine& LogLine::operator<< <char [193]>(char const (&) [193]);
// template LogLine& LogLine::operator<< <char [194]>(char const (&) [194]);
// template LogLine& LogLine::operator<< <char [195]>(char const (&) [195]);
// template LogLine& LogLine::operator<< <char [196]>(char const (&) [196]);
// template LogLine& LogLine::operator<< <char [197]>(char const (&) [197]);
// template LogLine& LogLine::operator<< <char [198]>(char const (&) [198]);
// template LogLine& LogLine::operator<< <char [199]>(char const (&) [199]);
// template LogLine& LogLine::operator<< <char [200]>(char const (&) [200]);
