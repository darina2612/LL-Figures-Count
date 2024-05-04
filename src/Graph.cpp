#include "Graph.h"

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
			auto currentElementNumber = rowNumber * rowLength + columnNumber;

			if (inputMatrix[rowNumber][columnNumber])
			{
				_visitedVertices.emplace(std::make_pair(currentElementNumber, false));

				if (!_adjacencyList.contains(currentElementNumber))
				{
					_adjacencyList.emplace(std::make_pair(currentElementNumber, std::vector<uint64_t>()));
				}
			}
			else
			{
				continue;
			}

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
	// this is a non-directed graph, so an edge must be added
	// both from the start vertex to te end vertex and vice versa
	_adjacencyList[startVertex].emplace_back(endVertex);
	_adjacencyList[endVertex].emplace_back(startVertex);
}


void Graph::RunDFS(uint64_t staringVertexId)
{
	_visitedVertices[staringVertexId] = true;
	
	for (const auto& adjacentVertex : _adjacencyList[staringVertexId])
	{
		if (!_visitedVertices[adjacentVertex])
		{
			RunDFS(adjacentVertex);
		}
	}
}