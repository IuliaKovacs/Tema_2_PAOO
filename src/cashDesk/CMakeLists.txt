# Set CMP0076 policy to NEW to enable the new behavior
cmake_policy(SET CMP0076 NEW)

# Add the main library sources
add_library(libCashDesk STATIC contributor.h contributor.cpp analyser.cpp)

# Add the subdirectory
add_subdirectory(Properties)


