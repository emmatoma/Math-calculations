#include <stdio.h>
#include <math.h>
#include <limits>
#include <iostream>

using namespace std;

const int maxV=1000;
int i, j, n;
double GR[maxV][maxV]; //Grafo con las distancias
double siguiente[maxV][maxV]; // Matriz de rutas
// Valor inf
double inf = 1.0 /0.0;
void muestra_matriz(double M[][maxV],int n){
    int i,j ;
for (i=1; i<=n; i++) {
      for (j=1; j<=n; j++) cout<<M[i][j]<<"\t";
         cout<<endl;
    } cout<<endl;
}
//Algoritmo de Floyd-Warshall
void FU(double D[][maxV], int V)
{
int k;
for (i=1; i<=V; i++) D[i][i]=0;
for (k=1; k<=V; k++){
  for (i=1; i<=V; i++)
    for (j=1; j<=V; j++)
      if (i!=j)
        if (D[i][k]+D[k][j]<D[i][j]){
              D[i][j]=D[i][k]+D[k][j];
              siguiente[i][j]=k;
        }
     cout<<" N�mero de etapa:"<<k<<endl;
     cout<<" Matriz con distancias m�s cortas:\n";
     muestra_matriz(D,V);
     cout<<" Matriz de rutas:\n";
     muestra_matriz(siguiente,V);
}

}

void get_shortest_path(int i,int j,double D[][maxV],int V){
    int previo; //nodo previo al que llegamos
       if(D[i][j]==inf){
         cout<<"No hay camino";
       }
     else {
      previo=j;
      cout<<j<<"<-";
      while(previo!=siguiente[i][previo]){
         previo=siguiente[i][previo];
         cout<<previo<<"<-";
      }
      cout<<i<<endl;
    }
}

//Function principal
int main()
{
cout<<"Cantidad de vertices > "; cin>>n;
cout<<"Introduzca la matriz de pesos de los vertices:\n";
for (i=1; i<=n; i++)
for (j=1; j<=n; j++)
{
  cout<<"GR["<<i<<"]["<<j<<"] > ";

  scanf("%lf",&GR[i][j]);

siguiente[i][j]=(GR[i][j]==inf)?inf:j;

}
cout<<"\nMatriz con datos de entrada:"<<endl;
muestra_matriz(GR,n);

FU(GR, n);

cout<<"Dame el nodo inicial:\n";
cin>>i;
cout<<"Dame el nodo destino:\n";
cin>>j;

get_shortest_path(i,j,GR,n);
}
