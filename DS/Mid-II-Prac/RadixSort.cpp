#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

void countingSort(int arr[],const int n, int exp)
{
    int output[n];
    int count[10] = {0};


    // Loop1: Sorting according to digits, count occurence   
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/exp) %10 ]++;
    }
    

    // Loop2: Cummulative addition
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    
    // Loop3: Counting sort algo for output array
    for (int i = n-1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }
    
    //Loop4: Copy the output array into orignal
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    
}

//Radix function
void radixSort(int arr[], int n)
{
    int max = findMax(arr, n);

    //Loop: Calling count sort per digit
    for (int exp = 1; max / exp > 0 ; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
    
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
