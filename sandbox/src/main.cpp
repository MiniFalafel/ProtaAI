#include <prota/prota.h>

int main()
{
	prota::Log::SetLogLevel(prota::INFO);

	// Randomize weights
	prota::Neuron::SetGeneration(true);

	// EXAMPLE NEURONS
	prota::Layer l = {
		std::make_shared<prota::Neuron>(std::vector<std::shared_ptr<prota::Connector>>()),
		std::make_shared<prota::Neuron>(std::vector<std::shared_ptr<prota::Connector>>()),
		std::make_shared<prota::Neuron>(std::vector<std::shared_ptr<prota::Connector>>()),
	};

	// Set values in l
	for (std::shared_ptr<prota::Connector> n : l)
	{
		n->SetValue(1.0f);
	}

	prota::Neuron JimmyNeutron = prota::Neuron(l);
	JimmyNeutron.Calculate();

	P_LOG_INFO(std::format("Calculated value: {}", JimmyNeutron.GetValue()));


	return 0;
}
