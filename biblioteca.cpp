#include "biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Biblioteca::Biblioteca()
    : livros(nullptr), numLivros(0) {}

Biblioteca::~Biblioteca()
{
    for (int i = 0; i < numLivros; ++i)
        delete livros[i];
    delete[] livros;
}

int contagemLinhas(string nomeArquivo)
{
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return -1;
    }

    int contador = 0;
    string linha;

    while (getline(arquivo, linha))
    {
        contador++;
    }
    arquivo.close();
    return contador;
}

void Biblioteca::carregarDados()
{
    string linha;
    string nomeArquvio = "livros.txt";
    int qtdLinhas = contagemLinhas(nomeArquvio);
    ifstream arquivoLivros(nomeArquvio);

    for (int i = 0; i < qtdLinhas; i++)
    {
        if (!arquivoLivros.is_open())
        {
            cerr << "Erro ao abrir o arquivo." << endl;
            return;
        }
        getline(arquivoLivros, linha);
        stringstream ss(linha);
        string titulo, autor, anoPublicacaoStr, qtdPaginasStr;

        getline(ss, titulo, ';');
        getline(ss, autor, ';');
        getline(ss, anoPublicacaoStr, ';');
        getline(ss, qtdPaginasStr, ';');

        int anoPublicacao = stoi(anoPublicacaoStr);
        int qtdPaginas = stoi(qtdPaginasStr);
        Livro *novoLivro = new Livro(titulo, autor, anoPublicacao, qtdPaginas);
        adicionarLivro(novoLivro);
    }
}

void Biblioteca::salvarDados()
{
    ofstream arquivoLivros("livros.txt");

    for (int i = 0; i < numLivros; i++)
    {
        arquivoLivros << livros[i]->getTitulo() << ';'
                      << livros[i]->getAutor() << ';'
                      << livros[i]->getAnoPublicacao() << ';'
                      << livros[i]->getQtdPaginas() << '\n';
    }

    arquivoLivros.close();
}

void Biblioteca::executarAcao(int opcao)
{
    switch (opcao)
    {
    case 1:
        cadastrarLivro();
        break;
    case 2:
        removerLivro();
        break;
    case 3:
        listarLivros();
        break;

    default:
        break;
    }
}

void Biblioteca::adicionarLivro(Livro *novoLivro)
{
    Livro **novoArray = new Livro *[numLivros + 1];
    for (int i = 0; i < numLivros; ++i)
    {
        novoArray[i] = livros[i];
    }

    novoArray[numLivros] = novoLivro;

    delete[] livros;
    livros = novoArray;

    ++numLivros;
}

void Biblioteca::removerLivro()
{
    int indiceRemover;
    cout << "Digite o número do livro que deseja remover: ";
    cin >> indiceRemover;
    char desejaRemover = 'n';

    for (int i = 0; i < numLivros; ++i)
    {
        if (i + 1 == indiceRemover)
        {
            cout << "Tem certeza que deseja remover o livro: " << endl;
            cout << livros[i]->getTitulo() << " (" << livros[i]->getAutor() << ")" << endl;
            cout << "Sim(s)/Não(n): ";
            cin >> desejaRemover;
            if (desejaRemover != 's')
            {
                break;
            }

            delete livros[i];

            for (int j = i; j < numLivros - 1; ++j)
            {
                livros[j] = livros[j + 1];
            }

            --numLivros;
            break;
        }
    }

    salvarDados();
}

void Biblioteca::cadastrarLivro()
{
    string titulo, autor, anoPublicacaoStr, qtdPaginasStr;
    int anoPublicacao, qtdPaginas;

    cin.ignore();

    cout << "Título do livro: ";
    getline(cin, titulo);

    cout << "Nome do autor: ";
    getline(cin, autor);

    cout << "Ano de publicação: ";
    getline(cin, anoPublicacaoStr);
    anoPublicacao = stoi(anoPublicacaoStr);

    cout << "Quantidade de páginas: ";
    getline(cin, qtdPaginasStr);
    qtdPaginas = stoi(qtdPaginasStr);

    Livro *novoLivro = new Livro(titulo, autor, anoPublicacao, qtdPaginas);
    adicionarLivro(novoLivro);
}

void Biblioteca::listarLivros()
{
    for (int i = 0; i < numLivros; ++i)
    {
        cout << "Livro " << i + 1 << " ------------------" << endl;
        cout << "Título: " << livros[i]->getTitulo() << endl;
        cout << "Autor: " << livros[i]->getAutor() << endl;
        cout << "Ano de publicação: " << livros[i]->getAnoPublicacao() << endl;
        cout << "Quantidade de páginas: " << livros[i]->getQtdPaginas() << endl;
        cout << "--------------------------------" << endl;
    }
}