FILE(GLOB WORKSPACE_DIR *)

message("-- question dir:")
foreach (dirpath ${WORKSPACE_DIR})
    if(NOT dirpath MATCHES ".*CMakeLists.txt")
        message("--     ${dirpath}")
        add_subdirectory(${dirpath})
    endif ()
endforeach ()
