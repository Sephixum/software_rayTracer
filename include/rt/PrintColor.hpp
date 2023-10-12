#pragma once

#include "Vec3.hpp"
#include <format>

template <rt::Arithmetic T> auto PrintColor(const rt::Vec3<T> &color_pixel) {
  std::puts(std::format("{} {} {}",
                        static_cast<int>(255.999 * color_pixel.GetX()),
                        static_cast<int>(255.999 * color_pixel.GetY()),
                        static_cast<int>(255.999 * color_pixel.GetZ()))
                .c_str());
}
