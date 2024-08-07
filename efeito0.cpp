// efeito.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>


using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;


/*cout << "Início" << endl;
sleep_for(milliseconds(500));
system("clear"); // substituir "clear" por "cls" em Windows
cout << "Meio segundo depois" << endl;
*/


void cls(void) {        // from stack overflow
    // system("cls||clear");
    system("cls");
    return;
}

void poeCursor(int l, int c) {
    // string code = "\033" + "[" + "0" + "; " + "0" + "H";
    // cout << "\033[0;0H";   // <ESC>[{ROW};{COLUMN}H posiciona cursor na linha coluna
    cout << "\033[H";
}

void limpaEcra(void) {
    cout << "\033[2J";     // limpa o ecrã
    poeCursor(0, 0);
}


void pausa(void) {   /// pausa marada
    char p = 'p';
    cin >> p;
}

string maiuscula(string palavra) {
    int l = palavra.size();
    for (int i = 0; i < l; i += 1) {
        if (palavra[i] > 96 && palavra[i] < 123) palavra[i] -= 32;
    }
    // cout << palavra;
    return palavra;
}

void menu() {
    //    cls();
    cout << string(52, '*') << endl;
    cout << '*' << string(50, ' ') << '*' << endl;
    cout << '*' << "  EFEITO" << string(42, ' ') << '*' << endl;
    cout << '*' << string(50, ' ') << '*' << endl;
    cout << '*' << "    1 - Diagonal Esquerda" << string(25, ' ') << '*' << endl;
    cout << '*' << "    2 - Diagonal Esquerda, Texto Invertido" << string(8, ' ') << '*' << endl;
    cout << '*' << "    3 - Diagonais Cruzadas" << string(24, ' ') << '*' << endl;
    cout << '*' << "    4 - Diagonal Direita, Texto Invertido" << string(9, ' ') << '*' << endl;
    cout << '*' << "    5 - Em V" << string(38, ' ') << '*' << endl;
    cout << '*' << "    6 - Deslizante" << string(32, ' ') << '*' << endl;
    cout << '*' << "    T - Todos" << string(37, ' ') << '*' << endl;
    cout << '*' << "    E - Encerrar" << string(34, ' ') << '*' << endl;
    cout << '*' << string(50, ' ') << '*' << endl;
    cout << string(52, '*') << endl << endl;
    cout << "  OPÇÃO> ";

}

char lerOpcao(const string opcoes) {
    char op = 'E';
    bool repetir = true;
    while (repetir) {
        menu();
        cin >> op;
        for (int i = 0; i < opcoes.size(); i += 1) {
            if (op == opcoes[i]) {
                repetir = false;
            }
        }
    }
    return op;
}

void diagEsq(string palavra) {       // efeito 1
    //    cls();
    int l = palavra.size();
    //    cout << palavra << " " << l << endl;
    for (int i = 0; i < l; i += 1) {
        cout << string(i, ' ') << palavra[i] << endl;
    }
}

void diagEsqInv(string palavra) {     // efeito 2
    //    cls();
    int l = palavra.size();
    //    cout << palavra << " " << l << endl;
    for (int i = l - 1; i > -1; i -= 1) {
        cout << string(l - i - 1, ' ') << palavra[i] << endl;
    }
}

void diagCruz(string palavra) {     // efeito 3
    int l = palavra.size();
    int j;
    for (int i = 0; i < l; i += 1) {
        if (i < (l / 2)) j = i;
        else j = l - i - 1;
        // cout << j << palavra[i] << (l - 2 * j) << palavra[i] << endl;
        if ((l - 2 * j - 2) >= 0) cout << string(j, ' ') << palavra[i] << string(l - 2 * j - 2, ' ') << palavra[i] << endl;
        else cout << string(j, ' ') << palavra[i] << endl;
    }
}

void diagDirInv(string palavra) {     // efeito 4
    //    cls();
    int l = palavra.size();
    //    cout << palavra << " " << l << endl;
    for (int i = 0; i < l; i += 1) {
        cout << string(l - i - 1, ' ') << palavra[i] << endl;
    }
}

