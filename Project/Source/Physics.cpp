//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Physics.h"
#include "Transform.h"
#include "GameObject.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Initialization:
//------------------------------------------------------------------------------

Vector2D Physics::Gravity = Vector2D(0, -981);
float Physics::AirDencity = 0.01225f;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Create a new physics component.
// Params:
//   transform - The transform of the object.
Physics::Physics() : Component("Physics") {

	m_velocity = Vector2D(0, 0);
	m_angularVelocity = 0;
	m_inverseMass = 1;
	m_forcesSum = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);
	m_oldTranslation = Vector2D(0, 0);
	m_dragCd = 0.1f;
	m_aDragCd = 0.1f;

}

void Physics::Initialize() {
	m_transform = (Transform*)GetOwner()->GetComponent("Transform");
}

Component* Physics::Clone() const {
	return new Physics(*this);
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
	//dragCoefficent * ((0.5 * airDensity) * (velocity^2 * surfaceArea))
	float D = m_dragCd * ((0.5f * AirDencity) * (m_velocity.MagnitudeSquared() * ((m_transform->GetScale().x * 0.001f) + (m_transform->GetScale().y * 0.001f))));

	//calculate angular drag
	//angularDragCoefficent * ((0.5 * airDensity) * (velocity^2 * surfaceArea))
	float aD = (m_aDragCd * ((0.5f * AirDencity) * (pow(m_angularVelocity, 2) * ((m_transform->GetScale().x * 0.001f) + (m_transform->GetScale().y * 0.001f))))) * m_inverseMass;

	//apply drag
	AddForce(m_velocity.Normalized() * -D);


	if (abs(aD) >= abs(m_angularVelocity)) {
		m_angularVelocity = 0;
	} else {
		if (m_angularVelocity > 0) {
			m_angularVelocity -= aD;
		}
		else {
			m_angularVelocity += aD;
		}
	}

	//apply gravity
	AddForce(Gravity);

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

// Add an angular force to the object.
// Params:
//	 force = A rotational force 
void Physics::AddAngularForce(const float force) {
	m_angularVelocity += force * m_inverseMass;
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

// Set the drag coeficient of a physics component.
	// Params:
	//	 dCe = New value for the drag coeficient.
void Physics::SetDragCoefficient(float dCd) {
	m_dragCd = dCd;
}

// Get the drag coeficient of a physics component.
// returns:
//	 A float representing the drag coeficient.
float Physics::GetDragCoefficient() const {
	return m_dragCd;
}

// Set the angular drag coeficient of a physics component.
// Params:
//	 adCe = New value for the angular drag coeficient.
void Physics::SetAngularDragCoefficient(float adCd) {
	m_aDragCd = adCd;
}

// Get the drag angular coeficient of a physics component.
// returns:
//	 A float representing the rotational drag coeficient.
float Physics::GetAngularDragCoefficient() const {
	return m_aDragCd;
}


//------------------------------------------------------------------------------
