cmake_minimum_required (VERSION 3.16)
project(qtimgui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick OpenGLWidgets Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick OpenGLWidgets Gui Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    qt_imgui_sources
    ImGuiRenderer.h
    ImGuiRenderer.cpp
    QtImGui.h
    QtImGui.cpp
)

# qt_imgui_quick: library with a qt renderer for Qml / QtQuick applications
add_library(qt_imgui_quick STATIC ${qt_imgui_sources})
target_include_directories(qt_imgui_quick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    qt_imgui_quick
    PUBLIC
    imgui
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    )
if (ANDROID)
    target_link_libraries(qt_imgui_quick PUBLIC log dl GLESv2 z)
endif()

# qt_imgui_widget: library with a qt renderer for classic Qt Widget applications
add_library(qt_imgui_widgets STATIC ${qt_imgui_sources})
target_include_directories(qt_imgui_widgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    qt_imgui_widgets
    PUBLIC
    imgui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    )
if (ANDROID)
    target_link_libraries(qt_imgui_widgets PUBLIC log dl GLESv2 z)
endif()
target_compile_definitions(qt_imgui_widgets PUBLIC QT_WIDGETS_LIB)
