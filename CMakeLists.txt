#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(ariel)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 0)
set(myproject_VERSION_MINOR 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB ariel_sources "src/*.cpp" "src/*.c")
# Define sources and executable
set(EXECUTABLE_NAME "ariel")
add_executable( ${EXECUTABLE_NAME} ${ariel_sources})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
if(UNIX)
  find_package(SFML 2 REQUIRED network audio graphics window system)
  find_package(OpenGL REQUIRED)
  find_package(GLUT REQUIRED)
  include_directories(${GLUT_INCLUDE_DIRS})
  include_directories(${OPENGL_INCLUDE_DIRS})
  if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries (${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
    target_link_libraries (${EXECUTABLE_NAME} ${GLUT_LIBRARIES})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} pthread dl)
    
  endif()
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  file(GLOB ariel_libs "lib/*.lib")
  set(SFML_DIR "include/")
  set(SFML_LIB "lib/")
  MESSAGE("${SFML_DIR}")
  include_directories(${SFML_DIR})
  link_directories(${SFML_LIB})
  find_library(SFML2 NAMES sfml)
  #set(CMAKE_FIND_LIBRARY_SUFFIXES .lib ${CMAKE_FIND_LIBRARY_SUFFIXES})
  target_compile_options(${EXECUTABLE_NAME} PRIVATE -bigobj)
  target_include_directories(${EXECUTABLE_NAME} PRIVATE ${SFML_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${ariel_libs})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)