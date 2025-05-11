cmake_minimum_required(VERSION 3.15)
project(task-board-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем всю логику (все .cpp кроме main.cpp) в статическую библиотеку core_lib
file(GLOB CORE_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM CORE_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_library(core_lib STATIC ${CORE_SOURCES})
target_include_directories(core_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Создаём исполняемый файл сервера из main.cpp и линкуем с core_lib
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE core_lib)

# === GoogleTest через FetchContent ===
include(FetchContent)
set(GOOGLETEST_VERSION v1.14.0)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/${GOOGLETEST_VERSION}.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключаем подпапку с тестами
enable_testing()
add_subdirectory(tests)
