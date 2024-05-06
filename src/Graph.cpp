#include "Graph.h"
#include <stack>

Graph::Graph(std::vector<std::vector<bool>> inputMatrix)
{
	ConstructGraphFromMatrix(inputMatrix);
}

int64_t Graph::CalculateNumberOfConnectedComponents()
{
	int64_t numberOfConnectedComponents{ 0 };

	for (const auto& kvp : _adjacencyList)
	{
		auto vertex = kvp.first;
		if (!_visitedVertices[vertex])
		{
			++numberOfConnectedComponents;
			RunDFS(vertex);
		}
	}

	return numberOfConnectedComponents;
}

void Graph::ConstructGraphFromMatrix(std::vector<std::vector<bool>> inputMatrix)
{
	auto rowLength = inputMatrix.empty() ? 0 : inputMatrix.front().size();
	for (auto rowNumber = 0; rowNumber < inputMatrix.size(); ++rowNumber)
	{
		for (auto columnNumber = 0; columnNumber < rowLength; ++columnNumber)
		{
			if (!inputMatrix[rowNumber][columnNumber])
			{
				// This element of the input matrix is not marked, so it must not be added as a vertex in the graph
				continue;
			}

			// The consecutive number of the element in the input matrix is used as vertex id in the graph 
			auto currentElementNumber = rowNumber * rowLength + columnNumber;

			// Add the vertex id as key in the visited vertices map that will be used in the traversal later
			_visitedVertices.emplace(std::make_pair(currentElementNumber, false));

			// Add the vertex id as key to the adjacency list map
			_adjacencyList.emplace(std::make_pair(currentElementNumber, std::vector<uint64_t>()));

			// Now check whether any of the alredy processed neighbouring elements in the input matrix is also marked.
			// In case it is, add the corresponding edge to the graph
			auto previousRow = rowNumber - 1;
			auto previousColumn = columnNumber - 1;
			if (previousRow >= 0 && inputMatrix[previousRow][columnNumber])
			{
				AddEdge(previousRow * rowLength + columnNumber, rowNumber * rowLength + columnNumber);
			}
			if (previousColumn >= 0 && inputMatrix[rowNumber][previousColumn])
			{
				AddEdge(currentElementNumber - 1, currentElementNumber);
			}
		}
	}
}

void Graph::AddEdge(uint64_t startVertex, uint64_t endVertex)
{
	// This is a non-directed graph, so an edge must be added
	// both from the start vertex to te end vertex and vice versa.
	_adjacencyList[startVertex].emplace_back(endVertex);
	_adjacencyList[endVertex].emplace_back(startVertex);
}

/// <summary>
/// Performs DFS in the graps starting with staringVertexId.
/// This method uses a loop rather that recursion in order avoid stack overflows
/// which would occur in the cases of input matrices with large number of marked elements. 
/// </summary>
/// <param name="staringVertexId"> The id of the vertex to start the trevarsal with.</param>
void Graph::RunDFS(uint64_t staringVertexId)
{
	std::stack<uint64_t> traversalStack;

	traversalStack.push(staringVertexId);

	while (!traversalStack.empty())
	{
		uint64_t currentStartingVertex = traversalStack.top();
		traversalStack.pop();

		_visitedVertices[currentStartingVertex] = true;

		for (const auto& vertex : _adjacencyList[currentStartingVertex])
		{
			if (!_visitedVertices[vertex])
			{
				traversalStack.push(vertex);
			}
		}
	}
}