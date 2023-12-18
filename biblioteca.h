#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "livro.h"
using namespace std;

class Biblioteca
{
private:
    Livro **livros;
    int numLivros;

public:
    Biblioteca();
    ~Biblioteca();

    void carregarDados();
    void salvarDados();
    void executarAcao(int opcao);
    void cadastrarLivro();
    void adicionarLivro(Livro *novoLivro);
    void removerLivro();
    void listarLivros();
};

#endif
