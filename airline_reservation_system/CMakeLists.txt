cmake_minimum_required(VERSION 3.0.0)  
project(line)  

SET (CMAKE_BUILD_TYPE "Debug")
SET (CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET (CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# find_package(Curses REQUIRED)
# include_directories(CURSES_INCLUDE_DIR)

add_compile_options(-g -Wunused)

add_executable(main ./src/main.c ./src/Line.c ./src/booking.c ./src/booked.c )
# target_link_libraries(main2 ${CURSES_LIBRARIES})