set(TARGET vulkan_exec)

set(SOURCES
    main.cpp
)

set(LIBRARIES
    Vulkan::Vulkan
    ${glfw3_LIBRARIES}
)

set(INCLUDES
    ${glfw3_INCLUDE_DIRS}
    ${glm_INCLUDE_DIRS}
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
target_include_directories(${TARGET} PRIVATE ${INCLUDES})
