# Set CMP0076 policy to NEW to enable the new behavior
cmake_policy(SET CMP0076 NEW)

# Add sources for libStudentMng target from this subdirectory
target_sources(libCashDesk
        PUBLIC
        building.h
        building.cpp
        land.h
        land.cpp
        property.h
        property.cpp
        )