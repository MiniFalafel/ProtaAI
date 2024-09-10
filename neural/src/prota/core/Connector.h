#pragma once

#include <iostream>

// The entire purpose of this class is to avoid causing circular import issues with 
// Synapses referencing Neurons and Neurons referencing Synapses

namespace prota
{

	class Connector
	{	// Parent of the Neuron class

		// Store computed value
		float m_Value = 0.0f;

	public:
		Connector() {}

		// GETTERS
		float GetValue() const { return m_Value; }

		// SETTERS
		void SetValue(float value) { m_Value = value; }

		// TRANSFER FUNCTIONS
		float SigmoidTangential(float t)
		{	// o(x) = 1 / (1 + e^-x) -> (0, 1), so: v(t) = 2 * o(x) - 1
			return 2.0 / (1 + exp(-t)) - 1.0;
		}

		float d_SigmoidTangential(float t)
		{	// Derivative of the SigmoidTangential method
			float e_t = exp(t);
			return 2.0f * e_t / pow(1.0f + e_t, 2.0f);
		}

		// VIRTUAL METHODS
		virtual void Calculate() = 0;
		
	};

}