#include "objectives/continuous/n-d/F8F2Function.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new F8F2Function(32),
		new MuPlusLambdaES(
			new UniformCrossover(1, {0.3, 0.7}),
			new SelfAdaptiveMutation(false),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		30
	);

	exper.run();
}
