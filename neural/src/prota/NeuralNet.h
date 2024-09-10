#pragma once

#include "Neuron.h"

namespace prota
{
	typedef std::vector<std::shared_ptr<Connector>> Layer;

	class NeuralNet
	{

		// Keeps a set of layers
		std::vector<Layer> m_Layers;

	public:

		// CONSTRUCTOR
		NeuralNet(std::vector<unsigned int> layout);

		// GETTERS
		unsigned int GetNumInputs() const;

		// Propogate!!!
		void Propogate(std::vector<float> inputs);

	};

}
