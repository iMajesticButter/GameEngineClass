//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "ColliderCircle.h"

#include "ColliderPoint.h"
#include "ColliderRectangle.h"
#include "Transform.h"
#include "Intersection2D.h"

#include <Graphics.h>
#include <DebugDraw.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor for circle collider.
// Params:
//   radius = The radius of the circle.
ColliderCircle::ColliderCircle(float radius) : Collider(ColliderType::ColliderTypeCircle) {
	m_radius = radius;
}

// Clone an collider and return a pointer to the cloned object.
// Returns:
//   A pointer to a collider.
Component* ColliderCircle::Clone() const {
	return new ColliderCircle(*this);
}

// Debug drawing for colliders.
void ColliderCircle::Draw() {
	DebugDraw::GetInstance().AddCircle(m_transform->GetTranslation(), m_radius, Graphics::GetInstance().GetCurrentCamera(), Colors::Green);
	DebugDraw::GetInstance().EndLineStrip(Graphics::GetInstance().GetCurrentCamera());
}

// Get the circle collider's radius.
// Returns:
//	 The circle collider's radius.
float ColliderCircle::GetRadius() const {
	return m_radius;
}

// Set the circle collider's radius.
// Params:
//   radius = The circle collider's new radius.
void ColliderCircle::SetRadius(float radius) {
	m_radius = radius;
}

// Check for collision between a circle and another arbitrary collider.
// Params:
//	 other = Reference to the second circle collider component.
// Returns:
//	 Return the results of the collision check.
bool ColliderCircle::IsCollidingWith(const Collider& other) const {
	if (other.GetType() == ColliderType::ColliderTypeCircle) {
		return CircleCircleIntersection(GetCircle(), ((ColliderCircle&)other).GetCircle());
	} else if (other.GetType() == ColliderType::ColliderTypeRectangle) {
		return RectangleCircleIntersection(((ColliderRectangle&)other).GetRect(), GetCircle());
	} else if (other.GetType() == ColliderType::ColliderTypePoint) {
		return PointCircleIntersection(other.GetTransform()->GetTranslation(), GetCircle());
	}
	return false;
}

Circle ColliderCircle::GetCircle() const {
	Circle c(m_transform->GetTranslation(), m_radius);
	return c;
}

