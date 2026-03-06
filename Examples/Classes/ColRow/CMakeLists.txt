add_executable(colrow matrix.cpp)

# Can change optimization and profiling flags in the following line:
target_compile_options(colrow PUBLIC -pg -O1)
target_link_options(colrow PUBLIC -pg)