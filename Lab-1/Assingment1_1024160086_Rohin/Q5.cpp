#include <iostream>
using namespace std;

int main() {
    

    int arr[2][2]={{1,2},{3,4}};    
    cout << "\nSum of each row:\n";
    for (int i = 0; i < 2; i++) {
        int rowSum = 0;
        for (int j = 0; j < 2; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " = " << rowSum << endl;
    }

    
    cout << "\nSum of each column:\n";
    for (int j = 0; j < 2; j++) {
        int colSum = 0;
        for (int i = 0; i < 2; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}