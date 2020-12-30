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

void leArquivo()
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
    Registro *r = new Registro[TAMANHOMAX];
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
        
        cont++;
        

    }

    r[1131606].imprime();
    delete[] r;
    cout << "terminei de ler papae" << endl;
    cout << "nesse arquivo , tem " << cont << " registros" <<endl;
    arq.close();
}

int main()
{

    leArquivo();

    return 0;
}
