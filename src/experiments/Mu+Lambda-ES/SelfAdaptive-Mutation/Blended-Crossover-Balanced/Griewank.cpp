#include "objectives/continuous/n-d/GriewankFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new GriewankFunction(32, -1000, 1000),
		new MuPlusLambdaES(
			new BlendedCrossover(),
			new SelfAdaptiveMutation(false),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		2
	);

	exper.run();
}
