#include "objectives/discrete/binary/AverageFragmentFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new AverageFragmentFunction(32),
		new MuPlusLambdaES(
			new UniformMutation(0.05),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		1000
	);

	exper.run();
}
