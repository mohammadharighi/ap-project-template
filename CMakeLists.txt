cmake_minimum_required(VERSION 3.16)
project(AdvancedProgrammingProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

enable_testing()

# ---------------------------------------------------------------------------
# Phase 4 (Qt GUI): uncomment when the ui/ directory has its own CMakeLists.txt
# ---------------------------------------------------------------------------
# option(BUILD_UI "Build the Qt GUI" OFF)
# if(BUILD_UI)
#     add_subdirectory(ui)
# endif()

# ---------------------------------------------------------------------------
# Core library: application logic, independent of the UI
# ---------------------------------------------------------------------------
add_library(core STATIC core/CommandParser.cpp)
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR})

# ---------------------------------------------------------------------------
# Command line interface (phases 1-3)
# ---------------------------------------------------------------------------
add_executable(ap_cli cli/main.cpp)
target_link_libraries(ap_cli PRIVATE core)

# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------
add_executable(core_tests tests/test_command_parser.cpp)
target_link_libraries(core_tests PRIVATE core)
add_test(NAME core_tests COMMAND core_tests)
