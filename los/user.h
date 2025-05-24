#pragma once

#include <optional>
#include <string_view>
#include <string>
namespace los
{
  std::optional<std::string_view> get_user();
  std::optional<const std::string> get_hostname();
}
