
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
GameObjectManager::GameObjectManager(Space* space) : BetaObject("ObjectManager", space) {
	m_timeAccumulator = 0;
	
}

// Destructor
GameObjectManager::~GameObjectManager() {
	Shutdown();
	Unload();
}

// Update all objects in the active game objects list.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void GameObjectManager::Update(float dt) {
	if (!((Space*)GetParent())->IsPaused()) {

		VariableUpdate(dt);
		FixedUpdate(dt);

	}

	DestroyObjects();
	Draw();

}

// Shutdown the game object manager, destroying all active objects.
void GameObjectManager::Shutdown(void) {
	for (int i = 0; i < m_gameObjectActiveList.size(); ++i) {
		delete m_gameObjectActiveList[i];
	}
	m_gameObjectActiveList.clear();
}

// Unload the game object manager, destroying all object archetypes.
void GameObjectManager::Unload(void) {
	for (int i = 0; i < m_gameObjectArchetypes.size(); ++i) {
		delete m_gameObjectArchetypes[i];
	}
	m_gameObjectArchetypes.clear();
}

// Add a game object to the active game object list.
// Params:
//	 gameObject = Reference to the game object to be added to the list.
void GameObjectManager::AddObject(GameObject& gameObject) {
	gameObject.SetParent(GetParent());
	gameObject.Initialize();
	
	m_gameObjectActiveList.push_back(&gameObject);

}

// Add a game object to the game object archetype list.
// Params:
//	 gameObject = Reference to the game object to be added to the list.
void GameObjectManager::AddArchetype(GameObject& gameObject) {
	
	m_gameObjectArchetypes.push_back(&gameObject);

}

// Returns a pointer to the first active game object matching the specified name.
// Params:
//	 objectName = The name of the object to be returned, if found.
// Returns:
//   If the named object is found,
//	   then return the pointer to the named game object,
//	   else return nullptr.
GameObject* GameObjectManager::GetObjectByName(const std::string& objectName) const {
	
	for (int i = 0; i < m_gameObjectActiveList.size(); ++i) {
		if (m_gameObjectActiveList[i]->GetName() == objectName) {
			return m_gameObjectActiveList[i];
		}
	}

	return nullptr;

}

// Returns a pointer to the first game object archetype matching the specified name.
// Params:
//	 objectName = The name of the archetype to be returned, if found.
// Returns:
//   If the named archetype is found,
//	   then return the pointer to the named game object archetype,
//	   else return nullptr.
GameObject* GameObjectManager::GetArchetypeByName(const std::string& objectName) const {
	for (int i = 0; i < m_gameObjectArchetypes.size(); ++i) {
		if (m_gameObjectArchetypes[i]->GetName() == objectName) {
			return m_gameObjectArchetypes[i];
		}
	}

	return nullptr;
}

// Returns the number of active objects with the given name.
// Params:
//   objectName = The name of the objects that should be counted.
unsigned GameObjectManager::GetObjectCount(const std::string& objectName) const {

	int count = 0;

	for (int i = 0; i < m_gameObjectActiveList.size(); ++i) {
		if (m_gameObjectActiveList[i]->GetName() == objectName && !m_gameObjectActiveList[i]->IsDestroyed()) {
			++count;
		}
	}

	return count;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Update object logic using variable timestep.
void GameObjectManager::VariableUpdate(float dt) {
	std::vector<GameObject*> updateList = m_gameObjectActiveList;
	for (int i = 0; i < updateList.size(); ++i) {
		updateList[i]->Update(dt);
	}
}

// Update object physics using fixed timestep.
void GameObjectManager::FixedUpdate(float dt) {
	
	m_timeAccumulator += dt;

	std::vector<GameObject*> updateList = m_gameObjectActiveList;

	while (m_timeAccumulator >= m_fixedUpdateDt) {
		for (int i = 0; i < updateList.size(); ++i) {
			updateList[i]->FixedUpdate(m_fixedUpdateDt);
		}
		m_timeAccumulator -= m_fixedUpdateDt;
	}

}

// Destroy any objects marked for destruction.
void GameObjectManager::DestroyObjects() {

	for (int i = 0; i < m_gameObjectActiveList.size(); ++i) {
		if (m_gameObjectActiveList[i]->IsDestroyed()) {
			delete m_gameObjectActiveList[i];
			m_gameObjectActiveList.erase(m_gameObjectActiveList.begin() + i);
		}
	}

}

// Draw all game objects in the active game object list.
void GameObjectManager::Draw(void) {
	for (int i = 0; i < m_gameObjectActiveList.size(); ++i) {
		m_gameObjectActiveList[i]->Draw();
	}
}
