#ifndef OBJECTIVES_DISCRETE_DiscreteObjective
#define OBJECTIVES_DISCRETE_DiscreteObjective

#include "../ExperimentObjective.hpp"

template <typename T>
class DiscreteObjective: public ExperimentObjective {
	protected:
	T bottomVal;
	T topVal;

	public:
	DiscreteObjective(
		unsigned int genomeLength,
		T bottomVal,
		T topVal
	);

	virtual std::vector<Locus*> getLoci();
	virtual ToStringFunction* getToString();
};

template <typename T>
DiscreteObjective<T>::DiscreteObjective(
	unsigned int genomeLength,
	T bottomVal,
	T topVal
) : ExperimentObjective(genomeLength) {
	this->bottomVal = bottomVal;
	this->topVal = topVal;
}

template <typename T>
std::vector<Locus*> DiscreteObjective<T>::getLoci() {
	return std::vector<Locus*>(
		this->genomeLength,
		new NumericCollectionLocus<T>(this->bottomVal, this->topVal, 1)
	);
}

template <typename T>
ToStringFunction* DiscreteObjective<T>::getToString() {
	return new ExperimentToString<T>(this->genomeLength);
}

#endif
