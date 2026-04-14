#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <math.h>

#include <SDL2/SDL.h>


/**
 * Data of a circle object in Descartes coordinate system
 */
typedef struct Color{
	Uint8 r, g, b;
} Color;

Color random_color(void);
typedef struct Circle
{
	double x;
	double y;
	double radius;
	Color color;
	
	int steps;
	double angle_step;
	double max_segment_length;
} Circle;

typedef struct Screen{
	int width;
	int height;
	SDL_Window* window;
    SDL_Renderer* renderer;
} Screen;

typedef struct Point {
  int x;
  int y;
} Point;

typedef enum{
	MODE_STEP_COUNT,
	MODE_ANGLE_STEP,
	MODE_MAX_SEGMENT
} MODE;

/**
 * Set the data of the circle
 */
void set_circle_data(Circle* circle, double x, double y, double radius, Color c, int s, double a_s, double m_s_l);

void draw_circle(Screen* screen, Circle* circle, MODE mode);

/**
 * Calculate the area of the circle.
 */
double calc_circle_area(const Circle* circle);

#endif // CIRCLE_H
