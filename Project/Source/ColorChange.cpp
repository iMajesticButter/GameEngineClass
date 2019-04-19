//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "ColorChange.h"

#include "Sprite.h"
#include "GameObject.h"
#include "Collider.h"

//------------------------------------------------------------------------------

namespace Behaviors {
	
	// Collision handler for ColorChange objects.
	// Params:
	//   object = The first object.
	//   other  = The other object the first object is colliding with.
	void ColorChangeCollisionHandler(GameObject& object, GameObject& other);

	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	// Params:
	//   normalColor = The color that the object reverts to when not colliding.
	//   collidedColor = The color that the object changes to when colliding.
	//   collidedColorTime = The amount of time the object will retain the collided color.
	ColorChange::ColorChange(const Color& normalColor, const Color& collidedColor, float collidedColorTime) : Component("ColorChange") {
		m_normalColor = normalColor;
		m_collidedColor = collidedColor;
		m_collidedColorTime = collidedColorTime;
	}

	// Return a new copy of the component.
	Component* ColorChange::Clone() const {
		return new ColorChange(*this);
	}

	// Initialize data for this object.
	void ColorChange::Initialize() {
		m_sprite = (Sprite*)GetOwner()->GetComponent("Sprite");
		((Collider*)GetOwner()->GetComponent("Collider"))->SetCollisionHandler(ColorChangeCollisionHandler);
	}

	// Update function for this component.
	// Params:
	//   dt = The (fixed) change in time since the last step.
	void ColorChange::Update(float dt) {
		if (m_collided) {
			m_collided = false;
			m_sprite->SetColor(m_collidedColor);
			m_timer = m_collidedColorTime;
		} else if (m_timer <= 0) {
			m_sprite->SetColor(m_normalColor);
		}

		m_timer -= dt;

	}

	// Collision handler for ColorChange objects.
	// Params:
	//   object = The first object.
	//   other  = The other object the first object is colliding with.
	void ColorChangeCollisionHandler(GameObject& object, GameObject& other) {
		((ColorChange*)object.GetComponent("ColorChange"))->m_collided = true;
		UNREFERENCED_PARAMETER(other);
	}
}
