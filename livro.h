#ifndef LIVRO_H
#define LIVRO_H

#include <string>
using namespace std;

class Livro
{
private:
    string titulo;
    string autor;
    int anoPublicacao;
    int qtdPaginas;

public:
    Livro(string titulo, string autor, int ano, int paginas);
    ~Livro();

    string getTitulo();
    string getAutor();
    int getAnoPublicacao();
    int getQtdPaginas();

    void exibirInformacoes();
};

#endif
