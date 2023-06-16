# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.24)
project ("wx-calc" CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


#[[ 设置 debug 标记 ==============================================================
    1. 2022 版本的 vs 的 debug 判断方式应该使用 CMAKE_BUILD_TYPE
    2. 将 CMAKE_BUILD_TYPE 保存到 project_debug , 避免重复判断
]]
if(CMAKE_BUILD_TYPE)
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
    if(${BUILD_TYPE} STREQUAL "debug")
        set(project_debug 1)
        set(CMAKE_BUILD_TYPE "Debug")
    elseif(${BUILD_TYPE} STREQUAL "release")
        set(project_debug 0)
        set(CMAKE_BUILD_TYPE "Release")
    else()
        set(project_debug 1)
        set(CMAKE_BUILD_TYPE "Debug")
    endif()
else()
    set(project_debug 1)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
 
# 设置 debug 库后缀
if(project_debug)
    set(CMAKE_DEBUG_POSTFIX d)
endif()
 
#[[ 架构判断 ====================================================================
    是否 64 位架构
]]
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH "x64")
    set(arch_64 1)
else()
    set(ARCH "x86")
    set(arch_64 0)
endif()
 
#[[ 设置字符集 ===================================================================
    添加 UNICODE 宏
]]
add_definitions(-DUNICODE -D_UNICODE)
 
#[[ wxWidgets 库处理 ============================================================
    
]]
# wxWidgets 根目录
set(wxWidgets_ROOT_DIR  E:/program/wx_wdigets_3.2.2.1)
# 64 位和 32 位的 lib 路径不同
if(arch_64)
    set(wxWidgets_LIB_DIR ${wxWidgets_ROOT_DIR}/lib/vc_x64_dll)
else()
    set(wxWidgets_LIB_DIR ${wxWidgets_ROOT_DIR}/lib/vc_dll)
endif()
# 库的使用方式, debug 和 release 的 dll 路径不同
set(wxWidgets_CONFIGURATION mswu${CMAKE_DEBUG_POSTFIX})
# 手动指定链接哪些动态库
set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)
 
# findpackage
find_package(wxWidgets 3.2 COMPONENTS core base REQUIRED)

# 公共头文件
include_directories(${CMAKE_SOURCE_DIR}/src/wx_calc_common)

set(lib_calc_kernel calc_kernel)

# 包含子项目。
add_subdirectory ("src")

enable_testing()
# test
add_subdirectory(test)
