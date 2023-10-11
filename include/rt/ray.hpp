#pragma once

#include "Vec3.hpp"

namespace rt {

template <typename T> struct Ray {
private:
  rt::Vec3<T> starting_point_;
  rt::Vec3<T> direction_;

public:
  Ray() = default;
  explicit Ray(const rt::Vec3<T> &starting_point, const rt::Vec3<T> &direction)
      : starting_point_(starting_point), direction_(direction) {}

  auto GetOrigin() const noexcept { return starting_point_; }
  auto GetDirection() const noexcept { return direction_; }

  auto PointAtParameter(float t) const {
    return rt::Vec3<T>(starting_point_ + (direction_ * t));
  }
};

} // namespace rt
