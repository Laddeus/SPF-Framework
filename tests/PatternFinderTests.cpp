#include "Utils/PatternFinderInternal.hpp"

#include <cstdint>
#include <iostream>

namespace {

bool ReflectionOwnerClassNameMustMatchExactly() {
  constexpr char actualOwner[] = "traffic_vehicle_type";
  constexpr const char* attributes[] = {"license_plate_type", "speed_class"};
  const auto ownerAddress = reinterpret_cast<uintptr_t>(actualOwner);

  bool passed = true;
  for (const char* attribute : attributes) {
    if (!SPF::Utils::Detail::PointerLeadsToString(ownerAddress, "traffic_vehicle_type", 1)) {
      std::cerr << "Expected traffic_vehicle_type owner to match for " << attribute << '\n';
      passed = false;
    }
    if (SPF::Utils::Detail::PointerLeadsToString(ownerAddress, "traffic_vehicle", 1)) {
      std::cerr << "traffic_vehicle incorrectly matched traffic_vehicle_type owner for " << attribute << '\n';
      passed = false;
    }
  }
  return passed;
}

}  // namespace

int main() {
  return ReflectionOwnerClassNameMustMatchExactly() ? 0 : 1;
}
