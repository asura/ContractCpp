#pragma once
#include <stdexcept>

class PostConditionError : public std::logic_error {
public:
  PostConditionError() = delete;
  explicit PostConditionError(const std::string& err_message);

  ~PostConditionError() = default;
};
