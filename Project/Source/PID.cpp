
#include "stdafx.h"

#include "PID.h"



namespace MathUtil {

	PID::PID() {
		m_p = 0;
		m_i = 0;
		m_d = 0;

		m_lastError = 0;
		m_accError = 0;
	}

	PID::PID(float proportionalGain, float integralGain, float derivitiveGain) {
		m_p = proportionalGain;
		m_i = integralGain;
		m_d = derivitiveGain;

		m_lastError = 0;
		m_accError = 0;
	}

	float PID::Run(float error, float dt) {
		m_accError += error * dt;
		float dError = (error - m_lastError) / dt;
		m_lastError = error;
		return (error * m_p) + (m_accError * m_i) + (dError * m_d);
	}

	void PID::PID::setPGain(float proportionalGain) {
		m_p = proportionalGain;
	}
	void PID::setIGain(float integralGain) {
		m_i = integralGain;
	}
	void PID::setDGain(float derivitiveGain) {
		m_d = derivitiveGain;
	}

	float PID::getPGain() const {
		return m_p;
	}
	float PID::getIGain() const {
		return m_i;
	}
	float PID::getDGain() const {
		return m_d;
	}

}