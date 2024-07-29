cmake_minimum_required(VERSION 3.16)
project(simplesim LANGUAGES CXX)

find_package(Kokkos REQUIRED)
add_executable(hellokokkos main.cpp)
target_link_libraries(hellokokkos PRIVATE Kokkos::kokkos)
target_compile_features(hellokokkos PRIVATE cxx_std_17)
