cmake_minimum_required (VERSION 2.6)
project (MyProject)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(app src/main.cpp src/Paciente.cpp src/Prontuario.cpp)