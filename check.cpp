#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("Data/norm_2p31_30_data_0.txt");
    if(!fin.is_open() || fin.eof())
    {
        std::cout << "no file!\n";
        return 0;
    }
    std::vector<int> numbers;
    int n;
    while(fin >> n)
        numbers.push_back(n);

    int size = numbers.size();
    double range = 2147483647;

    int mmax = 0, mmin = range/4;
    const int intervals = 20;
    int q[intervals] = {};
    
    //calculating how many numbers in each interval
    for(auto n : numbers)
    {
        if(n > mmax)
            mmax = n;
        if(n < mmin)
            mmin = n;
        q[int(n / range * double(intervals))]++;
    }

    std::cout << "min: " << mmin << "\nmax: " << mmax << "\n";

    for(int i = 0; i < intervals; ++i)
        std::cout << i << ": " << q[i] << '\n'; 

    double k = 0;
    for(int i = 0; i < intervals; ++i) //finding max value in q[] to calculate ***
        if (q[i] > k)
            k = q[i];

    //displaying distribution of data
    for(int i = 0; i < intervals; ++i)
    {
        double f = q[i] / k * double(intervals);
        for(int j = 0; j < f; j++) 
            std::cout << '*';
        std::cout << '\n';
    }

    return 0;
}