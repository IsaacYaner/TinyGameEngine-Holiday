#pragma once
#include "Fairy.h"
class Camera :	public Fairy
{
public:
	Camera();
	~Camera();
};

class PixelCamera : public Camera
{
public:
	PixelCamera();
	~PixelCamera();
};
