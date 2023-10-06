cmake_minimum_required(VERSION 3.0.0)  
project(line)  

add_compile_options(-g -Wunused)
add_executable(main ./src/Line.c ./src/booking.c ./src/booked.c)