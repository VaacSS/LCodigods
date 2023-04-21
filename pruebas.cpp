#include <iostream>

using namespace std;

const int MAX_DISCS = 10;

void printTowers(int A[], int B[], int C[], int n) {
    for (int i = n-1; i >= 0; i--) {
        if (i < n - A[0]) {
            cout << A[i+1];
        } else {
            cout << " ";
        }
        cout << "  ";
        if (i < n - B[0]) {
            cout << B[i+1];
        } else {
            cout << " ";
        }
        cout << "  ";
        if (i < n - C[0]) {
            cout << C[i+1];
        } else {
            cout << " ";
        }
        cout << endl;
    }
    cout << "--------------------------\n";
    cout << "  A     B     C\n\n";
}

void move(int A[], int B[], int C[], int& from, int& to) {
    if (from == 0) {
        cout << "Movimiento inválido" << endl;
        return;
    }
    if (to != 0 && C[to] < A[from]) {
        cout << "Movimiento inválido" << endl;
        return;
    }
    int disk = A[from];
    A[from] = 0;
    to++;
    C[to] = disk;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de discos: ";
    cin >> n;

    int A[MAX_DISCS+1] = {n};
    int B[MAX_DISCS+1] = {0};
    int C[MAX_DISCS+1] = {0};

    for (int i = 1; i <= n; i++) {
        A[i] = n - i + 1;
    }

    printTowers(A, B, C, n);

    int from, to;
    while (C[n] == 0) {
        cout << "Ingrese la torre de origen (1 para A, 2 para B, 3 para C): ";
        cin >> from;
        cout << "Ingrese la torre de destino (1 para A, 2 para B, 3 para C): ";
        cin >> to;
        move(A, B, C, from, to);
        printTowers(A, B, C, n);
    }

    cout << "¡Juego completado!" << endl;

    return 0;
}
