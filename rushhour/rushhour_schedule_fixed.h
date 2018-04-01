#ifndef RUSHHOUR_FIXEDINPUTSCHEDULE_H_
#define RUSHHOUR_FIXEDINPUTSCHEDULE_H_

#include <rushhour_schedule_schedule.h>
#include <chrono>
#include <cstdint>

namespace rushhour {
namespace schedule {

class Fixed : public Schedule {
public:
  Fixed(double rate_per_second,
        std::size_t count);

  std::size_t size() const override;
  std::chrono::nanoseconds operator[](std::size_t index) const override;

private:
  std::int64_t period_;
  std::size_t count_;
};

}  // namespace schedule
}  // namespace rushhour

#endif  // RUSHHOUR_FIXEDINPUTSCHEDULE_H_
