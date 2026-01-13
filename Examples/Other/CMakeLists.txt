add_executable(uptr uptr.cpp)
add_executable(sptr sptr.cpp)
add_executable(wptr wptr.cpp)
add_executable(forward forward.cpp)
target_compile_options(forward PUBLIC -fno-elide-constructors)

add_executable(variadic variadic.cpp)


