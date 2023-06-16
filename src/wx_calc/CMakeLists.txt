
#[[ wxWidgets ======================================================================
    
]]
# wxWidgets 头文件目录
include_directories(${wxWidgets_INCLUDE_DIRS})
# wxWidgets 库文件目录
link_directories(${wxWidgets_LIB_DIR})
# 添加预定义宏: WXUSINGDLL;UNICODE;_UNICODE
add_compile_definitions(${wxWidgets_DEFINITIONS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
aux_source_directory(. SRCS)
add_executable(${PROJECT_NAME} WIN32  ${SRCS})

# 指定源字符集和执行字符集
# 另一种方式是: 
# target_compile_options(MyApp PRIVATE "/source-charset:utf-8" "/execution-charset:utf-8")
target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
 
# 链接 wxWidgets 库
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

# 链接 lib_calc_kernel 库
target_link_libraries(${PROJECT_NAME} PRIVATE ${lib_calc_kernel})

add_dependencies(${PROJECT_NAME} ${lib_calc_kernel})

#[[ 复制 dll ====================================================================
    
]]
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND python ${CMAKE_SOURCE_DIR}/copy_wx_lib.py ${PROJECT_NAME} ${ARCH} ${CMAKE_BUILD_TYPE} ${CMAKE_SOURCE_DIR}
)
