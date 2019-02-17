#pragma once

#include "Neuron.h"

double StudyAlg(double lw, double koff, Neuron inp, Neuron cur) { return lw + (koff * inp.getValue() * cur.getValue()); }

class INeuron : public Neuron {
public:
	INeuron(double val) { this->value = val; }
	double getValue() override { return this->value; }
};

class Layer {
public:
	std::vector<Neuron> neurons;
	std::vector<double> topology;
	std::vector<double> ltopology;
	void FlushWeight();
};

class Net {
private:
	std::vector<Layer> layers;
	/* std::vector<double> topology;
	std::vector<double> ltopology; */
	std::vector<INeuron> inputs;
	double output;
public:
	Net();
	Net(std::vector<double> input);
	Net(std::vector<INeuron> input);
	virtual void Study(int,double koff);
	double getOutput() { return this->output; }
};