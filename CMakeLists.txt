# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.

# Requiring cmake v3.12 at minimum in order to use c++ 20
cmake_minimum_required (VERSION 3.12) 

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (LLFiguresCount)

add_subdirectory (src)
add_subdirectory (test)