//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Collider.h"

#include "GameObject.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Allocate a new collider component.
// Params:
//   type = The type of collider (see the ColliderType enum).
Collider::Collider(ColliderType type) : Component("Collider") {
	m_type = type;
}

// Set component pointers.
void Collider::Initialize() {
	m_transform = (Transform*)GetOwner()->GetComponent("Transform");
	m_physics = (Physics*)GetOwner()->GetComponent("Physics");
}

// Check if two objects are colliding and send collision events.
// Params:
//	 other = Reference to the second collider component.
void Collider::CheckCollision(const Collider& other) {
	if (IsCollidingWith(other)) {
		m_handler(*GetOwner(), *other.GetOwner());
		other.m_handler(*GetOwner(), *GetOwner());
	}
}

// Get the type of this component.
ColliderType Collider::GetType() const {
	return m_type;
}

// Sets the collision handler function for the collider.
// Params:
//   handler = A pointer to the collision handler function.
void Collider::SetCollisionHandler(CollisionEventHandler handler) {
	m_handler = handler;
}

Transform* Collider::GetTransform() const {
	return m_transform;
}
Physics* Collider::GetPhysics() const {
	return m_physics;
}


//------------------------------------------------------------------------------
