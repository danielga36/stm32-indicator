######################################################################
# CMakeLists.txt generated for component moon_riders
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(moon_riders)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT D:/personal_files_daniel_george/MATLAB/R2023a CACHE PATH "")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    set(BUILDING_IN_SOURCE_DIR TRUE)
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BUILDING_IN_SOURCE_DIR FALSE)
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
set(MOON_RIDERS_COMMON_DEFINES -DMODEL=moon_riders
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0)

set(MOON_RIDERS_COMMON_LINKER_FLAGS -static
    -m64)

add_library(moon_riders_objects OBJECT ${START_DIR}/moon_riders_ert_rtw/moon_riders.c)
set_target_properties(moon_riders_objects PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(moon_riders_objects PUBLIC c_std_99)
target_compile_definitions(moon_riders_objects PRIVATE ${MOON_RIDERS_COMMON_DEFINES})
target_link_libraries(moon_riders_objects PRIVATE ${MOON_RIDERS_COMMON_LINKER_FLAGS})
target_include_directories(moon_riders_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/moon_riders_ert_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/moon_riders_ert_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)
target_link_libraries(moon_riders_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)

add_executable(moon_riders  ${START_DIR}/moon_riders_ert_rtw/ert_main.c)
set_target_properties(moon_riders PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)
target_compile_features(moon_riders PUBLIC c_std_99)
target_compile_definitions(moon_riders PRIVATE ${MOON_RIDERS_COMMON_DEFINES})
target_link_libraries(moon_riders PRIVATE ${MOON_RIDERS_COMMON_LINKER_FLAGS})
target_link_libraries(moon_riders PRIVATE moon_riders_objects)
if(WIN32)
   target_link_libraries(moon_riders PRIVATE kernel32
       ws2_32
       mswsock
       advapi32)
endif()

######################################################################
## Extract debug symbols
######################################################################
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:moon_riders>;--flat,"
                "true"
        >)
    add_custom_command(TARGET moon_riders
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS moon_riders.dwarf)
endif()


######################################################################
## Target install and export rules
######################################################################
install(TARGETS moon_riders_objects EXPORT moon_ridersTargets OBJECTS DESTINATION moon_riders_ert_rtw)
install(TARGETS moon_riders RUNTIME DESTINATION . OPTIONAL)
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:moon_riders>/moon_riders.dwarf DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:moon_riders> DESTINATION . OPTIONAL CONFIGURATIONS Debug RelWithDebInfo)
endif()
install(EXPORT moon_ridersTargets NAMESPACE moon_riders:: DESTINATION moon_riders_ert_rtw/export)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/moon_riders.cmake 
 "include(\"\${CMAKE_CURRENT_LIST_DIR}/moon_ridersTargets.cmake\")" \n
    "target_include_directories(moon_riders::moon_riders_objects INTERFACE \n"
    "    \${MATLAB_ROOT}/extern/include" \n 
    "    \${MATLAB_ROOT}/simulink/include" \n 
    "    \${MATLAB_ROOT}/rtw/c/src" \n 
    "    \${MATLAB_ROOT}/rtw/c/src/ext_mode/common" \n 
    "    \${MATLAB_ROOT}/rtw/c/ert)" \n )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/moon_riders.cmake DESTINATION moon_riders_ert_rtw/export)

######################################################################
## Build success message
######################################################################
add_custom_command(TARGET moon_riders POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:moon_riders>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(moon_riders)
endif()
