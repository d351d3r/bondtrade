cmake_minimum_required(VERSION 3.19)  # 3.19 или более новая версия для лучшей поддержки C++23

# Назначьте название вашему проекту
project(MOEX_Parser)

# Укажите C++ стандарт
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включите поддержку Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Создайте список исходных файлов
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Создайте исполняемый файл
add_executable(moex_parser ${SOURCES})

# Укажите директории заголовочных файлов для нашего target
target_include_directories(moex_parser PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/hpp")

# Если вы используете дополнительные библиотеки, укажите их зависимости через Conan
# Например, для libcurl:
# target_link_libraries(moex_parser PRIVATE CONAN_PKG::libcurl)

# Если у вас есть другие зависимости, укажите их вот так:
# target_link_libraries(moex_parser PRIVATE CONAN_PKG::library_name)

# Если у вас есть другие опции компилятора или флаги, вы можете также добавить их сюда
# target_compile_options(moex_parser PRIVATE -some-compiler-options)
