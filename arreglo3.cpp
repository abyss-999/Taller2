#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

int busquedaBinaria(int arreglo[], int inicio, int fin, int objetivo) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arreglo[medio] == objetivo)
            return medio;
        else if (arreglo[medio] < objetivo)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1; 
}

int main() {
    const int maxElementos = 100;
    int arreglos[3][maxElementos];
    int n;

    for (int arregloIndex = 0; arregloIndex < 3; arregloIndex++) {
        cout << "Digite la cantidad de datos del arreglo " << arregloIndex + 1 << " (max " << maxElementos << "): ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Digite un numero: ";
            cin >> arreglos[arregloIndex][i];
        }

        sort(arreglos[arregloIndex], arreglos[arregloIndex] + n);
    }

    for (int arregloIndex = 0; arregloIndex < 3; arregloIndex++) {
        cout << "Elementos del arreglo " << arregloIndex + 1 << ":\n";
        for (int i = 0; i < n; i++) {
            cout << i << "->" << arreglos[arregloIndex][i] << endl;
        }

        int objetivo;
        cout << "Ingrese el valor a buscar en el arreglo " << arregloIndex + 1 << ": ";
        cin >> objetivo;

        int indiceEncontrado = busquedaBinaria(arreglos[arregloIndex], 0, n - 1, objetivo);
        if (indiceEncontrado != -1) {
            cout<<"*****************************************"<<endl;
            cout << "El valor " << objetivo << " se encuentra en la posicion " << indiceEncontrado << endl;
            cout<<"*****************************************"<<endl;
        } else {
            cout<<"*****************************************"<<endl;
            cout << "El valor " << objetivo << " no se encontro en el arreglo.\n";
            cout<<"*****************************************"<<endl;
        }
    }

    getch();
    return 0;
}
