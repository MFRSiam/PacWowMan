cmake_minimum_required(VERSION 3.20)
project(Sfml_vcpkg_proj)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sfml_vcpkg_proj main.cpp Game.cpp Game.h GameState.cpp GameState.h)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Sfml_vcpkg_proj PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(Sfml_vcpkg_proj PRIVATE fmt::fmt)
