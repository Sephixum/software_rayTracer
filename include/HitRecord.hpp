#pragma once

#include "Vec3.hpp"

struct HitRecord {
	float t;
	rt::Vec3<float> p;
	rt::Vec3<float> normal;
};
