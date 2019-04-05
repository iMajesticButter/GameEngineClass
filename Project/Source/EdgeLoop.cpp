
#include "stdafx.h"

#include "EdgeLoop.h"

#include "Transform.h"
#include "GameObject.h"

#include <Graphics.h>

namespace Behaviors {

	EdgeLoop::EdgeLoop() : Component("EdgeLoop") {

	}

	void EdgeLoop::Initialize() {
		m_transform = (Transform*)GetOwner()->GetComponent("Transform");
	}
	void EdgeLoop::Update(float dt) {
		UNREFERENCED_PARAMETER(dt);
		BoundingRectangle size = Graphics::GetInstance().GetScreenWorldDimensions();

		Vector2D pos = m_transform->GetTranslation();

		float buf = m_transform->GetScale().x;

		if (pos.x > size.right + buf || pos.x < size.left - buf) {
			pos.x = -pos.x;
		}

		if (pos.y > size.top + buf || pos.y < size.bottom - buf) {
			pos.y = -pos.y;
		}

		m_transform->SetTranslation(pos);

	}

	EdgeLoop* EdgeLoop::Clone() const {
		return new EdgeLoop(*this);
	}

}