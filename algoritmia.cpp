// programa testado apenas no https://www.programiz.com/cpp-programming/online-compiler/
// Dezembro 2023


#include <iostream>

using namespace std;

void espera(string msg){
    char letra;
    cout << endl << msg << ": ";
    cin.ignore();        // limpa o 'buffer' de teclado
    letra = getchar();
}

void menu(){
    cout << endl;
    cout << "  a - Paridade de um número" << endl;
    cout << "  b - Somar valores" << endl;
    cout << "  c - Fatorial de um número" << endl;
    cout << "  d - Tabuada" << endl;
    cout << "  e - Maior valor" << endl;
    cout << "  f - Laranjas em saldo" << endl;
    cout << "  g - Peso ideal" << endl;
    cout << "  h - Equipa vencedora" << endl;
    cout << "  i - Requerer reforma" << endl;
    cout << "  j - O triângulo" << endl;
    cout << "  k - Fatorial recursivo" << endl;
    cout << "  s - Sair do programa" << endl;
}

int escolheOpcao(string legenda){
    char letra;
    letra = 115;
    cout << endl;
    while (letra < 0 || letra > 13) {
        cout << legenda << ": ";
        cin >> letra;
        if (letra > 65 && letra < 91)
            letra -= 64;
        else if (letra > 96 && letra < 123) {
            if (letra == 115)
                letra = 0;
            else letra -= 96;
        }
    }
    cout << endl;
    return letra;
}

void paridade(){     // opçao a
    int numero;
    numero = 0;
    cout << "Escreva um número: ";
    cin >> numero;
    if (numero == 0) 
        cout << "O número é zero"  << endl;
    else if (numero % 2 == 0)
        cout << "O número " << numero << " é par." << endl;
    else
        cout << "O número " << numero << " é ímpar." << endl;
    espera("Tecle para continuar");
}  // paridade

int soma(int a, int b){
    return a + b;
}
int leNumero(string mensagem){
    int valor;
    cout << mensagem << ": ";
    cin >> valor;
    return valor;
}
void somaNumeros(){
    int primeiroNumero, segundoNumero;
    int resultado;
    primeiroNumero = leNumero("Qual é o primeiro número");
    segundoNumero = leNumero("Qual é o segundo número");
    resultado = soma(primeiroNumero, segundoNumero);
    cout << "Resultado: " << resultado << endl; 
}

void somarValores(){  // opcao b
    float valor, total = 0;
    int contador = 1;
    bool continuar = true;
    while (continuar){
        cout << "Valor " << contador++ << ": ";
        cin >> valor;
        total += valor;
        continuar = !(valor == 0);
    }
    contador -= 2;
    if (contador > 0) {
        cout << "Total de " << contador << " valores igual a " << total << endl;
        cout << "Média igual a " << total / contador << endl;
    }
    espera("Tecle para continuar");
}   // somarValores

float fatorial(long int num){
    if ( num < 2 )
        return 1;
    else
        return num * fatorial(--num);
}     // fatorial



void fatorialRecursivo(){   // opção K
    float num, resultado = 1; // fatorial de 0 ou 1 é 1
    int limite = 100;
    cout << "Número para calcular fatorial (0 a " <<  limite << "): ";
    cin >> num;
    if ( num >= 0 && num <= limite) {
        resultado = fatorial(num);
        cout << "O fatorial de " << num << " é " << resultado << endl;
    } else
        cout << "Número inválido" << endl; 
    espera("Tecle para continuar");
}  // fatorialRecursivo


void fatorialSimples(){
    float num, resultado = 1; // fatorial de 0 ou 1 é 1
    int contador, limite = 100;
    cout << "Número para calcular fatorial (0 a " <<  limite << "): ";
    cin >> num;
    if ( num >= 0 && num <= limite) {
        contador = num;
        while (contador > 1)
            resultado *= contador--;
        cout << "O fatorial de " << num << " é " << resultado << endl;
    } else
        cout << "Número inválido" << endl; 
    espera("Tecle para continuar");
}   // fatorialSimples



void tabuada(){
    float resultado, operador, operando = 1;
    int operadori, operandoi; 
    char operacao = 120;
    cout << "Número operando (1 a 10) ";
    cin >> operando;
    cout << "Operação ( X, +, -, /, %) ";
    cin >> operacao;
    for (operador = 1; operador < 11; operador++) {
        switch (operacao){
        case 120:
            resultado = operando * operador;
            break;
        case 43:
            resultado = operando + operador;
            break;
        case 45:
            resultado = operando - operador;
            break;
        case 47:
            resultado = operando / operador;
            break;
        case 37:
            operandoi = int(operando);
            operadori = int(operador);
            resultado = operandoi % operadori;
            break;
        default:
            resultado = 0;
        }
        // cout << fixed;
        // cout.precision(2);
        cout << operando << " " << operacao << " " << operador << " = " << resultado << endl;
    }
    espera("Tecle para continuar");
}      // tabuada


void maiorValor(){
    float valor, maiorVal, menorVal;
    int contador = 1;
    cout << "Valor " << contador << ": ";
    cin >> valor;
    maiorVal = menorVal = valor;
    while (valor != 0) {
        contador++;
        cout << "Valor " << contador << ": ";
        cin >> valor;
        if ( valor > maiorVal )
            maiorVal = valor;
        else if ( valor < menorVal )
            menorVal = valor;
    }
    if ( contador > 1 ) {
        cout << "O maior valor é " << maiorVal << endl;
        cout << "e o menor valor é " << menorVal << endl;
    } else
        cout << "Sem valores inseridos" << endl;
    espera("Tecle para continuar");
}     // maiorValor


