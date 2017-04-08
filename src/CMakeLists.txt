include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

add_library(
  Contract
  SHARED
  Contract.cpp
  PostConditionError.cpp
  PreConditionError.cpp
)
