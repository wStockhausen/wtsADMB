cmake_minimum_required(VERSION 3.24)

project(
    wtsADMB
    LANGUAGES CXX
    VERSION 2022.04.20
    DESCRIPTION "CMake script to build wtsADMB library"
)

#--set some local variables
set(LIB "wtsADMB")
set(ADMB_HOME $ENV{ADMB_HOME})
set(WTSADMB_INCLUDE "include")
set(WTSADMB_SRC "src")
set(myCXX_FLAGS "-DUSE_ADMB_CONTRIBS")

#--add "global" libraries
add_library(libadmb STATIC IMPORTED)
#--and set properties
set_property(
    TARGET libadmb 
    PROPERTY IMPORTED_LOCATION 
        "${ADMB_HOME}/lib/libadmb-contrib.a"
)

#--add "global" include directories (use #include <...>?)
include_directories(
    "${ADMB_HOME}/include"
    "${ADMB_HOME}/include/contrib"
)

#--add wtsADMB as library target
add_library(${LIB} STATIC)

#--add include directories (use #include "..."?) for wtsADMB target
target_include_directories(${LIB} PUBLIC "include")

#--add compiler features for wtsADMB target
target_compile_features(${LIB} PUBLIC cxx_std_14)

#--add preprocessor flags (no -D) for wtsADMB target
target_compile_definitions(${LIB} 
    PUBLIC USE_ADMB_CONTRIBS
    PUBLIC _USE_MATH_DEFINES
)
#--add compiler flags for wtsADMB target
target_compile_options(${LIB}
    PUBLIC -Wall
    PUBLIC -O3
)

#--add sources for wtsADMB target
target_sources(${LIB} 
    PUBLIC "${WTSADMB_SRC}/admbBasicFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/admbFileFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/admbParamFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/admbProbFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/admbStdFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/admbStringFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/rFunctions.cpp"
    PUBLIC "${WTSADMB_SRC}/wtsConsts.cpp"
)

target_link_libraries(${LIB} PUBLIC libadmb)