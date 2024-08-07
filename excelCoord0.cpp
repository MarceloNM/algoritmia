#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int fromBaseX(string origem, string base) {  // especial para coordenadas excel
    long int res = 0;                    // resultado final em decimal
    int lenb = base.size();         // comprimento da base
    int leno = origem.size();       // 
    int num;
    long int pot;
    for (int i = 0; i < leno; i += 1) {
        num = 0;
        pot = 1;
        while (num < lenb && origem[i] != base[num]) num += 1;
        for (int j = 0; j < leno - i - 1; j += 1) pot *= lenb;
        res = res + pot * (num + 1);
    }
    return res;
}

long int fromBase(string origem, string base) {   // bases normais em que o primeiro elemento vale zero
    long int res = 0;                    // resultado final em decimal
    int lenb = base.size();         // comprimento da base
    int leno = origem.size();       // 
    int num;
    long int pot;
    for (int i = 0; i < leno; i += 1) {
        num = 0;
        pot = 1;
        while (num < lenb && origem[i] != base[num]) num += 1;
        for (int j = 0; j < leno - i - 1; j += 1) pot *= lenb;
        res = res + pot * (num);
    }
    return res;
}

long int convLinhas(string origem){
    int res = stoi(origem);
    return res - 1;
}

long int convColunas(string origem){
    int res = fromBaseX(origem, "abcdefghijklmnopqrstuvwxyz");
    return res - 1;
}

string essetrim(string str){
    int ini = 0;
    int fini = str.length() - 1;
    while (str[ini] == 32 || str[ini] == 9 || str[ini] == 43 || str[ini] == 45) {
        ini += 1;
    }
    while (str[fini] == 32 || str[fini] == 9 || str[fini] == 43 || str[fini] == 45) {
        fini -= 1;
    }
    return str.substr(ini, fini + 1);
}

bool estNum(char ene) {
    return ene > 47 && ene < 58;
}

bool estLetra(char ele) {
    return (ele > 64 && ele < 92) || (ele > 96 && ele < 121);
}

bool validaXl(string coordXl){
    int finiLetra = 0;
    int iniNum = 1;
    bool valido;
    coordXl = essetrim(coordXl);
    if (coordXl.size() < 2) valido = false;
    else valido = estLetra(coordXl[0]);
    int pos = 1;
    while (pos < coordXl.size() && valido) {
        if (estLetra(coordXl[pos])){
            finiLetra = pos;
        } else {
            if (estNum(coordXl[pos])){
                if (iniNum == 1) iniNum = pos;
            } else {
                valido = false;
            }
        }
        pos += 1;   
    }
    if (valido && finiLetra < iniNum) {
        string s1 = coordXl.substr(0,finiLetra+1);
        string s2 = coordXl.substr(iniNum,coordXl.size());
        cout << "Coordenadas eXcel: |" << s1 << "|" << s2 << "|" << endl;
        cout << "Coordenadas array: |" << convColunas(s1) << "|" << convLinhas(s2) << "|" << endl;
    } else cout << "Não é um endereço eXcel válido" << endl;
    return valido;
}

void teste(void) {
    std::cout<<"Hello World"<< endl;
    
    cout << fromBaseX("aaa", "abcdefghijklmnopqrstuvwxyz") << endl;
    cout << fromBase("11111111", "0123456789") << endl;
    cout << fromBase("11111111", "0123456789ABCDEF") << endl;
    cout << fromBase("11111111", "01") << endl;
    cout << "Coluna " << convColunas("a") << endl;
    cout << "Linha " << convLinhas("23") << endl;
    
}

int main(int argc, char* argv[])
{
    vector<string> args;
    if (argc > 1) {                     // argc contém a quantidade de argumentos
        args.assign(argv + 1, argv + argc);
    }

    teste();
    
    validaXl("aaa1234");
    for (int j = 0; args.size() - 1; j += 1){
        validaXl(args[j]);
    }
    
    return 0;
}