#include "sort.h"
#include <chrono>
#include <fstream>
#include <map>
#include <thread>
#include <bits/stdc++.h> 

using namespace std::chrono;

void check_sort(void (*sort)(T&), std::string msg);
void count_time(std::vector<std::string> & filenames, 
				std::map<std::string, int> & average_millisec, 
				void (*sort)(T&));


int main()
{
	//check_sort(strand_sort, "strand sort");
	//check_sort(pigeonhole_sort, "pigeonhole sort");

	int intervals_millisec[5];
	std::map<std::string, int> average_millisec_strand, 
							   average_millisec_pigeon,
							   average_millisec_stable,
							   average_millisec_intrst,
							   average_millisec_quicks,
							   average_millisec_sort;

	std::vector<std::string> filenames = {"Data/unif_2p15_30_data_", //strand
										  "Data/unif_2p31_30_data_",
										  "Data/unif_N_30_data_",
										  "Data/norm_2p31_30_data_",
										  "Data/unif_2p15_100_data_",
										  "Data/unif_2p31_100_data_",
										  "Data/unif_N_100_data_",
										  "Data/norm_2p31_100_data_",
										  "Data/unif_2p15_300_data_",
										  "Data/unif_2p31_300_data_",
										  "Data/unif_N_300_data_",
										  "Data/norm_2p31_300_data_",
										  "Data/unif_2p15_1000_data_",
										  "Data/unif_2p31_1000_data_",
										  "Data/unif_N_1000_data_",
										  "Data/norm_2p31_1000_data_"
										  };	

	//std::thread th1(count_time, std::ref(filenames), std::ref(average_millisec_strand), strand_sort);
	//std::thread th2(count_time, std::ref(filenames), std::ref(average_millisec_pigeon), pigeonhole_sort);
	std::thread th3(count_time, std::ref(filenames), std::ref(average_millisec_stable), stable_sort);
	std::thread th4(count_time, std::ref(filenames), std::ref(average_millisec_intrst), introsort);
	std::thread th5(count_time, std::ref(filenames), std::ref(average_millisec_quicks), mp_quicksort);
	std::thread th6(count_time, std::ref(filenames), std::ref(average_millisec_sort), std_sort);

	//th1.join();
	//th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();

	// std::cout << "\nSTRAND\n";
	// for(auto i : average_millisec_strand)
	// 	std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";
	
	std::cout << "PIGEONHOLE\n";
	for(auto i : average_millisec_pigeon)
		std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";
	
	std::cout << "STABLE\n";
	for(auto i : average_millisec_stable)
		std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";
	
	std::cout << "INTROSORT\n";
	for(auto i : average_millisec_intrst)
		std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";

	std::cout << "QUICKSORT\n";
	for(auto i : average_millisec_quicks)
		std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";
	
	std::cout << "STD SORT\n";
	for(auto i : average_millisec_sort)
		std::cout << "    Average time for " << i.first << ": " << i.second << " mls. \n";
	

	
    return 0;
}
 
void check_sort(void (*sort)(T&), std::string msg)
{
	//displaying that sorting actually works
	T numbers;
	std::ifstream file("my_data.txt");

	if (!file.is_open()){
		std::cout << "Could not open the file.\n";
		return;
	}

	int number;
	while(file >> number)
		numbers.push_back(number);

	std::cout << "unsorted numbers: \n";
	for(int i = 0; i < numbers.size(); ++i)
		std::cout << numbers[i] << ' ';

	sort(numbers);	//sort that we want to check

	std::cout << "\n\nsorting with " << msg << "...\n" << "\nsorted numbers: \n";
	for(auto i : numbers)
		std::cout << i << ' ';

	std::cout << "\n------------------------------\n";

}


void count_time(std::vector<std::string> & filenames, std::map<std::string, int> & average_millisec, void (*sort)(T&))
{ 
	for(auto filecopy : filenames)
	{
		std::ifstream file[5];
		for(int i = 0; i < 5; ++i)
			file[i].open(filecopy + std::to_string(i) + ".txt");

		for(int i = 0; i < 5; ++i)
			if (!(file[i]).is_open()){
				std::cout << "Could not open the file " << filecopy << i << "\n";
				return;
			}

		int sum = 0;
		for(int i = 0; i < 5; ++i){
			T numbers;
			int number;
			while(file[i] >> number)
				numbers.push_back(number);

			auto start = steady_clock::now();
			sort(numbers);
			auto end = steady_clock::now();
			sum += duration_cast<milliseconds>(end - start).count();
		}
		average_millisec[filecopy] = sum/5;
		std::cout << ".\n";

		for(int i = 0; i < 5; ++i)
			file[i].close();
 
	}
}