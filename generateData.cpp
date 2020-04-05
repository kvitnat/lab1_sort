//generate data
#include <random>
#include <iostream>
#include <fstream>
#include <string>

#define PI 3.14159265
#define e 2.71828

const int N30   = 30000;
const int N100  = 100000;
const int N300  = 300000;
const int N1mln = 1000000;

void five_copies(long range, const int N, std::string name);
void five_copies(long range, const int N, std::string name, bool);

int main()
{
    //std::ofstream data[5];

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    //..........................................................................
    //1st type : uniform from 0 to 2^31
    five_copies(2147483647, N30, "Data/unif_2p31_30_data_");
    five_copies(2147483647, N100, "Data/unif_2p31_100_data_");
    five_copies(2147483647, N300, "Data/unif_2p31_300_data_");
    five_copies(2147483647, N1mln, "Data/unif_2p31_1000_data_");


    //.................................................................
    // 2nd type : uniform from 0 to N - 1
    five_copies(N30  - 1, N30,   "Data/unif_N_30_data_");
    five_copies(N100 - 1, N100,  "Data/unif_N_100_data_");
    five_copies(N300 - 1, N300,  "Data/unif_N_300_data_");
    five_copies(N1mln- 1, N1mln, "Data/unif_N_1000_data_");


    //..............................................................
    //3rd type : uniform from 0 to 2^15
    five_copies(32768, N30, "Data/unif_2p15_30_data_");
    five_copies(32768, N100, "Data/unif_2p15_100_data_");
    five_copies(32768, N300, "Data/unif_2p15_300_data_");
    five_copies(32768, N1mln, "Data/unif_2p15_1000_data_");


    //..........................................................................
    //4st type : normal from 0 to 2^31
    bool b;
    five_copies(2147483647, N30, "Data/norm_2p31_30_data_", b);
    five_copies(2147483647, N100, "Data/norm_2p31_100_data_", b);
    five_copies(2147483647, N300, "Data/norm_2p31_300_data_", b);
    five_copies(2147483647, N1mln, "Data/norm_2p31_1000_data_", b);

    std::cout << "data generated.\n";

    return 0;
    
}



void five_copies(long range, const int N, std::string name)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dis(0, range);  


    std::ofstream data[5];
    for (int i = 0; i < 5; ++i)
    {
        std::string file = name + std::to_string(i) + ".txt";
        data[i].open(file);
        if(!data[i].is_open())
        {
            std::cout << "fail\n";
            //return 0;
        }
        for(int j = 0; j < N; ++j)
            data[i] << dis(gen) << ' ';

        data[i].close();
    }
}

void five_copies(long range, const int N, std::string name, bool)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::normal_distribution<> dis(range/2, range/10); 

    std::ofstream data[5];
    for (int i = 0; i < 5; ++i)
    {
        std::string file = name + std::to_string(i) + ".txt";
        data[i].open(file);
        if(!data[i].is_open())
        {
            std::cout << "fail\n";
            return;
        }

        for(int j = 0; j < N; ++j)
            data[i] << int(dis(gen)) << ' ';
       

        data[i].close();
    }
}