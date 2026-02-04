add_executable(types types.cpp)
add_executable(chars chars.cpp)
add_executable(arrays arrays.cpp)
add_executable(array_passing array_passing.cpp)

add_library(common common.cpp)

add_executable(structs structs.cpp)
target_link_libraries(structs PUBLIC common)

add_executable(references references.cpp)
target_link_libraries(references PUBLIC common)

add_executable(overload overload.cpp)
target_compile_options(overload PRIVATE -Wfloat-conversion)

add_executable(functions functions.cpp)

add_subdirectory(LinkedList)
add_subdirectory(Timing)