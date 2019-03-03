#include <iostream>
using std::cout;
using std::endl;

void merge (int *numbers, int lStart, int lEnd, int rStart, int rEnd)
{
    // allocate dynamic memory
    // tmp is a buffer used to store merged items while the mergins is ongoing
    int size = rEnd - lStart + 1;
    int *tmp = new int[size];
    
    int t = 0;
    int l = lStart;
    int r = rStart;
    
    while (l <= lEnd && r <= rEnd) {
        if (numbers[l] <= numbers[r]) {
            tmp[t] = numbers[l];
            l++;
        } else {
            tmp[t] = numbers[r];
            r++;
        }
        t++;
    }

    while (l <= lEnd)
        tmp[t++] = numbers[l++];
    
    while (r <= rEnd)
        tmp[t++] = numbers[r++];

    for (int i = 0; i < size; i++)
        numbers[lStart+i] = tmp[i];

    // de-allocate dynamic memory
    delete[] tmp;
}

void mergeSort (int *numbers, int left, int right) 
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(numbers, left, mid);
    mergeSort(numbers, mid+1, right);

    merge(numbers, left, mid, mid+1, right);
}

void mergeSort (int *numbers, int size)
{
    mergeSort(numbers, 0, size-1);
}

int main () 
{
    // int x = 200;
    // cout << x++ << endl;
    // cout << ++x << endl;

    int nums [8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(nums) / sizeof(int);

    mergeSort(nums, size);
    
    // pointer arithmetic
    //cout << *(nums + 1) << endl;
    
    for (int i = 0; i < size; i++) {
        cout << nums[i] <<endl;
    }
}
