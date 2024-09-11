#include "Neuron.h"

namespace prota
{

	bool Neuron::s_RandomWeights = false;

	// CONSTRUCTOR
	Neuron::Neuron(Layer connections, float* weights)
	{	// Populates the array of synapses
		for (int i = 0; i < connections.size(); i++)
		{
			float w = 1.0f;
			if (weights != nullptr)
			{	// The weight is the value at the index in weights
				w = weights[i];
			} else if (IsGenerationRandom())
			{	// Get random float from [-1, 1]
				w = (float)(rand()) / (float)(RAND_MAX / 2) - 1.0f;
			}
			m_Synapses.push_back(std::make_shared<Synapse>(connections[i], w));
		}
	}

	void Neuron::Calculate()
	{	// Sum result of all synapses
		float sum = 0.0f;
		for (std::shared_ptr<Synapse> s : m_Synapses)
		{
			sum += s->toNeuron->GetValue() * s->Weight;
		}
		// Put sum through transfer function and set value
		SetValue(SigmoidTangential(sum));
	}

}
