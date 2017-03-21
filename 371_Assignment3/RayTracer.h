#pragma once

#include <vector>
#include <limits>

#include "Scene.h"
#include "Ray.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Plane.h"
#include "Camera.h"

#define DMAX 5
#define EPSILON 0.000001

class RayTracer {
public:

	static std::vector<Ray*> rays;

	static std::vector<Ray*> generateRays(Camera* camera, int resScale);

	static bool intersectRaySphere(Ray* ray, Sphere* sphere, float & t, glm::vec3 & norm);

	static bool intersectRayPlane(Ray* ray, Plane* sphere, float & t, glm::vec3 & norm);

	static bool intersectRayTriangle(Ray* ray, Triangle* sphere, float & t, glm::vec3 & norm);

	static glm::vec3 trace(Scene * scene, Ray * ray, int depth);

private:

	static bool solveQuadratic(const float & a, const float & b, const float & c, float & x0, float & x1);

	static glm::vec3 accLight(Scene * scene, glm::vec3 intersection, SceneGeometry * obj);
};