void emVe(string palavra) {             // efeito 5
    int l = palavra.size();
    int j;
    for (int i = 0; i < l; i += 1) {
        cout << string(i, ' ') << palavra[i] << string((l - 1) * 2 - 2 * i, ' ') << palavra[l - i - 1] << endl;
    }
}

void deslizante(string palavra, milliseconds velo) {       // efeito 6
    const int MAXLINE = 40;
    // int velo = 100;
    int l = palavra.size();
    bool movimento = true;
    string linha = string(MAXLINE, ' ');
    for (int i = 0; i < l; i++) {
        linha[i] = palavra[i];
    }
    string aux = " ";
    limpaEcra();
    cout << "\033[?25l";     // desliga o cursor
    int conteste = 0;
    while (movimento) {
        sleep_for(milliseconds(velo));
        cout << linha << "\r";
        aux = linha[MAXLINE - 1];
        for (int i = MAXLINE - 1; i > 0; i -= 1) {
            linha[i] = linha[i - 1];
        }
        linha[0] = aux[0];
        conteste++;
        movimento = conteste < 300;
    }
    cout << "\033[?25h";    // liga o cursor
}

int main(int argc, char* argv[]) {
    /*
    * Tratamento dos parametros de entrada
    * 
    * palavra1 [palavra2] ...
    * 
    * -i 0.25 palavra1 [palavra2] ... 
    * 
    */
    // from Stack Overflow
    
    string svelo;
    string exe_name = argv[0];          // Posição zero contém nome do programa em execução
    vector<string> argumentos;            // Vetor de strings para receber lista de argumentos 
    if (argc > 1) {                     // argc contém a quantidade de argumentos
        argumentos.assign(argv + 1, argv + argc);
    }
    else {
        argumentos.push_back("-i");
        argumentos.push_back("0.10");
        argumentos.push_back("jose");
        argumentos.push_back("mourinho");
    }
    int pos = 0;
    int haTempo = 0;
    if (argumentos[0] == "-i") {
        svelo = argumentos[1];
        pos = 2;
        haTempo = 1;
    }
    else {
        svelo = "0.25";
    }

    cout << argumentos.size();
    for (int i = 0; i < 4; i++)
        cout << argumentos[i] << endl;

    string palavra = maiuscula(argumentos[pos]);
    string palavrai = maiuscula(argumentos[argumentos.size() - pos + haTempo]);
    pos += 1;
    for (; pos < argumentos.size(); pos += 1) {
        palavra = palavra + " " + maiuscula(argumentos[pos]);
        palavrai = palavrai + " " + maiuscula(argumentos[argumentos.size() - pos + haTempo]);
    }
    

    // string svelo = "0.25";
    // string palavra1 = maiuscula("jose");
    // string palavra2 = maiuscula("mourinho");
    // string palavra = palavra1 + " " + palavra2;

    // string palavrai = palavra2 + " " + palavra1;

    milliseconds velo = (milliseconds) (int) (1000 * stod(svelo));

    bool continuar = true;

    while (continuar) {
        // menu();
        // cout << palavra << endl;
        char op = lerOpcao("123456TtEe");

        switch (op) {
        case '1':
            // cout << 1;
            diagEsq(palavra);
            // pausa();
            break;
        case '2':
            // cout << 2;
            diagEsqInv(palavra);
            // pausa();
            break;
        case '3':
            // cout << 3;
            diagCruz(palavra);
            // pausa();
            break;
        case '4':
            // cout << 4;
            diagDirInv(palavrai);
            break;
        case '5':
            // cout << 5;
            emVe(palavra);
            break;
        case '6':
            // cout << 6;
            deslizante(palavra, velo);
            break;
        case 'T': case 't':
            cout << 'T';
            break;
        case 'E': case 'e':
            // cout << 'E';
            continuar = false;
            break;
        default:
            break;
        }
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
