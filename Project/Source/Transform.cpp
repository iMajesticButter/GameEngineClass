//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Transform.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Transform constructor.
// Params:
//	 x = Initial world position on the x-axis.
//	 y = Initial world position on the y-axis.
Transform::Transform(float x, float y) {

	m_translation = Vector2D(x, y);
	m_rotation = 0;
	m_scale = Vector2D(50, 50);

}

// Transform constructor.
// Params:
//	 translation = World position of the object.
//   scale		 = Width and height of the object.
//   rotation	 = Rotation of the object about the z-axis.
Transform::Transform(Vector2D translation, Vector2D scale, float rotation) {

	m_translation = translation;
	m_scale = scale;
	m_rotation = rotation;

}

// Transform constructor.
// Params:
//	 translation = World position of the object.
//   rotation	 = Rotation of the object about the z-axis.
//	 scale = Width and height of the object.
Transform::Transform(Vector2D translation, float rotation, Vector2D scale) {

	m_translation = translation;
	m_rotation = rotation;
	m_scale = scale;

}

// Get the transform matrix, based upon translation, rotation and scale settings.
// Returns:
//	 A reference to the component's matrix structure
const Matrix2D& Transform::GetMatrix() {
	if (m_dirty) {

		//create matricies
		Matrix2D tMatrix = Matrix2D::TranslationMatrix(m_translation.x, m_translation.y);
		Matrix2D rMatrix = Matrix2D::RotationMatrixRadians(m_rotation);
		Matrix2D sMatrix = Matrix2D::ScalingMatrix(m_scale.x, m_scale.y);

		m_matrix = tMatrix * rMatrix * sMatrix;

		m_dirty = false;

	}

	return m_matrix;

}

// Set the translation of a transform component.
// Params:
//	 translation = Reference to a translation vector.
void Transform::SetTranslation(const Vector2D& translation) {
	if (!AlmostEqual(translation, m_translation)) {
		m_translation = translation;
		m_dirty = true;
	}
}

// Get the translation of a transform component.
// Returns:
//	 A reference to the component's translation structure.
const Vector2D& Transform::GetTranslation() const {
	return m_translation;
}

// Set the rotation of a transform component.
// Params:
//	 rotation = The rotation value (in radians).
void Transform::SetRotation(float rotation) {
	if (rotation != m_rotation) {
		m_rotation = rotation;
		m_dirty = true;
	}
}

// Get the rotation value of a transform component.
// Returns:
//	 The component's rotation value (in radians).
float Transform::GetRotation() const {
	return m_rotation;
}

// Set the scale of a transform component.
// Params:
//	 translation = Reference to a scale vector.
void Transform::SetScale(const Vector2D& scale) {
	if (!AlmostEqual(scale, m_scale)) {
		m_scale = scale;
		m_dirty = true;
	}
}

// Get the scale of a transform component.
// Returns:
//	 A reference to the component's scale structure.
const Vector2D& Transform::GetScale() const {
	return m_scale;
}


//------------------------------------------------------------------------------
