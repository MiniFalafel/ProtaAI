#pragma once

#include "prota/core/Neuron.h"

namespace prota
{
	class NeuralNet
	{

		// Keeps a set of layers
		std::vector<Layer> m_Layers;

	public:

		// CONSTRUCTORS
		// Layout/generation based
		NeuralNet(std::vector<unsigned int> layout);
		// Weight based
		NeuralNet(std::vector<std::vector<std::vector<float>>> layerWeights);

		// GETTERS
		uint32_t GetNumInputs() const;

		// Display (for debugging)
		void DisplayDebug();

		// Propogate!!!
		std::vector<float> Propagate(std::vector<float> inputs);

		// Backwards propagation
		void BackPropagate(std::vector<float> expectedOut);

	public: // STATIC PUBLIC ----------------------------------------

		// Wrapper of the neuron static method (makes more sense API wise, but still want neuron to have access to it)
		static void SetWeightGeneration(bool doRandomWeights) { Neuron::SetWeightGeneration(doRandomWeights); }


	};

}
