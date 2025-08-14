cmake_minimum_required(VERSION 3.21)

set(CMAKE_BUILD_TYPE Debug)

project(3x)

IF (WIN32)
    set(CMAKE_C_FLAGS "/Zi")
ELSE()
    set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -pedantic -g")
ENDIF()

file(GLOB SRC CONFIGURE_DEPENDS "main.c")

IF(WIN32)
    set(GMP_ROOT "" CACHE PATH "Root path to vcpkg installation for GMP")
    IF(GMP_ROOT)
        set(GMP_INCLUDE_DIR "${GMP_ROOT}/include")
        set(GMP_LIBRARY "${GMP_ROOT}/lib/gmp.lib")
    ENDIF()

    add_executable(${PROJECT_NAME} ${SRC})
    include_directories(${GMP_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${GMP_LIBRARY})
ELSE()
    add_executable(${PROJECT_NAME} ${SRC})
    target_link_libraries(${PROJECT_NAME} PRIVATE gmp)
ENDIF()
