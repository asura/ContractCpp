#include "PreConditionError.h"

PreConditionError::PreConditionError(
  const std::string& err_message)
  : std::logic_error(err_message)
{}
