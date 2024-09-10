#include "NeuralNet.h"

namespace prota
{

	// CONSTRUCTOR
	NeuralNet::NeuralNet(std::vector<unsigned int> layout)
	{	// Validate that the layout is at least 2 layers wide
		if (!(layout.size() >= 2))
		{	// Log error
			std::cout << "WARNING: Layout needs to have AT LEAST 2 layers (inputs and outputs)!\n";
			__debugbreak();
		}
		// Set m_NumInputs
		m_NumInputs = layout[0];

		// Generate all layers and populate synapses
		// Start with empty "previous" layer for input layer
		Layer lastLayer = {};

		// Loop through layout
		for (unsigned int num : layout)
		{	// Loop for num
			Layer nextLayer = {};
			for (int i = 0; i < num; i++)
			{	// Create neuron and append to the layer
				std::shared_ptr<Neuron> n = std::make_shared<Neuron>(lastLayer);
				// Add to the layer
				nextLayer.push_back(n);
			}
			// Set the lastLayer to the layer just created:
			lastLayer = nextLayer;
			// Push the layer
			m_Layers.push_back(lastLayer);
		}

	}

	void NeuralNet::Propogate(std::vector<float> inputs)
	{	// Validate that 'inputs' is the right size
		if (inputs.size() != m_NumInputs)
		{
			std::cout << "WARNING: Number of inputs provided does NOT match inputs of this network\n";
		}

	}

}