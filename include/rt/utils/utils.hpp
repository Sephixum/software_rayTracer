#pragma once

#include "HitAlbe.hpp"
#include "HitRecord.hpp"
#include "Vec3.hpp"
#include "globals.hpp"
#include "ray.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <format>
#include <string>

namespace rt {
namespace utils {

template <typename T>
auto DotProduct(const Vec3<T> &v1, const Vec3<T> &v2) noexcept {
  return (v1.GetX() * v2.GetX()) + (v1.GetY() * v2.GetY()) +
         (v1.GetZ() * v2.GetZ());
}

template <typename T>
auto CrossProduct(const Vec3<T> &v1, const Vec3<T> &v2) noexcept {
  return Vec3<T>((v1.GetY() * v2.GetZ() - v1.GetZ() * v2.GetY()),
                 (v1.GetZ() * v2.GetX() - v1.GetX() * v2.GetZ()),
                 (v1.GetX() * v2.GetY() - v1.GetY() * v2.GetX()));
}

template <typename T> inline auto UnitVector(rt::Vec3<T> v) noexcept {
  return v / v.Length();
}

} // namespace utils

template <typename T>
auto HitSphere(const Vec3<T> &center, float radius, const Ray<T> &ray) -> bool {
  Vec3<T> oc = ray.GetOrigin() - center;
  auto a = utils::DotProduct(ray.GetDirection(), ray.GetDirection());
  auto b = 2.0 * utils::DotProduct(oc, ray.GetDirection());
  auto c = utils::DotProduct(oc, oc) - (radius * radius);
  auto discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    return false;
  }
  auto temp = ((-b - std::sqrt(discriminant)) / (2 * a));
  return static_cast<T>((-b - std::sqrt(discriminant)) / (2 * a));
}

template <typename T> auto SetColor(const rt::Ray<T> &ray, HitAble *object) {
  HitRecord record;
  if (object->Hit(ray, 0.0f, MAXFLOAT, record)) {
    return (record.surface_normal + Vec3<T>(1, 1, 1)) *
           globals::kGradientStrength;
  }
  auto unit_direction = utils::UnitVector(ray.GetDirection());
  auto background_blend =
      globals::kGradientStrength * (unit_direction.GetY() + 1);
  return rt::Vec3<T>(1.0, 1.0, 1.0) * (1.0 - background_blend) +
         rt::Vec3<T>(0.5, 0.7, 1.0) * background_blend;
}

} // namespace rt
