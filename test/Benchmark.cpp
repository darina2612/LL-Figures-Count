#include <benchmark/benchmark.h>

#include "Graph.h"
#include "TestUtils.h"

static void BM_CalculateConnectedComponents_NoMarkedElements(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(state.range_x(), state.range_y(), [](size_t, size_t) { return false; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_AllElementsAreMarked(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(state.range_x(), state.range_y(), [](size_t, size_t) { return true; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_DiagonalIsMarked(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(
		state.range_x(),
		state.range_y(),
		[](size_t row, size_t column) { return row == column; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_EveryOtherRowIsMarked(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(
		state.range_x(),
		state.range_y(),
		[](size_t row, size_t) { return row % 2 == 0; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_EveryOtherColumnIsMarked(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(
		state.range_x(),
		state.range_y(),
		[](size_t, size_t column) { return column % 2 == 0; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

static void BM_CalculateConnectedComponents_RandomElementsAreMarked(benchmark::State& state)
{
	auto inputMatrix = TestUtils::GenerateInputMatrix(state.range_x(), state.range_y(), [](size_t, size_t) { return rand() % 2 == 0; });

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
->Args({ 1000, 1000 })
->Args({ 1000, 10000 })
->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();