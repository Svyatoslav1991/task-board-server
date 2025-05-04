cmake_minimum_required(VERSION 3.15)
project(task-board-server LANGUAGES CXX)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем, где искать заголовки (пусть пока папка пустая — добавите свои .hpp туда)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Собираем все .cpp из src/
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Генерируем исполняемый файл с именем проекта
add_executable(${PROJECT_NAME} ${SOURCES})
