#include <format>
#include <iostream>

#include "Vec3.hpp"
#include "globals.hpp"
#include "ray.hpp"
#include "utils.hpp"

using namespace rt;

auto main() -> int {

  {
    using namespace globals;
    std::puts(std::format("P3\n{} {}\n255", kImageWidth, kImageHeight).c_str());
  }

  const Vec3<float> lower_left_corner(-2.0f, -1.0f, -1.0f);
  const Vec3<float> horizontal(4.0f, 0.0f, 0.0f);
  const Vec3<float> vertical(0.0f, 2.0f, 0.0f);
  const Vec3<float> starting_point(0.0f, 0.0f, 0.0f);

  for (auto j{globals::kImageHeight - 1}; j >= 0; j--) {
    using namespace globals;
    for (auto i{0}; i < kImageWidth; i++) {
      auto u = i / float(kImageWidth);
      auto v = j / float(kImageHeight);

      Ray<float> ray(starting_point,
                     lower_left_corner + (horizontal * u) + (vertical * v));
      Vec3<float> color = rt::SetColor(ray);

      int ir = int(255.99 * color.GetX());
      int ig = int(255.99 * color.GetY());
      int ib = int(255.99 * color.GetZ());
      std::puts(std::format("{} {} {}", ir, ig, ib).c_str());
    }
  }

  return EXIT_SUCCESS;
}
