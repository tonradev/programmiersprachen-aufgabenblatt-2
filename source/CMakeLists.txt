# Build example
add_executable(example
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  rect.cpp
  circle.cpp
  example.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  window.cpp
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rect.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build clock
add_executable(clock
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  rect.cpp
  circle.cpp
  clock.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(clock glfw nanovg ${COPY_BINARY})