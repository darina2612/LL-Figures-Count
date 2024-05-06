#include <vector>
#include <functional>

class TestUtils
{
public:
	static std::vector<std::vector<bool>> GenerateInputMatrix(
		size_t numberOfRows,
		size_t numberOfColumns,
		std::function<uint64_t(size_t, size_t)> generateValueAtIndex);
};