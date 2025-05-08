cmake_minimum_required(VERSION 3.15)
project(task-board-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к заголовкам вашего сервера
include_directories(${CMAKE_SOURCE_DIR}/include)

# Собираем только исходники сервера
file(GLOB SERVER_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SERVER_SOURCES} "include/message.h")

# === GoogleTest через FetchContent ===
include(FetchContent)
set(GOOGLETEST_VERSION v1.14.0)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/${GOOGLETEST_VERSION}.zip
)
# Для MSVC: чтобы GTest использовал общий CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Подключаем подпапку с тестами
enable_testing()
add_subdirectory(tests)
