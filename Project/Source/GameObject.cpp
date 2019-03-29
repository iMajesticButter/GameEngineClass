//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "GameObject.h"

#include "Component.h"

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Create a new game object.
// Params:
//	 name = The name of the game object being created.
GameObject::GameObject(const std::string& name) : BetaObject(name) {
	numComponents = 0;
	isDestroyed = false;
}

// Clone a game object from another game object.
// Params:
//	 other = A reference to the object being cloned.
GameObject::GameObject(const GameObject& other) : BetaObject(other.GetName()) {
	numComponents = 0;
	isDestroyed = other.isDestroyed;

	for (int i = 0; i < other.numComponents; ++i) {
		if (other.components[i] != nullptr) {
			AddComponent(other.components[i]->Clone());
		}
	}

}

// Free the memory associated with a game object.
GameObject::~GameObject() {
	for (int i = 0; i < numComponents; ++i) {
		delete components[i];
	}
}

// Initialize this object's components and set it to active.
void GameObject::Initialize() {
	for (int i = 0; i < numComponents; ++i) {
		components[i]->Initialize();
	}
}

// Update any components attached to the game object.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void GameObject::Update(float dt) {
	if (isDestroyed) {
		return;
	}

	for (int i = 0; i < numComponents; ++i) {
		components[i]->Update(dt);
	}
}

// Updates components using a fixed timestep (usually just physics)
// Params:
//	 dt = A fixed change in time, usually 1/60th of a second.
void GameObject::FixedUpdate(float dt) {
	if (isDestroyed) {
		return;
	}

	for (int i = 0; i < numComponents; ++i) {
		components[i]->FixedUpdate(dt);
	}
}

// Draw any visible components attached to the game object.
void GameObject::Draw() {
	for (int i = 0; i < numComponents; ++i) {
		components[i]->Draw();
	}
}

// Adds a component to the object.
void GameObject::AddComponent(Component* component) {
	component->SetParent(this);
	components[numComponents++] = component;
}

// Retrieves the component with the given name if it exists.
// Params:
//   name = The name of the component to find.
Component* GameObject::GetComponent(const std::string& name) {
	for (int i = 0; i < numComponents; ++i) {
		if (components[i] != nullptr && components[i]->GetName() == name) {
			return components[i];
		}
	}
	return nullptr;
}

// Mark an object for destruction.
void GameObject::Destroy() {
	isDestroyed = true;
}

// Whether the object has been marked for destruction.
// Returns:
//		True if the object will be destroyed, false otherwise.
bool GameObject::IsDestroyed() const {
	return isDestroyed;
}

// Get the space that contains this object.
Space* GameObject::GetSpace() const {
	return (Space*)GetParent();
}

/*
//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

// Components
Component* components[25];
unsigned numComponents;

// Whether the object has been marked for destruction.
bool isDestroyed;
*/
