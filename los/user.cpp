#include "user.h"
#include <climits>
#include <optional>
#include <string_view>
#include <unistd.h>
#include <pwd.h>

std::optional<std::string_view> los::get_user()
{
  uid_t uid = getuid();
  passwd* pw = getpwuid(uid);
  if (!pw) return std::nullopt;

  return pw->pw_name;
}

std::optional<const std::string> los::get_hostname()
{
  char l_hsb[HOST_NAME_MAX];
  int l_hs = gethostname(l_hsb, sizeof(l_hsb));
  if (l_hs != 0) return std::nullopt;

  return std::string(l_hsb);
}
