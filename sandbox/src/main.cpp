#include <prota/prota.h>

int main()
{
	/*
	TEST NETWORK: has layout of {2, 3, 1}

	Pre-determined weights (see in array below)

	Output should look like this:
		> 0.227517468...

	*/

	// SETUP --------------------------------------------------------
	// Weights
	std::vector<std::vector<std::vector<float>>> weights = {
		{	// LAYER 1 (first hidden layer: 3 neurons)
			{0.5f,  0.25f},
			{0.7f,  1.0f},
			{0.12f, 0.3f},
		},
		{	// LAYER 2 (output layer: 1 neuron)
			{0.4f, 0.76f, 0.1f},
		},
	};
	
	// Feed weights into the network constructor
	prota::NeuralNet net(weights);

	// DEBUG DISPLAY
	net.DisplayDebug();

	// Setup logging
	prota::Log::SetLogLevel(prota::LogLevel::INFO);
	
	// Inputs
	std::vector<float> inputs = {0.5f, 0.7f};

	// RUN AND DISPLAY ----------------------------------------------
	
	// propogate inputs
	std::vector<float> out = net.Propagate(inputs);

	// display output
	P_LOG_INFO(std::format("OUT: {}", out[0]));


	return 0;
}
