#include "PostConditionError.h"

PostConditionError::PostConditionError(
  const std::string& err_message)
  : std::logic_error(err_message)
{}
