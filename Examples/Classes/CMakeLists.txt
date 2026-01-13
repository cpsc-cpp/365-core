add_executable(matrix matrix.cpp)
target_compile_options(matrix PUBLIC -fno-elide-constructors)

add_executable(order order.cpp)
add_executable(virtual virtual.cpp)

add_subdirectory(DataProcessing)
