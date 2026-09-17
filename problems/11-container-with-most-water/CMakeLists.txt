
cmake_minimum_required(VERSION 3.28)

project(11-container-with-most-water)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. solutions)

foreach (solution_ex ${solutions})
    get_filename_component(solution ${solution_ex} NAME_WE)
    add_executable(${solution} ${solution_ex})
endforeach ()