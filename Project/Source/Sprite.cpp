//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Sprite.h"
#include "SpriteSource.h"
#include "Transform.h"
#include "GameObject.h"

#include <Vector2D.h>
#include <Graphics.h>
#include <Mesh.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Create a new sprite object.
Sprite::Sprite() : Component("Sprite") {

	m_frameIndex = 0;
	m_spriteSource = nullptr;
	m_mesh = nullptr;
	m_color = Colors::White;

}

Sprite::Sprite(Mesh* mesh, Color color, SpriteSource* spriteSource, unsigned int frameIndex) : Component("Sprite") {
	m_mesh = mesh;
	m_color = color;
	m_spriteSource = spriteSource;
	m_frameIndex = frameIndex;
}

void Sprite::Initialize() {

	m_transform = (Transform*)GetOwner()->GetComponent("Transform");

}

Component* Sprite::Clone() const {
	return new Sprite(*this);
}

// Draw a sprite (Sprite can be textured or untextured).
void Sprite::Draw() {
	if (m_mesh == nullptr || m_transform == nullptr) {
		return;
	}

	if (m_spriteSource != nullptr) {
		Vector2D uvcoords(1, 0.5f);
		m_spriteSource->GetUV(m_frameIndex, uvcoords);

		Graphics::GetInstance().SetTexture(m_spriteSource->GetTexture(), uvcoords);
	} else {
		Graphics::GetInstance().SetTexture(nullptr);
	}

	Graphics::GetInstance().SetSpriteBlendColor(m_color);
	Graphics::GetInstance().SetTransform(m_transform->GetMatrix());

	m_mesh->Draw();

}

// Set a sprite's transparency (between 0.0f and 1.0f).
// Params:
//   alpha = New value for the sprite's 'alpha' value.
void Sprite::SetAlpha(float alpha) {
	m_color.a = alpha;
}

// Get the current value for a sprite's transparency.
float Sprite::GetAlpha() const {
	return m_color.a;
}

// Set the sprite's current frame.
// (NOTE: You must validate the frame index against the sprite source's frame count.)
// Params:
//   frameIndex = New frame index for the sprite (0 .. frame count).
void Sprite::SetFrame(unsigned int frameIndex) {
	if (m_spriteSource == nullptr) {
		return;
	}
	
	if (frameIndex < m_spriteSource->GetFrameCount()) {
		m_frameIndex = frameIndex;
	}
}

// Returns the index of the current frame being displayed.
unsigned Sprite::GetFrame() const {
	return m_frameIndex;
}

// Set the sprite's mesh.
// (NOTE: This mesh may be textured or untextured.)
// (NOTE: This mesh may contain any number of triangles.)
// Params:
//   mesh = Pointer to a mesh created using the Alpha Engine.
void Sprite::SetMesh(Mesh* mesh) {
	m_mesh = mesh;
}

// Set a new SpriteSource for the specified sprite.
// Params:
//	 spriteSource = A new sprite source for the sprite.
void Sprite::SetSpriteSource(SpriteSource* spriteSource) {
	m_spriteSource = spriteSource;
}

// Set the blend color for the specified sprite.
// Params:
//	 color = A new color for the sprite.
void Sprite::SetColor(Color color) {
	m_color = color;
}

// Retrieves the blend color for the sprite.
const Color& Sprite::GetColor() const {
	return m_color;
}

//------------------------------------------------------------------------------
