#pragma once
#include "Shapes.h"
#include <vector>

namespace Editor
{
	struct named_shape final
	{
		named_shape(Shape* c, const std::string& n) : shape(c), shape_name(n) {};
		Shape* shape;
		std::string shape_name;
	};

	class ShapeReader final
	{
	public:
		std::vector<named_shape> get_shapes() { return shapes; };
		void load(const std::string& path);
	private:
		std::vector<named_shape> shapes;
	};
}