# QuatCpp
Quaternion extension of LinearCpp embedded linear algebra library  
Written by Dan Oates (WPI Class of 2020)

### Description
This library adds quaternions to LinearCpp. The Quat class inherits from Vector<4> and has public fields for its w, x, y, and z components. Like LinearCpp, Quat operations are implemented with polymorphic expression classes to eliminate redundant copying and increase speed.

### API Summary
#### Quat Class
The Quat class has three constructors:
```
#include "QuatCpp.h"	// QuatCpp header file
float w, x, y, z;	// Quaternion components
Vector<3> axis;		// Rotation axis
float angle;		// Rotation angle

// Assign values...

Quat quat_unit;			// Unit quaternion [1, 0, 0, 0]
Quat quat_wxyz(w, x, y, z);	// Element constructor [w, x, y, z]
Quat quat_axis(axis, angle);	// Axis-angle constructor
```
The axis-angle constructor forms the quaternion which represents the rotation about the given axis unit vector by the given angle following right-hand convention. The Quat class has public w, x, y, and z fields:
```
Quat quat;
quat.w = 1.0f;
quat.x = 0.0f;
quat.y = 0.0f;
quat.z = 0.0f;
```
All appropriate-dimensioned vector and matrix operations from LinearCpp such as norm are also inherited.

#### Operators and Functions
The full list of library operators and functions added on-top of LinearCpp are shown below:
```
Quat conj(Quat q)				// Conjugation [w, -x, -y, -z]
Quat inv(Quat q)				// Inversion conj(q) / norm(q)^2
Quat operator*(Quat q1, Quat q2)		// Quaternion product q1 * q2
Vector<3> operator*(Quat q, Vector<3> v)	// Rotation of v by q
```
#### Circular Self-Assignment
The same circular self-assignment issue with LinearCpp (see [README](https://github.com/doates625/LinearCpp/blob/master/README.md)) also applies to the Quat class. For example:
```
Quat q1, q2;
Vector<3> v;

// Assign values...

q1 = q1 * q2;		// Incorrect
q1 = Quat(q1 * q2);	// Correct
v = q1 * v;		// Incorrect
v = Vector<3>(q1 * v);	// Correct
```

### Dependencies
[LinearCpp](https://github.com/doates625/LinearCpp)