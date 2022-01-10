#include <bits/stdc++.h>
using namespace std;
int H[50];
int size = -1;
// Function to return the index of the
// parent node of a given node
int parent(int i)
{

    return (i - 1) / 2;
}

// Function to return the index of the
// left child of the given node
int leftChild(int i)
{

    return ((2 * i) + 1);
}

// Function to return the index of the
// right child of the given node
int rightChild(int i)
{

    return ((2 * i) + 2);
}

void shiftDown(int i)
{
    int maxIndex = i;

    // Left Child
    int l = leftChild(i);

    if (l <= size && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }

    // If i not same as maxIndex
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {

        // Swap parent and current node
        swap(H[parent(i)], H[i]);

        // Update i to parent of i
        i = parent(i);
    }
}
// Function to insert a new element
// in the Binary Heap
void insert(int p)
{
    size = size + 1;
    H[size] = p;

    // Shift Up to maintain heap property
    shiftUp(size);
}
int extractMax()
{
    int result = H[0];

    // Replace the value at the root
    // with the last leaf
    H[0] = H[size];
    size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}
void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}
int getMax()
{

    return H[0];
}
void remove(int i)
{
    H[i] = getMax() + 1;

    // Shift the node to the root
    // of the heap
    shiftUp(i);

    // Extract the node
    extractMax();
}
void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
void bulidMaxHeap(int arr[], int n)
{
    // Creating MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    bulidMaxHeap(arr, n);
    // Deleting Elements from MaxHeap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}
void min_heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (i != smallest)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}
void buildMinHeap(int arr[], int n)
{
    // Creating MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
}
void heapSortReverse(int arr[], int n)
{
    buildMinHeap(arr, n);
    // Deleting Elements from MaxHeap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n, ch;
    int *A;
    int num, x, k = 0, element;
    do
    {
        cout << "\nMenus are:" << endl;
        cout << "0.Exit: " << endl;
        cout << "1.Random Numbers: " << endl;
        cout << "2.Display the array: " << endl;
        cout << "3.HeapSort the array in Ascending Order: " << endl;
        cout << "4.HeapSort the array in Descending Order: " << endl;
        cout << "5.Extract largest element: " << endl;
        cout << "6.Replace a value at node with new value: " << endl;
        cout << "7.Insert a new element: " << endl;
        cout << "8.Delete an element: " << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        int i = 0;
        switch (ch)
        {
        case 1:
            cout << "Enter the size of the array: ";
            cin >> n;
            A = new int[n];
            for (int i = 0; i < n; i++)
            {
                A[i] = rand() % 100;
                insert(A[i]);
            }
            break;
        case 2:
            cout << "The array is:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << A[i] << " ";
            }
            cout << "\n";
            cout << "Priority Queue : ";
            while (i <= size)
            {
                cout << H[i] << " ";
                i++;
            }
            break;
        case 3:
            heapSort(A, n);
            break;
        case 4:
            heapSortReverse(A, n);
            break;
        case 5:
            cout << "Node with maximum priority : " << extractMax() << "\n";
            break;
        case 6:
            cout << "Enter the node and value to be replaced: " << endl;
            cin >> num >> x;
            changePriority(num, x);
            cout << "Priority queue after "
                 << "priority change : ";
            while (k <= size)
            {
                cout << H[k] << " ";
                k++;
            }
            cout << "\n";
            break;
        case 7:
            cout << "Enter the element to be inserted: " << endl;
            cin >> element;
            insert(element);
            break;
        case 8:
            cout << "Enter the element to be deleted: " << endl;
            cin >> element;
            remove(element);
        }
    } while (ch != 0);
    delete A;
    return 0;
}
