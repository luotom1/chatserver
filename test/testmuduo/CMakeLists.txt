# cmake_minimum_required(VERSION 3.5)
# project(main)

# #配置编译选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")

# #配置头文件搜索路径
# # include_directories()
# #配置库文件搜索路径
# # link_directories()

# # 设置需要编译的源文件列表
# set(SRC_LIST muduo_server.cpp)
# #把.指定路径下的所有源文件名字放入变量名SRC_LIST中 
# #aux_source_directory(. SRC_LIST)

# #设置可执行文件最终生成路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# #生成可执行文件server
# add_executable(server muduo_server.cpp)
# #表示server这个可执行文件依赖于muduo_net muduo_base pthread这三个库文件
# target_link_libraries(server muduo_net muduo_base pthread)
