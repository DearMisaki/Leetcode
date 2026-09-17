
cmake_minimum_required(VERSION 3.28)

project(151-reverse-words-in-a-string)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. solutions)

foreach (solution_ex ${solutions})
    get_filename_component(solution ${solution_ex} NAME_WE)
    add_executable(${solution} ${solution_ex})
endforeach ()