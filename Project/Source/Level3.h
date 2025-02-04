//------------------------------------------------------------------------------
//
// File Name:	Level3.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Vector2D.h"
#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

class Texture;
class Mesh;
class SpriteSource;
class GameObject;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

namespace Levels
{
	class Level3 : public Level
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Creates an instance of Level 3.
		Level3();

		// Load the resources associated with Level 3.
		void Load() override;

		// Initialize the memory associated with Level 3.
		void Initialize() override;

		// Update Level 3.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		void Update(float dt) override;

		// Unload the resources associated with Level 3.
		void Unload() override;

	private:

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Resources
		Mesh* m_meshQuad;
		SpriteSource* m_spriteSourceCircle;
		SpriteSource* m_spriteSourceRect;

		// Properties
		float m_circleSpeed;
		float m_pointSpeed;
	};
}

//----------------------------------------------------------------------------
