#include "pch.h"
#include "Net.h"
#include "Net.h"

Net::Net() {
}

Net::Net(std::vector<double> input) : Net() {

}
Net::Net(std::vector<INeuron> input) : Net() {

}

void Net::Study(double koff) {
	
	for (int i = 0; i < this->layers.size(); i++) {
		
		Layer &curLayer = this->layers[i];

		for (int i = 0; i < curLayer.neurons.size(); i++) {
		
			Neuron &curNeuron = curLayer.neurons[i];
		}
	}
}
