# so
Sistemas Operacionais: Simulador da Arquitetura de Von Neumann e Pipeline MIPS

# Compilação e Execução
<p align="justify">

 Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


 | Comando                |  Função                                                                                           |
 | -----------------------| ------------------------------------------------------------------------------------------------- |
 |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
 |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
 |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
 |  `make c`              | make clean + make + make run (recomendado)                                                        |
 |  `make run`            | make + make run                                                                                   |

<p> </p>