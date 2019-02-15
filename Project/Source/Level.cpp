//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level.h"

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------


// Creates a game state.
// Params:
//   name = Name to use for this state.
Level::Level(const std::string& name) : BetaObject(name) {

}

// Retrieve the space in which the level is running.
Space* Level::GetSpace() const {
	return (Space*)GetParent();
}

