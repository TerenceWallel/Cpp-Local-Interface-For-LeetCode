get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} ABSOLUTE)
get_filename_component(CURRENT_DIR_NAME ${CURRENT_DIR} NAME)

add_executable(${CURRENT_DIR_NAME} main.cpp)