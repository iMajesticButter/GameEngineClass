#pragma once


#include "Component.h"


typedef class Transform Transform;


namespace Behaviors {
	class EdgeLoop : Component {
	public:

		EdgeLoop();

		void Initialize() override;
		void Update(float dt) override;

		EdgeLoop* Clone() const override;

	private:

		Transform* m_transform;

	};
}