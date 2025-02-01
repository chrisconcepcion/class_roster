cmake_minimum_required(VERSION 3.20)
project(MyProject) 
set(SOURCE_FILES Main.cpp roster.h roster.cpp degree.h student.h student.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
