#include "cuboid.h"

#include <math.h>

void set_size(Cuboid* cuboid, double x, double y, double z)
{
	//ellenőrzött beolvasás
	if(x>0.0){
		cuboid->x = x;
	} else {
		cuboid->x = NAN;
	}
	
	if(y>0.0){
		cuboid->y = y;
	} else {
		cuboid->y = NAN;
	}
	
	if(z>0.0){
		cuboid->z = z;
	} else {
		cuboid->z = NAN;
	}	
}

double calc_volume(const Cuboid* c){
	return (c->x)*(c->y)*(c->z);
}

double calc_surface(const Cuboid* c){
	double sideA, sideB, sideC;
	sideA=(c->x) * (c->y);
	sideB=(c->y) * (c->z);
	sideC=(c->x)*(c->z);
	return 2*(sideA+sideB+sideC);
}

int square(const Cuboid* c){
	if(((c->x) == (c->y)) || ((c->x) == (c->z)) || ((c->y) == (c->z)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
