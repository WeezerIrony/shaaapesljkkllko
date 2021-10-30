#pragma once
#include "Shapes.h"
#include <vector>

namespace Editor
{
	enum class command_type
	{
		translate = 0,
		rotate = 1,
		scale = 2,
		undo = 3
	};

	class Command
	{
	public:
		Command() = default;
		virtual void Execute() = 0;
		virtual void Revert() = 0;
		virtual command_type CommandType() = 0;
		void AddShape(Shape* shape);
	protected:
		std::vector<Shape*> shapes;
	};

	class Translate : public Command
	{
	public:
		Translate(Vector2 d): direction(d) {}
		virtual command_type CommandType() override { return command_type::translate; };
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		Vector2 direction;
	};

	class Rotate : public Command
	{
	public:
		Rotate(double a) : angle(a) {}
		virtual command_type CommandType() override { return command_type::rotate; };
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		double angle;
	};

	class Scale : public Command
	{
	public:
		Scale(Vector2 a) : axes(a) {}
		virtual command_type CommandType() override { return command_type::scale; };
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		Vector2 axes;
	};

	class Undo : public Command
	{
	public:
		virtual void Execute() override {};
		virtual void Revert() override {};
		virtual command_type CommandType() override { return command_type::undo; };
	};
}