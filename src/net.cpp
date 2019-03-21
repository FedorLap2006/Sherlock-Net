#include "pch.h"
#include "Net.h"
#include "Net.h"


Net::Net() {

}

Net::Net(std::vector<double> input) : Net() {

}
Net::Net(std::vector<INeuron> input) : Net() {

}


std::vector<std::vector<double>> Net::getWeights(bool old) {
	std::vector<std::vector<double>> out;
	if (old) {
		for (auto i : layers) {
			out.push_back(i.ltopology);
		}
	}
	else {
		for (auto i : layers) {
			out.push_back(i.topology);
		}
	}
	
	return out;
}

void Layer::FlushWeight() {
	for (int i = 0; i < this->neurons.size() && i < this->topology.size(); i++) {
		Neuron &curn = this->neurons[i];
		double &curWeight = this->topology[i];
		curn.setWeight(i,curWeight);
	}
	if (ltopology.size() != topology.size()) {
		for (int i = 0; i < this->topology.size(); i++) {
			ltopology.push_back(topology[i]);
		}
	}
	else {
		for (int i = 0; i < this->topology.size(); i++) {
			ltopology[i] = topology[i];
		}
	}
}

void Net::Study(int count_sets,double koff) {
	for (int i = 0; i < count_sets; i++) {

		for (int i = 0; i < this->layers.size(); i++) {

			Layer &curLayer = this->layers[i];

			for (int i = 0; i < curLayer.neurons.size(); i++) {
				int prevIndex = (i == 0 ? -1 : i);
				Neuron &curNeuron = curLayer.neurons[i];

				curLayer.topology[i] = StudyAlg(curLayer.ltopology[i], koff, curLayer.neurons[prevIndex], curLayer.neurons[i]); // RU: ְכדמנטעל ױובבא EN: Algorithm of Hebb

				curLayer.FlushWeight();
			}
		}
	}
}
