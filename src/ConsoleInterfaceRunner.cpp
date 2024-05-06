#include "ConsoleInterfaceRunner.h"
#include "Graph.h"
#include <format>
#include <iostream>
#include <string>
#include <algorithm>

const char ConsoleInterfaceRunner::EmptyElementSymbol = 'o';
const char ConsoleInterfaceRunner::MarkedElementSymbol = 'x';

void ConsoleInterfaceRunner::Run()
{
	while (true)
	{
		ProcessSingleIteration();
	}
}

void ConsoleInterfaceRunner::ProcessSingleIteration()
{
	PrintUsageInfo();

	std::vector<std::vector<bool>> inputMatrix;

	try
	{
		ProcessIterationInput(inputMatrix);
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << std::format("Current iteration failed: {}\nTry again.\n", + ex.what());
		return;
	}

	Graph graph(inputMatrix);

	std::cout << "Figures count: " << graph.CalculateNumberOfConnectedComponents() << std::endl;
}

void ConsoleInterfaceRunner::ProcessIterationInput(std::vector<std::vector<bool>>& inputMatrix)
{
	size_t n, m;

	std::cin >> n >> m;
	std::cin.get();

	for (auto row = 0; row < n; ++row)
	{
		std::string line;
		std::getline(std::cin, line);

		if (line.length() != m)
		{
			throw std::invalid_argument(std::format("Unexpected row lenght. Expected {} elements in a row, got {}.", m, line.length()).c_str());
		}

		std::vector<bool> inputRow(m);
		std::transform(
			line.cbegin(),
			line.cend(),
			inputRow.begin(),
			[](char c)
			{
				if (tolower(c) == EmptyElementSymbol)
				{
					return true;
				}

				if (tolower(c) == MarkedElementSymbol)
				{
					return false;
				}

				throw std::invalid_argument(std::format("Invalid element representation - \'{}\'.", c));
			});

		inputMatrix.emplace_back(inputRow);
	}
}

void ConsoleInterfaceRunner::PrintUsageInfo()
{
	std::cout << std::format(
		"Enter the dimentions of the input matrix and then the matrix itself.\n"
		"Use \'{}\' to represent empty elements and \'{}\' to represent the marked ones.\n",
		EmptyElementSymbol,
		MarkedElementSymbol);
}

