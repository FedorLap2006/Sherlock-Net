#include "pch.h"
#include "Net.h"
#include "Net.h"

const int stdKoffLearn = 10;

Net::Net() {

}

Net::Net(std::vector<double> input) : Net() {

}
Net::Net(std::vector<INeuron> input) : Net() {

}

void Layer::FlushWeight() {
	for (int i = 0; i < this->neurons.size() && i < this->topology.size(); i++) {
		Neuron &curn = this->neurons[i];
		double &curWeight = this->topology[i];
		curn.setWeight(curWeight);
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
	
	for (int i = 0; i < this->layers.size(); i++) {
		
		Layer &curLayer = this->layers[i];

		for (int i = 0; i < curLayer.neurons.size(); i++) {
			int prevIndex = (i == 0 ? -1 : i);
			Neuron &curNeuron = curLayer.neurons[i];

			curLayer.topology[i] = StudyAlg(curLayer.ltopology[i], koff, curLayer.neurons[prevIndex], curLayer.neurons[i]); // RU: ְכדמנטעל ױובבא EN: Alg of Hebb
			
			curLayer.FlushWeight();


		}
	}
}
