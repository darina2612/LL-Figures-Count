#include "TestUtils.h"

std::vector<std::vector<bool>> TestUtils::GenerateInputMatrix(
	size_t numberOfRows,
	size_t numberOfColumns,
	std::function<uint64_t(size_t, size_t)> generateValueAtIndex)
{
	std::vector<std::vector<bool>> inputMatrix(numberOfRows, std::vector<bool>(numberOfColumns, false));

	for (auto row = 0; row < numberOfRows; ++row)
	{
		for (auto column = 0; column < numberOfColumns; ++column)
		{
			inputMatrix[row][column] = generateValueAtIndex(row, column);
		}
	}

	return inputMatrix;
}