#include "Invoker.h"
#include <algorithm>

void Editor::Invoker::Undo()
{
	command_lists.back()->Revert();
	command_lists.pop_back();
}

void Editor::Invoker::AddShape(std::string name, Shape* shape)
{
	m_shapes[name] = shape;
}

void Editor::Invoker::Execute(Command* command, std::string shapeName)
{
	if (!shapeName.empty())
	{
		command->AddShape(m_shapes[shapeName]);
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
