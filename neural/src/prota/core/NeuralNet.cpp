#include "NeuralNet.h"

#include "prota/util/Log.h"

namespace prota
{

	// CONSTRUCTORS
	// Layout/generation
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
	// Weight based
	NeuralNet::NeuralNet(std::vector<std::vector<std::vector<float>>> layerWeights)
	{	// Assert that the size is > 0
		P_ASSERT(layerWeights.size() > 0, "layerWeights parameter is empty");
		
		// Add all the input neurons
		Layer prevLayer;
		for (unsigned int i = 0; i < layerWeights[0][0].size(); i++)
		{	// Create a neuron and push back (no weights because it's the input neuron)
			prevLayer.push_back(std::make_shared<Neuron>(std::vector<std::shared_ptr<Connector>>()));
		}
		// Push input layer
		m_Layers.push_back(prevLayer);

		// Loop through layers
		for (unsigned int i = 0; i < layerWeights.size(); i++)
		{	// Check that this layer isn't empty
			P_ASSERT(layerWeights[i].size() > 0, "A layer in layerWeights is empty");
			// Loop through each neuron in this layer
			Layer nextLayer;
			for (unsigned int j = 0; j < layerWeights[i].size(); j++)
			{	// Create a neuron pointing to the previous layer's neurons with leaded weights
				std::shared_ptr<Neuron> n = std::make_shared<Neuron>(prevLayer, &layerWeights[i][j][0]);
				nextLayer.push_back(n);
			}
			// Push the layer
			m_Layers.push_back(nextLayer);
			// Update prevLayer
			prevLayer = nextLayer;
		}
	}

	// GETTER
	uint32_t NeuralNet::GetNumInputs() const
	{	// Verify m_Layers size
		P_ASSERT(m_Layers.size() > 0, "There are no layers in this NeuralNet");
		return (uint32_t)m_Layers[0].size();
	}

	// Really shitty Debug display method
	void NeuralNet::DisplayDebug()
	{	// Loop through m_Layers
		for (unsigned int l = 0; l < m_Layers.size(); l++)
		{	// Loop through neurons
			// Layer marker
			std::cout << "L" << l << ":";
			for (unsigned int i = 0; i < m_Layers[l].size(); i++)
			{	// Display neuron on tLhe same line
				std::cout << "\tN ";
			}
			// Newline
			std::cout << '\n';
		}
	}

	// PROPOGATION
	std::vector<float> NeuralNet::Propagate(std::vector<float> inputs)
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
	
	// Backward propagate
	void NeuralNet::BackPropagate(std::vector<float> expectedOut)
	{	// Loop backwards through m_Layers
		for (unsigned int i = (unsigned int)(m_Layers.size() - 1); i > -1; i--)
		{	// Loop through the neurons
			for (unsigned int n = 0; n < (unsigned int)m_Layers[i].size(); n++)
			{	// Calculate delta using Newton's root approximation theory (gradient descent)
				// We actually don't have x sub n, we only have f(u), so f'(x) = f'(inv_f(u));
				float fx = m_Layers[i][n]->GetValue();
				float delta = -fx / Neuron::d_SigmoidTangential(Neuron::inv_SigmoidTangential(fx));
			}
		}
	}

}