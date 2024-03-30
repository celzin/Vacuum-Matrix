cmake_minimum_required(VERSION 3.12)

project("Autocomplete" VERSION 1.0.0)

add_executable(app "src/main.cpp" "src/Agent.cpp" "src/Environment.cpp" "src/InputGenerator.cpp" "src/Utility.cpp")