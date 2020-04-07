#include "sort.h"
void strand_sort(std::vector<int> & numbers)
{
    std::vector<int> temp;
    std::vector<int> result;

    while(numbers.size() > 0)
    {
        temp.push_back(numbers[0]);
        numbers.erase(numbers.begin() + 0);
        for(int i = 0; i < numbers.size(); ++i)
            if(numbers[i] >= temp[temp.size() - 1])
            {
                temp.push_back(numbers[i]);
                numbers.erase(numbers.begin() + i);
                i--;
            }
        int j = 0;
        for(int i = 0; i < result.size() && j < temp.size(); ++i)
            if(temp[j] < result[i])
                result.insert(result.begin() + i, temp[j++]);
        
        if(j < temp.size())
            result.insert(result.end(), temp.begin() + j, temp.end());
        temp.clear();
    }
    numbers = result;
}

void pigeonhole_sort(std::vector<int> & numbers)
{

}

void multi_pivot_sort(std::vector<int> & numbers)
{

}

void introsort(std::vector<int> & numbers)
{

}