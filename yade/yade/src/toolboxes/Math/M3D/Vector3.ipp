/***************************************************************************
 *   Copyright (C) 2004 by Olivier Galizzi                                 *
 *   olivier.galizzi@imag.fr                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3::Vector3 () : Serializable()
{
    // For efficiency in construction of large arrays of vectors, the
    // default constructor does not initialize the vector.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3::Vector3 (float vx, float vy, float vz) : Serializable()
{
    x = vx;
    y = vy;
    z = vz;
   // refs[0]=&x;
   // refs[1]=&y;
  //  refs[2]=&z;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3::Vector3 (float coord[3]) : Serializable()
{
    x = coord[0];
    y = coord[1];
    z = coord[2];
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3::Vector3 (const Vector3& v) : Serializable()
{
    x = v.x;
    y = v.y;
    z = v.z;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3& Vector3::operator= (const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline bool Vector3::operator== (const Vector3& v) const
{
    if ( FUZZ == 0.0f )
        return x == v.x && y == v.y && z == v.z;
    else
		return fabs(x - v.x) <= FUZZ && fabs(y - v.y) <= FUZZ && fabs(z - v.z) <= FUZZ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline bool Vector3::operator!= (const Vector3& v) const
{
    if ( FUZZ == 0.0f )
        return x != v.x || y != v.y || z != v.z;
    else
        return fabs(x - v.x) > FUZZ || fabs(y - v.y) > FUZZ || fabs(z - v.z) > FUZZ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline float& Vector3::operator[] (int i)
{
  // return ((float*)this)[i];
  // return *((&x)+i);
  //return (&x)[i];

//  return refs[i];

	//return *(const_cast<float*>(v+i));
	return v[i];
}

inline const float& Vector3::operator[] (int i) const
{
  // return ((float*)this)[i];
  // return *((&x)+i);
  //return (&x)[i];

//  return refs[i];

	//return *(const_cast<float*>(v+i));
	return v[i];
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3::operator float* ()
{
    //return (float*)this;
    return v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator+ (const Vector3& v) const
{
    return Vector3(x+v.x,y+v.y,z+v.z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator- (const Vector3& v) const
{
    return Vector3(x-v.x,y-v.y,z-v.z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator* (float f) const
{
    return Vector3(f*x,f*y,f*z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator/ (float f) const
{
    if ( f != 0.0f )
    {
        float invF = 1.0f/f;
        return Vector3(invF*x,invF*y,invF*z);
    }
    else
        return Vector3(Constants::MAX_FLOAT,Constants::MAX_FLOAT,Constants::MAX_FLOAT);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::operator- () const
{
    return Vector3(-x,-y,-z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 operator* (float f, const Vector3& v)
{
  return Vector3(f*v.x,f*v.y,f*v.z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3& Vector3::operator+= (const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3& Vector3::operator-= (const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3& Vector3::operator*= (float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3& Vector3::operator/= (float f)
{
    if ( f != 0.0f )
    {
        float invF = 1.0f/f;
        x *= invF;
        y *= invF;
        z *= invF;
    }
    else
    {
        x = Constants::MAX_FLOAT;
        y = Constants::MAX_FLOAT;
        z = Constants::MAX_FLOAT;
    }

    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline float Vector3::squaredLength () const
{
    return x*x + y*y + z*z;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline float Vector3::length () const
{
    return sqrt(x*x + y*y + z*z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline float Vector3::dot (const Vector3& v) const
{
    return x*v.x + y*v.y + z*v.z;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::cross (const Vector3& v) const
{
    return Vector3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::multTerm (const Vector3& v) const
{
	return Vector3(x*v.x,y*v.y,z*v.z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::inverse (float )
{
	return Vector3(1.0/x,1.0/y,1.0/z);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Vector3 Vector3::unitCross (const Vector3& v) const
{
    Vector3 res(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
    res.unitize();
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

