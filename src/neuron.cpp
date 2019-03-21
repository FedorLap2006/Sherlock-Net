#include "pch.h"
#include "Neuron.h"

void Neuron::kernel()
{
	double res(0.0);
	for (auto in : this->ins) {
		res += in.neuron->getValue() * in.weight;
	}
	this->value = res;
}
