//------------------------------------------------------------------------------
//
// File Name:	Transform.h
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

#include "Component.h"

#include <Matrix2D.h>

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// An example of the structure to be defined in Transform.h.
// You are free to change the contents of this structure as long as you do not
//   change the public method declarations declared in the header.
class Transform : Component {
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Transform constructor.
	// Params:
	//	 x = Initial world position on the x-axis.
	//	 y = Initial world position on the y-axis.
	Transform(float x, float y);

	// Transform constructor.
	// Params:
	//	 translation = World position of the object.
	//   scale		 = Width and height of the object.
	//   rotation	 = Rotation of the object about the z-axis.
	Transform(Vector2D translation = Vector2D(), Vector2D scale = Vector2D(50, 50), float rotation = 0);

	// Transform constructor.
	// Params:
	//	 translation = World position of the object.
	//   rotation	 = Rotation of the object about the z-axis.
	//	 scale = Width and height of the object.
	Transform(Vector2D translation = Vector2D(), float rotation = 0, Vector2D scale = Vector2D(50, 50));

	Component* Clone() const;

	// Get the transform matrix, based upon translation, rotation and scale settings.
	// Returns:
	//	 A reference to the component's matrix structure
	const Matrix2D& GetMatrix();

	// Set the translation of a transform component.
	// Params:
	//	 translation = Reference to a translation vector.
	void SetTranslation(const Vector2D& translation);

	// Get the translation of a transform component.
	// Returns:
	//	 A reference to the component's translation structure.
	const Vector2D& GetTranslation() const;

	// Set the rotation of a transform component.
	// Params:
	//	 rotation = The rotation value (in radians).
	void SetRotation(float rotation);

	// Get the rotation value of a transform component.
	// Returns:
	//	 The component's rotation value (in radians).
	float GetRotation() const;

	// Set the scale of a transform component.
	// Params:
	//	 translation = Reference to a scale vector.
	void SetScale(const Vector2D& scale);

	// Get the scale of a transform component.
	// Returns:
	//	 A reference to the component's scale structure.
	const Vector2D& GetScale() const;

private:
	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// The translation (or world position) of a game object.
	Vector2D	m_translation;

	// The rotation (or orientation) of a game object.
	float	m_rotation;

	// The scale (or size) of a game object.
	Vector2D	m_scale;

	// The transformation matrix resulting from multiplying the 
	// translation, rotation, and scale matrices.
	Matrix2D	m_matrix;

	// True if the transformation matrix needs to be recalculated.
	bool	m_dirty;
};
//------------------------------------------------------------------------------
