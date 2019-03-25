#include "stdafx.h"

#include "Behaviors.h"

#include "Physics.h"
#include "Transform.h"
#include "MathUtil.h"

#include <Input.h>
#include <Graphics.h>

float lastError = 0;
float aError = 0;

void Behaviors::UpdateShip(Transform* transform, Physics* physics, float dt) {

	//---get required variables---

	//get mouse position
	Vector2D mousePos = Graphics::GetInstance().ScreenToWorldPosition(Input::GetInstance().GetCursorPosition());

	//get vector to mouse
	Vector2D mouseVec = transform->GetTranslation() - mousePos;

	//get mouse angle
	float mouseA = MathUtil::Wrap(atan2(mouseVec.y, mouseVec.x) + (float)(90 * MathUtil::DegToRad), 0.0f, (float)(2.0f*M_PI));

	//get ship angle
	float shipA = MathUtil::Wrap(transform->GetRotation(), 0.0f, (float)(2.0f*M_PI));

	//---pid controller to turn to mouse---
	float P = 1;
	float I = 0;
	float D = 0.5f;

	//get error
	//float error = abs(mouseA - shipA);
	float error = abs(atan2(sin(shipA - mouseA), cos(shipA - mouseA)));

	//algorithm
	aError += error * dt;
	float dError = (error - lastError) / dt;
	lastError = error;
	float angularForce = (error * P) + (aError * I) + (dError * D);

	//apply angular force
	/*if (transform->GetRotation() > mouseA) {
		physics->AddAngularForce(-angularForce*0.1f);
	} else {
		physics->AddAngularForce(angularForce*0.1f);
	}*/

	Vector2D n = Vector2D(cos(shipA + (180 * (float)MathUtil::DegToRad)), sin(shipA + (180 * (float)MathUtil::DegToRad)));

	//Vector2D n = Vector2D(cos(transform->GetRotation()), sin(transform->GetRotation()));

	if (mouseVec.DotProduct(n) > 0) {
		//accute
		physics->AddAngularForce(-angularForce * 0.1f);
	} else if (mouseVec.DotProduct(n) < 0) {
		//obtuse
		physics->AddAngularForce(angularForce*0.1f);
	}

	//debug
	system("cls");

	std::cout << "mouseA: " << mouseA << std::endl;
	std::cout << "mousAd: " << mouseA * MathUtil::RadToDeg << std::endl;
	std::cout << "ship A: " << shipA << std::endl;
	std::cout << "shipAd: " << shipA * MathUtil::RadToDeg << std::endl;
	std::cout << "aForce: " << angularForce << std::endl;
	std::cout << "error: " << error << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

}