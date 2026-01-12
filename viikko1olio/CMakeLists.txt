cmake_minimum_required(VERSION 3.16)

project(viikko1olio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikko1olio main.cpp)

include(GNUInstallDirs)
install(TARGETS viikko1olio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
