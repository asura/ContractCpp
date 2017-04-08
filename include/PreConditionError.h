#pragma once
#include <stdexcept>

class PreConditionError : public std::logic_error {
public:
  PreConditionError() = delete;
  explicit PreConditionError(const std::string& err_message);

  ~PreConditionError() = default;
};
