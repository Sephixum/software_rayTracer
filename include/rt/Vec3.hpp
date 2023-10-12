#pragma once

#include <array>
#include <cmath>
#include <concepts>
#include <iostream>
#include <type_traits>

namespace rt {

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <Arithmetic T> class Vec3;

template <Arithmetic T> using color = Vec3<T>;

template <Arithmetic T> class Vec3 {
private:
  std::array<T, 3> arr_;

public:
  Vec3() = default;
  explicit Vec3(T x, T y, T z) : arr_{x, y, z} {}

  auto GetX() const noexcept { return arr_[0]; }

  auto GetY() const noexcept { return arr_[1]; }

  auto GetZ() const noexcept { return arr_[2]; }

  auto Length() const noexcept {
    return std::sqrt(arr_[0] * arr_[0] + arr_[1] * arr_[1] + arr_[2] * arr_[2]);
  }

  [[nodiscard]] const auto &operator+() const noexcept { return *this; }

  [[nodiscard]] const auto operator-() const noexcept {
    return Vec3(-arr_[0], -arr_[1], -arr_[2]);
  }

  [[nodiscard]] const auto operator[](int i) const noexcept { return arr_[i]; }

  [[nodiscard]] auto &operator[](int i) noexcept { return arr_[i]; }

  auto &operator+=(const Vec3 &rhs) {
    arr_[0] += rhs.GetX();
    arr_[1] += rhs.GetY();
    arr_[2] += rhs.GetZ();
    return *this;
  }

  [[nodiscard]] auto operator+(const Vec3 &rhs) const noexcept {
    return Vec3(arr_[0] + rhs.GetX(), arr_[1] + rhs.GetY(),
                arr_[2] + rhs.GetZ());
  }

  auto &operator-=(const Vec3 &rhs) noexcept {
    arr_[0] -= rhs.GetX();
    arr_[1] -= rhs.GetY();
    arr_[2] -= rhs.GetZ();
    return *this;
  }

  [[nodiscard]] auto operator-(const Vec3 &rhs) const noexcept {
    return Vec3(arr_[0] + rhs.GetX(), arr_[1] + rhs.GetY(),
                arr_[2] + rhs.GetZ());
  }

  auto &operator*=(const Vec3 &rhs) noexcept {
    arr_[0] *= rhs.GetX();
    arr_[1] *= rhs.GetY();
    arr_[2] *= rhs.GetZ();
    return *this;
  }

  auto &operator*=(const T rhs) const noexcept {
    arr_[0] *= rhs;
    arr_[1] *= rhs;
    arr_[2] *= rhs;
    return *this;
  }

  [[nodiscard]] auto operator*(const Vec3 &rhs) const noexcept {
    return Vec3(arr_[0] * rhs.GetX(), arr_[1] * rhs.GetY(),
                arr_[2] * rhs.GetZ());
  }

  [[nodiscard]] auto operator*(const T rhs) const noexcept {
    return Vec3(arr_[0] * rhs, arr_[1] * rhs, arr_[2] * rhs);
  }

  auto &operator/=(const Vec3 &rhs) noexcept {
    arr_[0] /= rhs.GetX();
    arr_[1] /= rhs.GetY();
    arr_[2] /= rhs.GetZ();
    return *this;
  }

  auto &operator/=(const T rhs) const {
    arr_[0] /= rhs;
    arr_[1] /= rhs;
    arr_[2] /= rhs;
    return *this;
  }

  [[nodiscard]] auto operator/(const Vec3 &rhs) const noexcept {
    return Vec3(arr_[0] / rhs.GetX(), arr_[1] / rhs.GetY(),
                arr_[2] / rhs.GetZ());
  }

  [[nodiscard]] auto operator/(const T rhs) const noexcept {
    return Vec3(arr_[0] / rhs, arr_[1] / rhs, arr_[2] / rhs);
  }

  friend auto &operator<<(std::ostream &out, const Vec3<T> &rhs) {
    return out << rhs.GetX() << ' ' << rhs.GetY() << ' ' << rhs.GetZ();
  }

  // using color = Vec3<T>;
  // friend auto &operator<<(std::ostream &out, const color &rhs);
  // {
  //   return out << static_cast<int>(255.999 * rhs.GetX()) << ' '
  //              << static_cast<int>(255.999 * rhs.GetY()) << ' '
  //              << static_cast<int>(255.999 * rhs.GetZ()) << ' ';
  // }
};

} // namespace rt
