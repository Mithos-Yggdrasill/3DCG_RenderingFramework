#include "Camera.h"
#include <cstdlib>
#include <string>

Camera::Camera(AppConfiguration & appCfg){

	eye.x = std::atof(appCfg["camera.eye.x"].c_str());
	eye.y = std::atof(appCfg["camera.eye.y"].c_str());
	eye.z = std::atof(appCfg["camera.eye.z"].c_str());

	look.x = std::atof(appCfg["camera.look.x"].c_str());
	look.y = std::atof(appCfg["camera.look.y"].c_str());
	look.z = std::atof(appCfg["camera.look.z"].c_str());

	upV.x = std::atof(appCfg["camera.up.x"].c_str());
	upV.y = std::atof(appCfg["camera.up.y"].c_str());
	upV.z = std::atof(appCfg["camera.up.z"].c_str());

	distance = std::atof(appCfg["camera.worldwindow.distance"].c_str());
    width = std::atof(appCfg["camera.worldwindow.width"].c_str());
    height = std::atof(appCfg["camera.worldwindow.height"].c_str());

    n = Vector(look,eye);
    n.normalize();

    u = upV.cross(n);
    u.normalize();

    v = n.cross(u);
}

void Camera::up(){
	Quaternion p = Quaternion(eye);
	Quaternion q = Quaternion(-1,u);
	Quaternion result = q*p*q.conjugate();

	eye = Point(result.b,result.c,result.d);

	n = Vector(look,eye);
	n.normalize();

	v = n.cross(u);

}

void Camera::down(){
	Quaternion p = Quaternion(eye);
	Quaternion q = Quaternion(1,u);
	Quaternion result = q*p*q.conjugate();

	eye = Point(result.b,result.c,result.d);

	n = Vector(look,eye);
	n.normalize();

	v = n.cross(u);

}

void Camera::left(){
	Quaternion p = Quaternion(eye);
	Quaternion q = Quaternion(-1,v);
	Quaternion result = q*p*q.conjugate();

	eye = Point(result.b,result.c,result.d);

	n = Vector(look,eye);
	n.normalize();

	u = upV.cross(n);
    u.normalize();

	v = n.cross(u);

}

void Camera::right(){
	Quaternion p = Quaternion(eye);
	Quaternion q = Quaternion(1,v);
	Quaternion result = q*p*q.conjugate();

	eye = Point(result.b,result.c,result.d);

	n = Vector(look,eye);
	n.normalize();

    u = upV.cross(n);
    u.normalize();

	v = n.cross(u);
}
