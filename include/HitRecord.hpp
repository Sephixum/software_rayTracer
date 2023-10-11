#pragma once

#include "Vec3.hpp"

struct HitRecord {
	float distance_from_ray_origin;
	rt::Vec3<float> point_of_intersection;
	rt::Vec3<float> surface_normal;
};
