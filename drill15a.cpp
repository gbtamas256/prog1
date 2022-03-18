/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp ` fltk-config --ldflags --use-images` -o a2.out
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include "./GUI/Window.h"

#include <string>

using namespace Graph_lib;

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x)+slope(x); }

int main(){

	Point orig {300,300};
	Simple_window win {Point{100,100}, 600, 600, "Function graphs"};
	
	Axis x(Axis::x, orig, 400, 20, "1 = = 20 pixels");
	Axis y(Axis::y, orig, 400, 20, "1 = = 20 pixels");
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);

	win.wait_for_button();
	
	int xmax = 600;
	int ymax = 400;
	int x_orig = xmax/2;
	int y_orig = ymax/2;
	Point orig2 {x_orig,y_orig};
	int r_min = -10;
	int r_max = 11;
	int n_points = 400;
	int y_scale = 20;
	int x_scale = 20;
	
	Function s {one,r_min,r_max,orig2,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,orig2,n_points,x_scale,y_scale};
	Text t(Point{75, 300}, "x/2");
	Function s3 {square,r_min,r_max,orig2,n_points,x_scale,y_scale};
	Function s4 {cos,r_min,r_max,orig2,n_points,x_scale,y_scale};
	s4.set_color(Color::blue);
	Function s5 {sloping_cos, r_min,r_max,orig,400,30,30};
	win.attach(s);
	win.attach(s2);
	win.attach(t);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.wait_for_button();
}























