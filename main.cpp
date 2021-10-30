#include "ShapeReader.h"
#include "CommandReader.h"
#include "Invoker.h"
using namespace Editor;

int main()
{
	ShapeReader in_shapes;
	CommandReader in_commands;
	Invoker in_voker;
	in_shapes.load("C:\\Users\\Billy Scranner\\source\\repos\\shapes\\shapes\\shapes.txt");
	in_commands.load("C:\\Users\\Billy Scranner\\source\\repos\\shapes\\shapes\\commands.txt");
	for (auto n_s : in_shapes.get_shapes())
	{
		in_voker.AddShape(n_s.shape_name, n_s.shape);
	}
	for (auto c_t : in_commands.get_cmds())
	{
		if (c_t.command->CommandType() != command_type::undo)
			in_voker.Execute(c_t.command, c_t.shape_name);
		else
			in_voker.Undo();
	}
	return 0;
}