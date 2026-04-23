
# Wymagana minimalna wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu i wersja
project(MojProjekt VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Określenie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# Dodanie pliku wykonywalnego (nazwa_binarki źródła)
add_executable(moj main.cpp
loops.cpp
var_class.cpp
types.cpp
data_containers.cpp
errors_train.cpp
)
