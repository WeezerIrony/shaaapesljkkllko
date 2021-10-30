#include "Invoker.h"
#include <algorithm>

void Editor::Invoker::Undo()
{
	command_lists.back()->Revert();
	command_lists.pop_back();
}

void Editor::Invoker::AddShape(const std::string& name, Shape* shape)
{
	m_shapes[name] = shape;
}

void Editor::Invoker::Execute(Command* command, const std::string& shapeName)
{
	if (shapeName!="all")
	{
		auto iter = m_shapes.find(shapeName);
		if (iter!=m_shapes.end())
			command->AddShape(iter->second);
	}
	else
	{
		for (auto&& [name, shape] : m_shapes)
		{
			command->AddShape(shape);
		}
	}
	command->Execute();
	command_lists.push_back(command);
}
