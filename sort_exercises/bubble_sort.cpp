#include <iostream>
#include <string>

void swap (int *numbers, int i, int j) 
{
    int tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
}

void bubble_sort (int *numbers, int numItems)
{
    std::cout << "size: " << sizeof(numbers) << std::endl;
    bool swapped = false;
    
    for (int i = numItems-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (numbers[j] <= numbers[j+1]) continue;
            
            swap(numbers, j, j+1); 
            swapped = true;
        }

        if (!swapped)
            break;
        else
            swapped = false;
    }
}  

int main ()
{
    // reads a token from stdin and tries to interpret it as a string
    // cin can read into other variables types as well, e.g. std::string
    // error handling is important with cin, or you may notice strange
    // behaviour
    int x;
    std::string name;
    std::cin >> x;
    std::cin >> name;
    std::cout << "read: " << x << ", " << name << std::endl;
       
    int numbers [5] = { 6, 5, 4, 3, 2 }; 
    int numItems = sizeof(numbers) / sizeof(int);
    bubble_sort(numbers, numItems);

    for (int i = 0; i < numItems; i++) {
        std::cout << numbers[i] << std::endl;    
    }
}
