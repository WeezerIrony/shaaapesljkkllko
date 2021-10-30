#pragma once
#include "Math.h"
#include <string>

namespace Editor
{
	class Shape
	{
	public:
		virtual void Translate(Vector2 direction) = 0;
		virtual void Rotate(double angle) = 0;
		virtual void Scale(Vector2 axes) = 0;
	};

	class Triangle : public Shape
	{
	public:
		Triangle(Vector2 po1, Vector2 po2, Vector2 po3) : p1(po1), p2(po2), p3(po3) {}
		virtual void Translate(Vector2 direction) override;
		virtual void Rotate(double angle) override;
		virtual void Scale(Vector2 axes) override;
	private:
		Vector2 p1;
		Vector2 p2;
		Vector2 p3;
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle(Vector2 po1, Vector2 po2) : p1(po1), p2(po2) {}
		virtual void Translate(Vector2 direction) override;
		virtual void Rotate(double angle) override;
		virtual void Scale(Vector2 axes) override;
	private:
		Vector2 p1;
		Vector2 p2;
	};

	class Ellipse : public Shape
	{
	public:
		Ellipse(Vector2 c, double mi, double ma) : center(c), minor(mi), major(ma) {}
		virtual void Translate(Vector2 direction) override;
		virtual void Rotate(double angle) override;
		virtual void Scale(Vector2 axes) override;
	private:
		Vector2 center;
		double minor;
		double major;
	};
}