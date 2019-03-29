//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Archetypes.h"

#include "GameObject.h"
#include "Space.h"
#include "SpriteSource.h"
#include "MeshHelper.h"

#include <Mesh.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

namespace Archetypes {

	// Create the ship game object.
	// Params:
	//   mesh  = The mesh to use for the object's sprite.
	// Returns:
	//	 A pointer to the newly constructed game object
	GameObject* CreateShip(Mesh* mesh) {

		GameObject* ship = new GameObject("Ship");


		

	}

	// Create the archetype for the bullet object.
	// Params:
	//   mesh  = The mesh to use for the object's sprite.
	// Returns:
	//	 A pointer to the newly constructed game object
	GameObject* CreateBulletArchetype(Mesh* mesh) {

	}

	// Create the monkey game object.
	// Params:
	//   mesh  = The mesh to use for the object's sprite.
	//   spriteSource = The sprite source to use for the object.
	// Returns:
	//	 A pointer to the newly constructed game object
	GameObject* CreateMonkey(Mesh* mesh, SpriteSource* spriteSource) {

	}

}