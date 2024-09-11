#include <prota/prota.h>

int main()
{
	/*
	TEST NETWORK: has layout of 2, 2, 1 (2 inputs, 2 in hidden layer, 1 output)

	if:
		- inputs are {0.5, 0.7}
		- AND all weights are 1.0
	then:
		- output should be APPROXIMATELY 0.49075135...

	*/

	// SETUP --------------------------------------------------------
	// Make sure neuron generation only generates weights of 1.0f
	prota::NeuralNet::SetWeightGeneration(false);
	prota::NeuralNet net({2, 2, 1});

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
