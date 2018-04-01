#ifndef RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_
#define RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_

#include <chrono>
#include <cstdint>

#include <rushhour_schedule_schedule.h>

namespace rushhour {
namespace schedule {

class Unlimited : public Schedule {
public:
  Unlimited(std::size_t count);

  std::size_t size() const override;
  std::chrono::nanoseconds operator[](std::size_t index) const override;

private:
  std::size_t count_;
};

}  // namespace schedule
}  // namespace rushhour

#endif  // RUSHHOUR_UNLIMITEDINPUTSCHEDULE_H_
