pybind11_add_module(PyLineFromPointCloud PyLineFromPointCloud.cpp)
target_link_libraries(PyLineFromPointCloud PUBLIC LineFromPointCloud ${OpenCV_LIBS})
# set_target_properties(PyLineFromPointCloud PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
# set_target_properties(PyLineFromPointCloud PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
set_target_properties(PyLineFromPointCloud
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/python/LineFromPointCloud/"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/python/LineFromPointCloud/"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
  )



