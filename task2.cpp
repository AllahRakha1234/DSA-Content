#include <iostream>
#include <time.h>
using namespace std;
// Display Function
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
// Counting Sort
void countingSort(int arr[], int size)
{
    int largest = 0;
    int temp[size];
    // Finding Largest element
    for (int i = 0; i < size; i++)
    {
        if (largest < arr[i])
            largest = arr[i];
    }
    int freqDist[largest + 1]; // One increment in largest element to include zero as well
    // Initialinzing freqDist to zero
    for (int i = 0; i <= largest; i++)
    {
        freqDist[i] = 0;
    }
    // Finding Frequency Distribution
    for (int i = 0; i < size; i++)
    {
        freqDist[arr[i]]++;
    }
    // Finding Comulative Sum
    for (int i = 1; i <= largest; i++)
    {
        freqDist[i] += freqDist[i - 1];
    }
    // Sorting Array
    for (int i = 0; i < size; i++)
    {
        freqDist[arr[i]]--;
        temp[freqDist[arr[i]]] = arr[i];
    }
    // Diplaying sorted array
    cout << "Sorted Array: " << endl;
    display(temp, size);
}
int main()
{
    int size ;
    int range = 100 ;
    cout << "Enter the size of the array: " ;
    cin >> size ;
    int array[size];
    srand(time(NULL)); // Generating random numbers to populate the array
    for (int i = 0; i < size; i++)
    {
        int random = 1 + (rand() % 100);
        array[i] = random;
    }
    cout << "Given array: " << endl;
    display(array, size);     // Displaying the given array 
    countingSort(array, size);  // Calling countingSort function
    return 0;
}