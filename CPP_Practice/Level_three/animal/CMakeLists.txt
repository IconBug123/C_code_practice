cmake_minimum_required(VERSION 3.20)
project(AnimalSim LANGUAGES CXX)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 源文件清单
set(SRC
    src/main.cpp
    src/ConsoleUI.cpp
    src/IOUtil.cpp
    src/Dog.cpp
    src/Cat.cpp
    src/Bird.cpp
)

# 头文件清单
set(HEADERS
    include/Animal.h
    include/Dog.h
    include/Cat.h
    include/Bird.h
    include/IOUtil.h
    include/ConsoleUI.h
)

add_executable(AnimalSim ${SRC} ${HEADERS})

# 按目录树分组：VS 里会显示 include/ 和 src/ 树状结构
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SRC} ${HEADERS})

# 可执行文件输出路径：build/bin/<Config>
set_target_properties(AnimalSim PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY                ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
  RUNTIME_OUTPUT_DIRECTORY_DEBUG          ${CMAKE_BINARY_DIR}/bin/Debug
  RUNTIME_OUTPUT_DIRECTORY_RELEASE        ${CMAKE_BINARY_DIR}/bin/Release
  RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}/bin/RelWithDebInfo
  RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     ${CMAKE_BINARY_DIR}/bin/MinSizeRel
)
