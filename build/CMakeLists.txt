cmake_minimum_required(VERSION 3.10)

# προσθέτο τα cpp files
project(Multibrot_Generator VERSION 3.5)

find_package(X11 REQUIRED)
file(GLOB_RECURSE SRC_FILES_C ${CMAKE_SOURCE_DIR}/../src/*.c)
file(GLOB_RECURSE SRC_FILES_CPP ${CMAKE_SOURCE_DIR}/../src/*.cpp)
#file(GLOB_RECURSE SRC_IMGUI_FILES ${CMAKE_SOURCE_DIR}/src/imgui/*.cpp)
# φτιάνω το executable
add_executable(Multibrot_Generator ${CMAKE_SOURCE_DIR}/../main.cpp ${SRC_FILES_C} ${SRC_FILES_CPP})

# προσθέτω ότι directories χρειάζομαι
target_include_directories(Multibrot_Generator
    PUBLIC
    ${CMAKE_SOURCE_DIR}/../include
)


target_link_directories(Multibrot_Generator PUBLIC ${CMAKE_SOURCE_DIR}/../src/glfw)

target_link_libraries(Multibrot_Generator
    PUBLIC
    glfw3
    X11::X11
)

# για να φτίαξω το πρόγραμα γράφω τα παρακάτω:
# cd build
# cmake ..
# make
# ./Multibrot_Generator