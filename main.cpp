#include <iostream>
#include <iomanip>
using namespace std;

void imprimirMatriz(  int **pMat, int tam);
int sumaDiagonal(  int **pMat, int tam );
int sumaSuperior(int **pMat, int tam);

int main()
{ int t;
     int* *pMatriz = nullptr;

    srand(time(nullptr));
    cout << "Tamanio de la matriz cuadrada: ";
    cin >> t;
    //--- dimensionar la matriz
    pMatriz = new int*[t];
    for(int f=0; f<t; f++)
        pMatriz[f] = new int[t];
    //---- llenamos la matriz con valores al azar
    for(int f=0; f<t; f++)
        for(int c=0; c<t; c++)
            pMatriz[f][c] = rand() % 99 + 1;
    imprimirMatriz(pMatriz,t);
    cout << "\n\nLa suma de los elementos de la diagonal principal : " << sumaDiagonal(pMatriz, t ) << "\n";
    cout << "\n\nLa suma de los elementos que estan por encima de la diagonal es: " << sumaSuperior(pMatriz,t) << "\n";
    //--- liberamos memoria del heap
    for(int f=0; f<t; f++)
        delete  []pMatriz[f];
    delete []pMatriz;
    pMatriz=nullptr;
    return 0;
}

int sumaSuperior(int **pMat, int tam)
{
  int suma=0;
  for(int f=0; f<tam-1; f++)
      for(int c=f+1; c<tam; c++)
          suma += pMat[f][c];
  return suma;
}

int sumaDiagonal(  int **pMat, int tam )
{   int suma=0;
    for(int i=0; i<tam; i++)
        suma = suma + pMat[i][i];
    return suma;
}


void imprimirMatriz(  int **pMat, int tam)
{
    for(int f=0; f<tam; f++) {
        for (int c = 0; c < tam; c++)
            cout << setw(4) << pMat[f][c];
        cout << "\n";
    }
}