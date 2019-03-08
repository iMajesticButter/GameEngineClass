//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Physics.h"
#include "Transform.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Create a new physics component.
// Params:
//   transform - The transform of the object.
Physics::Physics(Transform* transform) {

	m_velocity = Vector2D(0, 0);
	m_angularVelocity = 0;
	m_inverseMass = 1;
	m_forcesSum = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);
	m_oldTranslation = Vector2D(0, 0);
	m_transform = transform;
	m_dragCd = 0;
	m_aDragCd = 0;

}

// Reset acceleration.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Physics::Update(float dt) {

	UNREFERENCED_PARAMETER(dt);

	//calculate acceleration
	m_acceleration = m_forcesSum * m_inverseMass;
	m_forcesSum = Vector2D(0, 0);
}

// Update velocity and translation.
// Params:
//	 dt = Change in time (in seconds) since the last fixed update.
void Physics::FixedUpdate(float dt) {
	//set velocity
	m_velocity = m_velocity + (m_acceleration * dt);

	//translation
	m_oldTranslation = m_transform->GetTranslation();
	m_transform->SetTranslation(m_oldTranslation + (m_velocity * dt));

	//rotaion
	m_transform->SetRotation(m_transform->GetRotation() + (m_angularVelocity * dt));

	//calculate drag
	float D = m_dragCd * ((0.5f * 1.225f) * (m_velocity.MagnitudeSquared() * ((m_transform->GetScale().x * 0.1f) + (m_transform->GetScale().y * 0.1f))));
	std::cout << "Drag: " << D << " m/s^2" << std::endl;

}

// Set the velocity of a physics component.
// Params:
//	 velocity = Pointer to a velocity vector.
void Physics::SetVelocity(const Vector2D& velocity) {
	m_velocity = velocity;
}

// Get the velocity of a physics component.
// Returns:
//		A reference to the component's velocity structure.
const Vector2D& Physics::GetVelocity() const {
	return m_velocity;
}

// Set the angular velocity of a physics component.
// Params:
//	 velocity = New value for the rotational velocity.
void Physics::SetAngularVelocity(float velocity) {
	m_angularVelocity = velocity;
}

// Get the angular velocity of a physics component.
// Returns:
//	 A float representing the new angular velocity.
float Physics::GetAngularVelocity() const {
	return m_angularVelocity;
}

// Set the mass of the physics component.
// Params:
//   mass = The new mass of the physics component.
void Physics::SetMass(float mass) {
	m_inverseMass = 1 / mass;
}

// Add a force to the object.
// Params:
//	 force = A force vector with direction and magnitude.
void Physics::AddForce(const Vector2D& force) {
	m_forcesSum += force;
}

// Get the acceleration of a physics component.
// Returns:
//	 A reference to the component's acceleration structure.
const Vector2D& Physics::GetAcceleration() const {
	return m_acceleration;
}

// Get the old translation (position) of a physics component.
// Returns: 
//   A reference to the component's oldTranslation structure,
const Vector2D& Physics::GetOldTranslation() const {
	return m_oldTranslation;
}


//------------------------------------------------------------------------------
