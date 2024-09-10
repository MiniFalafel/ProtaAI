#pragma once

#include <vector>

#include "Connector.h"
#include "Synapse.h"

namespace prota
{

	class Neuron : public Connector
	{

		// Should store an array of 'Synapse's which connect to neurons of the previous layer
		std::vector<std::shared_ptr<Synapse>> m_Synapses;

	public:

		Neuron(std::vector<std::shared_ptr<Connector>> connections);

	private: // STATIC PRIVATE

		// Generation settings
		static bool s_RandomWeights;


	public: // STATIC PUBLIC

		// SETTER
		static void SetGeneration(bool doRandomWeights) { s_RandomWeights = doRandomWeights; }

		// GETTER
		static bool IsGenerationRandom() { return s_RandomWeights; }


	};

}
