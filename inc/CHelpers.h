#ifndef __CHelpers__H__
#define __CHelpers__H__
#include <cmath>

bool __CHelpers_SrtLDAbs(const long double a, const long double b) {
  return std::abs(a)<std::abs(b);
}
bool __CHelpers_SrtFAbs(const float a, const float b) {
  return std::abs(a)<std::abs(b);
}

#endif
