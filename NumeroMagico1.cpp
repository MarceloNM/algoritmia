#include <iostream>
#include <random>
#include <math.h>

using namespace std;

std::mt19937 randGen(std::random_device{}());

int next_int(int a, int b) {
    std::uniform_int_distribution <> dis(a, b);
    return dis(randGen);
}

double next_double(double a = 0.0, double b = 1.0) {
    std::uniform_real_distribution <> dis(a, b);
    return dis(randGen);
}

void encrip(char *dest, char *src, bool b) {
    const int desvio = 14;
    int i = b ? 1 : -1;
    while (*src != 0) {
        *dest = *src + i * desvio;
        *dest++;
        *src++;
        i *= -1;
    }
}

int lerInt(int min, int max, string pedido, string falha) {
    int a;
    cout << pedido << " " << min << " e " << max << ": ";
    cin >> a;
    bool correto = false;
    while(!correto || a < min || a > max) {
        if(cin.fail())  {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << falha << endl;
            cin >> a;
        }
        correto = !cin.fail();
    }
    return a;
} // fim da função lerInt


int main() {
    const int min = 1;      // valor mínimo de escolha
    const int max = 20;     // valor máximo de escolha
    const int distProx = 3;
    const int distMProx = 2;
//    cout << next_int(min, max) << endl;
//    cout << next_double(min, max) << endl;
//    cout << next_double() << endl;
    int tentativas = 0; 
    int numUser = 0;
    int numMagic = next_int(min, max);
    int distancia = 0;
    /* const string ganhou[20] = {"Brutal!! Acertou à primeira.", 
                        "Brilhante! Acertou à segunda.", 
                        "Muito Bom. Mas não lhe serve para nada.", 
                        "Bom. Um dia há de ser ótimo.", 
                        "Teve sorte de principiante.", 
                        "Sorte ao jogo, azar ao amor.", 
                        "Continue a tentar, só pode melhorar.", 
                        "No seu lugar não arriscava mais.", 
                        "O seu futuro é fácil de prever.", 
                        "Tente o caminho do mérito, mas não vai ser fácil.", 
                        "Estou sem palavras com o seu talento para números.", 
                        "Não decida nada com moeda ao ar. Não vai ter moedas para isso.", 
                        "A sorte favorece os audazes. Não é o caso.", 
                        "Melhor comprar feito do que fazer.", 
                        "Já tentou o jogo do Bicho? Não tente.", 
                        "Na próxima, pense antes de jogar", 
                        "O casino não é a sua casa.", 
                        "Fica-lhe mais barato fumar.", 
                        "Decididamente, abandone o jogo.", 
                        "Record mundial! Nunca alguém demorou tanto!" };
*/
     const string ganhou[20] = {"Brutal!! Acertou à primeira.", 
                        "Brilhante! Acertou à segunda.", 
                        "Muito Bom. Mas não lhe serve para nada.", 
                        "Bom. Um dia há de ser ótimo.", 
                        "Teve sorte de principiante.", 
                        "Sorte ao jogo, azar ao amor.", 
                        "Continue a tentar, só pode melhorar.", 
                        "No seu lugar não arriscava mais.", 
                        "O seu futuro é fácil de prever.", 
                        "Tente o caminho do mérito, mas não vai ser fácil.", 
                        "Estou sem palavras com o seu talento para números.", 
                        "Não decida nada com moeda ao ar. Não vai ter moedas para isso.", 
                        "A sorte favorece os audazes. Não é o caso.", 
                        "Melhor comprar feito do que fazer.", 
                        "Já tentou o jogo do Bicho? Não tente.", 
                        "Na próxima, pense antes de jogar", 
                        "O casino não é a sua casa.", 
                        "Fica-lhe mais barato fumar.", 
                        "Decididamente, abandone o jogo.", 
                        "Record mundial! Nunca alguém demorou tanto!" };

    do {
        // cout << "Escolha um número entre 1 e 20: " << endl;
        // cin >> numUser;
        numUser = lerInt(min, max, "Escolha um número entre", "Valor não válido. Repita");
        distancia = abs(numUser - numMagic);
        tentativas++;
        if (!distancia) {
            cout << ganhou[--tentativas];
        } else if (distancia < distMProx) {
            cout << " -> o fim está muito próximo" << endl;
        } else if (distancia < distProx) {
            cout << " -> o fim está próximo" << endl;
        } else {
            cout << " -> tem que estudar mais" << endl;
        }
    } while (distancia && tentativas < 19);
    if (tentativas == 20) cout << "É melhor ir descansar!" << endl;
}
