#include "cuboid.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid, squareC;
	double surface, volume;
	int issquare;
	
	set_size(&cuboid, 2, 4, 13);
	set_size(&squareC, 6, 6, 9);
	
	surface=calc_surface(&cuboid);
	volume=calc_volume(&cuboid);
	printf("Cuboid surface: %lf\n", surface);
	printf("Cuboid volume: %lf\n", volume);
	issquare=square(&cuboid);
		if(issquare){
			printf("The cuboid has square sides. :)\n");
		}
		else{
			printf("The cuboid doesn't have square sides. :(\n");
		}
	
	surface=calc_surface(&squareC);
	volume=calc_volume(&squareC);
	printf("Cuboid surface: %lf\n", surface);
	printf("Cuboid volume: %lf\n", volume);
	issquare=square(&squareC);
		if(issquare){
			printf("The cuboid has square sides. :)\n");
		}
		else{
			printf("The cuboid doesn't have square sides. :(\n");
		}
	
}