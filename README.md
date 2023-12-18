# Biblioteca

Uma aplicação simples e funcional de gerenciamento de livros em uma biblioteca.

# Tabela de conteúdos

- [Tecnologias](#tecnologias)
- [Setup Database](#setup-database)
- [Como rodar](#como-rodar)

# Tecnologias

- [x] C++
- [x] iostream
- [x] fstream
- [x] sstream
- [x] string

# Setup Database

Os passos a seguir descrevem como configurar o banco de dados da aplicação.

- Crie um arquvio txt de nome "livros.txt";
- Para adicionar livros a esse arquivo você deverá digitar-los seguindo a seguinte estrutura:
  - título do livro;nome do autor;ano de publicação;quantidade de páginas
- Observe que os textos estam separados por ";" isso é extremamente importante para que a aplicação execute corretamente.


# Como Rodar

```shell
## Para executar a aplicação você precisará compilar o projeto com algum compilador de C++:
## No meu caso utilizei o g++
$ g++ -std=c++11 -o biblioteca livro.cpp biblioteca.cpp main.cpp
## Execute o arquivo gerado de nome "biblioteca"
$ ./biblioteca
```
