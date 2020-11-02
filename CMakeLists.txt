project(sparse_solver)
cmake_minimum_required(VERSION 3.1)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse2 -msse3 -Wall  -std=c++14  -Wall -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -msse2 -msse3 -std=c++14 -Wall -O3")

find_package(Eigen 3 REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})


find_package(CSparse REQUIRED)
if (FBLOCKSOLVER_USE_CSPARSE)
  if(CSPARSE_FOUND)
    set(BUILD_CSPARSE OFF CACHE BOOL "Build local CSparse library")
  else(CSPARSE_FOUND)
    set(BUILD_CSPARSE ON CACHE BOOL "Build local CSparse library")
    if(BUILD_CSPARSE)
      set(CSPARSE_FOUND TRUE)
    endif()
  endif(CSPARSE_FOUND)
else(FBLOCKSOLVER_USE_CSPARSE)
  set(BUILD_CSPARSE OFF "Build local CSparse library")
endif(FBLOCKSOLVER_USE_CSPARSE)
include_directories(${CSPARSE_INCLUDE_DIR})

find_package(Cholmod)
include_directories(${CHOLMOD_INCLUDE_DIR})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES src/base/matrix_structure.cpp
            src/csparse/csparse_extension.cpp
            src/base/marginal_covariance_cholesky.cpp
            src/csparse/csparse_helper.cpp

            )

add_library(sparse_solver SHARED ${SOURCES})
target_link_libraries(sparse_solver ${CSPARSE_LIBRARY} ${CHOLMOD_LIBRARY})

add_executable(test_sparse_solver_cs test/test_sparse_solver_cs.cpp)
target_link_libraries(test_sparse_solver_cs sparse_solver)

add_executable(test_cholmod test/test_cholmod.cpp)
target_link_libraries(test_cholmod sparse_solver)


add_executable(test_pcg test/test_pcg.cpp)
target_link_libraries(test_pcg sparse_solver)