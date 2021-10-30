#include "Shapes.h"
namespace Editor
{
	void Triangle::Translate(Vector2 direction)
	{
		p1.x += direction.x;
		p2.x += direction.x;
		p3.x += direction.x;
		p1.y += direction.y;
		p2.y += direction.y;
		p3.y += direction.y;
	}

	void Triangle::Rotate(double angle)
	{
	}

	void Triangle::Scale(Vector2 axes)
	{
	}

	void Rectangle::Translate(Vector2 direction)
	{
		p1.x += direction.x;
		p2.x += direction.x;
		p1.y += direction.y;
		p2.y += direction.y;
	}

	void Rectangle::Rotate(double angle)
	{
	}

	void Rectangle::Scale(Vector2 axes)
	{
	}

	void Ellipse::Translate(Vector2 direction)
	{
		center.x += direction.x;
		center.y += direction.y;
	}

	void Ellipse::Rotate(double angle)
	{
	}

	void Ellipse::Scale(Vector2 axes)
	{
		major *= axes.x;
		minor *= axes.y;
	}
}