Algoritmo "Algoritmia"

Var
acabar: logico
opcao: inteiro


procedimento espera(msg: caracter)
  var
  letra: caracter
  inicio
    escreva(msg)
    leia(letra)
fimprocedimento    // espera



procedimento menu
  var
  inicio
  escreval("")
  escreval("")
  escreval("a - Paridade de um n�mero")
  escreval("b - Somar valores")
  escreval("c - Fatorial de um n�mero")
  escreval("d - Tabuada")
  escreval("e - Maior valor")
  escreval("f - Laranjas em saldo")
  escreval("g - Peso ideal")
  escreval("h - Equipa vencedora")
  escreval("i - Requerer reforma")
  escreval("j - O tri�ngulo")
  escreval("k - Fatorial recursivo")
  escreval("s - Sair do programa")
  escreval("")
fimprocedimento  // menu



funcao escolheOpcao(legenda: caracter): inteiro
  var
  valor: caracter
  ascii: inteiro
  sair: logico
  inicio
  repita
    escreva(legenda)
    leia(valor)
    valor <- minusc(valor)
    ascii <- asc(valor)
    se ( (ascii > 96) e (ascii < 108) ) ou (ascii = 115) ou (ascii = 48) ent�o
       sair <- verdadeiro
    fimse
  ate sair
  limpatela
  retorne ascii
fimfuncao   // escolherOpcao



procedimento paridade
  var
  numero: inteiro
  inicio
  numero <- 0
  escreva("Escreva um numero: ")
  leia(numero)
  se ( numero = 0 ) entao
    escreval("O n�mero � zero")
  senao
    se ( numero % 2 = 0 ) entao  // % ou mod -> resto da divis�o
      escreval("O n�mero ", numero, " � par")
    senao
      escreval("O n�mero ", numero, " � impar")
    fimse
  fimse
  espera("Tecle para continuar")
fimprocedimento



procedimento somarValores
  var
  valor, total: real
  contador: inteiro
  inicio
  contador <- 1
  total <- 0
  repita
    escreva("Valor ", contador, ": ")
    leia(valor)
    contador <- contador + 1    // incremente contador
    total <- total + valor    // acumula valores
  ate ( valor = 0 )
  contador <- contador - 2
  se ( contador > 0) entao
     escreval("Total de ", contador, " valores igual a ", total)
     escreval("M�dia igual a ", total / contador )
  fimse
  espera("Tecle para continuar")
fimprocedimento    // somarValores



funcao fatorial(num: inteiro): real
  var
  inicio
  se ( num < 2 ) entao
    retorne 1
  senao
    retorne num * fatorial( num - 1)
  fimse
fimfuncao     // fatorial



procedimento fatorialRecursivo
  var
  num, limite: inteiro
  resultado: real
  inicio
  limite <- 100
  resultado <- 1   // fatorial de 0 ou 1 � 1
  escreva("N�mero para calcular fatorial (0 a ", limite, "): ")
  leia(num)
  se ( num >= 0 ) e (num <= limite) entao
    resultado <- fatorial(num)
    escreval("O fatorial de ", num, " � ", resultado)
  senao
    escreval("N�mero inv�lido")
  fimse
  espera("Tecle para continuar")
fimprocedimento  // fatorialRecursivo



procedimento fatorialSimples
  var
  num, contador, limite: inteiro
  resultado: real
  inicio
  limite <- 100
  resultado <- 1
  escreva("N�mero para calcular fatorial (0 a ", limite, "): ")
  leia(num)
  se ( num >= 0 ) e (num <= limite) entao
    contador <- num
    enquanto ( contador > 1 ) faca
      resultado <- resultado * contador
      contador <- contador - 1
    fimenquanto
    escreval("O fatorial de ", num, " � ", resultado)
  senao
    escreval("N�mero inv�lido")
  fimse
  espera("Tecle para continuar")
