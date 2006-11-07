/*************************************************************************
*  Copyright (C) 2004 by Janek Kozicki                                   *
*  cosurgi@berlios.de                                                    *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#include "LatticeBeamAngularSpring.hpp"


LatticeBeamAngularSpring::LatticeBeamAngularSpring() : InteractionPhysics()
{

	initialPlaneAngle	= 0;
//	planeAngle		= 0;
	lastCrossProduct	= Vector3r(0,0,0); // stupid value, zero is useless...
	initialOffPlaneAngle	= 0;
//	offPlaneAngle		= 0;
	planeSwap180		= false;
//	createIndex();
}


LatticeBeamAngularSpring::~LatticeBeamAngularSpring()
{

}

void LatticeBeamAngularSpring::registerAttributes()
{
	InteractionPhysics::registerAttributes();
	REGISTER_ATTRIBUTE(initialPlaneAngle);
//	REGISTER_ATTRIBUTE(planeAngle); // FIXME - can be calculated after deserialization
	REGISTER_ATTRIBUTE(lastCrossProduct);
	REGISTER_ATTRIBUTE(planeSwap180);
	REGISTER_ATTRIBUTE(initialOffPlaneAngle);
//	REGISTER_ATTRIBUTE(offPlaneAngle); // FIXME - can be calculated after deserialization
}

