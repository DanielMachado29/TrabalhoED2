#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int tamanhoArquivo(fstream& arq)
{
    //int pos = arq.tellg();
    arq.seekg(0, arq.end);
    int tam = arq.tellg();
    arq.seekg(0);
    return tam;
}

void escreveArquivoTexto()
{
    ofstream arq("arqTexto.txt");

    arq << "Dados:" << endl;
    arq << 4.2;
    arq << 2 << 3;

    cout << "Tamanho em bytes apos escrita: " << arq.tellp() << endl;

    //arq.close();
}

void leArquivoTextoString()
{
    ifstream arq("arqTexto.txt");

    if(arq.is_open())
    {
        cout << "Informacoes armazenadas no arquivo:\n\n***" << endl;

        string str;
        int count = 1;
        while(getline(arq, str))
        {
            cout << count << " - EOF: " << ((arq.eof()) ? "true" : "false") << endl;
            cout << str << endl;
            count++;
        }
        cout << "***" << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}

void leArquivoTextoGeral()
{
    ifstream arq("brazil_covid19_cities.csv");

    if(arq.is_open())
    {
        cout << "Informacoes armazenadas no arquivo:\n\n***" << endl;

        string str;
        float val;
        while(arq.is_open())
        {
            getline(arq, str);
            //arq >> val;
            cout << str << endl;
        }



        // ERRO: irá gerar lixo de memória, pois val irá armazenar todos os dígitos na sequência
        //int intval;
        //arq >> intval;
        // cout << str << '\n' << val << '\n' << intval << endl;

        cout << "\n***" << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
    cout << "ACABEI DE LER O DOCUMENTOOOOOOOO"<<endl;
}

void escreveArquivoBinario()
{
    fstream arq("arq.bin", ios::out | ios::binary);

    if(arq.is_open())
    {
        float val = 4.2;
        string str = "Dados";
        int intval = 2;

        // ERRO: verifique como o arquivo fica corrompido!
        //arq.write(reinterpret_cast<const char*>(&str), str.length());

        arq.write(reinterpret_cast<const char*>(str.c_str()), str.length());
        arq.write(reinterpret_cast<const char*>(&val), sizeof(float));
        arq.write(reinterpret_cast<const char*>(&intval), sizeof(int));

        intval = 3;
        arq.write(reinterpret_cast<char*>(&intval), sizeof(int));

        cout << "Tamanho em bytes apos escrita: " << arq.tellp() << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}

void adicionaInfoArquivo(fstream& arq)
{
    if(arq.is_open())
    {
        string app = "app";
        arq.write(reinterpret_cast<const char*>(app.c_str()), app.length());
        //arq << app;

        cout << "Tamanho em bytes apos escrita: " << arq.tellp() << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}

void leArquivoBinario()
{
    fstream arq("arq.bin", ios::in | ios::binary);

    if(arq.is_open())
    {
        float val;
        char str[10];
        int intval;

        arq.read(str, 5);
        str[5] = '\0';
        arq.read(reinterpret_cast<char*>(&val), sizeof(float));
        arq.read(reinterpret_cast<char*>(&intval), sizeof(int));
        cout << str << '\n' << val << " " << intval << " ";

        arq.read(reinterpret_cast<char*>(&intval), sizeof(int));
        cout << intval << endl;

        // ERRO: tentar ler após o fim do arquivo irá retornar 0 bytes e str ficará inalterado
        // arq.read(str, 3);
        // str[3] = '\0';
        // cout << str << endl;
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}

void geraCSV()
{
    ofstream arq("dados.csv");

    for(int i = 1; i <= 1000000; i++)
    {
        arq << i << "," << i*2 << "," << rand()%i << endl;
    }

    arq.close();
}

void carregaArquivoPorBlocos(int tamBloco)
{
    char *dados = new char[tamBloco];
    ifstream arq("dados.csv");

    if(arq.is_open())
    {
        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        while(!arq.eof())
        {
            arq.read(dados, tamBloco);
            cout << arq.gcount() << " bytes lidos" << endl;
        }
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        cout << duration_cast<duration<double>>(fim - inicio).count() << " segundos" << endl;
    }

    arq.close();
    delete [] dados;
}

void geraArquivoBinario()
{
    ofstream arq("dados.dat", ios::binary);

    for(int i = 1; i <= 1000000; i++)
    {
        int x = i;
        arq.write(reinterpret_cast<const char*>(&x), sizeof(int));
        x = i * 2;
        arq.write(reinterpret_cast<const char*>(&x), sizeof(int));
        x = rand() % i;
        arq.write(reinterpret_cast<const char*>(&x), sizeof(int));
    }

    arq.close();
}

void carregaRegistro(int indice)
{
    ifstream arq("dados.dat", ios::binary);

    if(arq.is_open())
    {
        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        int x;
        arq.seekg((indice-1)*12);
        arq.read(reinterpret_cast<char*>(&x), sizeof(int));
        cout << x << ", ";
        arq.read(reinterpret_cast<char*>(&x), sizeof(int));
        cout << x << ", ";
        arq.read(reinterpret_cast<char*>(&x), sizeof(int));
        cout << x << endl;
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        cout << duration_cast<duration<double>>(fim - inicio).count() << " segundos" << endl;
    }

    arq.close();
}

int main()
{
    // EXEMPLO 1: Criação de um arquivo texto
    // Não há distinção entre o inteiro e o float, são todos transformados em caracteres
    // escreveArquivoTexto();

    // fstream arq("arqTexto.txt");
    // cout << "Tamanho do arquivo texto: " << tamanhoArquivo(arq) << endl;
    // arq.close();

    // EXEMPLO 2: Leitura de um arquivo texto utilizando getline
    // A cada linha, imprimimos o índice da linha e o valor de EOF.
    // leArquivoTextoString();

    // EXEMPLO 3: Tentativa de leitura de um arquivo texto utilizando os tipos de dados originais
    leArquivoTextoGeral();

    // EXEMPLO 4: Criação de um arquivo binário
    //escreveArquivoBinario();

    // EXEMPLO 5: Adição de novas informações a um arquivo previamente criado
    // ERRO: apenas abrir o arquivo já apaga o seu conteúdo
    // fstream arq("arqTexto.txt", ios::out);
    // arq.seekp(2);

    //fstream arq("arqTexto.txt", ios::app);
    // fstream arq("arq.bin", ios::app);
    // adicionaInfoArquivo(arq);
    // cout << "Tamanho do arquivo texto: " << tamanhoArquivo(arq) << endl;
    // arq.close();

    // EXEMPLO 6: Leitura de um arquivo binário
    // leArquivoBinario();

    // EXEMPLO 7: Acesso direto a um arquivo binário usando seekg
    // geraArquivoBinario();
    // carregaRegistro(100000);

    // EXEMPLO 8: Leitura de um arquivo grande usando um buffer na memória principal
    // geraCSV();
    // carregaArquivoPorBlocos(5000000);

    return 0;
}
