#include "sort.h"
#include <fstream>

int main()
{
	std::vector<int> numbers;
	std::ifstream file("Data/unif_2p15_30_data_0.txt");
	if (!file.is_open())
	{
		std::cout << "Could not open the file.\n";
		return 0;
	}
	int number;
	while(file >> number)
		numbers.push_back(number);

	strand(numbers);
	return 0;
}
