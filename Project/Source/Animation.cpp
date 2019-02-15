//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Animation.h"
#include "Sprite.h"


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Construct a new animation object.
// Params:
//   sprite = The sprite this animation will be manipulating.
Animation::Animation(Sprite* sprite) {
	m_sprite = sprite;
	m_frameCount = 0;
	m_frameDelay = 0;
	m_frameDuration = 0;
	m_frameIndex = 0;
	m_frameStart = 0;
	m_isDone = false;
	m_isLooping = false;
	m_isRunning = false;
}

// Play a simple animation sequence (0 .. frameCount).
// Params:
//   frameStart = The starting frame for the sequence.
//	 frameCount = The number of frames in the sequence.
//	 frameDuration = The amount of time to wait between frames (in seconds).
//	 Loop = True if the animation loops, false otherwise.
void Animation::Play(unsigned frameStart, unsigned frameCount, float frameDuration, bool Loop) {

	m_frameIndex = frameStart;
	m_frameStart = frameStart;
	m_frameCount = frameCount;
	m_frameDuration = frameDuration;
	m_frameDelay = m_frameDuration;
	m_isLooping = Loop;
	m_isDone = false;
	m_isRunning = true;

	m_sprite->SetFrame(m_frameIndex);

}

// Update the animation.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Animation::Update(float dt) {

	m_isDone = false;

	if (!m_isRunning) {
		return;
	}

	m_frameDelay -= dt;

	if (m_frameDelay <= 0) {

		/*std::cout << m_frameIndex << std::endl;
		std::cout << (m_frameCount + m_frameStart) - 1 << std::endl;
		std::cout << "---------------" << std::endl;*/

		m_frameDelay = m_frameDuration;

		++m_frameIndex;

		if (m_isLooping) {
			if (m_frameIndex >= m_frameCount + m_frameStart) {
				m_frameIndex = m_frameStart;
			}
		} else if(m_frameIndex >= (m_frameCount + m_frameStart)-1) {
			m_isDone = true;
			m_isRunning = false;

			/*std::cout << m_frameIndex << std::endl;
			std::cout << (m_frameCount + m_frameStart) - 1 << std::endl;
			std::cout << "---------------" << std::endl;*/

		}

		m_sprite->SetFrame(m_frameIndex);

	}

}

// Determine if the animation has reached the end of its sequence.
// Returns:
//	 The value in isDone.
bool Animation::IsDone() const {
	return m_isDone;
}

//Set the frame duration
//Params:
//  frameDuration = The amount of time to wait between frames (in seconds).
void Animation::setFrameDuration(float frameDuration) {
	m_frameDuration = frameDuration;
}

//Set the current frame
//Params:
//  frame = The frame to go to
void Animation::setFrame(unsigned frame) {
	m_frameIndex = frame;
}

//Determine the number of frames
//Returns:
//  the number of frames
unsigned Animation::getFrameCount() const {
	return m_frameCount;
}

//Determine the current frame
//Returns:
//  the current frame index
unsigned Animation::getFrame() const {
	return m_frameIndex;
}
