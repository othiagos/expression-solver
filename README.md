# Expression Solver

**Descrição em alto nível da funcionalidade do código:**
>O problema apresentado é criar um resolvedor de expressões matemáticas que será usado em uma escola 
de ensino fundamental para ler, resolver e converter expressões. O programa será capaz de ler expressões
tanto no formato infixa (notação usual), quanto no formato posfixa (notação polonesa invertida), o 
sistema suportará as 4 operações básicas: multiplicação(*), divisão(/),  adição(+) e subtração(-), 
a entrada será apenas números não negativos com separador fracionário “.”. Assim, para resolver o 
problema foi utilizado uma árvore de expressões para poder armazenar e utilizar da sua forma para
poder converter e calcular expressões.

## **Compilação e Execução**

```bash
$ make
$ make run

```
## **Instruções para execução**
```
LER TIPOEXP EXP, lê a expressão passada.
INFIXA, converter a expressão armazenada para notação infixa.
POSFIXA, converter a expressão armazenada para notação posfixa.
RESOLVE, calcula o valor da expressão armazenada.
SAIR, termina a execução do programa.
```
## **Execução Testes**

```bash
$ make run_test
```

## **Arquivos disponíveis**

```bash
$ ./bin/expression_solver < input.txt
$ ./bin/expression_solver < allinput.txt
```
