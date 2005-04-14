#ifndef __SDECCONTACTPHYSICS_HPP__
#define __SDECCONTACTPHYSICS_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "InteractionPhysics.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class SDECContactPhysics : public InteractionPhysics
{

	public : virtual ~SDECContactPhysics();

	public : Real kn;				// normal elastic constant.
	public : Real ks;				// shear elastic constant.
	public : Real initialKn;			// initial normal elastic constant.
	public : Real initialKs;			// initial shear elastic constant.
	public : Real equilibriumDistance;		// equilibrium distance
	public : Real initialEquilibriumDistance;	// initial equilibrium distance
	public : Vector3r prevNormal;			// unit normal of the contact plane.
	public : Vector3r normalForce;			// normal force applied on a DE
	public : Vector3r shearForce;			// shear force applied on a DE
	public : Real frictionAngle; 			// angle of friction, according to Coulumb criterion
	public : Real tangensOfFrictionAngle;

	REGISTER_CLASS_NAME(SDECContactPhysics);
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(SDECContactPhysics,false);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __SDECCONTACTPHYSICS_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

