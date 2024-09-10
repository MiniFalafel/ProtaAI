#include "NeuralNet.h"

#include "prota/util/Log.h"

namespace prota
{

	// CONSTRUCTOR
	NeuralNet::NeuralNet(std::vector<unsigned int> layout)
	{	// Validate that the layout is at least 2 layers wide
		P_ASSERT(layout.size() >= 2, "Layout needs to have AT LEAST 2 layers (input+output layers)");

		// Generate all layers and populate synapses
		// Start with empty "previous" layer for input layer
		Layer lastLayer = {};

		// Loop through layout
		for (unsigned int num : layout)
		{	// Loop for num
			Layer nextLayer = {};
			for (unsigned int i = 0; i < num; i++)
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

	// GETTER
	unsigned int NeuralNet::GetNumInputs() const
	{	// Verify m_Layers size
		P_ASSERT(m_Layers.size() > 0, "There are no layers in this NeuralNet");
		return m_Layers[0].size();
	}

	// PROPOGATION
	std::vector<float> NeuralNet::Propogate(std::vector<float> inputs)
	{	// Validate that 'inputs' is the right size
		P_ASSERT(inputs.size() == GetNumInputs(), "Number of inputs provided does NOT match inputs of this network");

		// Set the values for all of the input neurons
		for (unsigned int i = 0; i < m_Layers[0].size(); i++)
		{
			m_Layers[0][i]->SetValue(inputs[i]);
		}

		// Return object
		std::vector<float> r;

		// Loop through all layer EXCEPT the input layer
		for (unsigned int i = 1; i < m_Layers.size(); i++)
		{	// Loop through each neuron in current layer
			for (std::shared_ptr<Connector> n : m_Layers[i])
			{	// Calculate the value at this neuron
				n->Calculate();
				// If this is the output layer, store neuron's value in the return object
				if (i == m_Layers.size() - 1)
					r.push_back(n->GetValue());
			}
		}

		return r;
	}

}