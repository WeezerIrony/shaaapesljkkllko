#include "Commands.h"
namespace Editor
{
	void Command::AddShape(Shape* shape)
	{
		shapes.push_back(shape);
	}

	void Translate::Execute()
	{
		for (auto* s : shapes) {
			s->Translate(direction);
		}
	}

	void Translate::Revert()
	{
		for (auto* s : shapes) {
			s->Translate(Vector2(-direction.x, -direction.y));
		}
	}

	void Rotate::Execute()
	{
		for (auto* s : shapes) {
			s->Rotate(angle);
		}
	}

	void Rotate::Revert()
	{
		for (auto* s : shapes) {
			s->Rotate(-angle);
		}
	}

	void Scale::Execute()
	{
		for (auto* s : shapes) {
			s->Scale(axes);
		}
	}

	void Scale::Revert()
	{
		for (auto* s : shapes) {
			s->Scale(Vector2(1/axes.x, 1/axes.y));
		}
	}
}