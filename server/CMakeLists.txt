cmake_minimum_required(VERSION 3.10)
project(Server)

# Укажите путь к vcpkg
set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)

# Добавьте исполняемые файлы
add_executable(server server_main.cpp)

# Связываем библиотеки с вашими исполняемыми файлами
target_link_libraries(server PRIVATE socketio_server)

