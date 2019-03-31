#pragma once


namespace MathUtil {

	class PID {
	public:

		PID();
		PID(float proportionalGain, float integralGain, float derivitiveGain);

		float Run(float error, float dt);

		void setPGain(float proportionalGain);
		void setIGain(float integralGain);
		void setDGain(float derivitiveGain);

		float getPGain() const;
		float getIGain() const;
		float getDGain() const;

	private:

		float m_p;
		float m_i;
		float m_d;

		float m_lastError;
		float m_accError;

	};

}