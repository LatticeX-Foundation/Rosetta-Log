# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 3.2)
project(spdlog_examples CXX)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

if(SPDLOG_BUILD_EXAMPLE_HO)
    set(EXAMPLE_SRC 
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/loggers.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/logger_stream.cpp 
        )
endif()
# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(example example.cpp)
target_link_libraries(example PRIVATE spdlog::spdlog)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(example_header_only ${EXAMPLE_SRC} example.cpp )
    target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(test test.cpp)
target_link_libraries(test PRIVATE spdlog::spdlog)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(test_header_only ${EXAMPLE_SRC} test.cpp)
    target_link_libraries(test_header_only PRIVATE spdlog::spdlog_header_only)
endif()
