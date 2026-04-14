#include "circle.h"

void set_circle_data(Circle* circle, double x, double y, double radius,
					 Color c, int s, double a_s, double m_s_l)
{
	circle->x = x;
	circle->y = y;
	if (radius > 0.0) {
		circle->radius = radius;
	} else {
		circle->radius = 30 + (rand() % 100);
	}
	circle->color.r = c.r;
	circle->color.g = c.g;
	circle->color.b = c.b;

	if(s>0){
		circle->steps = s;
	} else {
		circle->steps = 50;
	}

	if(a_s > 0){
		circle->angle_step = a_s;
	} else {
		circle->angle_step = 0.01;
	}

	if(m_s_l > 0){
		circle->max_segment_length = m_s_l;
	} else {
		circle->max_segment_length = 7;
	}
}

double calc_circle_area(const Circle* circle)
{
	double area = circle->radius * circle->radius * M_PI;
	return area;
}

void draw_circle(Screen* screen, Circle* circle, MODE mode){
	SDL_SetRenderDrawColor(screen->renderer,
    circle->color.r,
    circle->color.g,
    circle->color.b,
    255);

	double x_0, y_0, x, y;
  	double phi, delta;
	switch(mode){
		case MODE_STEP_COUNT: delta = 2*M_PI / circle->steps; break;

		case MODE_ANGLE_STEP: delta = circle->angle_step; break;

		case MODE_MAX_SEGMENT: delta = circle->max_segment_length / circle->radius; break;
		
		default: delta = 0.01;
	}

  phi = 0;

  x_0 = circle->radius * cos(phi) + circle->x;
  y_0 = circle->radius * sin(phi) + circle->y;

  while (phi < 2 * M_PI) {
    Point p_0;
    Point p;
    phi += delta;
    x = circle->radius * cos(phi) + circle->x;
    y = circle->radius * sin(phi) + circle->y;
    p_0.x = x_0;
    p_0.y = y_0;
    p.x = x;
    p.y = y;
	SDL_RenderDrawLine(screen->renderer, p_0.x, p_0.y, p.x, p.y);
    x_0 = x;
    y_0 = y;
  }
}