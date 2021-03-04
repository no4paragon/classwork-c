

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



int main()
{
    const int size = 6;
    int arr[size];
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << "\t";
    }
    cout << "\n";
    cout << arr[0] << " is the first element & the last element is " << arr[5] << endl;
    cout << "\n";

    cout << "Every element at an odd index" << endl;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 1) {
            cout << arr[i] << endl;
        }
    }
    cout << "\n";

    cout << "Every odd element" << endl;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            cout << arr[i] << endl;
        }
    }
    cout << "\n";

    cout << "All elements in reverse order" << endl;
    for (int i = 5; i >= 0; i--) {
        cout << arr[i] << "\t";
    }

    return 0;


}

