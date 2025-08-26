# Copyright (c) 2025 David Ibehej
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

add_library(algorithm SHARED ./src/cGA.c)
set_target_properties(algorithm PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(algorithm PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/python_wrapper")