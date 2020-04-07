#include "sort.h"
#include <chrono>
#include <fstream>
using namespace std::chrono;

int main()
{
	std::vector<int> numbers;
	std::ifstream file("Data/unif_2p15_300_data_1.txt");
	//std::ifstream file("my_data.txt");
	if (!file.is_open())
	{
		std::cout << "Could not open the file.\n";
		return 0;
	}
	int number;
	while(file >> number)
		numbers.push_back(number);

	// std::cout << "unsorted numbers: \n";
	// for(int i = 0; i < numbers.size(); ++i)
	// 	std::cout << numbers[i] << ' ';

	auto start = steady_clock::now();
	strand_sort(numbers);
	auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);
    std::cout << "strand sort: " << elapsed.count() << " mls\n";

	// std::cout << "\nsorted numbers: \n";
	// for(auto i : numbers)
	// 	std::cout << i << ' ';
	// std::cout << '\n';

	return 0;
}
