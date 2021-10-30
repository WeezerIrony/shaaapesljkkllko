#include "CommandReader.h"
#include <fstream>

void Editor::CommandReader::load(const std::string& path)
{
	std::string line, name;
	std::ifstream myfile(path);
	myfile >> line;
	if(line == "translate")
	{
		double x, y;
		myfile >> name >> x >> y;
		commands.emplace_back(new Translate({ x,y }), name);
	}
	if (line == "rotate")
	{
		double angle;
		myfile >> name >> angle;
		commands.emplace_back(new Rotate(angle), name);
	}
	if (line == "scale")
	{
		double x, y;
		myfile >> name >> x >> y;
		commands.emplace_back(new Scale({ x,y }), name);
	}
	if (line == "undo")
	{
		commands.emplace_back(new Undo(), "all");
	}
}
