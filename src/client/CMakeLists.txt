#定义一个src_list变量,用于存放当前目录下的所有源文件
aux_source_directory(. SRC_LIST)

#生成可执行文件
add_executable(ChatClient ${SRC_LIST})

#指定可执行文件链接时需要链接的库文件
target_link_libraries(ChatClient pthread)