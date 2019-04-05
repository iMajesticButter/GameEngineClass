#pragma once


#include "Component.h"

typedef class Transform Transform;

namespace Behaviors {

	class Death : Component {
	public:

		Death();

		void Initialize() override;
		void Update(float dt) override;

		Death* Clone() const override;

	private:

		Transform* m_transform;

	};

}