void laranjas() {
    int qtLaranjas;
    float aPagar;
    cout << "Quantas laranjas quer? ";
    cin >> qtLaranjas;
    if ( qtLaranjas > 0 ) {
        if ( qtLaranjas < 12 )
            aPagar = qtLaranjas * 0.3;
        else
            aPagar = qtLaranjas * 0.5;
        cout << "O valor a pagar é " << aPagar << "€" << endl;
    } else
        cout << "Volte sempre!" << endl;
    espera("Tecle para continuar");
}    // laranjas

void pesoIdeal() {
    string nome = "", sexo = "M";
    float altura, pIdeal;
    cout << "Nome: ";
    cin >> nome;
    cout << "Sexo (M/F): ";
    cin >> sexo;
    cout << "Altura: ";
    cin >> altura;
    if ( altura > 2 && altura < 200 )
        altura /= 100; 
    if ( sexo == "F" || sexo == "f" )
        pIdeal = (altura * 62.1) - 44.7;
    else
        pIdeal = (altura * 72.7) - 58;
    cout << "O peso ideal de " << nome << " é " << pIdeal << endl;
    espera("Tecle para continuar");
}     // pesoIdeal

void equipaVencedora() {
    string equipa[2];
    int indice, pontos[2];
    for ( indice = 0; indice < 2; indice++) {
        cout << "Nome da equipa " << indice + 1 << ": ";
        cin >> equipa[indice];
        cout << "Pontos da equipa " << equipa[indice] << ": ";
        cin >> pontos[indice];
    }
    if ( pontos[0] > pontos[1] )
        cout << "A equipa vencedora é: " << equipa[0] << endl;
    else if ( pontos[0] < pontos[1] )
        cout << "A equipa vencedora é: " <<  equipa[1] << endl;
    else
        cout << "As equipas " << equipa[0] << " e " << equipa[1] << " empataram" << endl;
    espera("Tecle para continuar");
}       // equipaVencedora


void reforma(){
    string codigoEmpregado;
    int anoNascimento, anoIngresso, anoAtual = 2023, idade, tempoTrabalho;
    cout << "Código do empregado: ";
    cin >> codigoEmpregado;
    cout << "Ano de nascimento do empregado: ";
    cin >> anoNascimento;
    cout << "Ano de entrada na empresa: ";
    cin >> anoIngresso;
    idade = anoAtual - anoNascimento;
    tempoTrabalho = anoAtual - anoIngresso;
    if ( idade >= 65  || tempoTrabalho >= 30 )
        cout << "Requerer aposentadoria" << endl;
    else if ( idade >= 60 && tempoTrabalho >= 25 )
        cout << "Requerer aposentadoria" << endl;
    else
        cout << "Não requerer" << endl;
    espera("Tecle para continuar");
}      // reforma

void triangulo(){
    float lados[3];
    bool sair, certo;
    int indice = 0;
    sair = certo = false;
    while ( !certo ){  // valida o triângulo e termina o procedimento com valor 0 na entrada
        cout << "Lado " << indice + 1 << " do triângulo: ";
        cin >> lados[indice];
        if (lados[indice] > 0)
            if (indice < 2)
                indice++;
            else if ( lados[0] >= lados[1] + lados[2] || lados[1] >= lados[0] + lados[2] || lados[2] >= lados[0] + lados[1]) {
                cout << "Erro nos dados" << endl;
                cout << "Não é um triângulo. Repita." << endl;
                indice = 0;
            } else
                certo = true;
        else {
            sair = true;
            certo = true;
        }
    }
    if ( sair )
        cout << "Xau" << endl;
    else if ( lados[0] == lados[1] && lados[0] == lados[2] && lados[1] == lados[2])
        cout << "O triângulo é equilátero" << endl;
    else if ( lados[0] != lados[1] && lados[0] != lados[2] && lados[1] != lados[2])
        cout << "O triângulo é escaleno" << endl;
    else 
        cout << "O triângulo é isósceles" << endl;
    espera("Tecle para continuar");
}      // triangulo

int main(int argc, char *argv[]) {
    char opcao = 1;
    cout << "Hello world!" << endl;
    while (opcao != 0){
        menu();
        opcao = escolheOpcao("Digite a opcao");
        switch(opcao) {
        case 0:          // opção S
            cout << endl << "---  Xau  ---" << endl;
            break;
        case 1:          // opção A
            // somaNumeros();
            paridade();
            break;
        case 2:          // opção B
            somarValores();
            break;
        case 3:          // opção C
            fatorialSimples();
            break;
        case 4:          // opção D
            tabuada();
            break;
        case 5:          // opção E
            maiorValor();
            break;
        case 6:          // opção F
            laranjas();
            break;
        case 7:          // opção G
            pesoIdeal();
            break;
        case 8:          // opção H
            equipaVencedora();
            break;
        case 9:          // opção I
            reforma();
            break;
        case 10:          // opção J
            triangulo();
            break;
        case 11:          // opção K
            fatorialRecursivo();
            break;
        default:
            cout << "Opção inválida" << endl;
        }
    }
    return 0;
}