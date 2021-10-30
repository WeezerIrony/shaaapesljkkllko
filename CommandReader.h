#pragma once
#include "Commands.h"

namespace Editor
{
	struct command_to final
	{
		command_to(Command* c, const std::string& n) : command(c), shape_name(n) {};
		Command* command;
		std::string shape_name;
	};

	class CommandReader final
	{
	public:
		std::vector<command_to> get_cmds() { return commands; };
		void load(const std::string& path);
	private:
		std::vector<command_to> commands;
	};
}