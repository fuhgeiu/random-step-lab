cmake_minimum_required(VERSION 3.10)

project(step_lab)

set(CMAKE_CXX_STANDARD 11)

option(BENCHMARK_STATIC "Link Google Benchmark statically" ON)
#option(USE_STATIC_GTEST "Use static Google Test library" ON)

#path to built library
set(BENCHMARK_DIR "/users/alexcarnes/benchmark")
#set(GOOGLE_TEST_DIR "/users/alexcarnes/google_test")


# Include directories for Google Benchmark and other project directories
include_directories(
    ${BENCHMARK_DIR}/include  # Google Benchmark headers
    #${GOOGLE_TEST_DIR}
    ${PROJECT_SOURCE_DIR}/includes  # includes
    ${PROJECT_SOURCE_DIR}/step_lab  
    ${PROJECT_SOURCE_DIR}/step_lab_main
    ${PROJECT_SOURCE_DIR}/testing
)

if(BENCHMARK_STATIC)
    set(BENCHMARK_LIB_PATH "${BENCHMARK_DIR}/build_static/src/libbenchmark_main.a")
else()
    set(BENCHMARK_LIB_PATH "${BENCHMARK_DIR}/build_dynamic/src/libbenchmark.dylib")
endif()


# Set path for static or dynamic library files for Google Test
#if(USE_STATIC_GTEST)
#    set(GTEST_LIB_PATH "${GOOGLE_TEST_DIR}/lib/libgtest.a")
#else()
#    set(GTEST_LIB_PATH "${GOOGLE_TEST_DIR}/lib/libgtest.dylib")
#endif()


# Add source files common to both executables
set(SOURCE_FILES 

    step_lab/steplab.h  
    includes/classcustvar_template.hpp
    includes/singlelink.hpp
)

set(SOURCE_FILES_RUN

    step_lab_main/main.cpp
)

set(SOURCE_FILES_BENCHMARK
    testing/benchmark.cpp		
)


# run 
add_executable (step_lab_run ${SOURCE_FILES} ${SOURCE_FILES_RUN})

# to run benchmark benchmark
add_executable(step_lab_benchmark ${SOURCE_FILES} ${SOURCE_FILES_BENCHMARK})

#include benchmark headers per target
target_include_directories(step_lab_run PRIVATE ${BENCHMARK_DIR})
target_include_directories(step_lab_benchmark PRIVATE ${BENCHMARK_DIR})


target_link_libraries(step_lab_benchmark ${BENCHMARK_LIB_PATH})

#target_link_libraries(step_lab_benchmark ${BENCHMARK_LIB_PATH} ${GTEST_LIB_PATH})






