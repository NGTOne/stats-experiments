#ifndef OBJECTIVES_DISCRETE_BINARY_BinaryObjective
#define OBJECTIVES_DISCRETE_BINARY_BinaryObjective

#include "../DiscreteObjective.hpp"

class BinaryObjective: public DiscreteObjective<unsigned int> {
	public:
	BinaryObjective(unsigned int genomeLength);
	virtual ToStringFunction* getToString();
};

#endif
