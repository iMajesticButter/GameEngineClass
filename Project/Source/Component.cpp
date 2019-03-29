//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include"Component.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor - needed to construct BetaObject.
Component::Component(const std::string& name) : BetaObject(name) {

}

// Retrieve component's owner object (if any).
GameObject* Component::GetOwner() const {
	return (GameObject*)GetParent();
}

