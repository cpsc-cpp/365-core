add_executable(pi_time pi_approx.cpp)
target_compile_options(pi_time PRIVATE -fno-inline-functions)