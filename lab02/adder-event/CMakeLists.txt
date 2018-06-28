# Define the version of cmake required
cmake_minimum_required (VERSION 2.6)

# Define the project name of these source code
project (Adder_event)

# We use a CMake moduile to fine the SystemC library. Define the module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Find the package, which defines variable SYSTEMC_INCLUDE_DIRS
# and SYSTEMC_LIBRARIES.
find_package(SystemC)

# This command sets -I flag of g++, and able to take array as input
include_directories(${SYSTEMC_INCLUDE_DIRS})

# Define the executable name and its source code
add_executable(Adder_event main.cpp)

# Define the used libraries of the executable, Equal to -l flags of g++
# In here, the libraries are given in apsolute path. hence no needs for -L
# flag
target_link_libraries(Adder_event ${SYSTEMC_LIBRARIES}) 


# change the name of the executable form Adder_event to adder.
set_target_properties(Adder_event PROPERTIES OUTPUT_NAME adder)
