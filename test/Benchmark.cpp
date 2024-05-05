#include <benchmark/benchmark.h>

#include "Graph.h"

static void BM_CalculateConnectedComponents_NoMarkedElements(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), false));

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_NoMarkedElements)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_AllElementsAreMarked(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), true));

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_AllElementsAreMarked)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_DiagonalIsMarked(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), false));

	for (auto i = 0; i < std::min(state.range(0), state.range(1)); ++i)
	{
		inputMatrix[i][i] = true;
	}

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_DiagonalIsMarked)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_EveryOtherRowIsMarked(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), false));

	for (auto row = 0; row < state.range(0); row += 2)
	{
		for (auto column = 0; column < state.range(0); ++column)
		{
			inputMatrix[row][column] = true;
		}
	}

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_EveryOtherRowIsMarked)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_EveryOtherColumnIsMarked(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), false));

	for (auto row = 0; row < state.range(0); ++row)
	{
		for (auto column = 0; column < state.range(0); column += 2)
		{
			inputMatrix[row][column] = true;
		}
	}

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_EveryOtherColumnIsMarked)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_RandomElementsAreMarked(benchmark::State& state)
{
	std::vector<std::vector<bool>> inputMatrix(state.range(0), std::vector<bool>(state.range(1), false));

	for (auto row = 0; row < state.range(0); ++row)
	{
		for (auto column = 0; column < state.range(0); ++column)
		{
			inputMatrix[row][column] = rand() % 2 == 0;
		}
	}

	while (state.KeepRunning())
	{
		Graph graph(inputMatrix);
		graph.CalculateNumberOfConnectedComponents();
	}
}

BENCHMARK(BM_CalculateConnectedComponents_RandomElementsAreMarked)
->Args({ 1, 1 })
->Args({ 10, 10 })
->Args({ 10, 100 })
->Args({ 1000, 100 })
->Args({ 1000, 20000 })
->Args({ 100000, 20000 })
->Args({ 500000, 500000 })
->Args({ 1000000, 2000000 })
->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();