#include "Sphere.hpp"
#include "utils.hpp"
#include <cmath>

Sphere::Sphere(Vec3<float> center, float radius)
    : center(center), radius(radius) {}

auto Sphere::Hit(const rt::Ray<float> &ray, float t_min, float t_max,
                 HitRecord &record) const -> bool {

  Vec3<float> ray_to_center = ray.GetOrigin() - center;

  auto a = utils::DotProduct(ray.GetDirection(), ray.GetDirection());
  auto half_b = utils::DotProduct(ray_to_center, ray.GetDirection());
  auto c =
      (ray_to_center.Length() * ray_to_center.Length()) - (radius * radius);

  const float discriminant = (half_b * half_b) - (a * c);
  if (discriminant < 0) {
    return false;
  }

  // Find the nearest root that lies in the acceptable range
  auto root = ((-half_b - std::sqrt(discriminant)) / (a));
  if ((root <= t_min) || (root >= t_max)) {
    root = ((-half_b + std::sqrt(discriminant)) / (a));
    if ((root <= t_min) || (root >= t_max)) {
      return false;
    }
  }

  record.distance_from_ray_origin = root;
  record.point_of_intersection =
      ray.PointAtParameter(record.distance_from_ray_origin);
  record.surface_normal = (record.point_of_intersection - center) / radius;

  return true;
}
