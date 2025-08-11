#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = n - 1;
    while (start < end) {        
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}