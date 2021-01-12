#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm>    // std::swap
#include "Registro.cpp"
#define TAMANHOMAX 1431490

using namespace std;
using namespace std::chrono;

void leArquivo(Registro *r , int N)
{
    ifstream arq("brazil_covid19_cities.csv");
    if (!arq.is_open())
    {
        cout << "Problema ao abrir o Arquivo!" << endl;
        return;
    }
    string dataCompleta, estado, cidade;
    int casos, mortes;
    int codigoCidade; //// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
    string linha, stringTemporaria1, stringTemporaria2, stringTemporaria3;
    int cont=0;
    while (getline(arq, linha))
    {
        stringstream ss(linha);
        getline(ss, dataCompleta, ',');
        r[cont].setDataCompleta(dataCompleta);
        getline(ss, estado, ',');
        r[cont].setEstado(estado);
        getline(ss, cidade, ',');
        r[cont].setCidade(cidade);
        getline(ss, stringTemporaria1, ',');
        istringstream(stringTemporaria1) >> codigoCidade; //// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
        r[cont].setCodigoCidade(codigoCidade);
        getline(ss, stringTemporaria2, ',');
        istringstream(stringTemporaria2) >> casos;
        r[cont].setCasos(casos);
        getline(ss, stringTemporaria3, ',');
        istringstream(stringTemporaria3) >> mortes;
        r[cont].setMortes(mortes);

        //r[cont].imprime();
        if(cont>N)
        break;
        cont++;
        
        

    }
    cont--;
    cout << "terminei de ler papae" << endl;
    cout << "nesse arquivo , tem " << cont << " registros" <<endl;
    arq.close();
}


    
void bubbleSort(Registro *r, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)
    // Os ultimos elementos de i já estão no lugar 
    for (j = 0; j < n-i-1; j++)  
        if (r[j].getCasos() > r[j+1].getCasos())  
            swap(r[j],r[j+1]);
}  
  
void printArray(Registro *r, int size)  
{    
    for (int i = 0; i < size; i++)  
        cout << r[i].getCasos() << " ";  
    cout << endl;  
}

void testeOrdenandoBubbleSort(Registro *r , int N){
    leArquivo(r,N);
    cout<<"-----------------------------------------"<<endl;
    bubbleSort(r, N);
    printArray(r,N);
    cout<<"teste completo"<<endl;

}

int main()
{
    int tamanhoN[] = {10000,50000,100000,500000,1000000};
    Registro *r = new Registro[tamanhoN[0]];
    testeOrdenandoBubbleSort(r,tamanhoN[0]); // acima de 100.000 registros ja demora bastante
    delete[] r;
    return 0;
}
