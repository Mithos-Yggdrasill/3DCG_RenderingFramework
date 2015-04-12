#include "scene/SceneFactory.h"
#include "util/Point.h"
#include "util/Colour.h"
#include "shape/Sphere.h"
#include "shape/Square.h"
#include "shading/Light.h"
#include "shape/mesh/Mesh.h"
#include <iostream>
#include <cstdlib>

Scene SceneFactory::createScene(const std::string & filename){

	Scene scene;
	Material currMtrl;

	std::ifstream inf(filename.c_str());
	if (!inf) {
		std::cout << "SDL file " << filename << " could not be opened!\n";
		exit(1);
	}

	while(inf){
		std::string key;
		inf >> key;
		if(key.empty()){
			continue;
		}
		if(key.compare("background")==0){
			double r,g,b;
			inf >> r >> g >> b;
			scene.setBackground(Colour(r,g,b));
		} else if (key.compare("light")==0){
			double x,y,z,r,g,b;
			inf >> x >> y >> z >> r >> g >> b;
			scene.addLight(Light(Point(x,y,z),Colour(r,g,b)));
		} else if(!processMaterial(inf, key, currMtrl)){
			scene.addObject(createShape(inf, key, currMtrl));
		}
	}
	return scene;
}


bool SceneFactory::processMaterial(std::ifstream & inf, const std::string & key, Material & currMtrl){
	if(key.compare("diffuse")==0){
		double r,g,b;
		inf >> r >> g >> b;
		currMtrl.setDiffuse(Colour(r,g,b));
		return true;
	} else if (key.compare("ambient")==0){
		double r,g,b;
		inf >> r >> g >> b;
		currMtrl.setAmbient(Colour(r,g,b));
		return true;
	}
	return false;
}

Shape * SceneFactory::createShape(std::ifstream & inf, const std::string & key, const Material & currMtrl){
	Shape * shape;
	if(key.compare("sphere")==0){
		shape = new Sphere;
	} else if(key.compare("square") == 0) {
		shape = new Square;
	} else if (key.compare("mesh") == 0) {
		std::string filename;
		inf >> filename;
		shape = new Mesh(filename);
	} else {
		std::cout << "Token " << key << " in SDL file is not supported!\n";
		exit(1);
	}
	shape->setMaterial(Material(currMtrl));
	return shape;
}

