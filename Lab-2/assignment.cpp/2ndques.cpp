#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i =0; i<n ; i++){
        for(int j =0; j< i-n-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
cout << "Original array: ";
    printArray(arr, n);

    bubblesort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;

}