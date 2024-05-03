#pragma once
#include <vector>
#include <unordered_map>

class Graph
{
public:
	Graph(std::vector<std::vector<bool>> inputMatrix);

	int64_t CalculateNumberOfConnectedComponents();

private:
	void ConstructGraphFromMatrix(std::vector<std::vector<bool>> inputMatrix);
	void AddEdge(uint64_t srartVertex, uint64_t endVertex);
	void RunDFS(uint64_t staringVertexId);

	std::unordered_map<uint64_t, std::vector<uint64_t>> _adjacencyList;
	std::unordered_map<uint64_t, bool> _visitedVertices;
};