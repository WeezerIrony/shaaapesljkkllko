#pragma once
#include "Shapes.h"
#include "Commands.h"
#include <unordered_map>

namespace Editor
{
	class Invoker final
	{
	public:
		void Undo();
		void AddShape(const std::string& name, Shape* shape);
		void Execute(Command* command, const std::string& shapeName);
	private:
		std::unordered_map<std::string, Shape*> m_shapes;
		std::vector<Command*> command_lists;
	};
}