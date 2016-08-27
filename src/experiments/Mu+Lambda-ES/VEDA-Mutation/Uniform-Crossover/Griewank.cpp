#include "objectives/continuous/n-d/GriewankFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new GriewankFunction(32, -1000, 1000),
		new VEDA_ES(
			150,
			new UniformCrossover(1, {0.3, 0.7})
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		20
	);

	exper.run();
}
