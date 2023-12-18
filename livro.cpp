#include "livro.h"
#include <iostream>

using namespace std;

Livro::Livro(string titulo, string autor, int ano, int paginas)
    : titulo(titulo), autor(autor), anoPublicacao(ano), qtdPaginas(paginas) {}

Livro::~Livro() {}

void Livro::exibirInformacoes()
{
    cout << "Título: " << titulo << "\nAutor: " << autor << "\nAno: " << anoPublicacao << "\nPáginas: " << qtdPaginas << endl;
}

string Livro::getTitulo()
{
    return titulo;
}
string Livro::getAutor()
{
    return autor;
}
int Livro::getAnoPublicacao()
{
    return anoPublicacao;
}
int Livro::getQtdPaginas()
{
    return qtdPaginas;
}