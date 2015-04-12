#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "Renderer.h"
#include <string>
#include <stdlib.h>
#include "Ray.h"
#include "util/Vector.h"
#include "util/Colour.h"

Renderer::Renderer(const Camera * const camera, const Scene & scene, AppConfiguration & appCfg):scene(scene), camera(camera){

	nCols = atoi(appCfg["image.nCols"].c_str());
	nRows = atoi(appCfg["image.nRows"].c_str());
	rayTracer = new RayTracer(scene);
}

Renderer::~Renderer(){
	delete rayTracer;
	rayTracer = 0;
}

void Renderer::render(){
	double widthPixel = camera->getWidth()/nCols;
	double heightPixel = camera->getHeight()/nRows;
	Vector v1 = (camera->getHeight()/2 * camera->getV()) + (-1*camera->getWidth()/2 * camera->getU());
	Vector v3 = -1 * camera->getDistance() * camera->getN() + v1;

	for (int r = 0; r < nRows ; r++){
		for (int c = 0; c < nCols; c++){
			Vector v2 = (c * widthPixel * camera->getU()) + (-1*r * heightPixel * camera->getV());
			Vector dir = v3 + v2;
			Colour col = rayTracer->shade(Ray(camera->getEye(), dir));
			glColor3d(col.r, col.g, col.b);
			glRecti(c, nRows-r, c+1, nRows-r-1);
		}
	}
}

