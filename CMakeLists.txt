cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Quest VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable name and source files
add_executable(Quest main.cpp)

find_package(OpenSSL REQUIRED)
target_link_libraries(Quest OpenSSL::SSL OpenSSL::Crypto)

# Include the baseClasses directory for header files
target_include_directories(Quest PRIVATE ${CMAKE_SOURCE_DIR}/baseClasses)
target_include_directories(Quest PRIVATE ${CMAKE_SOURCE_DIR}/characterClasses)

# Add source files from the baseClasses directory
file(GLOB BASE_SOURCES "baseClasses/*.cpp")
file(GLOB CHARACTER_SOURCES "characterClasses/*.cpp")

target_sources(Quest PRIVATE ${BASE_SOURCES} ${CHARACTER_SOURCES})

# Optional: Set the output directory for the binary (can be customized)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)