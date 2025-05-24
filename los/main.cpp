#include "kernel.h"
#include "release.h"
#include "user.h"
#include <optional>
#include <print>
#include <string>
#include <string_view>
int main()
{
  std::optional<std::string_view>  uname = los::get_user();
  std::optional<const std::string> hname = los::get_hostname();

  if (uname && hname) std::println("{}@{}", *uname, *hname);
  std::println("\n{}", los::get_release());

  if (std::optional<const std::string> kernel = los::kernel())
    std::println("{}", *kernel);
}
