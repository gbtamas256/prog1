/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp ` fltk-config --ldflags --use-images` -o a2.out
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include "./GUI/Window.h"

#include <string>

using namespace Graph_lib;

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
}
