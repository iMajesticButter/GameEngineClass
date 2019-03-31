//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "MeshHelper.h"

#include <MeshFactory.h>
#include <Vertex.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
namespace MeshHelper {
	// Create a colored mesh consisting of a single triangle using the Beta Framework.
	// Params:
	//   color0 = The color of vertex 0.
	//   color1 = The color of vertex 1.
	//   color2 = The color of vertex 2.
	// Returns:
	//	 A pointer to the newly created mesh.
	Mesh* CreateTriangleMesh(const Color& color0, const Color& color1, const Color& color2) {

		Vertex v[]{
			Vertex(Vector2D(-0.5, 0.5), color0),
			Vertex(Vector2D(-0.5, -0.5), color1),
			Vertex(Vector2D(0.5, 0), color2)
		};

		MeshFactory::GetInstance().AddTriangle(v[0], v[1], v[2]);

		return MeshFactory::GetInstance().EndCreate(MeshDrawMode::MDM_Triangles);

	}

	// Create a textured quad mesh using the Beta Framework.
	// Params:
	//   textureSize = The UV size of the mesh, in texture coordinates.
	//	 extents	 = The XY distance of the vertices from the origin.
	// Returns:
	//	 A pointer to the newly created mesh.
	Mesh* CreateQuadMesh(const Vector2D& textureSize, const Vector2D& extents) {

		Vertex v[]{
			Vertex(Vector2D(-extents.x, extents.y), Vector2D(0, 0)),
			Vertex(Vector2D(-extents.x, -extents.y), Vector2D(0, textureSize.y)),
			Vertex(Vector2D(extents.x, -extents.y), Vector2D(textureSize.x, textureSize.y)),
			Vertex(Vector2D(extents.x, extents.y), Vector2D(textureSize.x, 0))
		};

		MeshFactory::GetInstance().AddTriangle(v[0], v[1], v[2]);
		MeshFactory::GetInstance().AddTriangle(v[0], v[3], v[2]);

		return MeshFactory::GetInstance().EndCreate(MeshDrawMode::MDM_Triangles);

	}
}
//------------------------------------------------------------------------------
