#include "kernel.h"
#include <format>
#include <optional>
#include <string>
#include <sys/utsname.h>

std::optional<const std::string> los::kernel()
{
  utsname bf;
  if (uname(&bf) != 0) return std::nullopt;

  return std::format("{} {}", bf.sysname, bf.release);
}
