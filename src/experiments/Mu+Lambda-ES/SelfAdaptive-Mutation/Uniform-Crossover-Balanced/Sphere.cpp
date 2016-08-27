#include "objectives/continuous/n-d/SphereFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new SphereFunction(32, -1000, 1000),
		new MuPlusLambdaES(
			new UniformCrossover(1),
			new SelfAdaptiveMutation(false),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		3000
	);

	exper.run();
}
