#include "Contract.h"
#include "PostConditionError.h"
#include "PreConditionError.h"
#include "catch.hpp"

class Sample
{
public:
  std::string foo(const std::string& x)
  {
    Contract::Requires(! x.empty());

    auto result = x + "sample";
    Contract::Ensures([&]() -> bool { return (! result.empty()); });
    return result;
  }

  std::string bar(const std::string& x)
  {
    Contract::Requires(! x.empty());

    std::string result;
    Contract::Ensures([&]() -> bool { return (! result.empty()); });
    return result;
  }
};

TEST_CASE("事前条件を満たしていれば何も起きない", "[unit][Contract]") {
  Sample sut;

  REQUIRE_NOTHROW(sut.foo("xxx"));
}

TEST_CASE("事前条件を満たさない場合(呼び出し側の責務不履行)は例外発生", "[unit][Contract]") {
  Sample sut;

  REQUIRE_THROWS_AS(sut.foo(""), PreConditionError);
}

TEST_CASE("事後条件を満たさない場合は例外発生", "[unit][Contract]") {
  Sample sut;

  REQUIRE_THROWS_AS(sut.bar("xyz"), PostConditionError);
}
