# cmake的学习总结

使用变量的方式是 `${变量名}`, 在`if`中可以直接使用变量名即可, 定义变量时为 set(变量名 xxx)

## 常用环境变量

1. `CMAKE_BINARY_DIR`, `PROJECT_BINARY_DIR`, `<自己的project name>_BINARY_DIR`： 

这三个变量指代内容一致,如果时`in_source`编译, 指的是工程顶层目录,
如果时`out_of_source`编译,指的是工程编译发生的目录

2. `CMAKE_SOURCE_DIR`, `PROJECT_SOURCE_DIR`, `<project name>_SOURCE_DIR`:

这三个变量指代内容一致,不论采用何种方式编译,指的都是工程顶层目录

3. `CMAKE_CURRENT_SOURCE_DIR` :

指的是当前处理的`CMakeLists.txt`所在的路径

4. `CMAKE_CURRENT_LIST_FILE` :

输出调用这个变量的 CMakeLists.txt 的完整路径



