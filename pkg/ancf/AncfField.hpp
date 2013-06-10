#if 0
#pragma once

#include<woo/core/Field.hpp>
#include<woo/core/Scene.hpp>

#include<woo/dem/Particle.hpp>


struct AncfField: public Field{
	WOO_CLASS_BASE_DOC_ATTRS_CTOR_PY(AncfField,Field,"Field for ANCF (absolute nodal coordinate formulation) finite elements (highly experimental)",
	);
}
WOO_REGISTER_OBJECT(AncfField);

struct AncfData: public NodeData{
	WOO_CLASS_BASE_DOC_ATTRS_CTOR_PY(AncfData,NodeData,"Nodal data for ANCF",
		// TODO: perhaps create aderived class, so that only elements who need sloe vector store them
		((Vector3r,drdx,Vector3r::Zero(),,"X slope vector"))
		((Vector3r,drdy,Vector3r::Zero(),,"Y slope vector"))
		((Vector3r,drdz,Vector3r::Zero(),,"Z slope vector"))
		, /*ctor*/
		, /*py*/ .def("_getDataOnNode",&Node::pyGetData<AncfData>).staticmethod("_getDataOnNode").def("_setDataOnNode",&Node::pySetData<AncfData>).staticmethod("_setDataOnNode");
	);
};
WOO_REGISTER_OBJECT(AncfData);

template<> struct NodeData::Index<AncfData>{enum{value=Node::ST_ANCF};};

struct AncfElt: public Shape{
	//virtual getNumDofs(){ throw std::invalid_argument("getNumDofs() called on abstract AncfElt object."); }
	//virtual getShapeFuncMatrix(Real,){ throw std::invalid_argument("getNumDofs() called on abstract AncfElt object."); }
	WOO_CLASS_BASE_DOC_ATTRS_CTOR(AncfElt,Shape,"Abstract ancf element.",
		/* attrs */, /*ctor*/createIndex();
	);
	REGISTER_CLASS_INDEX(AncfElt,Shape)
};
WOO_REGISTER_OBJECT(AncfElt);

struct AncfBeam2n: public AncfElt{
	MatrixXr getShapeFunctionMatrix(const Vector3r& pt);
	WOO_CLASS_BASE_DOC_ATTRS_CTOR(AncfBeam2n,AncfElt,"Ancf beam with 2 nodes and 24 dofs, see [Yakoub2001]",
		/*attrs*/
		((Real,l,NaN,,"Beam length (used in shape function matrix computations)"))
		,/*ctor*/createIndex();
	);
	REGISTER_CLASS_INDEX(AncfBeam2n);
};
WOO_REGISTER_OBJECT(AncfBeam2n);
#endif
