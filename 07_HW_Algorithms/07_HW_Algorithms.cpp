#include <iostream>
using namespace std;

/*Task 1*/
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) 
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


/*Task 2*/
int pow(int a, int b) 
{
    if (b == 0)
    return 1;

    return a * pow(a, b - 1);
}

/*Task 3*/
int binarySearch(int arr[], int left, int right, int target) 
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}


int main() {
    const int MAX_SIZE = 20;
    int arr[MAX_SIZE];
    int n;

	cout << "Enter size of array (max " << MAX_SIZE << "): " << endl;
    cin >> n;

    if (n <= 0 || n > MAX_SIZE)
    {
        cout << "Incorrect size of array. Try again!" << endl;
    }

	cout << "Enter elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left, right;
    cout << "Enter left index to sort (0.." << n - 1 << "): "; cin >> left;
    cout << "Enter right index to sort (0.." << n - 1 << "): "; cin >> right;

    if (left < 0 || right >= n || left > right)
    {
        cout << "Invalid sorting range!!! Try again!" << endl;
        return 1;
    }

    quickSort(arr, left, right);

    cout << "Array after sorting the range [" << left << ", " << right << "]: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*Task 2*/
    int number, degree;
    cout << "Enter number: "; cin >> number;
    cout << "Enter degree: "; cin >> degree;

    if (degree < 0)
    {
        cout << "Degree must be non-negative." << endl;
    }

    int result = pow(number, degree);
    cout << number << "^" << degree << " = " << result << endl;

    /*Task 3*/
    int Arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 18 };
    int N = sizeof(Arr) / sizeof(Arr[0]);

    int target;
    cout << "Enter the number to search in array [ ";
    for (int i = 0; i < N; i++) 
    {
        cout << Arr[i] << " ";
    }
    cout << "]: ";
    cin >> target;

    int index = binarySearch(Arr, 0, N - 1, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    
}
