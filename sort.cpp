#include "sort.h"

void strand_sort(T & numbers)
{
    T temp;
    T result;

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

void stable_sort(T & numbers)
{
    std::stable_sort(numbers.begin(), numbers.end());
}

void pigeonhole_sort(T & numbers)
{
    int min = numbers[0], max = numbers[0];
    for(int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] > max)
            max = numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
    }

    int range = max - min + 1;

    try{
        T* pigeonholes = new T[range];
        for(int i = 0; i < numbers.size(); ++i)
        pigeonholes[numbers[i] - min].push_back(numbers[i]);

        numbers.clear();
        for(int i = 0; i < range; ++i){
            for(int j = 0; j < pigeonholes[i].size(); ++j)
                numbers.push_back((pigeonholes[i])[j]);
    }
    }
    catch(std::exception & ex){
        std::cout << ex.what() << std::endl;
    }
}

void multi_pivot_sort(std::vector<int> & numbers)
{

}

void introsort(std::vector<int> & numbers)
{

}