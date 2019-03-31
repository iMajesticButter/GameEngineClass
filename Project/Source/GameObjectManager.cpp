
//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "GameObjectManager.h"

#include "Space.h"


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor(s)
GameObjectManager::GameObjectManager(Space* space) : BetaObject("ObjectManager") {

}

// Destructor
GameObjectManager::~GameObjectManager() {

}

// Update all objects in the active game objects list.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void GameObjectManager::Update(float dt) {

}

// Shutdown the game object manager, destroying all active objects.
void GameObjectManager::Shutdown(void) {

}

// Unload the game object manager, destroying all object archetypes.
void GameObjectManager::Unload(void) {

}

// Add a game object to the active game object list.
// Params:
//	 gameObject = Reference to the game object to be added to the list.
void GameObjectManager::AddObject(GameObject& gameObject) {

}

// Add a game object to the game object archetype list.
// Params:
//	 gameObject = Reference to the game object to be added to the list.
void GameObjectManager::AddArchetype(GameObject& gameObject) {

}

// Returns a pointer to the first active game object matching the specified name.
// Params:
//	 objectName = The name of the object to be returned, if found.
// Returns:
//   If the named object is found,
//	   then return the pointer to the named game object,
//	   else return nullptr.
GameObject* GameObjectManager::GetObjectByName(const std::string& objectName) const {

}

// Returns a pointer to the first game object archetype matching the specified name.
// Params:
//	 objectName = The name of the archetype to be returned, if found.
// Returns:
//   If the named archetype is found,
//	   then return the pointer to the named game object archetype,
//	   else return nullptr.
GameObject* GameObjectManager::GetArchetypeByName(const std::string& objectName) const {

}

// Returns the number of active objects with the given name.
// Params:
//   objectName = The name of the objects that should be counted.
unsigned GameObjectManager::GetObjectCount(const std::string& objectName) const {

}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Update object logic using variable timestep.
void GameObjectManager::VariableUpdate(float dt) {

}

// Update object physics using fixed timestep.
void GameObjectManager::FixedUpdate(float dt) {

}

// Destroy any objects marked for destruction.
void GameObjectManager::DestroyObjects() {

}

// Draw all game objects in the active game object list.
void GameObjectManager::Draw(void) {

}
