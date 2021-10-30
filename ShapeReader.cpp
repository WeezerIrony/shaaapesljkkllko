#include "ShapeReader.h"
#include <fstream>

void Editor::ShapeReader::load(const std::string& path)
{
	std::string line, name;
	std::ifstream myfile(path);
	myfile >> line;
	if (line == "triangle")
	{
		double x1, y1, x2, y2, x3, y3;
		myfile >> name >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		shapes.emplace_back(new Triangle({ x1,y1 }, { x2, y2 }, { x3, y3 }), name);
	}
	if (line == "rectangle")
	{
		double x1, y1, x2, y2;
		myfile >> name >> x1 >> y1 >> x2 >> y2;
		shapes.emplace_back(new Rectangle({x1,y1}, {x2,y2}), name);
	}
	if (line == "Ellipse")
	{
		double xc, yc, major, minor;
		myfile >> name >> xc >> yc >> major >> minor;
		shapes.emplace_back(new Ellipse({ xc,yc }, major, minor), name);
	}
}
