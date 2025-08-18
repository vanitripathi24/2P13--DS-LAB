#include<iostream>
using namespace std;

 int binarysearch(int arr[], int n , int key){
     int low = 0 , high = n-1;

     while(low<=high){
        int mid = low + (high -low)/2;

        if(arr[mid]== key){
            return mid;
        }

        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
     }
     return -1;
    
 }
 int main(){
     int arr[] = {2, 4, 7, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;
   int result = binarysearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array" << endl;

    return 0;
}
 