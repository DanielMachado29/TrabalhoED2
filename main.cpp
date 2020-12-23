#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

// void leArquivoTextoGeral()
// {
//     ifstream arq("brazil_covid19_cities.csv");

//     if (arq.is_open())
//     {
//         cout << "Informacoes armazenadas no arquivo:\n\n***" << endl; ////////////////////////////////PRIMEIRA FORMA QUE FIZ

//         string str;
//         float val;
//         while (arq.is_open())
//         {
//             getline(arq, str);
//             arq >> val;
//             cout << val << str << endl;
//         }
//         cout << "\n***" << endl;
//     }
//     else
//         cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
//     cout << "ACABEI DE LER O DOCUMENTOOOOOOOO" << endl;
// }



// void leArquivoTextoGeral()
// {
//     ifstream arq("brazil_covid19_cities.csv");

//     if(arq.is_open())
//     {
//         string str;
//         float val;

//         while(!arq.eof()){
//         getline(arq, str);
//         arq >> val;
//         cout <<  val << str << endl;
//         }
//         // ERRO: irá gerar lixo de memória, pois val irá armazenar todos os dígitos na sequência////////////////////////////////SEGUNDA FORMA QUE FIZ
//         //int intval; 
//         //arq >> intval;
//         // cout << str << '\n' << val << '\n' << intval << endl;

//         cout << "\n***" << endl;
//     }
//     else
//         cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
// }



void leArquivo(){
    ifstream arq("brazil_covid19_cities.csv");
if(!arq.is_open())
    {
        cout<< "Problema ao abrir o Arquivo!"<< endl;
       // https://www.youtube.com/watch?v=_IzYGiuX8QM
    }

}


void leArquivoTextoGeral()
{
    ifstream arq("brazil_covid19_cities.csv");

    if(arq.is_open())
    {
        string str;
        int ano;
        int mes;
        int dia;
        
        while(!arq.eof()){
        getline(arq, str , ',');
        arq >> ano;
        arq >> mes;                     // dessa forma , o mes e o dia tao ficando com "-" na frente  
        arq >> dia;                     // podemos tratar o "negativo no meio do codigo depois" -> da pra tratar no construtor
        

        cout << ano << mes <<dia << str << endl;
        }

        cout << "\n***" << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}




int main()
{
    
    leArquivoTextoGeral();

    return 0;
}
 