#ifndef OBJECTIVES_ExperimentObjective
#define OBJECTIVES_ExperimentObjective

#include <libHierGA/HierGA.hpp>
#include <vector>

class ExperimentObjective : public ObjectiveFunction {
	private:

	protected:
	unsigned int genomeLength;

	public:
	ExperimentObjective(unsigned int genomeLength);

	virtual std::vector<Locus*> getLoci()=0;
	virtual ToStringFunction* getToString()=0;
};

class ExperimentToString : public ToStringFunction {
	private:

	protected:
	unsigned int genomeLength;

	public:
	ExperimentToString(unsigned int genomeLength);
	virtual std::string toString(Genome* genome)=0;
};

#endif
