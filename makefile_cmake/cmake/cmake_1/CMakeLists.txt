cmake_minimum_required (VERSION 3.0) #要求cmake版本
project (test_1)    #为该项目起一个名字

#把src目录下所有源文件路径放到变量hello_src中
#aux_source_directory不会递归包含子目录,仅包含制定的dir目录
#如果指定目录中增加了源文件,CMakeLists文件无变化,无法识别,需要重新执行cmake
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/hello SOURCE_HELLO)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/world SOURCE_WORLD)

add_definitions("-g -Wall -std=c++11")  #添加编译参数

add_executable(main
               ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
               ${SOURCE_HELLO}
               ${SOURCE_WORLD})
