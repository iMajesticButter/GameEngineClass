//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Space.h"
#include "Level.h"

#include <iostream>

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor(s)
Space::Space(const std::string& name) : BetaObject(name) {
	m_paused = false;
	m_currentLevel = nullptr;
	m_nextLevel = nullptr;
	m_objectManager = new GameObjectManager(this);
}

// Destructor
Space::~Space() {
	delete m_currentLevel;
	delete m_nextLevel;
	delete m_objectManager;
}

// Updates the state manager and object manager.
// Params:
//   dt = The change in time since the last call to this function.
void Space::Update(float dt) {

	//std::cout << "Space::Update" << std::endl;

	if (m_nextLevel != nullptr) {
		ChangeLevel();
		return;
	}

	if (m_currentLevel != nullptr) {
		m_currentLevel->Update(dt);
	}

	m_objectManager->Update(dt);

}

// Shuts down the object manager
void Space::Shutdown() {
	if (m_currentLevel != nullptr) {

		m_currentLevel->Shutdown();
		m_currentLevel->Unload();

		m_objectManager->Shutdown();
		m_objectManager->Unload();

		delete m_currentLevel;
		m_currentLevel = nullptr;
	}
}

// Returns a boolean indicating whether objects in this space are paused.
// Returns:
//   True if the space is paused, false otherwise.
bool Space::IsPaused() const {
	return m_paused;
}

// Returns the name of the level currently running in this space.
std::string Space::GetLevelName() const {
	if (m_currentLevel != nullptr) {
		return m_currentLevel->GetName();
	}
	return "";
}

// Pauses the space, preventing objects from being updated, but objects are still drawn.
// Params:
//   value = A true/false value that indicates whether the space should be paused.
void Space::SetPaused(bool value) {
	m_paused = value;
}

// Sets the level that the space is using after unloading the current level.
// Params:
//   level = The next level that the space will be using.
void Space::SetLevel(Level* level) {
	m_nextLevel = level;
	m_nextLevel->SetParent(this);
}

// Restarts the current level (next level = current)
void Space::RestartLevel() {
	m_nextLevel = m_currentLevel;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Updates current/next level pointers and calls shutdown/unload/load/init
void Space::ChangeLevel() {

	//std::cout << "Space::ChangeLevel" << std::endl;

	//shutdown level
	if (m_currentLevel != nullptr) {
		m_currentLevel->Shutdown();
		m_objectManager->Shutdown();
	}

	//skip if restarting
	if (m_currentLevel != m_nextLevel) {
		if (m_currentLevel != nullptr) {
			m_currentLevel->Unload();
			m_objectManager->Unload();
			delete m_currentLevel;
		}
		m_currentLevel = m_nextLevel;
		m_currentLevel->Load();
	}

	m_currentLevel->Initialize();

	m_nextLevel = nullptr;

}

// Returns the object manager, which you can use to retrieve and add objects.
GameObjectManager& Space::GetObjectManager() {
	return *m_objectManager;
}

	

