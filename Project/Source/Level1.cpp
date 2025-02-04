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
#include "EdgeLoop.h"
#include "Level3.h"

#include <Input.h>
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
		m_mesh = MeshHelper::CreateQuadMesh(Vector2D(1 / 1, 1 / 1), Vector2D(1 * 1, 1 * 1));

		m_spriteSource = new SpriteSource("SpaceShip.png", 1, 1);
	}

	// Initialize the memory associated with Level 1.
	void Level1::Initialize() {
		GameObject* ship = Archetypes::CreateShip(m_mesh, m_spriteSource);
		ship->AddComponent((Component*)new Behaviors::EdgeLoop());
		GetSpace()->GetObjectManager().AddObject(*ship);
		GetSpace()->GetObjectManager().AddArchetype(*Archetypes::CreateShip(m_mesh, m_spriteSource));


		Physics::AirDencity = 0;
		Physics::Gravity = Vector2D(0, 0);

	}

	// Update Level 1.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Level1::Update(float dt) {
		UNREFERENCED_PARAMETER(dt);
		if (Input::GetInstance().CheckTriggered('1')) {
			GetSpace()->SetLevel(new Level3());
		}
	}

	// Shutdown any memory associated with Level 1.
	void Level1::Shutdown() {
		
	}

	// Unload the resources associated with Level 1.
	void Level1::Unload() {
		delete m_mesh;
		delete m_spriteSource;
	}

}

//----------------------------------------------------------------------------
