cmake_minimum_required(VERSION 3.16)

project(viikko6olio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikko6olio main.cpp
    student.h student.cpp)

include(GNUInstallDirs)
install(TARGETS viikko6olio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
