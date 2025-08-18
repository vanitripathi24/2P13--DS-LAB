#include <iostream>
using namespace std;


class DiagonalMatrix {
    int *arr, n;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        arr = new int[n]();   
    }
    void set(int i, int j, int val) {
        if(i==j) arr[i-1] = val;
    }
    int get(int i, int j) {
        if(i==j) return arr[i-1];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

class TriDiagonalMatrix {
    int *arr, n;
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        arr = new int[3*n - 2]();   
    }
    void set(int i, int j, int val) {
        if(i-j==1) arr[i-2] = val;           
        else if(i-j==0) arr[n-1+i-1] = val;   
        else if(i-j==-1) arr[2*n-1+i-1] = val; 
    }
    int get(int i, int j) {
        if(i-j==1) return arr[i-2];
        else if(i-j==0) return arr[n-1+i-1];
        else if(i-j==-1) return arr[2*n-1+i-1];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};


class LowerTriangular {
    int *arr, n;
public:
    LowerTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2]();  
    }
    void set(int i, int j, int val) {
        if(i>=j) arr[(i*(i-1))/2 + (j-1)] = val;
    }
    int get(int i, int j) {
        if(i>=j) return arr[(i*(i-1))/2 + (j-1)];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};


class UpperTriangular {
    int *arr, n;
public:
    UpperTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2]();
    }
    void set(int i, int j, int val) {
        if(i<=j) arr[(j*(j-1))/2 + (i-1)] = val;
    }
    int get(int i, int j) {
        if(i<=j) return arr[(j*(j-1))/2 + (i-1)];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};
class SymmetricMatrix {
    int *arr, n;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2]();
    }
    void set(int i, int j, int val) {
        if(i>=j) arr[(i*(i-1))/2 + (j-1)] = val;
        else arr[(j*(j-1))/2 + (i-1)] = val;
    }
    int get(int i, int j) {
        if(i>=j) return arr[(i*(i-1))/2 + (j-1)];
        else return arr[(j*(j-1))/2 + (i-1)];
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int choice, n;
    cout<<"Enter dimension of square matrix (n): ";
    cin>>n;

    
    cout<<"1. Diagonal Matrix\n";
    cout<<"2. Tri-diagonal Matrix\n";
    cout<<"3. Lower Triangular Matrix\n";
    cout<<"4. Upper Triangular Matrix\n";
    cout<<"5. Symmetric Matrix\n";
    cout<<"Enter choice: ";
    cin>>choice;

    int val, i, j;
    switch(choice) {
        case 1: {
            DiagonalMatrix m(n);
            cout<<"Enter diagonal elements: \n";
            for(int k=1;k<=n;k++) {
                cin>>val;
                m.set(k,k,val);
            }
            cout<<"Matrix:\n"; m.display();
            break;
        }
        case 2: {
            TriDiagonalMatrix m(n);
            cout<<"Enter elements (i j value), -1 to stop:\n";
            while(true) {
                cin>>i;
                if(i==-1) break;
                cin>>j>>val;
                m.set(i,j,val);
            }
            cout<<"Matrix:\n"; m.display();
            break;
        }
        case 3: {
            LowerTriangular m(n);
            cout<<"Enter elements (i j value), -1 to stop:\n";
            while(true) {
                cin>>i;
                if(i==-1) break;
                cin>>j>>val;
                m.set(i,j,val);
            }
            cout<<"Matrix:\n"; m.display();
            break;
        }
        case 4: {
            UpperTriangular m(n);
            cout<<"Enter elements (i j value), -1 to stop:\n";
            while(true) {
                cin>>i;
                if(i==-1) break;
                cin>>j>>val;
                m.set(i,j,val);
            }
            cout<<"Matrix:\n"; m.display();
            break;
        }
        case 5: {
            SymmetricMatrix m(n);
            cout<<"Enter elements (i j value), -1 to stop:\n";
            while(true) {
                cin>>i;
                if(i==-1) break;
                cin>>j>>val;
                m.set(i,j,val);
            }
            cout<<"Matrix:\n"; m.display();
            break;
        }
        default: cout<<"Invalid choice!";
    }

    return 0;
}
