#ifndef RUSHHOUR_SWEEPINPUTSCHEDULE_H_
#define RUSHHOUR_SWEEPINPUTSCHEDULE_H_

#include <chrono>
#include <cstdint>

#include <rushhour_schedule_schedule.h>

namespace rushhour {
namespace schedule {

class Sweep : public Schedule {
public:
  Sweep(double starting_rate_per_second,
                     double ending_rate_per_second,
                     std::size_t count);

  std::size_t size() const override;
  std::chrono::nanoseconds operator[](std::size_t index) const override;

private:
  double start_rate_;
  double end_rate_;
  std::size_t count_;
};

}  // namespace schedule
}  // namespace rushhour

#endif  // RUSHHOUR_SWEEPINPUTSCHEDULE_H_
