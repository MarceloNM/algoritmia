# PI04 Exercícios de algoritmia em pseudocódico, expressos em Python
# Novembro de 2023 
# Cada exercício está numa função (iniciada por 'def') e é coordenado pelo programa principal no fim do ficheiro
# O programa foi testado na versão de Python 3.11.5 
# A validação da entrada de dados é rudimentar. O objetivo é apenas didático 

import os   # para usar o comando de DOS que limpa o ecrã (a tela) 'cls'

def espera(msg):
    letra = input(msg)
# fim da função espera

def menu():
    print("")
    print("")
    print("a - Paridade de um número")
    print("b - Somar valores")
    print("c - Fatorial de um número")
    print("d - Tabuada")
    print("e - Maior valor")
    print("f - Laranjas em saldo")
    print("g - Peso ideal")
    print("h - Equipa vencedora")
    print("i - Requerer reforma")
    print("j - O triângulo")
    print("k - Fatorial recursivo")
    print("s - Sair do programa")
    print("")
# fim da funçao menu


def escolheOpcao(legenda):
    sair = False
    while not sair:
        valor = input(legenda)
        if valor != "":
            valor = valor.lower()
            ascii = ord(valor)
            if (ascii > 96 and ascii < 108 ) or (ascii == 115):
                sair = True
    os.system("cls")
    return ascii
# fim da função escolheOpção


def paridade():
    numero = int(input("Escreva um número: "))  # o input recebe sempre o tipo 'string'
    if numero == 0:
        print("O número é zero")
    elif numero % 2 == 0:                     # para esta expressão 'numero' tem que ser numérico
        print("O número ", numero, "é par")
    else:
        print("O número ", numero, "é ímpar")
    espera("Tecle para continuar")
# fim da função paridade


def somarValores():
    contador = 1
    total = 0.0
    valor = 1
    while valor != 0:
        valor = int(input("Valor " + str(contador) + ": "))
        contador += 1
        total += valor
    contador -= 2
    if contador > 0:
        print("Total de ", contador, " valores igual a ", total)
        print("Média igual a ", total / contador )
    espera("Tecle para continuar")
# fim da função somarValores


def fatorial(num):
    if num < 2:
        return 1
    else:
        return num * fatorial( num - 1)
# fim da função fatorial


def fatorialRecursivo():
    limite = 100
    resultado = 1
    num = int(input("Número para calcular o fatorial (0 a " + str(limite) + "): "))
    if num >= 0 and num <= limite:
        resultado = fatorial(num)
        print("O fatorial de ", num, " é ", resultado)
    else:
        print("Número inválido")
    espera("Tecle para continuar")
# fim da função fatorialRecursivo


def fatorialSimples():
    limite = 100
    resultado = 1
    num = int(input("Número para calcular o fatorial (0 a " + str(limite) + "): "))
    if num >= 0 and num <= limite:
        contador = num
        while contador > 1:
            resultado *= contador
            contador -= 1
        print("O fatorial de ", num, " é ", resultado)
    else:
        print("Número inválido")
    espera("Tecle para continuar")
# fim da função fatorialSimples


def tabuada():
    #operando = 1
    #operacao = "X"
    operando = int(input("Número operando (1 a 10) "))
    operacao = input("Operação ( X, +, -, /, %) ")
    if operacao != "":
        ascii = ord(operacao)
        for i in range(10):
            operador = i + 1
            match ascii:
                case 120:
                    resultado = operando * operador
                case 43:
                    resultado = operando + operador
                case 45:
                    resultado = operando - operador
                case 47:
                    resultado = operando / operador
                case 37:
                    resultado = operando % operador
                case _:
                    print("Operação inválida")
                    break
            print(operando, " ", operacao, " ", operador, " = ", resultado)
    else:
        print("Operação inválida")
    espera("Tecle para continuar")
# fim da função tabuada


def maiorValor():
    contador = 1
    valor = int(input("Valor " + str(contador) + ": "))
    maiorVal = menorVal = valor
    # menorVal = valor
    while valor != 0:
        contador += 1
        valor = int(input("Valor " + str(contador) + ": "))
        if valor > maiorVal and valor != 0:
            maiorVal = valor
        elif valor < menorVal and valor != 0:
            menorVal = valor
    if contador > 1:
        print("O maior valor é ", maiorVal)
        print("e o menor valor é ", menorVal)
    else:
        print("Sem valores inseridos")
    espera("Tecle para continuar")
