#pragma once

#include "Component.h"

#include "PID.h"

typedef class Transform Transform;
typedef class Physics Physics;

namespace Behaviors {

	class Ship : Component {
	public:

		Ship(float p = 1, float i = 0, float d = 1, float maxAngualar = 0.45f, float movementSpeed = 325);

		void Initialize() override;

		void Update(float dt) override;

		Component* Clone() const;
	private:

		Transform* m_transform = nullptr;
		Physics* m_physics = nullptr;

		float m_maxAngular;
		float m_movementSpeed;

		MathUtil::PID m_pid;

	};

}