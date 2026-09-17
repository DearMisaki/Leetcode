cmake_minimum_required(VERSION 3.28)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

function(get_subdirs result cur_dir)
    file(GLOB sub_items RELATIVE ${cur_dir} "${cur_dir}/*")
    set(sub_dir "")
    foreach (item ${sub_items})
        if (IS_DIRECTORY ${cur_dir}/${item})
            list(APPEND sub_dir ${item})
        endif ()
    endforeach ()
    set(${result} ${sub_dir} PARENT_SCOPE)
endfunction()

get_subdirs(problems ${CMAKE_SOURCE_DIR}/problems)

message(STATUS "---------- Problems ----------")

foreach(problem ${problems})
    message(${problem})
endforeach(problem )

message(STATUS "---------- Problems ----------")

foreach (problem ${problems})
    add_subdirectory(${CMAKE_SOURCE_DIR}/problems/${problem})
endforeach ()
