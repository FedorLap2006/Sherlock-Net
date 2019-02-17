#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

class Neuron;

typedef struct Input {
	Neuron* neuron;
	double weight;
}Input;

class Neuron
{
protected:
	double value;
public:
	Neuron() = default;
	Neuron(std::vector<Input> input);
	virtual double getValue() { this->kernel(); return tanh(this->value); }
	// virtual void setLvalue(double val) { this->lvalue; }
	virtual void setWeight(int32_t num,double w);
	virtual void setValue(double val) { this->value = val; }
	virtual void setInput(std::vector<Input> input) { this->ins = input; }
	virtual void kernel();

	~Neuron() = default;
private:
	std::vector<Input> ins;
	// double lvalue;

};
