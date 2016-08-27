#include "objectives/continuous/n-d/RastriginFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new RastriginFunction(32),
		new MuPlusLambdaES(
			new UniformCrossover(1),
			new SelfAdaptiveMutation(false),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		200
	);

	exper.run();
}
