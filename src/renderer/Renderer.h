#ifndef RENDERER_H_
#define RENDERER_H_

#include "scene/Scene.h"
#include "renderer/Camera.h"
#include "renderer/raytracer/RayTracer.h"

class Renderer {

	const Scene scene;
	const Camera * const camera;
	RayTracer* rayTracer;
	int nRows, nCols;

public:

	Renderer(const Camera * const camera, const Scene & scene, AppConfiguration & AppCfg);

	~Renderer();

	void render();

};

#endif /* RENDERER_H_ */
