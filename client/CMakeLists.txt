cmake_minimum_required(VERSION 3.10)
project(Client)

# Укажите путь к vcpkg
set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED COMPONENTS system)


# Добавьте исполняемые файлы
add_executable(client client_main.cpp)

# Связываем библиотеки с вашими исполняемыми файлами

target_link_libraries(client PRIVATE Boost::system pthread )
