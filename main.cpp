#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

void leArquivo(){
    ifstream arq("brazil_covid19_cities.csv");
    if(!arq.is_open())
        {
            cout<< "Problema ao abrir o Arquivo!"<< endl;
            return;
        }
    string dataCompleta, estado, cidade;
    int dia, mes, ano;
    int casos, mortes;
    int codigoCidade;  //// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
    string linha , stringTemporaria1 ,stringTemporaria2,stringTemporaria3;
    while(getline(arq,linha)){
        stringstream ss(linha);
        getline(ss, dataCompleta , ',');
        getline(ss, estado , ',');
        getline(ss, cidade , ',');
        getline(ss, stringTemporaria1 , ',');
        istringstream(stringTemporaria1) >> codigoCidade;//// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
        getline(ss, stringTemporaria2 , ',');
        istringstream(stringTemporaria2) >> casos;
        getline(ss, stringTemporaria3 , ',');
        istringstream(stringTemporaria3) >> mortes;

        cout<< ' ' <<dataCompleta <<' ' << estado <<' ' << cidade <<' ' << codigoCidade <<' ' << casos <<' ' << mortes <<endl;
    }
    cout << "terminei de ler papae"<<endl;
    arq.close();
}

int main()
{
    
    leArquivo();

    return 0;
}
 