fimprocedimento   // fatorialSimples



procedimento tabuada
  var
  operador, operando, ascii: inteiro
  resultado: real
  operacao: caracter
  inicio
  operando <- 1
  operacao <- "X"
  escreva("N�mero operando (1 a 10) ")
  leia(operando)
  escreva("Opera��o ( X, +, -, /, %) ")
  leia(operacao)
  ascii <- asc(operacao)
  para operador de 1 ate 10 passo 1 faca
    escolha ascii
    caso 42, 88, 120
      resultado <- operando * operador
    caso 43
      resultado <- operando + operador
    caso 45
      resultado <- operando - operador
    caso 47
      resultado <- operando / operador
    caso 37
      resultado <- operando % operador
    outrocaso
      resultado <- 0
    fimescolha
    escreval(operando, " ", operacao, " ", operador, " = ", resultado)
  fimpara
  espera("Tecle para continuar")
fimprocedimento      // tabuada



procedimento maiorValor
  var
  valor, maiorVal, menorVal: real
  contador: inteiro
  inicio
  contador <- 1
  escreva("Valor ", contador, ": ")
  leia(valor)
  maiorVal <- valor
  menorVal <- valor
  enquanto (valor <> 0) faca
    contador <- contador + 1
    escreva("Valor ", contador, ": ")
    leia(valor)
    se ( valor > maiorVal ) entao
      maiorVal <- valor
    senao
      se ( valor < menorVal ) entao
        menorVal <- valor
      fimse
    fimse
  fimenquanto
  se ( contador > 1 ) entao
    escreval("O maior valor � ", maiorVal)
    escreval("e o menor valor � ", menorVal)
  senao
    escreval("Sem valores inseridos")
  fimse
  espera("Tecle para continuar")
fimprocedimento    // maiorValor



procedimento laranjas
  var
  qtLaranjas: inteiro
  aPagar: real
  inicio
  escreva("Quantas laranjas quer? ")
  leia(qtLaranjas)
  se ( qtLaranjas > 0 ) entao
    se ( qtLaranjas < 12 ) entao
      aPagar <- qtLaranjas * 0.3
    senao
      aPagar <- qtLaranjas * 0.5
    fimse
    escreval("O valor a pagar � ", aPagar, "�")
  senao
    escreval("Volte sempre")
  fimse
  espera("Tecle para continuar")
fimprocedimento    // laranjas



procedimento pesoIdeal
  var
  nome, sexo: caracter
  altura, pIdeal: real
  inicio
  nome <- ""
  sexo <- "M"
  escreva("Nome: ")
  leia(nome)
  escreva("Sexo (M/F): ")
  leia(sexo)
  escreva("Altura: ")
  leia(altura)
  se ( altura > 2 ) e ( altura < 200 ) entao
    altura <- altura / 100
  fimse
  se ( sexo = "F" ) ou ( sexo = "f" ) entao
    pIdeal <- (altura * 62.1) - 44.7
  senao
    pIdeal <- (altura * 72.7) - 58
  fimse
  escreval("O peso ideal de ", nome, " � ", pIdeal)
  espera("Tecle para continuar")
fimprocedimento     // pesoIdeal



procedimento equipaVencedora
  var
  equipa: vetor [0..1] de caracter
  pontos: vetor [0..1] de inteiro
  indice: inteiro
  inicio
  para indice de 0 ate 1 passo 1 faca
    escreva("Nome da equipa ", indice + 1, ": ")
    leia(equipa[indice])
    escreva("Pontos da equipa ", equipa[indice], ": ")
    leia(pontos[indice])
  fimpara
  se ( pontos[0] > pontos[1] ) entao
    escreval("A equipa vencedora �: ", equipa[0])
  senao
    se ( pontos[0] < pontos[1] ) entao
      escreval("A equipa vencedora �: ", equipa[1])
    senao
      escreval("As equipas ", equipa[0], " e ", equipa[1], " empataram")
    fimse
  fimse
  espera("Tecle para continuar")
