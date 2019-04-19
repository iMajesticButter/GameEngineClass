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
#include "ColliderCircle.h"
#include "ColliderRectangle.h"
#include "ColliderPoint.h"
#include "ColorChange.h"
#include "EdgeLoop.h"

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
	GameObject* CreateShip(Mesh* mesh, SpriteSource* spriteSource) {

		GameObject* ship = new GameObject("Ship");

		Transform* transform = new Transform(0, 0);
		//transform->SetScale(Vector2D(10, 10));
		Physics* physics = new Physics();

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



	GameObject* CreateCircle(Mesh* mesh, SpriteSource* spriteSource, Vector2D pos, Vector2D vel, float radius) {
		Transform* transform = new Transform(pos, Vector2D(2*radius, 2*radius));
		Sprite* sprite = new Sprite(mesh, Colors::Yellow, spriteSource);
		Physics* physics = new Physics();
		physics->SetVelocity(vel);
		ColliderCircle* col = new ColliderCircle(radius);
		Behaviors::ColorChange* colorChange = new Behaviors::ColorChange(Colors::Yellow, Colors::Red);
		Behaviors::EdgeLoop* edgeLoop = new Behaviors::EdgeLoop();

		GameObject* circle = new GameObject("circle");
		circle->AddComponent((Component*)transform);
		circle->AddComponent((Component*)sprite);
		circle->AddComponent((Component*)physics);
		circle->AddComponent((Component*)col);
		circle->AddComponent((Component*)colorChange);
		circle->AddComponent((Component*)edgeLoop);

		return circle;
	}

	GameObject* CreateRectangle(Mesh* mesh, SpriteSource* spriteSource, Vector2D pos, Vector2D vel, Vector2D extents) {
		Transform* transform = new Transform(pos, extents);
		Sprite* sprite = new Sprite(mesh, Colors::LightBlue, spriteSource);
		Physics* physics = new Physics();
		physics->SetVelocity(vel);
		ColliderRectangle* col = new ColliderRectangle(extents);
		Behaviors::ColorChange* colorChange = new Behaviors::ColorChange(Colors::LightBlue, Colors::Red);
		Behaviors::EdgeLoop* edgeLoop = new Behaviors::EdgeLoop();

		GameObject* circle = new GameObject("rectangle");
		circle->AddComponent((Component*)transform);
		circle->AddComponent((Component*)sprite);
		circle->AddComponent((Component*)physics);
		circle->AddComponent((Component*)col);
		circle->AddComponent((Component*)colorChange);
		circle->AddComponent((Component*)edgeLoop);

		return circle;
	}

	GameObject* CreatePoint(Mesh* mesh, SpriteSource* spriteSource, Vector2D pos, Vector2D vel) {
		Transform* transform = new Transform(pos, Vector2D(20, 20));
		Sprite* sprite = new Sprite(mesh, Colors::Blue, spriteSource);
		Physics* physics = new Physics();
		physics->SetVelocity(vel);
		ColliderPoint* col = new ColliderPoint();
		Behaviors::ColorChange* colorChange = new Behaviors::ColorChange(Colors::Blue, Colors::Red);
		Behaviors::EdgeLoop* edgeLoop = new Behaviors::EdgeLoop();

		GameObject* circle = new GameObject("point");
		circle->AddComponent((Component*)transform);
		circle->AddComponent((Component*)sprite);
		circle->AddComponent((Component*)physics);
		circle->AddComponent((Component*)col);
		circle->AddComponent((Component*)colorChange);
		circle->AddComponent((Component*)edgeLoop);

		return circle;
	}



}