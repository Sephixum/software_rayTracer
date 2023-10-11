#include "Sphere.hpp"
#include "utils.hpp"
#include <cmath>

Sphere::Sphere(Vec3<float> center, float radius)
    : center(center), radius(radius) {}

auto Sphere::Hit(const rt::Ray<float> &ray, float t_min, float t_max,
                 HitRecord &record) const -> bool {

  Vec3<float> ray_to_center = ray.GetOrigin() - center;

  auto a = utils::DotProduct(ray.GetDirection(), ray.GetDirection());
  auto b = 2.0 * utils::DotProduct(ray_to_center, ray.GetDirection());
  auto c = utils::DotProduct(ray_to_center, ray_to_center) - (radius * radius);

  const float discriminant = (b * b) - (4 * a * c);
  if (discriminant > 0) {
    float temp = ((-b - std::sqrt(discriminant)) / (2 * a));
    if ((temp < t_max) && (temp > t_min)) {
      record.distance_from_ray_origin = temp;
      record.point_of_intersection =
          ray.PointAtParameter(record.distance_from_ray_origin);
      record.surface_normal = (record.point_of_intersection - center) / radius;
      return true;
    }
    temp = ((-b + std::sqrt(discriminant)) / (2 * a));
    if ((temp < t_max) && (temp > t_min)) {
      record.distance_from_ray_origin = temp;
      record.point_of_intersection =
          ray.PointAtParameter(record.distance_from_ray_origin);
      record.surface_normal = (record.point_of_intersection - center) / radius;
      return true;
    }
  }
  return false;
}
