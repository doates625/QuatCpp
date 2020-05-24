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
 * @param w_ W-component
 * @param x_ X-component
 * @param y_ Y-component
 * @param z_ Z-component
 */
Quat::Quat(float w_, float x_, float y_, float z_)
{
	w() = w_;
	x() = x_;
	y() = y_;
	z() = z_;
}

/**
 * @brief Axis-angle constructor
 * @param axis Axis unit vector
 * @param angle Rotation angle (right-handed)
 */
Quat::Quat(const MatrixExp<3, 1>& axis, float angle)
{
	float angle_half = 0.5f * angle;
	float cos_ = cosf(angle_half);
	float sin_ = sinf(angle_half);
	w() = cos_;
	x() = sin_ * axis.get(0, 0);
	y() = sin_ * axis.get(1, 0);
	z() = sin_ * axis.get(2, 0);
}

/**
 * @brief Matrix expression copy constructor
 */
Quat::Quat(const MatrixExp<4, 1>& vec)
{
	(*this) = vec;
}

/**
 * @brief Assignment operator
 * @return Self-reference
 */
Quat& Quat::operator=(const MatrixExp<4, 1>& vec)
{
	if (this != &vec)
	{
		w() = vec.get(0, 0);
		x() = vec.get(1, 0);
		y() = vec.get(2, 0);
		z() = vec.get(3, 0);
	}
	return *this;
}

/**
 * @brief Gets reference to w component
 */
float& Quat::w()
{
	return (*this)(0);
}

/**
 * @brief Gets reference to x component
 */
float& Quat::x()
{
	return (*this)(1);
}

/**
 * @brief Gets reference to y component
 */
float& Quat::y()
{
	return (*this)(2);
}

/**
 * @brief Gets reference to z component
 */
float& Quat::z()
{
	return (*this)(3);
}

/**
 * @brief Quaternion multiplication (lhs * rhs)
 */
Quat operator*(const MatrixExp<4, 1>& lhs, const MatrixExp<4, 1>& rhs)
{
	// LHS elements
	const float lhs_w = lhs.get(0, 0);
	const float lhs_x = lhs.get(1, 0);
	const float lhs_y = lhs.get(2, 0);
	const float lhs_z = lhs.get(3, 0);

	// RHS elements
	const float rhs_w = rhs.get(0, 0);
	const float rhs_x = rhs.get(1, 0);
	const float rhs_y = rhs.get(2, 0);
	const float rhs_z = rhs.get(3, 0);

	// Quaternion product
	Quat prod;
	prod.w() = lhs_w * rhs_w - lhs_x * rhs_x - lhs_y * rhs_y - lhs_z * rhs_z;
	prod.x() = lhs_w * rhs_x + lhs_x * rhs_w + lhs_y * rhs_z - lhs_z * rhs_y;
	prod.y() = lhs_w * rhs_y - lhs_x * rhs_z + lhs_y * rhs_w + lhs_z * rhs_x;
	prod.z() = lhs_w * rhs_z + lhs_x * rhs_y - lhs_y * rhs_x + lhs_z * rhs_w;
	return prod;
}

/**
 * @brief Returns rotation of vector by quaternion
 */
Vector<3> operator*(const MatrixExp<4, 1>& quat, const MatrixExp<3, 1>& vec)
{
	// Quaternion elements
	const float q_w = quat.get(0, 0);
	const float q_x = quat.get(1, 0);
	const float q_y = quat.get(2, 0);
	const float q_z = quat.get(3, 0);

	// Quaternion products
	const float q_xx = q_x * q_x;
	const float q_yy = q_y * q_y;
	const float q_zz = q_z * q_z;
	const float q_wx = q_w * q_x;
	const float q_wy = q_w * q_y;
	const float q_wz = q_w * q_z;
	const float q_xy = q_x * q_y;
	const float q_xz = q_x * q_z;
	const float q_yz = q_y * q_z;

	// Rotation matrix (1/2 scale)
	Matrix<3, 3> rot;
	rot(0, 0) = 0.5f - q_yy - q_zz;
	rot(1, 1) = 0.5f - q_xx - q_zz;
	rot(2, 2) = 0.5f - q_xx - q_yy;
	rot(0, 1) = q_xy - q_wz;
	rot(1, 0) = q_xy + q_wz;
	rot(0, 2) = q_xz + q_wy;
	rot(2, 0) = q_xz - q_wy;
	rot(1, 2) = q_yz - q_wx;
	rot(2, 1) = q_yz + q_wx;

	// Final result
	return 2.0f * (rot * vec);
}
