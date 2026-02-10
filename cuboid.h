#ifndef CUBOID_H
#define CUBOID_H

typedef struct Cuboid
{	double x;
	double y;
	double z;
} Cuboid;

void set_size(Cuboid* cuboid, double x, double y, double z);

double calc_volume(const Cuboid* c);

double calc_surface(const Cuboid* c);

int square(const Cuboid* c);

#endif