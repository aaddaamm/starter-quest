cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Quest VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable name and source files
add_executable(Quest main.cpp)

find_package(OpenSSL REQUIRED)

# Check if OpenSSL was found
if(OpenSSL_FOUND)
  # Link your target with OpenSSL libraries
  target_link_libraries(Quest ${OpenSSL_LIBRARIES})
else()
  message(FATAL_ERROR "OpenSSL not found. Please install OpenSSL or check your installation.")
endif()

# Include the baseClasses directory for header files
target_include_directories(Quest PRIVATE ${CMAKE_SOURCE_DIR}/baseClasses)

# Add source files from the baseClasses directory
file(GLOB SOURCES "baseClasses/*.cpp")

# Link the source files from baseClasses to the Quest executable
target_sources(Quest PRIVATE ${SOURCES})

# Optional: Set the output directory for the binary (can be customized)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)