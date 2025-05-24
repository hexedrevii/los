#include "release.h"
#include <format>
#include <stdexcept>
#include <string>
#include <fstream>

const std::string los::get_release()
{
  std::ifstream osr("/etc/os-release");
  if (!osr.is_open())
    throw std::runtime_error("Could not open /etc/os-release. (Are you running Linux?)");

  std::string oname, vname;
  std::string ln;
  while (std::getline(osr, ln))
  {
    if (ln.empty()) continue;

    unsigned long dl = ln.find('=');
    if (dl == std::string::npos) continue;

    std::string name = ln.substr(0, dl);

    std::string value = ln.substr(dl+1, ln.size());
    value.erase(0, 1);
    value.erase(value.size() - 1);

    if (name == "NAME") oname = value;
    else if (name == "VERSION") vname = value;

    if (!oname.empty() && !vname.empty()) break;
  }

  return std::format("{} {}", oname, vname);
}
