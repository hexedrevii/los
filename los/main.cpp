#include "kernel.h"
#include "release.h"
#include "user.h"
#include <cstring>
#include <optional>
#include <print>
#include <string>
#include <string_view>
int main(int argc, char** argv)
{
  if (argc > 1 && std::strcmp(argv[1], "-n") == 0)
  {
    std::optional<std::string_view>  uname = los::get_user();
    std::optional<const std::string> hname = los::get_hostname();

    if (uname && hname) std::println("{}@{}\n", *uname, *hname);
  }

  std::println("{}", los::get_release());

  if (std::optional<const std::string> kernel = los::kernel())
    std::println("{}", *kernel);
}
