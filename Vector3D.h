#pragma once

class Vector3D{
public:
	Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
	bool operator==(Vector3D const& vec)
	{
		if (x == vec.x && y == vec.y && z == vec.z)
			return true;
		else
			return false;
	}

private:
	double x, y, z;
};
