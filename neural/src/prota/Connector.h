#pragma once

#include <iostream>

// The entire purpose of this class is to avoid causing circular import issues with 
// Synapses referencing Neurons and Neurons referencing Synapses

namespace prota
{

	class Connector
	{	// Parent of the Neuron class

	public:
		Connector()
		{	// Verify that the parent constructor is being called.
			std::cout << "Connector initialized!\n";
		}
		
	};

}
