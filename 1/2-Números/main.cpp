#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void imprime(int vetor[], int n);
int main() {
    int numeros[20];
    int i = 0;
    while (1) {
        cin >> numeros[i];
        if (cin.eof()) break;
        i++;
    }
    int impar[20];
    int par[20];
    int numImp = 0;
    int numPar = 0;
    for (int j = 0; j < i; j++) {
        if (numeros[j] % 2 == 1) {
            impar[numImp] = numeros[j];
            numImp++;
        } else {
            par[numPar] = numeros[j];
            numPar++;
        }
    }
    imprime(par, numPar);
    imprime(impar, numImp);
    return 0;
}
void imprime(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (vetor[j] == vetor[i] && j != i) break;
            if (j == i) cout << vetor[i] << " ";
        }
    }
    cout << endl;
}
