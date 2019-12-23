/**
 * @file QuatMul.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuatMul.h"

/**
 * @brief Constructor (lhs * rhs)
 */
QuatMul::QuatMul(const QuatExp& lhs, const QuatExp& rhs) :
	lhs_ptr(&lhs),
	rhs_ptr(&rhs)
{
	// Conditionally copy lhs
	if (!lhs.evaluated())
	{
		lhs_copy = lhs;
		lhs_ptr = &lhs_copy;
	}

	// Conditionally copy rhs
	if (!rhs.evaluated())
	{
		rhs_copy = rhs;
		rhs_ptr = &rhs_copy;
	}
}

/**
 * @brief Gets w component
 */
float QuatMul::get_w() const
{
	return
		lhs_ptr->get_w() * rhs_ptr->get_w()
		- lhs_ptr->get_x() * rhs_ptr->get_x()
		- lhs_ptr->get_y() * rhs_ptr->get_y()
		- lhs_ptr->get_z() * rhs_ptr->get_z();
}

/**
 * @brief Gets x component
 */
float QuatMul::get_x() const
{
	return
		lhs_ptr->get_w() * rhs_ptr->get_x()
		+ lhs_ptr->get_x() * rhs_ptr->get_w()
		+ lhs_ptr->get_y() * rhs_ptr->get_z()
		- lhs_ptr->get_z() * rhs_ptr->get_y();
}

/**
 * @brief Gets y component
 */
float QuatMul::get_y() const
{
	return
		lhs_ptr->get_w() * rhs_ptr->get_y()
		- lhs_ptr->get_x() * rhs_ptr->get_z()
		+ lhs_ptr->get_y() * rhs_ptr->get_w()
		+ lhs_ptr->get_z() * rhs_ptr->get_x();
}

/**
 * @brief Gets z component
 */
float QuatMul::get_z() const
{
	return
		lhs_ptr->get_w() * rhs_ptr->get_z()
		+ lhs_ptr->get_x() * rhs_ptr->get_y()
		- lhs_ptr->get_y() * rhs_ptr->get_x()
		+ lhs_ptr->get_z() * rhs_ptr->get_w();
}

/**
 * @brief Quaternion multiplication (lhs * rhs)
 */
QuatMul operator*(const QuatExp& lhs, const QuatExp& rhs)
{
	return QuatMul(lhs, rhs);
}
