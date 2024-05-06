#include <vector>

class ConsoleInterfaceRunner
{
public:
	static void Run();

private:
	static void ProcessSingleIteration();
	static void ProcessIterationInput(std::vector<std::vector<bool>>& inputMatrix);
	static void PrintUsageInfo();

	static const char EmptyElementSymbol;
	static const char MarkedElementSymbol;
};