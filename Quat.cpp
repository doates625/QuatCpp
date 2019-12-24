/**
 * @file Quat.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "Quat.h"
#include <LinearCpp.h>
#include <math.h>

/**
 * @brief Default union quaternion constructor
 */
Quat::Quat() : Quat(1.0f, 0.0f, 0.0f, 0.0f)
{
	return;
}

/**
 * @brief Element constructor
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
 * @brief Axis-angle constructor
 * @param axis Axis unit vector
 * @param angle Rotation angle (right-handed)
 */
Quat::Quat(const VectorExp<3>& axis, float angle)
{
	float angle_half = 0.5f * angle;
	float cos_ = cosf(angle_half);
	float sin_ = sinf(angle_half);
	this->w = cos_;
	this->x = sin_ * axis.get(0);
	this->y = sin_ * axis.get(1);
	this->z = sin_ * axis.get(2);
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

/**
 * @brief Quaternion multiplication (lhs * rhs)
 */
Quat operator*(const Quat& lhs, const Quat& rhs)
{
	Quat prod;
	prod.w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
	prod.x = lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y;
	prod.y = lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x;
	prod.z = lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w;
	return prod;
}

/**
 * @brief Returns rotation of vector v by unit quaternion q
 */
Vector<3> operator*(const Quat& quat, const Vector<3>& vec)
{
	// Quaternion products
	const float qxx = quat.x * quat.x;
	const float qyy = quat.y * quat.y;
	const float qzz = quat.z * quat.z;
	const float qwx = quat.w * quat.x;
	const float qwy = quat.w * quat.y;
	const float qwz = quat.w * quat.z;
	const float qxy = quat.x * quat.y;
	const float qxz = quat.x * quat.z;
	const float qyz = quat.y * quat.z;

	// Rotation matrix (1/2 scale)
	Matrix<3, 3> rot;
	rot(0, 0) = 0.5f - qyy - qzz;
	rot(1, 1) = 0.5f - qxx - qzz;
	rot(2, 2) = 0.5f - qxx - qyy;
	rot(0, 1) = qxy - qwz;
	rot(1, 0) = qxy + qwz;
	rot(0, 2) = qxz + qwy;
	rot(2, 0) = qxz - qwy;
	rot(1, 2) = qyz - qwx;
	rot(2, 1) = qyz + qwx;

	// Final result
	return 2.0f * (rot * vec);
}
