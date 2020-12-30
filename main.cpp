#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include "Registro.cpp"
#define TAMANHOMAX 1431490

using namespace std;
using namespace std::chrono;

void leArquivo(Registro *r)
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
    cout<<"aisdjaosid"<<endl;

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
        if(cont>50000)
        break;
        cont++;
        
        

    }
    cout << "terminei de ler papae" << endl;
    cout << "nesse arquivo , tem " << cont << " registros" <<endl;
    arq.close();
}




void swap(Registro *r,int a,int b)  
{  
    
    Registro temp(r[a].getDataCompleta(),r[a].getEstado(),r[a].getCidade(),r[a].getCodigoCidade(),r[a].getCasos(),r[a].getMortes());
   
    r[b].setDataCompleta(r[a].getDataCompleta());  
    r[b].setEstado(r[a].getEstado());
    r[b].setCidade(r[a].getCidade());
    r[b].setCodigoCidade(r[a].getCodigoCidade());
    r[b].setCasos(r[a].getCasos());
    r[b].setMortes(r[a].getMortes());



    r[a].setDataCompleta(temp.getDataCompleta()); 
    r[a].setEstado(temp.getEstado()); 
    r[a].setCidade(temp.getCidade()); 
    r[a].setCodigoCidade(temp.getCodigoCidade()); 
    r[a].setCasos(temp.getCasos()); 
    r[a].setMortes(temp.getMortes()); 
}  
  
// A function to implement bubble sort  
void bubbleSort(Registro *r, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (r[j].getCasos() > r[j+1].getCasos())  
            swap(r,j,j+1);  
}  
  
/* Function to print an array */
void printArray(Registro *r, int size)  
{    
    for (int i = 0; i < size; i++)  
        cout << r[i].getCasos() << " ";  
    cout << endl;  
}

int main()
{
    Registro *r = new Registro[50000];
    leArquivo(r);
    //printArray(r,10000);
    cout<<"-----------------------------------------"<<endl;
    bubbleSort(r, 50000);
    printArray(r,50000);
    cout<<"teste completo"<<endl;
    

    delete[] r;





    return 0;
}
