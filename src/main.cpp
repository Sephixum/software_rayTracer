#include <format>
#include <iostream>

#include "PrintColor.hpp"
#include "Sphere.hpp"
#include "Vec3.hpp"
#include "globals.hpp"
#include "ray.hpp"
#include "utils.hpp"

using namespace rt;

auto main() -> int {

  // auto aspect_ratio = 16.0 / 9.0;
  auto aspect_ratio = 2.0 / 1.0;
  float image_width = 800.f;
  float image_height = static_cast<float>(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  auto camera_center = Vec3<float>(0.f, 0.f, 0.f);
  auto viewport_height = 2.0;
  auto viewport_width =
      viewport_height * (static_cast<float>(image_width / image_height));
  auto focal_length = 1.0f;

  /*
   * Calculate vectors across the-
   * horizontall and down the vertical viewport edges
   */
  auto viewport_u = Vec3<float>(viewport_width, 0.f, 0.f);
  auto viewport_v = Vec3<float>(0.f, -viewport_height, 0.f);

  /*
   * Calculate the horizontal and-
   * vertical delta vectors from pixel to pixel
   */
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  /*
   * Calculate the location of the upper left pixel
   */
  auto viewport_upper_left = camera_center - Vec3<float>(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel100_loc =
      viewport_upper_left + (pixel_delta_u + pixel_delta_v) * 0.5;

  {
    using namespace globals;
    std::puts(std::format("P3\n{} {}\n255", kImageWidth, kImageHeight).c_str());
  }

  const Vec3<float> lower_left_corner(-2.0f, -1.0f, -1.0f);
  const Vec3<float> horizontal(4.0f, 0.0f, 0.0f);
  const Vec3<float> vertical(0.0f, 2.0f, 0.0f);
  const Vec3<float> starting_point(0.0f, 0.0f, 0.0f);

  Sphere sphere(Vec3<float>(0, 0, 1), 0.5);

  for (auto j{0}; j < image_height; ++j) {
    using namespace globals;
    std::clog << "\rScanning remaining: " << (image_height - j) << ' '
              << std::flush << std::endl;
    for (auto i{0}; i < image_width; ++i) {

      auto pixel_center =
          pixel100_loc + (pixel_delta_u * i) + (pixel_delta_v * j);
      auto ray_direction = pixel_center - camera_center;
      Ray<float> ray(camera_center, ray_direction);

      Vec3<float> color = rt::SetColor(ray, &sphere);
      PrintColor(color);
    }
  }
  std::clog << "\rDone.          \n";

  return EXIT_SUCCESS;
}
