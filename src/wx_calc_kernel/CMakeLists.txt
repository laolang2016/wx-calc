include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(. KERNEL_SRCS)
add_library(${lib_calc_kernel} SHARED ${KERNEL_SRCS})

set_target_properties(${lib_calc_kernel} PROPERTIES VERSION 1.0 SOVERSION 1)
target_include_directories(${lib_calc_kernel} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "====> Boost_INCLUDE_DIRS:${Boost_INCLUDE_DIRS}")
message(STATUS "====> Boost_LIBRARY_DIRS:${Boost_LIBRARY_DIRS}")

# 链接 boost 库
# target_link_libraries(${lib_calc_kernel} PUBLIC Boost::boost)
target_include_directories(${lib_calc_kernel} PUBLIC ${Boost_INCLUDE_DIRS})

# 复制 dll 到 app 目录
add_custom_command(TARGET ${lib_calc_kernel} POST_BUILD
    COMMAND python ${CMAKE_SOURCE_DIR}/copy_dll.py ${CMAKE_CURRENT_BINARY_DIR} ${lib_calc_kernel} ${ARCH} ${CMAKE_BUILD_TYPE} ${CMAKE_SOURCE_DIR}
)