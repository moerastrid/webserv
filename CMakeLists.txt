cmake_minimum_required(VERSION 3.21.0)

project(webserv)

# Sourcefiles with main function (excluded from testing)
set (SRCS_MAIN
	src/main.cpp
)

set (SRCS
	src/hello-world.cpp
    src/Config.cpp
	src/errorMessage.cpp
)
set (EXEC_NAME webserv)

# Compiler settings
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address") #cmake -DCMAKE_BUILD_TYPE=DEBUG to add debug flags
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) #vscode include path checking

# Make executable with output name specified under EXEC_NAME and sources specified under SRCS and SRCS_MAIN
add_executable(${EXEC_NAME} ${SRCS} ${SRCS_MAIN})
target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#-------------------- TESTING -------------------------------

if ((PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME AND BUILD_TESTS) OR WEBSERV_BUILD_TESTS)
	add_subdirectory(test)
	enable_testing()
endif()
