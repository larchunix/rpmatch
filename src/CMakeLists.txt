include_directories(${CMAKE_CURRENT_BINARY_DIR})
configure_file(config.cmake.h ${CMAKE_CURRENT_BINARY_DIR}/config.h)

list(
  APPEND RPMATCH_SOURCES
  config.h
  rpmatch.c
)

add_executable(rpmatch ${RPMATCH_SOURCES})
target_compile_definitions(rpmatch PRIVATE HAVE_CONFIG_H)

install(TARGETS rpmatch RUNTIME DESTINATION bin)

# vi: set ft=cmake et sw=2 ts=2:
