#pragma once

#include <cmath>
#include <concepts>
#include <iostream>
#include <type_traits>

namespace rt {

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <Arithmetic T> using Vec3T = std::array<T, 3>;

template <Arithmetic T> class Vec3 {
private:
  Vec3T<T> arr_;

public:
  Vec3() = default;
  explicit Vec3(T x, T y, T z) : arr_{x, y, z} {}

  inline auto GetX() const noexcept { return arr_[0]; }

  inline auto GetY() const noexcept { return arr_[1]; }

  inline auto GetZ() const noexcept { return arr_[2]; }

  inline auto Length() const noexcept {
    return std::sqrt(arr_[0] * arr_[0] + arr_[1] * arr_[1] + arr_[2] * arr_[2]);
  }

  [[nodiscard]] inline const auto &operator+() const noexcept { return *this; }

  [[nodiscard]] inline const auto operator-() const noexcept {
    return Vec3(-arr_[0], -arr_[1], -arr_[2]);
  }

  [[nodiscard]] inline const auto operator[](int i) const noexcept {
    return arr_[i];
  }

  [[nodiscard]] inline auto &operator[](int i) noexcept { return arr_[i]; }

  inline auto &operator+=(const Vec3 &v2) {
    arr_[0] += v2.GetX();
    arr_[1] += v2.GetY();
    arr_[2] += v2.GetZ();
    return *this;
  }

  [[nodiscard]] inline auto operator+(const Vec3 &v2) const noexcept {
    return Vec3(arr_[0] + v2.GetX(), arr_[1] + v2.GetY(), arr_[2] + v2.GetZ());
  }

  inline auto &operator-=(const Vec3 &v2) noexcept {
    arr_[0] -= v2.GetX();
    arr_[1] -= v2.GetY();
    arr_[2] -= v2.GetZ();
    return *this;
  }

  [[nodiscard]] inline auto operator-(const Vec3 &v2) const noexcept {
    return Vec3(arr_[0] + v2.GetX(), arr_[1] + v2.GetY(), arr_[2] + v2.GetZ());
  }

  inline auto &operator*=(const Vec3 &v2) noexcept {
    arr_[0] *= v2.GetX();
    arr_[1] *= v2.GetY();
    arr_[2] *= v2.GetZ();
    return *this;
  }

  inline auto &operator*=(const T s) const noexcept {
    arr_[0] *= s;
    arr_[1] *= s;
    arr_[2] *= s;
    return *this;
  }

  [[nodiscard]] inline auto operator*(const Vec3 &v2) const noexcept {
    return Vec3(arr_[0] * v2.GetX(), arr_[1] * v2.GetY(), arr_[2] * v2.GetZ());
  }

  [[nodiscard]] inline auto operator*(const T s) const noexcept {
    return Vec3(arr_[0] * s, arr_[1] * s, arr_[2] * s);
  }

  inline auto &operator/=(const Vec3 &v2) noexcept {
    arr_[0] /= v2.GetX();
    arr_[1] /= v2.GetY();
    arr_[2] /= v2.GetZ();
    return *this;
  }

  inline auto &operator/=(const T s) const {
    arr_[0] /= s;
    arr_[1] /= s;
    arr_[2] /= s;
    return *this;
  }

  [[nodiscard]] inline auto operator/(const Vec3 &v2) const noexcept {
    return Vec3(arr_[0] / v2.GetX(), arr_[1] / v2.GetY(), arr_[2] / v2.GetZ());
  }

  [[nodiscard]] inline auto operator/(const T s) const noexcept {
    return Vec3(arr_[0] / s, arr_[1] / s, arr_[2] / s);
  }
};

} // namespace rtr