fimprocedimento    // equipaVencedora



procedimento reforma
  var
  codigoEmpregado: caracter
  anoNascimento, anoIngresso, anoAtual: inteiro
  idade, tempoTrabalho: inteiro
  inicio
  anoAtual <- 2023
  escreva("C�digo do empregado: ")
  leia(codigoEmpregado)
  escreva("Ano de nascimento do empregado: ")
  leia(anoNascimento)
  escreva("Ano de entrada na empresa: ")
  leia(anoIngresso)
  idade <- anoAtual - anoNascimento
  tempoTrabalho <- anoAtual - anoIngresso
  se ( idade >= 65 ) ou ( tempoTrabalho >=30 ) ent�o
    escreval("Requerer aposentadoria")
  senao
    se ( idade >= 60 ) e ( tempoTrabalho >= 25 ) ent�o
      escreval("Requerer aposentadoria")
    senao
      escreval("N�o requerer")
    fimse
  fimse
  espera("Tecle para continuar")
fimprocedimento  // reforma



procedimento triangulo
  Var
  lados: vetor [0..2] de real
  sair, certo: logico
  indice: inteiro
  Inicio
  certo <- falso
  sair <- falso
  indice <- 0
  enquanto ( nao certo ) faca  // valida o tri�ngulo e termina o procedimento com valor 0 na entrada
    escreva("Lado ", indice + 1, " do tri�ngulo: ")
    leia(lados[indice])
    se (lados[indice] > 0) ent�o
      se (indice < 2) entao
        indice <- indice + 1
      senao
        se ( lados[0] >= lados[1] + lados[2] ) ou ( lados[1] >= lados[0] + lados[2]) ou ( lados[2] >= lados[0] + lados[1]) entao
          escreval("Erro nos dados")
          escreval("N�o � um tri�ngulo. Repita.")
          indice <- 0
        senao
          certo <- verdadeiro
        fimse
      fimse
    senao
      sair <- verdadeiro
      certo <- verdadeiro
    fimse
  fimenquanto
  se ( sair ) entao
    escreval("Xau")
  senao
    se ( lados[0] = lados[1] ) e ( lados[0] = lados[2]) e ( lados[1] = lados[2]) entao
      escreval("O tri�ngulo � equil�tero")
    senao
      se ( lados[0] <> lados[1] ) e ( lados[0] <> lados[2]) e ( lados[1] <> lados[2]) entao
        escreval("O tri�ngulo � escaleno")
      senao
        escreval("O tri�ngulo � is�sceles")
      fimse
    fimse
  fimse
  espera("Tecle para continuar")
fimprocedimento



Inicio                 // O programa principal (main) come�a aqui
acabar <- falso
repita   // A estrutura repete at� que a vari�vel l�gica 'acabar' seja verdadeira
  limpatela      // comando VisualG equivalente ao CLS do DOS
  menu()
  opcao <- escolheOpcao("A sua escolha: ")
  escolha opcao
    caso 97
      paridade()        // carater "a"
    caso 98
      somarValores()    // carater "b"
    caso 99
      fatorialSimples() // carater "c"
    caso 100
      tabuada()         // carater "d"
    caso 101
      maiorValor()      // carater "e"
    caso 102
      laranjas()        // carater "f"
    caso 103
      pesoIdeal()       // carater "g"
    caso 104
      equipaVencedora()  // carater "h"
    caso 105
      reforma()      // carater "i"
    caso 106
      triangulo()    // carater "j"
    caso 107
      fatorialRecursivo()    // carater "k"
    caso 48, 115
      acabar <- verdadeiro  // carater "0" ou "s"
    outrocaso
      escreval(opcao)
      escreval("Op��o errada")
  fimescolha
ate acabar
escreval("")
escreva("Adeus e obrigado")
Fimalgoritmo

