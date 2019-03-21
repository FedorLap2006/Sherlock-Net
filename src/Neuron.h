#pragma once

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>

class Neuron;

#if __cplusplus < 199711L
#error not supported compiller version ( C++11 )

#elif defined( _MSC_VER )
#endif

struct {
	void* data;
	enum {
		TINT,
		TFLOAT,
		TDOUBLE,
	}type;
	size_t size;
}val_t;

struct cmd_t {
	enum {
		TPLUS,
		TMINUS,
		TMUL,
		TDIV,
		TSEND
	}kind;
	
//	int recvID = 0;

	val_t* value = nullptr;
};

struct {
	cmd_t cmd;
	
	Neuron* sender = nullptr;
 	Neuron* receiver = nullptr;
//	double weight;
}Link;

class Neuron
{
protected:
	
public:
	Neuron() = default;
	Neuron(std::vector<Link> links);
	virtual void kernel();
	
	~Neuron() = default;
private:
	std::vector<Link*> conns;
	// double lvalue;

};
