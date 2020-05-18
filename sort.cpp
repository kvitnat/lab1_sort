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




void swapValue(int *a, int *b) 
{ 
    int *temp = a; 
    a = b; 
    b = temp; 
    return; 
} 
  
/* Function to sort an array using insertion sort*/
void InsertionSort(int arr[], int *begin, int *end) 
{ 
    // Get the left and the right index of the subarray 
    // to be sorted 
    int left = begin - arr; 
    int right = end - arr; 
  
    for (int i = left+1; i <= right; i++) 
    { 
        int key = arr[i]; 
        int j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= left && arr[j] > key) 
        { 
            arr[j+1] = arr[j]; 
            j = j-1; 
        } 
        arr[j+1] = key; 
   } 
  
   return; 
} 
  
// A function to partition the array and return 
// the partition point 
int* Partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            // increment index of smaller element 
            i++; 
  
            std::swap(arr[i], arr[j]); 
        } 
    } 
    std::swap(arr[i + 1], arr[high]); 
    return (arr + i + 1); 
} 
  
  
// A function that find the middle of the 
// values pointed by the pointers a, b, c 
// and return that pointer 
int *MedianOfThree(int * a, int * b, int * c) 
{ 
    if (*a < *b && *b < *c) 
        return (b); 
  
    if (*a < *c && *c <= *b) 
        return (c); 
  
    if (*b <= *a && *a < *c) 
        return (a); 
  
    if (*b < *c && *c <= *a) 
        return (c); 
  
    if (*c <= *a && *a < *b) 
        return (a); 
  
    if (*c <= *b && *b <= *a) 
        return (b); 
} 

void IntrosortUtil(int arr[], int * begin, 
                  int * end, int depthLimit) 
{ 
    // Count the number of elements 
    int size = end - begin; 
  
      // If partition size is low then do insertion sort 
    if (size < 16) 
    { 
        InsertionSort(arr, begin, end); 
        return; 
    } 
    
    // If the depth is zero use heapsort 
    if (depthLimit == 0) 
    { 
        std::make_heap(begin, end+1); 
        std::sort_heap(begin, end+1); 
        return; 
    } 
  
    // Else use a median-of-three concept to 
    // find a good pivot 
    int * pivot = MedianOfThree(begin, begin+size/2, end); 
  
    // Swap the values pointed by the two pointers 
    swapValue(pivot, end); 
  
   // Perform Quick Sort 
    int * partitionPoint = Partition(arr, begin-arr, end-arr); 
    IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1); 
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1); 
  
    return; 
} 
  
/* Implementation of introsort*/
void introsort(T & numbers) 
{ 
    int * begin = &numbers[0];
    int * end = &numbers[numbers.size() - 1];
    int depthLimit = 2 * log(end-begin); 
    int* arr = &numbers[0];

    // Perform a recursive Introsort 
    IntrosortUtil(arr, begin, end, depthLimit); 
  
    return; 
} 

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

void mp_quicksort(T & numbers)
{
    int * arr = &numbers[0];
    int low = 0, high = numbers.size() - 1;
    quickSort(arr, low, high);
}

void std_sort(T & numbers)
{
    std::sort(numbers.begin(), numbers.end());
}