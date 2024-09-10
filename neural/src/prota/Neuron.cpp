#include "Neuron.h"

namespace prota
{

	bool Neuron::s_RandomWeights = false;

	// CONSTRUCTOR
	Neuron::Neuron(std::vector<std::shared_ptr<Connector>> connections)
	{	// Populates the array of synapses
		for (int i = 0; i < connections.size(); i++)
		{
			float w = 1.0f;
			if (IsGenerationRandom())
			{	// Get random float from [-1, 1]
				w = (float)(rand()) / (float)(RAND_MAX / 2) - 1.0f;
			}
			m_Synapses.push_back(std::make_shared<Synapse>(connections[i], w));
		}
	}

}
