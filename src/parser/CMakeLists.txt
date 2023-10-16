cmake_minimum_required(VERSION 3.19)  # 3.19 или более новая версия для лучшей поддержки C++23

# Назначьте название вашему подпроекту
project(MOEX_Parser)

# Укажите C++ стандарт
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включите поддержку Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Создайте список исходных файлов для вашего подпроекта
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Создайте исполняемый файл
add_executable(moex_parser ${SOURCES})

# Укажите директории заголовочных файлов для вашего подпроекта
target_include_directories(moex_parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/hpp)

# Если вы используете дополнительные библиотеки, например, libcurl,
# Conan автоматически загрузит их, поэтому вы можете использовать их через цели Conan
# Например:
# target_link_libraries(moex_parser PRIVATE CONAN_PKG::libcurl)

# Если у вас есть другие зависимости, укажите их вот так:
# target_link_libraries(moex_parser PRIVATE CONAN_PKG::library_name)

# Если у вас есть другие опции компилятора или флаги, вы можете также добавить их сюда
# target_compile_options(moex_parser PRIVATE -some-compiler-options)
