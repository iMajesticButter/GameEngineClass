//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "ColliderRectangle.h"

#include "ColliderCircle.h"
#include "ColliderPoint.h"
#include "Transform.h"
#include "Intersection2D.h"

#include <Graphics.h>
#include <DebugDraw.h>

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor for rectangle collider.
// Params:
//   extents = The rectangle's extents (half-width, half-height).
ColliderRectangle::ColliderRectangle(const Vector2D& extents) : Collider(ColliderType::ColliderTypeRectangle) {
	m_extents = extents;
}

// Clone an collider and return a pointer to the cloned object.
// Returns:
//   A pointer to a collider.
Component* ColliderRectangle::Clone() const {
	return new ColliderRectangle(*this);
}

// Debug drawing for colliders.
void ColliderRectangle::Draw() {
	DebugDraw* dbgd = &DebugDraw::GetInstance();
	Camera* cam = &Graphics::GetInstance().GetCurrentCamera();
	Vector2D pos = m_transform->GetTranslation();

	dbgd->AddLineToStrip(pos + Vector2D(-m_extents.x / 2,  m_extents.y / 2), pos + Vector2D( m_extents.x / 2,  m_extents.y / 2), Colors::Green);
	dbgd->AddLineToStrip(pos + Vector2D( m_extents.x / 2,  m_extents.y / 2), pos + Vector2D( m_extents.x / 2, -m_extents.y / 2), Colors::Green);
	dbgd->AddLineToStrip(pos + Vector2D( m_extents.x / 2, -m_extents.y / 2), pos + Vector2D(-m_extents.x / 2, -m_extents.y / 2), Colors::Green);
	dbgd->AddLineToStrip(pos + Vector2D(-m_extents.x / 2, -m_extents.y / 2), pos + Vector2D(-m_extents.x / 2,  m_extents.y / 2), Colors::Green);
	dbgd->AddLineToStrip(pos + Vector2D(-m_extents.x / 2,  m_extents.y / 2), pos + Vector2D( m_extents.x / 2, -m_extents.y / 2), Colors::Green);

	dbgd->EndLineStrip(*cam);

}

// Get the rectangle collider's extents (half-width, half-height).
// Returns:
//	 The extents of the rectangle.
const Vector2D& ColliderRectangle::GetExtents() const {
	return m_extents;
}

// Set the rectangle collider's extents (half-width, half-height).
// Params:
//   extents = The new extents of the rectangle.
void ColliderRectangle::SetExtents(const Vector2D& extents) {
	m_extents = extents;
}

// Check for collision between a circle and another arbitrary collider.
// Params:
//	 other = Reference to the second circle collider component.
// Returns:
//	 Return the results of the collision check.
bool ColliderRectangle::IsCollidingWith(const Collider& other) const {
	if (other.GetType() == ColliderType::ColliderTypeCircle) {
		return RectangleCircleIntersection(GetRect(), ((ColliderCircle&)other).GetCircle());
	} else if (other.GetType() == ColliderType::ColliderTypeRectangle) {
		return RectangleRectangleIntersection(GetRect(), ((ColliderRectangle&)other).GetRect());
	} else if (other.GetType() == ColliderType::ColliderTypePoint) {
		return PointRectangleIntersection(other.GetTransform()->GetTranslation(), GetRect());
	}
	return false;
}


BoundingRectangle ColliderRectangle::GetRect() const {
	BoundingRectangle rect(m_transform->GetTranslation(), m_extents);
	return rect;
}

//------------------------------------------------------------------------------
