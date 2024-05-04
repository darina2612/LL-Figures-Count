#include "ConsoleInterfaceRunner.h"
#include <iostream>
#include <string>
#include <vector>

void ConsoleInterfaceRunner::Run()
{
	bool shouldContinue{true};
	while (shouldContinue)
	{
		shouldContinue = ProcessSingleIteration();
	}

	return;
}

bool ConsoleInterfaceRunner::ProcessSingleIteration()
{
	

	return true;
}

bool ConsoleInterfaceRunner::ReadIterationInput()
{
	// TODO: Check whether 'esc' was pressed. If so, return false - execution should be terminated.

	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> inputMatrix;

	return true;
}

