//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Archetypes.h"

#include "GameObject.h"
#include "Space.h"
#include "SpriteSource.h"
#include "MeshHelper.h"
#include "Transform.h"
#include "Physics.h"
#include "Sprite.h"
#include "Animation.h"
#include "Ship.h"

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
	GameObject* CreateShip() {

		GameObject* ship = new GameObject("Ship");

		Transform* transform = new Transform(0, 0);
		Physics* physics = new Physics();

		Mesh* mesh = MeshHelper::CreateQuadMesh(Vector2D(1 / 1, 1 / 1), Vector2D(1 * 1, 1 * 1));

		SpriteSource* spriteSource = new SpriteSource("SpaceShip.png", 1, 1);

		Sprite* sprite = new Sprite(mesh, Colors::White, spriteSource, 0);

		Animation* animation = new Animation();

		Behaviors::Ship* shipController = new Behaviors::Ship();


		ship->AddComponent((Component*)transform);
		ship->AddComponent((Component*)physics);
		ship->AddComponent((Component*)sprite);
		ship->AddComponent((Component*)animation);
		ship->AddComponent((Component*)shipController);

		return ship;

	}

	// Create the archetype for the bullet object.
	// Params:
	//   mesh  = The mesh to use for the object's sprite.
	// Returns:
	//	 A pointer to the newly constructed game object
	GameObject* CreateBulletArchetype(Mesh* mesh) {
		UNREFERENCED_PARAMETER(mesh);
		return nullptr;
	}

	// Create the monkey game object.
	// Params:
	//   mesh  = The mesh to use for the object's sprite.
	//   spriteSource = The sprite source to use for the object.
	// Returns:
	//	 A pointer to the newly constructed game object
	GameObject* CreateMonkey(Mesh* mesh, SpriteSource* spriteSource) {
		UNREFERENCED_PARAMETER(mesh);
		UNREFERENCED_PARAMETER(spriteSource);
		return nullptr;
	}

}