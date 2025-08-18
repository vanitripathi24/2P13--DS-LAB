#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, num;  
    Element *data;
};
void readMatrix(SparseMatrix &m) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> m.rows >> m.cols >> m.num;
    m.data = new Element[m.num];
    cout << "Enter row, col, value (triplets): ";
    for (int i = 0; i < m.num; i++) {
        cin >> m.data[i].row >> m.data[i].col >> m.data[i].val;
    }
}
void display(const SparseMatrix &m) {
    cout << "Row Col Val" <<endl;
    for (int i = 0; i < m.num; i++) {
        cout << m.data[i].row << "   " 
             << m.data[i].col << "   " 
             << m.data[i].val << endl;
    }
}

SparseMatrix transpose(const SparseMatrix &m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.num = m.num;
    t.data = new Element[t.num];
    for (int i = 0; i < m.num; i++) {
        t.data[i].row = m.data[i].col;
        t.data[i].col = m.data[i].row;
        t.data[i].val = m.data[i].val;
    }
    return t;
}
SparseMatrix add(const SparseMatrix &a, const SparseMatrix &b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible" << endl;
        return {0,0,0,nullptr};
    }

    SparseMatrix sum;
    sum.rows = a.rows; sum.cols = a.cols;
    sum.data = new Element[a.num + b.num];
    int i=0, j=0, k=0;

    while (i<a.num && j<b.num) {
        if (a.data[i].row < b.data[j].row ||
            (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        } else if (b.data[j].row < a.data[i].row ||
                   (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            sum.data[k++] = b.data[j++];
        } else {
            sum.data[k] = a.data[i];
            sum.data[k++].val = a.data[i++].val + b.data[j++].val;
        }
    }
    while (i<a.num) sum.data[k++] = a.data[i++];
    while (j<b.num) sum.data[k++] = b.data[j++];
    sum.num = k;
    return sum;
}
SparseMatrix multiply(const SparseMatrix &a, const SparseMatrix &b) {
    if (a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        return {0,0,0,nullptr};
    }

    SparseMatrix prod;
    prod.rows = a.rows; prod.cols = b.cols;
    prod.data = new Element[a.num * b.num]; // worst case
    prod.num = 0;

    for (int i = 0; i < a.num; i++) {
        for (int j = 0; j < b.num; j++) {
            if (a.data[i].col == b.data[j].row) {
                int r = a.data[i].row;
                int c = b.data[j].col;
                int v = a.data[i].val * b.data[j].val;

                // check if (r,c) already exists
                bool found = false;
                for (int k = 0; k < prod.num; k++) {
                    if (prod.data[k].row == r && prod.data[k].col == c) {
                        prod.data[k].val += v;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    prod.data[prod.num++] = {r, c, v};
                }
            }
        }
    }
    return prod;
}

int main() {
    SparseMatrix A, B;

    cout << "Enter first matrix:";
    readMatrix(A);
    cout << "Enter second matrix:" ;
    readMatrix(B);

    cout << "Matrix A:" ; display(A);
    cout << "Matrix B:" ; display(B);

    cout << "Transpose of A:";
    SparseMatrix T = transpose(A);
    display(T);

    cout << "Addition of A and B:";
    SparseMatrix S = add(A,B);
    display(S);

    cout << "Multiplication of A and B:";
    SparseMatrix M = multiply(A,B);
    display(M);

    return 0;
}

