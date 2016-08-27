#include "objectives/continuous/n-d/RosenbrockFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new RosenbrockFunction(32, -10, 10),
		new MuPlusLambdaES(
			new UniformCrossover(1),
			new SelfAdaptiveMutation(false),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		150
	);

	exper.run();
}
