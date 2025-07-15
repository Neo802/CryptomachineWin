cmake_minimum_required(VERSION 3.14)
project(CryptomachineWin)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cryptomachine/algorithms
    ${CMAKE_CURRENT_SOURCE_DIR}/cryptomachine/widgets
)

file(GLOB ALGO_SOURCES "cryptomachine/algorithms/*.cpp")
file(GLOB WIDGET_SOURCES "cryptomachine/widgets/*.cpp")

# Ensure at least main.cpp and MainWindow.cpp are present
set(SOURCE_FILES
    main.cpp
    MainWindow.cpp
    ${ALGO_SOURCES}
    ${WIDGET_SOURCES}
    widgets/CaesarWidget.cpp
    widgets/VigenereWidget.cpp
    widgets/BeaufortWidget.cpp
    widgets/AutokeyWidget.cpp
    widgets/VatsayanaWidget.cpp
    widgets/PlayfairWidget.cpp
    widgets/TwoSquareWidget.cpp
    widgets/FourSquareWidget.cpp
    # ...add other .cpp files as needed..
)

if(NOT ALGO_SOURCES)
    message(WARNING "No algorithm source files found in cryptomachine/algorithms/")
endif()

if(NOT WIDGET_SOURCES)
    message(WARNING "No widget source files found in cryptomachine/widgets/")
endif()

add_executable(CryptomachineWin ${SOURCE_FILES})

set_target_properties(CryptomachineWin PROPERTIES WIN32_EXECUTABLE TRUE)

target_link_libraries(CryptomachineWin PRIVATE Qt6::Core Qt6::Widgets)