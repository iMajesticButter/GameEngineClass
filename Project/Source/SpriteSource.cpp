//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "SpriteSource.h"

#include <Texture.h>
#include <Vector2D.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Allocate a new sprite source object.
// Params:
//	 numCols = The number of columns in the sprite sheet.
//	 numRows = The number of rows in the sprite sheet.
//	 texture = A pointer to a texture that has been loaded by the Alpha Engine.
SpriteSource::SpriteSource(Texture* texture, int numCols, int numRows) {
	m_numCols = numCols;
	m_numRows = numRows;
	m_texture = texture;
	m_TextureOwned = false;
}

// Allocate a new sprite source object.
// Params:
//	 numCols = The number of columns in the sprite sheet.
//	 numRows = The number of rows in the sprite sheet.
//	 texture = The name of the texture asset to use.
SpriteSource::SpriteSource(std::string texture, int numCols, int numRows) {
	m_numCols = numCols;
	m_numRows = numRows;
	m_texture = Texture::CreateTextureFromFile(texture);
	m_TextureOwned = true;
}

SpriteSource::~SpriteSource() {
	if (m_TextureOwned) {
		delete m_texture;
	}
}

// Returns a pointer to the texture, for the purposes of rendering a sprite.
// Returns:
//	 A pointer to the sprite source texture.
Texture* SpriteSource::GetTexture() const {
	return m_texture;
}

// Returns the maximum number of frames possible, given the dimensions of the sprite sheet.
// Returns:
//	 The calculated frame count.
unsigned SpriteSource::GetFrameCount() const {
	return m_numCols * m_numRows;
}

// Returns the UV coordinates of the specified frame in a sprite sheet.
// Params:
//	 frameIndex = A frame index within a sprite sheet.
//   textureCoords = Reference to a Vector2D containing the UV/texture coordinates.
void SpriteSource::GetUV(unsigned int frameIndex, Vector2D& textureCoords) const {
	float u = 1.0f / m_numCols;
	float v = 1.0f / m_numRows;

	float c = (float)(frameIndex % m_numCols);
	float r = (float)(frameIndex / m_numCols);

	textureCoords = Vector2D(u*c, v*r);

}

//----------------------------------------------------------------------------
