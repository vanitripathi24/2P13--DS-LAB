//Argh 1024160084
#include <iostream>
using namespace std;

void reverseArray() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n / 2; i++) swap(arr[i], arr[n - i - 1]);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10], n;
    cout << "Enter size of square matrices: ";
    cin >> n;
    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> b[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) c[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << "Resultant matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << c[i][j] << " ";
        cout << endl;
    }
}

void transposeMatrix() {
    int a[10][10], t[10][10], r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> a[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) t[j][i] = a[i][j];

    cout << "Transpose matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) cout << t[i][j] << " ";
        cout << endl;
    }
}

int main() {
    reverseArray();
    matrixMultiplication();
    transposeMatrix();
    return 0;
}
