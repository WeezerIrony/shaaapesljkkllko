#include "Shapes.h"
#include <vector>

namespace Editor
{
	class Command
	{
	public:
		Command() = default;
		virtual void Execute() = 0;
		virtual void Revert() = 0;
		void AddShape(Shape* shape);
	protected:
		std::vector<Shape*> shapes;
	};

	class Translate : public Command
	{
	public:
		Translate(Vector2 d): direction(d) {}
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		Vector2 direction;
	};

	class Rotate : public Command
	{
	public:
		Rotate(float a) : angle(a) {}
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		float angle;
	};

	class Scale : public Command
	{
	public:
		Scale(Vector2 a) : axes(a) {}
		virtual void Execute() override;
		virtual void Revert() override;
	private:
		Vector2 axes;
	};
}