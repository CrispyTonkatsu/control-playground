add_executable(visualizer main.cpp)
target_include_directories(visualizer PRIVATE
	mujoco_INCLUDE_DIRS
	${GLFW_INCLUDE_DIRS}
)
target_link_libraries(visualizer PRIVATE
	project-warnings
	mujoco::mujoco
	glfw
)
