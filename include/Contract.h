#pragma once
#include <functional>
#include <string>

/// <summary>契約を表現する</summary>
class Contract
{
public:
  /// <summary>事前条件</summary>
  static void Requires(bool condition, const std::string& err_message = "");
  static void Requires(std::function<bool()> condition, const std::string& err_message = "");

  /// <summary>事後条件</summary>
  static void Ensures(bool condition, const std::string& err_message = "");
  static void Ensures(std::function<bool()> condition, const std::string& err_message = "");
};
