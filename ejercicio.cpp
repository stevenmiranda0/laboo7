#include <iostream>
#include <fstream>
using namespace std;

void leerArchivo(int numeros[], int &tam) {
    ifstream archivo("datos.txt");
    tam = 0;

    if (!archivo) {
        cout << "No se pudo abrir datos.txt" << endl;
        return;
    }

    while (archivo >> numeros[tam]) {
        tam++;
        if (tam >= 100) {
            cout << "Advertencia: Se alcanzó el límite de 100 números." << endl;
            break;
        }
    }

    archivo.close();
}

void clasificarNumeros(int numeros[], int tam) {
    ofstream pares("pares.txt", ios::trunc);
    ofstream impares("impares.txt", ios::trunc);

    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0)
            pares << numeros[i] << endl;
        else
            impares << numeros[i] << endl;
    }

    cout << "Clasificación lista.\n";
}

void ordenarArchivo(const char nombre[]) {
    int arr[100], tam = 0;
    ifstream archivo(nombre);

    if (!archivo) {
        cout << "No se pudo abrir " << nombre << endl;
        return;
    }

    while (archivo >> arr[tam] && tam < 100)
        tam++;
    archivo.close();

    for (int i = 0; i < tam - 1; i++)
        for (int j = 0; j < tam - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    ofstream nuevo(nombre, ios::trunc);
    for (int i = 0; i < tam; i++)
        nuevo << arr[i] << endl;

    cout << "Archivo " << nombre << " ordenado.\n";
}

void mostrarArchivo(const char nombre[]) {
    ifstream archivo(nombre);
    int x;

    if (!archivo) {
        cout << "No se pudo abrir " << nombre << endl;
        return;
    }

    cout << "\n--- Contenido de " << nombre << " ---\n";
    while (archivo >> x)
        cout << x << " ";
    cout << "\n\n";

    archivo.close();
}

int main() {
    int numeros[100], tam = 0;
    int opcion;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Clasificar numeros\n";
        cout << "2. Ordenar archivos\n";
        cout << "3. Ver resultados\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                leerArchivo(numeros, tam);
                clasificarNumeros(numeros, tam);
                break;
            case 2:
                ordenarArchivo("pares.txt");
                ordenarArchivo("impares.txt");
                break;
            case 3:
                mostrarArchivo("pares.txt");
                mostrarArchivo("impares.txt");
                break;
            case 4:
                cout << "Adiós...\n";
                break;
            default:
                cout << "Opción no válida\n";
        }

    } while (opcion != 4);

    return 0;
