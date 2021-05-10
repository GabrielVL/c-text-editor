cmake_minimum_required(VERSION 3.19)
project(c_text_editor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "-DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)
set(UI ${CMAKE_CURRENT_LIST_DIR}/mainwindow.ui)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        Sources/main.cpp
        Sources/mainwindow.cpp
        Headers/mainwindow.h
        Sources/mainwindow.ui
        Sources/TcpServer.cpp
        Headers/TcpServer.h
        Sources/TcpClient.cpp
        Headers/TcpClient.h
        Sources/Reader.cpp
        Headers/Reader.h
        Sources/memoryManager.cpp
        Headers/memoryManager.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS Network ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network ${REQUIRED_LIBS_QUALIFIED})
