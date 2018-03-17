#ifndef RUSHHOUR_SWEEPINPUTSCHEDULE_H_
#define RUSHHOUR_SWEEPINPUTSCHEDULE_H_

#include "rushhour_inputschedule.h"
#include <chrono>
#include <cstdint>

namespace rushhour {

class SweepInputSchedule : public InputSchedule {
public:
  SweepInputSchedule(double starting_rate_per_second,
                     double ending_rate_per_second,
                     std::size_t count);

  std::size_t size() const override;
  std::chrono::nanoseconds operator[](std::size_t index) const override;

private:
  double start_rate_;
  double end_rate_;
  std::size_t count_;
};

}  // namespace rushhour

#endif  // RUSHHOUR_SWEEPINPUTSCHEDULE_H_
