//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "ColliderPoint.h"

#include "Transform.h"
#include "Intersection2D.h"
#include "ColliderCircle.h"
#include "ColliderRectangle.h"
#include "Shapes2D.h"

#include <Graphics.h>
#include <DebugDraw.h>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor for point collider.
ColliderPoint::ColliderPoint() : Collider(ColliderType::ColliderTypePoint) {

}

// Clone an collider and return a pointer to the cloned object.
// Returns:
//   A pointer to a collider.
Component* ColliderPoint::Clone() const {
	return new ColliderPoint(*this);
}

// Debug drawing for colliders.
void ColliderPoint::Draw() {
	DebugDraw::GetInstance().AddCircle(m_transform->GetTranslation(), 10, Graphics::GetInstance().GetCurrentCamera(), Colors::Green);
	DebugDraw::GetInstance().EndLineStrip(Graphics::GetInstance().GetCurrentCamera());
}

// Check for collision between a point and another arbitrary collider.
// Params:
//	 other = Reference to the second point collider component.
// Returns:
//	 Return the results of the collision check.
bool ColliderPoint::IsCollidingWith(const Collider& other) const {
	if (other.GetType == ColliderType::ColliderTypeCircle) {
		//return PointCircleIntersection(m_transform->GetTranslation(), (ColliderCircle)other.//get circle);
	} else if (other.GetType == ColliderType::ColliderTypeRectangle) {
		//return PointRectangleIntersection(m_transform->GetTranslation(), (ColliderRectangle)other.//get rect)
	} else if (other.GetType == ColliderType::ColliderTypePoint) {
		return m_transform->GetTranslation().DistanceSquared(other.GetTransform()->GetTranslation()) == 0;
	}
	return false;
}

