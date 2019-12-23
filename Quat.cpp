/**
 * @file Quat.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "Quat.h"

/**
 * @brief Default union quaternion constructor
 */
Quat::Quat() : Quat(1.0f, 0.0f, 0.0f, 0.0f)
{
	return;
}

/**
 * @brief Quaternion constructor
 * @param w W-component
 * @param x X-component
 * @param y Y-component
 * @param z Z-component
 */
Quat::Quat(float w, float x, float y, float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

/**
 * @brief Vector expression copy constructor
 */
Quat::Quat(const VectorExp<4>& vec)
{
	(*this) = vec;
}

/**
 * @brief Assignment operator
 * @return Self-reference
 */
Quat& Quat::operator=(const VectorExp<4>& vec)
{
	if (this != &vec)
	{
		this->w = vec.get(0);
		this->x = vec.get(1);
		this->y = vec.get(2);
		this->z = vec.get(3);
	}
	return *this;
}

/**
 * @brief Gets w component
 */
float Quat::get_w() const
{
	return w;
}

/**
 * @brief Gets x component
 */
float Quat::get_x() const
{
	return x;
}

/**
 * @brief Gets y component
 */
float Quat::get_y() const
{
	return y;
}

/**
 * @brief Gets z component
 */
float Quat::get_z() const
{
	return z;
}

/**
 * @brief Returns true to indicate evaluation
 */
bool Quat::evaluated() const
{
	return true;
}
