#include <prota/prota.h>

int main()
{
	// Create a network with random weights
	prota::NeuralNet::SetWeightGeneration(true);
	prota::NeuralNet net({2, 5, 5, 5, 2});
	
	std::vector<float> output = net.Propagate({0.5, 0.5});

	std::cout << "OUTPUT: ";
	for (float f : output)
	{
		std::cout << f << ", ";
	}
	std::cout << '\n';

	return 0;
}
