file(GLOB_RECURSE PLATFORMER_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(Platformer ${PLATFORMER_SOURCES})
target_include_directories(Platformer PRIVATE include)
target_link_libraries(Platformer PRIVATE Atelier)

add_custom_target(Platformer_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:Platformer>/assets
    COMMENT "Copie des assets de Platformer"
)
add_dependencies(Platformer Platformer_assets)