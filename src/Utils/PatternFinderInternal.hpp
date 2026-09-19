#pragma once

#include <cstdint>
#include <cstring>

namespace SPF::Utils::Detail {

/**
 * @brief Resolves a pointer chain and checks whether it leads to the expected class name.
 */
inline bool PointerLeadsToString(uintptr_t addr, const char* expectedClassName, int maxDepth = 3) {
  if (addr < 0x10000 || maxDepth <= 0) return false;
  try {
    const char* str = reinterpret_cast<const char*>(addr);
    if (str[0] >= 0x20 && str[0] <= 0x7E && std::strcmp(str, expectedClassName) == 0) return true;
    return PointerLeadsToString(*reinterpret_cast<uintptr_t*>(addr), expectedClassName, maxDepth - 1);
  } catch (...) {
    return false;
  }
}

}  // namespace SPF::Utils::Detail
