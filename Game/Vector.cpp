#include "Vector.h"
#define _USE_MATH_DEFINES
#include <cmath>

void Vector2::Set(float x_, float y_)
{
	this->x = x_;
	this->y = y_;
}

Vector2 Vector2::Add(Vector2* vec2)
{
	return{ this->x + vec2->x, this->y + vec2->y };
}

Vector2 Vector2::Sub(Vector2* vec2)
{
	return{ this->x - vec2->x, this->y - vec2->y };
}

Vector2 Vector2::Mul(float mul)
{
	return{ this->x * mul, this->y * mul };
}

Vector2 Vector2::Div(float div)
{
	return{ this->x / div, this->y / div };
}

Vector2 Vector2::Nomalize()
{
	float len = this->Length();
	return{ this->x / len,this->y / len };
}

float Vector2::Dot(Vector2* vec2)
{
	return ((this->x * vec2->x) + (this->y * vec2->y));
}

float Vector2::Cross(Vector2* vec2)
{
	return (this->x * vec2->y - vec2->x * this->y);
}

Vector2 Vector2::Rotate(float rad)
{
	return{ ((this->x * cosf(rad)) - (this->y * sinf(rad))),((this->x * sinf(rad)) + (this->y * cosf(rad))) };
}

float Vector2::Angle()
{
	return atan2f(this->y, this->x);
}

float Vector2::Angle2(Vector2* vec2)
{
	return atan2(vec2->y - this->y, vec2->x - this->x);
}

float Vector2::Length()
{
	return sqrtf(this->x * this->x + this->y * this->y);
}

float Vector2::LengthSquared()
{
	return (this->x * this->x) + (this->y * this->y);
}

float Vector2::LengthTo(Vector2* vec2)
{
	return sqrtf(LengthSquaredTo(vec2));
}

float Vector2::LengthSquaredTo(Vector2* vec2)
{
	return (vec2->x - this->x) * (vec2->x - this->x) + (vec2->y - this->y) * (vec2->y - this->y);
}

void Vector2::Decompose(Vector2* vec2, Vector2* outvec1, Vector2* outvec2)
{
	float angle_rota = vec2->Angle();
	float vec_rota = Angle();
	float diff_rota = vec_rota - angle_rota;
	float vec_length = Length();

	float vec_a_length = vec_length * cosf(diff_rota);
	float vec_b_length = vec_length * sinf(diff_rota);
	float vec_a_rota = angle_rota;
	float vec_b_rota = angle_rota + (float)M_PI_2;

	*outvec1 = { vec_a_length * cosf(vec_a_rota), vec_a_length * sinf(vec_a_rota) };
	*outvec2 = { vec_b_length * cosf(vec_b_rota), vec_b_length * sinf(vec_b_rota) };
}
bool Vector2::CrossPoint(Vector2* vec1_gool, Vector2* vec2_start, Vector2* vec2_gool, Vector2* output)
{
	Vector2 p1 = { this->x,this->y };
	Vector2 p2 = *vec1_gool;
	Vector2 p3 = *vec2_start;
	Vector2 p4 = *vec2_gool;

	float d = (p2.x - p1.x)*(p4.y - p3.y) - (p2.y - p1.y)*(p4.x - p3.x);
	if (d == 0)
	{
		return FALSE;
	}
	float u = ((p3.x - p1.x)*(p4.y - p3.y) - (p3.y - p1.y)*(p4.x - p3.x)) / d;
	float v = ((p3.x - p1.x)*(p2.y - p1.y) - (p3.y - p1.y)*(p2.x - p1.x)) / d;

	// このブロックを消すと、直線同士の交点になります
	{
		if (u < 0.0 || u > 1.0)
		{
			return FALSE;
		}
		if (v < 0.0 || v > 1.0)
		{
			return FALSE;
		}
	}
	*output = { p1.x + u * (p2.x - p1.x) ,p1.y + u * (p2.y - p1.y) };

	return TRUE;
}