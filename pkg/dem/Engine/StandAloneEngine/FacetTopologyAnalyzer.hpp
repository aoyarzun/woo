// 2009 © Václav Šmilauer <eudoxos@arcig.cz>
#pragma once
#include<yade/core/StandAloneEngine.hpp>
/*! Initializer for filling adjacency geometry data for facets.
 *
 * Common vertices and common edges are identified and mutual angle between facet faces
 * is written to InteractingFacet instances.
 * If facets don't move with respect to each other, this must be done only at the beginning.
 */
class FacetTopologyAnalyzer: public StandAloneEngine{
	struct VertexData{
		VertexData(body_id_t _id, int _vertexNo, Vector3r _pos, Real _coord): id(_id), vertexNo(_vertexNo), coord(_coord), pos(_pos){index=3*id+vertexNo; isLowestIndex=true;}
		//! Facet (body id) that we represent
		body_id_t id;
		//! vertex number within this Facet
		int vertexNo;
		//! projected coordinate along projectionAxis
		Real coord;
		//! global coordinates
		Vector3r pos;
		//! index of this vertex (canonical ordering)
		size_t index;
		//! is this vertex the first one in the "identity" graph?
		bool isLowestIndex;
		//! vertices that are "identical" with this one, but have higer indices
		vector<shared_ptr<VertexData> > nextIdentical;
	};
	struct VertexComparator{
		bool operator()(const shared_ptr<VertexData>& v1, const shared_ptr<VertexData>& v2){return v1->coord<v2->coord;}
	};

	public:
		//! Axis along which to do the initial vertex sort
		Vector3r projectionAxis;
		//! maximum distance of "identical" vertices, relative to maximum facet size
		Real relTolerance;
	void action(MetaBody*); 
	FacetTopologyAnalyzer(): projectionAxis(Vector3r::UNIT_X), relTolerance(1e-4) {}
	DECLARE_LOGGER;
	REGISTER_CLASS_AND_BASE(FacetTopologyAnalyzer,StandAloneEngine);
	REGISTER_ATTRIBUTES(StandAloneEngine, /* none */);
};
REGISTER_SERIALIZABLE(FacetTopologyAnalyzer);



