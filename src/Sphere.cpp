#include "Sphere.hpp"
#include "utils.hpp"
#include <cmath>

Sphere::Sphere(Vec3<float> center, float radius)
    : center(center), radius(radius) {}

auto Sphere::Hit(const rt::Ray<float> &ray, float t_min, float t_max,
                 HitRecord &record) const -> bool {

  Vec3<float> oc = ray.GetOrigin() - center;

  auto a = utils::DotProduct(ray.GetDirection(), ray.GetDirection());
  auto b = 2.0 * utils::DotProduct(oc, ray.GetDirection());
  auto c = utils::DotProduct(oc, oc) - (radius * radius);

  const float discriminant = (b * b) - (4 * a * c);
  if (discriminant > 0) {
    float temp = ((-b - std::sqrt(discriminant)) / (2 * a));
    if ((temp < t_max) && (temp > t_min)) {
      record.t = temp;
      record.p = ray.PointAtParameter(record.t);
      record.normal = (record.p - center) / radius;
      return true;
    }
    temp = ((-b + std::sqrt(discriminant)) / (2 * a));
    if ((temp < t_max) && (temp > t_min)) {
      record.t = temp;
      record.p = ray.PointAtParameter(record.t);
      record.normal = (record.p - center) / radius;
      return true;
    }
  }
  return false;
}
