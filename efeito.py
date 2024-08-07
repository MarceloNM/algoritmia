# efeitos do c++ em python 
# MarceloNM 202403

import time, sys

def funcao():
    print("sou uma função disfuncional")

def teste():
    str0 = "JOSE"
    str = "MOURINHO"
    str1 = str0 + " " + str     # junta as duas strings na ordem correta
    str2 = str + " " + str0     # junta as duas strings na ordem inversa
    i = 0
    for x in str1:          # diagonal direita 
        print(i * " " +  x)    # coloca 'i' espaços à esquerda
        i += 1                  # ciclo foreach não tem contador...
    print("\n")

    i = 0
    for x in str2:          # diagonal direita trocada usa a string alternativa
        print(i * " " +  x)
        i += 1
    print("\n")

    i = 0
    l = len(str1)
    for x in str1:          # diagonal esquerda
        print((l - i - 1) * " " +  x)   # coloca à esquerda espaços
        i += 1                          # do tamanho da string - 'i'
    print("\n")

    l = len(str1)
    for i in range(0,l):          # diagonal esquerda invertida
        print((l - i - 1) * " " +  str1[l - i - 1])    # lê a string da direita para a esquerda
    print("\n")
    
    l = len(str1)
    for i in range(0,l):          # em V  - coloca espaços à esquerda e no meio
        print(i * " " +  str1[i] + (2 * (l - i -1 )) * " " + str1[l - i - 1])
        i += 1
    print("\n")

    l = len(str1)
    m = l // 2
    p = l % 2
    for i in range(0,l):            # em X
        esq = i if i < m else l - i -1        # calcula os espaços à esquerda
        centro = l - 2 * esq - 2              # calcula os espaços a meio
        dir = "" if i == m and p == 1 else str1[i]   # evita duas letras quando a string tem comprimento ímpar 
        print(esq * " " + str1[i] + centro * " " + dir)  # e o cruzamento tem só uma letra
    print("\n")

    MAXL = 40      # número da carateres da linha de movimento
    movimento = True      # variável de controlo de ciclo (para posteriormente juntar uma interrupção)
    linha = str1 + (MAXL - len(str1)) * " "    # carrega a linha inicial com a palavra
    contador = 0         # contador de controlo enquanto não tiver um mecanismo de interrupção
    sys.stdout.write("\033[?25l")   # Código de escape para desligar o piscar do cursor no terminal
    while (movimento):
        #print(linha + "\r")   // \r faz voltar o cursor para o início da linha, mas não funciona com 'print'
        sys.stdout.write(linha + "\r")  # outra forma de escrever para o terminal
        time.sleep(0.15)        # 0.15 segundo de pausa entre cada apresentação da string para simular movimento
        aux = linha[MAXL - 1]    # guarda o último carater da linha
        linha = aux + linha[0:MAXL-1]  # no python as strings são imutáveis; esta atribuição cria uma nova
        contador += 1
        movimento = contador < 100       # termina com este número de ciclos
    sys.stdout.write("\033[?25h")       # volta a ligar o cursor do terminal
    print("\n")


#sys.stdout.write("\r{}".format(i))
#    sys.stdout.flush()





# main   Com 4 letrinhas apenas se escreve a palavra main, é das palavras pequenas a maior que o python não tain

funcao()

teste()

# acabou o main

