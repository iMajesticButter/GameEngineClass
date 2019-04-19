//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Level3.h"

#include "Level1.h"
#include "SpriteSource.h"
#include "GameObject.h"
#include "MeshHelper.h"
#include "Space.h"
#include "GameObjectManager.h"
#include "Archetypes.h"

#include <Input.h>
#include <Texture.h>
#include <Mesh.h>
#include <iostream>

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

namespace Levels {
	
	// Creates an instance of Level 3.
	Level3::Level3() : Level("level3") {
		m_circleSpeed = 30.0f;
		m_pointSpeed = 25.0f;
	}

	// Load the resources associated with Level 3.
	void Level3::Load() {

		m_meshQuad = MeshHelper::CreateQuadMesh(Vector2D(1, 1), Vector2D(0.5f, 0.5f));

		m_spriteSourceCircle = new SpriteSource("CircleHollow.png");
		m_spriteSourceRect = new SpriteSource("RectHollow.png");

	}

	// Initialize the memory associated with Level 3.
	void Level3::Initialize() {
		GetSpace()->GetObjectManager().AddObject(*Archetypes::CreatePoint(m_meshQuad, m_spriteSourceCircle, Vector2D(0, 0), Vector2D(0, -85)));
		GetSpace()->GetObjectManager().AddObject(*Archetypes::CreateCircle(m_meshQuad, m_spriteSourceCircle, Vector2D(0, 0), Vector2D(0, 0), 50));
		
		
	}

	// Update Level 3.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Level3::Update(float dt) {
		UNREFERENCED_PARAMETER(dt);
		if (Input::GetInstance().CheckTriggered('2')) {
			GetSpace()->SetLevel(new Level1());
		}
	}

	// Unload the resources associated with Level 3.
	void Level3::Unload() {
		delete m_spriteSourceCircle;
		delete m_spriteSourceRect;
	}

	
}

//----------------------------------------------------------------------------
