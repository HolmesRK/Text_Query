cmake_minimum_required(VERSION 3.0.0)
project(TextQuery VERSION 0.1.0)

include(CTest)
enable_testing()

# aux_source_directory(. DIR_SRCS)
# add_executable(demo ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


# 添加头文件路径
include_directories(include)
include_directories(src)

#井好表示注释
PROJECT( TextQuery )                       #设定工程名

# SET(CMAKE_CXX_COMPILER "clang")         #设置编译器（可选的有gcc，g++）

# 设置用debug还是release模式。debug允许断点，而release更快
set( CMAKE_BUILD_TYPE Debug )
# set( CMAKE_BUILD_TYPE Release )

# 设置编译选项
# 允许c++17标准、O3优化、多线程。match选项可避免一些cpu上的问题
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -march=native -O3 -pthread" )

# 设置调试断点
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")



#设定可执行二进制文件的目录
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

#设定存放编译出来的库文件的目录
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

#并且把该目录设为连接目录
LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)
#
# find_package (Threads REQUIRED)
#设定头文件目录
#INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include)

# 增加子文件夹(注意我们的src路径是通过子文件夹的形式添加的，在这里面也是可以些CMakeLists.txt的)
ADD_SUBDIRECTORY( ${PROJECT_SOURCE_DIR}/src)
# 或则是ADD_SUBDIRECTORY( src)

add_executable(TextQuery main.cpp)

# 添加头文件路径
target_include_directories(TextQuery PUBLIC ${PROJECT_SOURCE_DIR}/include)
# 添加链接库
target_link_libraries(TextQuery Packages)