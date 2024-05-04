#include <gtest/gtest.h>

#include "Graph.h"

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

TEST(GraphTests, NoMarkedElements) {
	Graph graph({
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},

		});

	ASSERT_EQ(0, graph.CalculateNumberOfConnectedComponents());
}

TEST(GraphTests, MarkedElementsOnDiagonal) {
	Graph graph({
		{true, false, false, false},
		{false, true, false, false},
		{false, false, true, false},
		{false, false, false, true},
		});

	ASSERT_EQ(4, graph.CalculateNumberOfConnectedComponents());
}

TEST(GraphTests, AllElementsAreMarked) {
	Graph graph({
		{true, true, true, true},
		{true, true, true, true},
		{true, true, true, true},
		});

	ASSERT_EQ(1, graph.CalculateNumberOfConnectedComponents());
}