# fim da função maiorValor


def laranjas():
    qtLaranjas = int(input("Quantas laranjas quer? "))
    if qtLaranjas > 0:
        if qtLaranjas < 12:
            aPagar = qtLaranjas * 0.3
        else:
            aPagar = qtLaranjas * 0.5
        print("O valor a pagar é ", aPagar, "€")
    else:
        print("Volte sempre")
    espera("Tecle para continuar")
# fim da função laranjas


def pesoIdeal():
    nome = input("Nome: ")
    sexo = input("Sexo (M/F): ")
    altura = float(input("Altura: "))
    if altura > 2 and altura < 200:
        altura = altura / 100
    if sexo in "fF":
        pIdeal = ( altura * 62.1 ) - 44.7
    else:
        pIdeal = ( altura * 72.7 ) - 58
    print("O peso ideal de ", nome, " é ", pIdeal)
    espera("Tecle para continuar")
# fim da função pesoIdeal


def equipaVencedora():
    equipa = ["",""]
    pontos = [0,0]
    for indice in range(2):
        equipa[indice] = input("Nome da equipa " + str(indice + 1) + ": ")
        pontos[indice] = int(input("Pontos da equipa " + str(indice + 1) + ": "))
    if pontos[0] > pontos[1]:
        print("A equipa vencedora é: ", equipa[0])
    elif pontos[0] < pontos[1]:
        print("A equipa vencedora é: ", equipa[1])
    else:
        print("As equipas ", equipa[0], " e ", equipa[1], " empataram")
    espera("Tecle para continuar")
# fim da função equipaVencedora


def reforma():
    anoAtual = 2023
    codigoEmpregado = input("Código do empregado: ")
    anoNascimento = int(input("Ano de nascimento do empregado: "))
    anoIngresso =  int(input("Ano de entrada na empresa: "))
    idade = anoAtual - anoNascimento
    tempoTrabalho = anoAtual - anoIngresso
    if idade >= 65 or tempoTrabalho >= 30:
        print("Requerer aposentadoria")
    elif idade >= 60 and tempoTrabalho >= 25:
        print("Requerer aposentadoria")
    else:
        print("Não requerer")
    espera("Tecle para continuar")
# fim da função reforma


def triangulo():
    lados = [0,0,0]
    certo = False
    sair = False
    indice = 0
    while not certo:
        lados[indice] = int(input("Lado " + str(indice + 1) + " do triângulo: "))
        if lados[indice] > 0:
            if indice < 2:
                indice += 1
            elif lados[0] >= lados[1] + lados[2] or lados[1] >= lados[0] + lados[2] or lados[2] >= lados[0] + lados[1]:
                print("Erro nos dados")
                print("Não é um triângulo. Repita.")
                indice = 0
            else:
                certo = True
        else:
            sair = certo = True
    if sair:
        print("Xau")
    elif lados[0] == lados[1] and lados[0] == lados[2] and lados[1] == lados[2]:
        print("O triângulo é equilátero")
    elif lados[0] != lados[1] and lados[0] != lados[2] and lados[1] != lados[2]:
        print("O triângulo é escaleno")
    else:
        print("O triângulo é isósceles")
    espera("Tecle para continuar")
# fim da função triangulo


# Programa principal
acabar = False
while not acabar:
    os.system('cls')
    menu()
    opcao = escolheOpcao('A sua escolha: ')
    match opcao:     # valor do código ascii da letra de opção
        case 97:
            paridade()
        case 98:
            somarValores()
        case 99:
            fatorialSimples()
        case 100:
            tabuada()
        case 101:
            maiorValor()
        case 102:
            laranjas()
        case 103:
            pesoIdeal()
        case 104:
            equipaVencedora()
        case 105:
            reforma()
        case 106:
            triangulo()
        case 107:
            fatorialRecursivo()
        case 115:
            acabar = True
        case _:
            print("Escolheu", opcao, "não prevista")
print("")
print("Adeus e obrigado")
# fim do programa principal


