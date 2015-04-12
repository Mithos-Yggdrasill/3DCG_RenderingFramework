#include "RayTracer.h"
#include "util/Vector.h"

Colour RayTracer::shadeHit(const Ray & ray, const HitInfo & hitInfo){

	Light l = scene.getLights().at(0);
	Vector s = Vector(hitInfo.getHitPoint(), l.getPosition());
	Vector m = hitInfo.getHitNormal();
	double r,g,b;

	if(s.dot(m) > 0){
		r = hitInfo.getHitMaterial().getDiffuse().r * l.getColour().r * (s.dot(m))/(s.length()*m.length()) + hitInfo.getHitMaterial().getAmbient().r * l.getColour().r;
		g = hitInfo.getHitMaterial().getDiffuse().g * l.getColour().g * (s.dot(m))/(s.length()*m.length()) + hitInfo.getHitMaterial().getAmbient().g * l.getColour().g;
		b = hitInfo.getHitMaterial().getDiffuse().b * l.getColour().b * (s.dot(m))/(s.length()*m.length()) + hitInfo.getHitMaterial().getAmbient().b * l.getColour().b;
	} else {
		r = hitInfo.getHitMaterial().getAmbient().r * l.getColour().r;
		g = hitInfo.getHitMaterial().getAmbient().g * l.getColour().g;
		b = hitInfo.getHitMaterial().getAmbient().b * l.getColour().b;
	}
	return Colour(r,g,b);
}
