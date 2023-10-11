#pragma once

#include "HitAlbe.hpp"

using namespace rt;

class Sphere : public HitAble {
public:
  Sphere() = default;
  explicit Sphere(Vec3<float> center, float radius);
  virtual auto Hit(const rt::Ray<float> &ray, float t_min, float t_max,
                   HitRecord &record) const -> bool override;
  Vec3<float> center;
  float radius;
};
