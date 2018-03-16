#ifndef RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_
#define RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_

#include "rushhour_inputschedule.h"
#include <chrono>
#include <cstdint>

namespace rushhour {

class UnlimitedInputSchedule : public InputSchedule {
public:
  UnlimitedInputSchedule(std::size_t count);

  std::size_t size() const override;
  std::chrono::nanoseconds operator[](std::size_t index) const override;

private:
  std::size_t count_;
};

}  // namespace rushhour

#endif  // RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_
