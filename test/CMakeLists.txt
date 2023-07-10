set(TEST_EXECUTABLE_NAME minirt_unit_tests)

set(TEST_SRCS
	test.cpp
)

# Download GoogleTest
# --------------------------------------------------
include(GoogleTest)
include(FetchContent)

if (version VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

list(TRANSFORM SRCS PREPEND ../ OUTPUT_VARIABLE PROJECT_SRCS)

# Tests
# --------------------------------------------------
add_executable(
	${TEST_EXECUTABLE_NAME}
	${PROJECT_SRCS}
	${TEST_SRCS}
)

# Add include directories from the main project
target_include_directories(${TEST_EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Link gtest to the test executable
target_link_libraries(
	${TEST_EXECUTABLE_NAME}
	gtest_main
)

# Add tests to CTest
# Set working directory to the the testing folder so that the test can find their test files
# --------------------------------------------------
gtest_discover_tests(${TEST_EXECUTABLE_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} TEST_PREFIX "miniRT/")
enable_testing()
