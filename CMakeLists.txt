cmake_minimum_required(VERSION 3.21)
project(xmlparser_abgabe)

set(CMAKE_CXX_STANDARD 17)

add_executable(xmlparser_abgabe scr/main.cpp
        scr/XMLparser.cpp scr/XMLparser.h
        scr/include/filewrite/filewrite.cpp scr/include/filewrite/filewrite.h)
