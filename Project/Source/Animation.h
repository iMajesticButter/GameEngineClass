//------------------------------------------------------------------------------
//
// File Name:	Animation.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef class Sprite Sprite;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------
// You are free to change the contents of this class as long as you do not
// change the public functions declared in the header.
class Animation : Component {
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------
	
	// Construct a new animation object.
	// Params:
	//   sprite = The sprite this animation will be manipulating.
	Animation();

	void Initialize() override;
	Component* Clone() const ;

	// Play a simple animation sequence (0 .. frameCount).
	// Params:
	//   frameStart = The starting frame for the sequence.
	//	 frameCount = The number of frames in the sequence.
	//	 frameDuration = The amount of time to wait between frames (in seconds).
	//	 Loop = True if the animation loops, false otherwise.
	void Play(unsigned frameStart, unsigned frameCount, float frameDuration, bool Loop);

	// Update the animation.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt) override;

	// Determine if the animation has reached the end of its sequence.
	// Returns:
	//	 The value in isDone.
	bool IsDone() const;

	//Set the frame duration
	//Params:
	//  frameDuration = The amount of time to wait between frames (in seconds).
	void setFrameDuration(float frameDuration);

	//Set the current frame
	//Params:
	//  frame = The frame to go to
	void setFrame(unsigned frame);

	//Determine the number of frames
	//Returns:
	//  the number of frames
	unsigned getFrameCount() const;

	//Determine the current frame
	//Returns:
	//  the current frame index
	unsigned getFrame() const;

private:
	// The current frame being displayed.
	unsigned m_frameIndex;

	// The maximum number of frames in the sequence.
	unsigned m_frameCount;

	// The starting frame of the sequence.
	unsigned m_frameStart;

	// The time remaining for the current frame.
	float m_frameDelay;

	// The amount of time to display each frame.
	// (Used only when playing simple animations (0 .. numFrame).)
	float m_frameDuration;

	// True if the animation is running; false if the animation has stopped.
	bool m_isRunning;

	// True if the animation loops back to the beginning.
	bool m_isLooping;

	// True if the end of the animation has been reached, false otherwise.
	// (Hint: This should be true for only one game loop.)
	bool m_isDone;

	// The sprite this animation will manipulate.
	Sprite* m_sprite;
};
//----------------------------------------------------------------------------
