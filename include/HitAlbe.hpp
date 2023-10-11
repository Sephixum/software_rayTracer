#pragma once

#include "HitRecord.hpp"
#include "ray.hpp"

/*
  abstract class for any ray-hitable object
*/

class HitAble {
public:
  virtual auto Hit(const rt::Ray<float> &ray, float t_min, float t_max,
                   HitRecord &record) const -> bool = 0;
};
