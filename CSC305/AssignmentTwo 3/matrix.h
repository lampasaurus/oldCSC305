#ifndef MATRIX_H
#define MATRIX_H

/**
 *  @todo assignment two
 *  1. extend these matrix classes to support all the basic linear algebra functions
 *  (add, subtract, multiply)
 *  2. add convenience functions to create scale & rotation matrices around the available axes,
 *  and a translation matrix
 *  3. add functions to create the projection matrix versions.
 *  for perspective projection, this function should take the field of view, image ratio, near plane and far plane distance
 *  for orthographic projection it should take the left, right, top, bottom, near plane and far plane values
 *  4. add functions to create the view matrix using eye position, at position and the up vector
 */

/**
 *	@class	Matrix3x3
 *	@brief	3 by 3 Matrix class
 *	Homogenous 3x3 Matrix, onedimensional array (like opengl), column major
 *	|0 3 6|
 *	|1 4 7|
 *	|2 5 8|
 */
class Matrix3x3
{
public:

    float elements[9];/**< array storing the values of the matrix. */

    /**
     *	default constructor
     *	generates the identity matrix
     */
    Matrix3x3();

    /**
     *	generates the identity matrix
     */
    void loadIdentity();
    void invert();
    void add(Matrix3x3 added);
    void subtract(Matrix3x3 sub);
    void multiply(Matrix3x3 mult);
    void rotate(float degrees);

};

/**
 *	@class	Matrix4x4
 *	@brief	4 by 4 matrix
 *	Homogenous 4x4 Matrix, onedimensional array (like opengl), column major
 *	|0 4 8  12|
 *	|1 5 9  13|
 *	|2 6 10 14|
 *	|3 7 11 15|
 */
class Matrix4x4
{
public:

    float elements[16];	/**< array storing the values of the matrix. */

    /**
     *	default constructor
     *	generates the identity matrix
     */
    Matrix4x4();

    /**
     *	generates the identity matrix
     */
    void loadIdentity();
};

#endif // MATRIX_H
