#include "Mesh.h"
#include "shape/mesh/IFace.h"
#include "shape/mesh/AFace.h"
#include "shape/mesh/FlatFace.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "util/Vector.h"
#include "util/Point.h"

Mesh::Mesh(const std::string & filename){
	readFile(filename);
}

void Mesh::readFile(const std::string & filename){
	std::ifstream inf(filename.c_str());
	if (!inf) {
		std::cout << "Mesh file " << filename << " could not be opened!\n";
		exit(1);
	}
	unsigned numberOfVertices, numberOfNormals, numberOfFaces;
	inf >> numberOfVertices >> numberOfNormals >> numberOfFaces;
//	std::cout<< numberOfVertices << numberOfNormals << numberOfFaces << std::endl;
	double x,y,z;
	for(unsigned i = 0; i < numberOfVertices; i++){
		inf >> x >> y >> z;
		verts.push_back(Point(x,y,z));
//		std::cout << verts.at(i).x << verts.at(i).y << verts.at(i).z << std::endl;
	}
	for(unsigned i = 0; i < numberOfNormals; i++){
		inf >> x >> y >> z;
		norms.push_back(Vector(x,y,z));
//		std::cout << norms.at(i).x << norms.at(i).y << norms.at(i).z << std::endl;
	}
	for(unsigned i = 0; i < numberOfFaces; i++){
		unsigned numberOfVerticesOnFace, p0, p1, p2, normal, normal1, normal2;
		inf >> numberOfVerticesOnFace >> p0 >> p1 >> p2 >> normal >> normal1 >> normal2;
		AFace *face;
		face = new FlatFace(&verts.at(p0), &verts.at(p1), &verts.at(p2), norms.at(normal));
		faces.push_back(face);
//		std::cout << faces.at(i)->getVertex(0).x << faces.at(i)->getVertex(0).y << faces.at(i)->getVertex(0).z << std::endl;
//		std::cout << faces.at(i)->getVertex(1).x << faces.at(i)->getVertex(1).y << faces.at(i)->getVertex(1).z << std::endl;
//		std::cout << faces.at(i)->getVertex(2).x << faces.at(i)->getVertex(2).y << faces.at(i)->getVertex(2).z << std::endl;
	}
	inf.close();
}


HitInfo Mesh::intersection(const Ray & ray){
	HitInfo bestHitInfo(DBL_MAX);
	for(std::vector<IFace*>::iterator it = faces.begin(); it != faces.end(); ++it) {
		HitInfo hitInfo = (*it)->intersection(ray);
		if(hitInfo.getT() < bestHitInfo.getT()){
			bestHitInfo = hitInfo;
		}
	}
	bestHitInfo.setHitMaterial(Material(mtrl));
	return bestHitInfo;
}

