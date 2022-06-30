include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(test1 "test1.cc")
target_link_libraries(test1 leveldb)
