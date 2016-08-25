#include "objectives/discrete/binary/BinaryObjective.hpp"

BinaryObjective::BinaryObjective(
	unsigned int genomeLength
) : DiscreteObjective<unsigned int>(genomeLength, 0, 1) {}

ToStringFunction* BinaryObjective::getToString() {
	return new ExperimentToString<unsigned int>(this->genomeLength, "");
}
