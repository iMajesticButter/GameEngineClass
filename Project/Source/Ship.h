#pragma once

#include "Component.h"

namespace Behaviors {

	class Ship : Component {
	public:

		Ship(float p = 1, float i = 0, float d = 0.3f, float maxAngualar = 0.45f, float movementSpeed = 325);

		void Initialize();

		void Update(float dt);

		Component* Clone() const;
	private:

		Transform* m_transform = nullptr;
		Physics* m_physics = nullptr;

		float m_lastError;
		float m_accError;

	};

}