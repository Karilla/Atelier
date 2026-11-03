add_library(glad STATIC glad/glad.c)
target_include_directories(glad SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(glad PRIVATE ${CMAKE_DL_LIBS})

add_library(glm INTERFACE)
add_library(glm::glm ALIAS glm)
target_include_directories(glm SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(stb_image INTERFACE)
target_include_directories(stb_image SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})