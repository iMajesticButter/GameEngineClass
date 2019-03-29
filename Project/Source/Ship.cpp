#include "stdafx.h"

#include "Ship.h"

#include "GameObject.h"
#include "Physics.h"
#include "Transform.h"
#include "MathUtil.h"

#include <Input.h>
#include <Graphics.h>

namespace Behaviors {

	Ship::Ship(float p = 1, float i = 0, float d = 0.3f, float maxAngualar = 0.45f, float movementSpeed = 325) : Component("Ship") {
		m_lastError = 0;
		m_accError = 0;
	}

	void Ship::Initialize() {
		m_transform = (Transform*)GetOwner()->GetComponent("Transform");
		m_physics = (Physics*)GetOwner()->GetComponent("Phyiscs");
	}

	void Ship::Update(float dt) {

	}

	Component* Ship::Clone() const {
		return new Ship(*this);
	}

}