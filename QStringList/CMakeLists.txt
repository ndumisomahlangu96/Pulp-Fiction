cmake_minimum_required(VERSION 3.19)
project(QStringList LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(QStringList
    main.cpp
)

target_link_libraries(QStringList
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS QStringList
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
