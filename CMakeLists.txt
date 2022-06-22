cmake_minimum_required(VERSION 3.21)
project(xmlparser_abgabe)

set(CMAKE_CXX_STANDARD 17)

add_executable(xmlparser_abgabe
        scr/Test/test_file_write_chris.cpp
        #scr/main.cpp
        scr/XMLparser.cpp
        scr/include/filewrite/filewrite.cpp
        scr/abstractXMLparser.cpp
        scr/include/XMLread/readXML.cpp
        scr/Test/test_file_write_chris.cpp)

include(FindXercesC)
find_package(XercesC REQUIRED)
target_link_libraries(xmlparser_abgabe XercesC::XercesC)