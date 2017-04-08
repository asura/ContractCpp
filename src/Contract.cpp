#include "Contract.h"
#include "PostConditionError.h"
#include "PreConditionError.h"

void Contract::Requires(bool condition, const std::string& err_message)
{
  if (! condition) {
    throw PreConditionError(err_message);
  }
}

void Contract::Requires(std::function<bool()> condition, const std::string& err_message)
{
  if (! condition()) {
    throw PreConditionError(err_message);
  }
}

void Contract::Ensures(bool condition, const std::string& err_message)
{
  if (! condition) {
    throw PostConditionError(err_message);
  }
}

void Contract::Ensures(std::function<bool()> condition, const std::string& err_message)
{
  if (! condition()) {
    throw PostConditionError(err_message);
  }
}
