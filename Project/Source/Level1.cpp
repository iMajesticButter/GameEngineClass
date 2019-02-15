//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "Space.h"
#include "Level2.h"

#include "MeshHelper.h"
#include <Mesh.h>
#include <Graphics.h>
#include <Texture.h>
#include "Sprite.h"
#include "SpriteSource.h"
#include "Animation.h"

#include <iostream>
#include <Engine.h>
#include <Color.h>

namespace Levels {
	
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Creates an instance of Level 1.
	Level1::Level1() : Level("Level1") {
		lives = 3;
	}

	// Load the resources associated with Level 1.
	void Level1::Load() {
		//std::cout << "Level1::Load" << std::endl;
		//mesh = CreateTriangleMesh(Colors::Aqua, Colors::Orange, Colors::Violet);

		//--------

		//mesh = CreateQuadMesh(Vector2D(1.0f/3.0f, 1.0f/5.0f), Vector2D(3, 0.25f));
		mesh = CreateQuadMesh(Vector2D(1.0f / 3.0f, 1.0f / 5.0f), Vector2D(0.5f, 0.5f));
		
		//texture = Texture::CreateTextureFromFile("Monkey.png");

		ss = new SpriteSource("Monkey.png", 3, 5);

		//mesh = CreateTriangleMesh(Colors::Red, Colors::Green, Colors::Blue);

	}

	// Initialize the memory associated with Level 1.
	void Level1::Initialize() {
		//std::cout << "Level1::Initialize" << std::endl;
		
		//sprite = new Sprite(mesh);

		sprite = new Sprite(mesh, Colors::White, ss, 0);

		anim = new Animation(sprite);

		anim->Play(0, 8, 0.1f, true);

	}

	// Update Level 1.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Level1::Update(float dt) {
		UNREFERENCED_PARAMETER(dt);

		//std::cout << "Level1::Update" << std::endl;
		
		--lives;
		if (lives <= 0) {
			//GetSpace()->SetLevel(new Level2);
		}

		//Graphics::GetInstance().SetTexture(texture);
		//Graphics::GetInstance().SetTransform(Vector2D(0, 0), Vector2D(200.0f, 200.0f), 0);

		//mesh->Draw();
		anim->Update(dt);
		sprite->Draw();
		
	}

	// Shutdown any memory associated with Level 1.
	void Level1::Shutdown() {
		//std::cout << "Level1::Shutdown" << std::endl;
	}

	// Unload the resources associated with Level 1.
	void Level1::Unload() {
		//std::cout << "Level1::Unload" << std::endl;
	}

}

//----------------------------------------------------------------------------
