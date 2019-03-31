//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Level1.h"
#include "Space.h"
#include "Level2.h"
#include "Transform.h"
#include "Physics.h"
#include "Behaviors.h"

#include "MeshHelper.h"
#include <Mesh.h>
#include <Graphics.h>
#include <Texture.h>
#include "Sprite.h"
#include "SpriteSource.h"
#include "Animation.h"
#include "Archetypes.h"
#include "GameObject.h"

#include <iostream>
#include <Engine.h>
#include <Color.h>

namespace Levels {
	
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Creates an instance of Level 1.
	Level1::Level1() : Level("Level1") {
		
	}

	// Load the resources associated with Level 1.
	void Level1::Load() {
		
	}

	// Initialize the memory associated with Level 1.
	void Level1::Initialize() {
		ship = Archetypes::CreateShip();
		ship->Initialize();

		Physics::AirDencity = 0;
		Physics::Gravity = Vector2D(0, 0);

	}

	// Update Level 1.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Level1::Update(float dt) {
		ship->Update(dt);
		ship->FixedUpdate(dt);
		ship->Draw();
	}

	// Shutdown any memory associated with Level 1.
	void Level1::Shutdown() {
		ship->Shutdown();
	}

	// Unload the resources associated with Level 1.
	void Level1::Unload() {
		ship->Unload();
	}

}

//----------------------------------------------------------------------------
