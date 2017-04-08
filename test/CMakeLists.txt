include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/vendor/Catch/single_include
)

add_executable(
  Tester
  Contract.cpp
  tester.cpp
)

target_link_libraries(
  Tester
  Contract
)
