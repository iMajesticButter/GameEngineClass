#include "stdafx.h"

#include "Behaviors.h"

#include "Physics.h"
#include "Transform.h"
#include <Input.h>
#include <Graphics.h>

float lastError = 0;
float aError = 0;
const double nintyDegRad = (M_PI / 180);

void Behaviors::UpdateShip(Transform* transform, Physics* physics, float dt) {

	//---get required variables---

	//get mouse position
	Vector2D mousePos = Graphics::GetInstance().ScreenToWorldPosition(Input::GetInstance().GetCursorPosition());

	//get vector to mouse
	Vector2D mouseVec = transform->GetTranslation() - mousePos;

	//get mouse angle
	float mouseA = atan2(mouseVec.y, mouseVec.x) + (float)(90 * nintyDegRad);

	//---pid controller to turn to mouse---
	float P = 1;
	float I = 0;
	float D = 0.5f;

	//get error
	float error = abs(mouseA - transform->GetRotation());

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

	Vector2D n = Vector2D(cos(transform->GetRotation() + (180 * (float)nintyDegRad)), sin(transform->GetRotation() + (180 * (float)nintyDegRad)));

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
	std::cout << "ship A: " << transform->GetRotation() << std::endl;
	std::cout << "aForce: " << angularForce << std::endl;
	std::cout << "error: " << error << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

}