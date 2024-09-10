#pragma once

#include <memory>

#include "prota/core/Connector.h"

namespace prota
{

	class Synapse
	{

	public:
		// Has a pointer to a neuron and a weight value, describing the connection
		std::shared_ptr<Connector> toNeuron;
		float Weight;

		Synapse(std::shared_ptr<Connector> neuron, float weight)
			: toNeuron(neuron), Weight(weight) {}


	// -------------------------------------------------------

	private: // STATIC PRIVATE

		// Pruning Threshold - how low can the weight be before we decide a synapse can be deleted?
		//    > NOTE: Since weight values can range from [-1.0, 1.0], We'll take the absolute value of values before comparing to the threshold
		static float s_PruningThreshold;

	public: // STATIC PUBLIC
		
		// Setter - pruning threshold
		static void SetPruningThreshold(float t) { s_PruningThreshold = t; }

		// Getter
		static float GetPruningThreshold() { return s_PruningThreshold; }

	};

}
