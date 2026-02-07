cmake_minimum_required(VERSION 3.16)

project(viikko5olio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikko5olio main.cpp
    seuraaja.h seuraaja.cpp
    notifikaattori.h notifikaattori.cpp)

include(GNUInstallDirs)
install(TARGETS viikko5olio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
