#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void concatenatestrings(){
    string str1, str2;
    cout<<"elements of first string : ";
    getline(cin , str1);
      cout<<"elements of second string : ";
    getline(cin , str2);

    string result = str1+str2;
    cout << "Concatenated String: " << result << endl;
}
void reversestring(){
    string str;
    cout<<"enter the word to be reversed : ";
    getline(cin , str);
 reverse(str.begin() , str.end());
     cout<<"Reversed String: " << str << endl;
 }

void deletevowels(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    string result = " ";
    for(char c : str){
        char lower = tolower(c);
         if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')) {
            result += c;
    }

}
 cout << "String without vowels: " << result << endl;
}

void sortstrings(){
    int n;
     cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[100];
    for(int i =0; i<n ; i++){
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }
    sort(arr , arr+n);
    cout << "Strings in alphabetical order: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
}
}
void upperToLower() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    char lower =tolower(ch);
    cout << "lowercase : " << lower<< endl;
}
int main() {
    int choice;
    do {
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete Vowels from String\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: concatenatestrings(); break;
            case 2: reversestring(); break;
            case 3: deletevowels(); break;
            case 4: sortstrings(); break;
            case 5: upperToLower(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    return 0;
}