#include <gtest/gtest.h>

#include "Graph.h"
#include "TestUtils.h"

// This is the example form the task definition
TEST(GraphTests, SmokeTest) {
	Graph graph({
		{true, false, false, false, false},
		{true, false, true, true, false},
		{false, true, false, true, false},
		{false, true, true, true, false},
		{false, false, false, false, true}
		});

	ASSERT_EQ(3, graph.CalculateNumberOfConnectedComponents());
}

class ParametrisedGraphTests : public ::testing::TestWithParam<std::pair<size_t, size_t>> {
};

TEST_P(ParametrisedGraphTests, NoMarkedElements) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(inputSize.first, inputSize.second, [](size_t, size_t) { return false; }));

	ASSERT_EQ(0, graph.CalculateNumberOfConnectedComponents());
}

TEST_P(ParametrisedGraphTests, AllElementsAreMarked) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(inputSize.first, inputSize.second, [](size_t, size_t) { return true; }));

	ASSERT_EQ(1, graph.CalculateNumberOfConnectedComponents());
}

TEST_P(ParametrisedGraphTests, MarkedElementsOnDiagonal) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(inputSize.first, inputSize.second, [](size_t row, size_t column) { return row == column; }));

	ASSERT_EQ(std::min(inputSize.first, inputSize.second), graph.CalculateNumberOfConnectedComponents());
}

TEST_P(ParametrisedGraphTests, EveryOtherRowIsMarked) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(inputSize.first, inputSize.second, [](size_t row, size_t) { return row % 2 == 0; }));

	// In case each row with even index is marked,
	// the number of marked rows is number of rows / 2 for even number of rows
	// and (number of rows / 2) + 1 for odd number of rows.
	auto expectedNumberOfConnectedComponents = inputSize.first / 2 + inputSize.first % 2;
	ASSERT_EQ(expectedNumberOfConnectedComponents, graph.CalculateNumberOfConnectedComponents());
}

TEST_P(ParametrisedGraphTests, EveryOtherColumnIsMarked) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(inputSize.first, inputSize.second, [](size_t, size_t column) { return column % 2 == 0; }));

	// In case each column with even index is marked,
	// the number of marked columns is number of columns / 2 for even number of columns
	// and (number of columns / 2) + 1 for odd number of columns.
	auto expectedNumberOfConnectedComponents = inputSize.second / 2 + inputSize.second % 2;
	ASSERT_EQ(expectedNumberOfConnectedComponents, graph.CalculateNumberOfConnectedComponents());
}

TEST_P(ParametrisedGraphTests, EveryOtherRowAndEveryOtherColumnAreMarked) {
	const auto& inputSize = GetParam();
	Graph graph(TestUtils::GenerateInputMatrix(
		inputSize.first,
		inputSize.second,
		[](size_t row, size_t column) { return (row % 2 == 0) || (column % 2 == 0); }));

	ASSERT_EQ(1, graph.CalculateNumberOfConnectedComponents());
}

INSTANTIATE_TEST_CASE_P(
	ParametrisedGraphTests,
	ParametrisedGraphTests,
	::testing::Values(
		std::make_pair(2, 3),
		std::make_pair(3, 2),
		std::make_pair(5, 5),
		std::make_pair(10, 10),
		std::make_pair(15, 10),
		std::make_pair(10, 15)));
