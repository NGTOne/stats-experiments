#ifndef OBJECTIVES_ExperimentObjective
#define OBJECTIVES_ExperimentObjective

#include <libHierGA/HierGA.hpp>
#include <vector>
#include <sstream>

class ExperimentObjective : public ObjectiveFunction {
	private:

	protected:
	unsigned int genomeLength;

	public:
	ExperimentObjective(unsigned int genomeLength);

	virtual std::vector<Locus*> getLoci()=0;
	virtual ToStringFunction* getToString()=0;
};

template <typename T>
class ExperimentToString : public ToStringFunction {
	private:

	protected:
	unsigned int genomeLength;
	std::string separator;

	public:
	ExperimentToString(
		unsigned int genomeLength,
		std::string separator = " "
	);
	std::string toString(Genome* genome);
};

template <typename T>
ExperimentToString<T>::ExperimentToString(
	unsigned int genomeLength,
	std::string separator
) {
	this->genomeLength = genomeLength;
	this->separator = separator;
}

template <typename T>
std::string ExperimentToString<T>::toString(Genome* genome) {
	std::stringstream ss;
	for (unsigned int i = 0; i < this->genomeLength; i++)
		ss << genome->getIndex<T>(i)
			<< (i < this->genomeLength - 1 ? this->separator : "");
	return ss.str();
}

#endif
