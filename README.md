
# Sistema de Contas-Bancarias
 
Um sistema de contas bancárias é uma plataforma que permite aos clientes gerenciar suas finanças, realizar transações e acessar uma variedade de serviços oferecidos por uma instituição financeira.

## Motivação do projeto

O desenvolvimento de projetos de sistemas bancários representa um desafio significativo, exigindo a aplicação prática dos conhecimentos obtidos na disciplina de Linguagem de Programação, utilizando structs, ponteiros e vetores.
Ao empregar a estruturação eficiente por meio de structs, é possível organizar os diversos elementos de um sistema bancário de maneira lógica e coerente. As structs oferecem uma forma de representar entidades complexas, como contas bancárias, clientes e transações, de maneira estruturada, facilitando a manipulação e o gerenciamento desses dados.
Os ponteiros, por sua vez, desempenham um papel crucial na otimização do uso da memória, permitindo o acesso direto aos endereços de dados.
A utilização de vetores torna-se fundamental para lidar com conjuntos de dados extensos, como históricos de transações ou informações de clientes. 
O projeto de sistemas bancários é uma aplicação prática dos conhecimentos de programação, e também uma oportunidade para aprimorar habilidades essenciais no desenvolvimento de software.

## 📋 Pré-requisitos  

**Sistema operacional:** Windows 7 (com Service Pack 1) ou superior, incluindo Windows 10.

- Arquitetura: O Clion que suporta sistemas operacionais de 32 e 64 bits.

- Processador: Processador Intel Pentium 4 ou posterior compatível com a tecnologia SSE2.

**Requisitos gerais:**

- Memória RAM: Recomenda-se ter pelo menos 4 GB de RAM disponíveis para uma experiência de uso mais fluida.

- Espaço em disco: Espaço suficiente no disco rígido para instalar o VSCode e armazenar seus projetos e arquivos.

- Resolução de tela: Uma resolução de tela de 1280 x 720 ou superior é recomendada para a melhor experiência visual.

## 🔧 Instalação

É necessário ter sido instalado o [Clion](https://www.jetbrains.com/pt-br/clion/download/#section=windows) para fazer os rodar o software de Sistemas Bancarias, abaixar o [Git](https://git-scm.com/download/win) para ter terminal do git e será necessário clonar o repositório em sua maquina, inserindo o comando:

```bash
git clone https://github.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias/branches
```

Ao rodar o projeto verifica a sua versão do Cmake, pois o software está rodando na versão (VERSION 3.24) .

## 🚀 Começando

Reforçando é necessário clonar o repositório em sua maquina, inserindo o comando:

```bash
git clone https://github.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias/branches
```


## ⚙️ Executando os testes

Para iniciar a execução do projeto basta dar um click no triangulo verde no canto superior da direita, como esta na imagem :

![imagem 1](https://raw.githubusercontent.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias/main/Downlode%20prints/1.png)

Agora, você terá acesso ao menu, onde poderá realizar as ações necessárias. É possível inserir um novo cliente, alterar seus dados, procurar por uma conta específica, listar todas as contas cadastradas, efetuar depósitos e saques, imprimir todos os dados das contas e, por último, verificar o saldo geral. Confira a imagem abaixo para uma visualização completa:

![imagem 2](https://raw.githubusercontent.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias/main/Downlode%20prints/2.png)

## 📹 Vídeo da equipe explicando o projeto
[video 1](https://www.youtube.com/watch?v=lbHJ74EuPE8)
[video 2](https://www.youtube.com/watch?v=2yNvXDcZyE0)

## ⌨️ Todas as funções do programa

Todas as funções do software são  essas :

- **void inserir(Conta_ contas, int totalContas)**;
Esta função realiza a inserção de uma nova conta no programa. Toda vez que é chamada, aloca uma nova posição de memória e realoca os novos dados para ela.

- **void alterar(Conta_ contas, int totalContas)**;
Esta função tem como objetivo realizar alterações em uma conta selecionada, sendo o único parâmetro que ela altera o nome.

- **void procurar(Conta_ contas, int totalContas)**;
Esta função tem como objetivo procurar uma conta específica e exibir todos os seus dados.

- **void listar(Conta_ contas, int totalContas)**;
Esta função tem como objetivo listar todas as contas cadastradas no programa.

- **void depositar(Conta_ contas, int totalContas)**;
Esta função tem como objetivo depositar mais dinheiro em uma conta cadastrada.

- **void sacar(Conta_ contas, int totalContas)**;
Esta função tem como objetivo sacar dinheiro de uma conta cadastrada.

- **void imprimir(Conta_ contas, int totalContas)**;
Esta função tem como objetivo mostrar todos os dados de uma conta cadastrada no programa.

- **void saldoGeral(Conta_ contas, int totalContas)**;
Esta função tem como objetivo mostrar o saldo geral de todas as contas.

## 🛠️ Construído em
* [C](https://learn.microsoft.com/pt-br/cpp/c-language/?view=msvc-170) - Documentação da linguagem C

## 📌 Versão

Nós estamos na versão 1.0.0. Para as versões disponíveis, observe as [repositório](https://github.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias). 

## ✒️ Autores
* **Desenvolvedor** - *Trabalho de desenvolvimento do código* - [Abdiel Junio](https://github.com/abdieljunio) ;
* **Desenvolvedor** - *Trabalho de desenvolvimento do código* - [Gustavo Barros](https://github.com/gubarros92) ;
*  **Desenvolvedor** - *Trabalho de desenvolvimento do código* - [Rafael Queiroz](https://github.com/RafaQueirox) ;
* **Desenvolvedor** - *Trabalho de desenvolvimento do código* - [Tadeu Bordignon](https://github.com/tadeurb) ;
* **Desenvolvedor e QA** - *Trabalho de desenvolvimento do código, revisão e teste* - [Thiago Foganholo](https://github.com/ThiagoFoganholo) ;

Você também pode ver a lista de todos os [colaboradores](https://github.com/ThiagoFoganholo/Sistema-de-Contas-Bancarias/settings/access) que participaram deste projeto.

## 📄 Licença

Este projeto está sob a licença livre - veja o arquivo [LICENSE.md](https://github.com/usuario/projeto/licenca) para detalhes.
