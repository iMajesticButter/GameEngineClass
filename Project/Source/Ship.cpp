#include "stdafx.h"

#include "Ship.h"

#include "GameObject.h"
#include "Physics.h"
#include "Transform.h"
#include "MathUtil.h"

#include <Input.h>
#include <Graphics.h>

namespace Behaviors {

	Ship::Ship(float p, float i, float d, float maxAngualar, float movementSpeed) : Component("Ship") {
		m_maxAngular = maxAngualar;
		m_movementSpeed = movementSpeed;

		m_pid = MathUtil::PID(p, i, d);

	}

	void Ship::Initialize() {
		m_transform = (Transform*)GetOwner()->GetComponent("Transform");
		m_physics = (Physics*)GetOwner()->GetComponent("Physics");
	}

	void Ship::Update(float dt) {

		//---get required variables---

		//get mouse position
		Vector2D mousePos = Graphics::GetInstance().ScreenToWorldPosition(Input::GetInstance().GetCursorPosition());

		//get vector to mouse
		Vector2D mouseVec = m_transform->GetTranslation() - mousePos;

		//get mouse angle
		float mouseA = MathUtil::Wrap(atan2(mouseVec.y, mouseVec.x) + (float)(90 * MathUtil::DegToRad), 0.0f, (float)(2.0f*M_PI));

		//get ship angle
		float shipA = MathUtil::Wrap(m_transform->GetRotation(), 0.0f, (float)(2.0f*M_PI));

		//get ship vector
		Vector2D shipVec = Vector2D(cos(shipA + (float)MathUtil::DegToRad * 90), sin(shipA + (float)MathUtil::DegToRad * 90));



		//---pid controller to turn to mouse---
		//get error
		//float error = abs(mouseA - shipA);
		float error = abs(atan2(sin(shipA - mouseA), cos(shipA - mouseA)));

		float angularForce = m_pid.Run(error, dt);

		//apply force limiter
		angularForce = std::clamp(angularForce, -m_maxAngular, m_maxAngular);

		Vector2D n = Vector2D(cos(shipA + (180 * (float)MathUtil::DegToRad)), sin(shipA + (180 * (float)MathUtil::DegToRad)));

		//Vector2D n = Vector2D(cos(transform->GetRotation()), sin(transform->GetRotation()));

		if (mouseVec.DotProduct(n) > 0) {
			//accute
			m_physics->AddAngularForce(-angularForce * 0.1f);
		}
		else if (mouseVec.DotProduct(n) < 0) {
			//obtuse
			m_physics->AddAngularForce(angularForce * 0.1f);
		}



		//---movement---

		//move when w is pressed
		if (Input::GetInstance().CheckHeld('W')) {
			m_physics->AddForce(shipVec * m_movementSpeed);
		}

	}

	Component* Ship::Clone() const {
		return new Ship(*this);
	}

}