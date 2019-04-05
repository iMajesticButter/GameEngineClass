
#include "stdafx.h"

#include "Death.h"

#include "Transform.h"
#include "GameObject.h"

#include <Graphics.h>

namespace Behaviors {
	Death::Death() : Component("Death") {

	}

	void Death::Initialize() {
		m_transform = (Transform*)GetOwner()->GetComponent("Transform");
	}
	void Death::Update(float dt) {
		UNREFERENCED_PARAMETER(dt);
		BoundingRectangle size = Graphics::GetInstance().GetScreenWorldDimensions();
		
		Vector2D pos = m_transform->GetTranslation();

		float buf = m_transform->GetScale().x + m_transform->GetScale().y;

		if (pos.x > size.right + buf || pos.y > size.top + buf || pos.x < size.left - buf || pos.y < size.bottom - buf) {
			GetOwner()->Destroy();
		}

	}

	Death* Death::Clone() const {
		return new Death(*this);
	}
}