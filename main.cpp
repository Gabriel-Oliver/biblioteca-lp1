#include "biblioteca.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int qtdOpcoes = 5;
    string opcoes[qtdOpcoes] = {
        "1. Adicionar Livro",
        "2. Remover Livro",
        "3. Listar Livros",
        "4. Sair",
        "Escolha uma opção: "};
    Biblioteca biblioteca;
    biblioteca.carregarDados();

    int opcao;
    do
    {
        for (int i = 0; i < qtdOpcoes; i++)
        {
            cout << opcoes[i];
            if (i != qtdOpcoes - 1)
            {
                cout << endl;
            }
        }

        cin >> opcao;

        biblioteca.executarAcao(opcao);

    } while (opcao != 4);

    biblioteca.salvarDados();

    return 0;
}
