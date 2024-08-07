#include <iostream>
#include <string>

using namespace std;


void funcao(void) {
    cout << "olá, funcao!!!" << endl; 
}

void teste(void) {
    // string str0 = string(10, '*');
    // string str = string(10, '$');
    string str0 = "OLA";
    string str = "MUNDO";
    string str1 = str0 + " " + str;
    string str2 = str + " " + str0;
    cout << str0 << str << str0 << endl;
    for (int i = 0; i < str1.size(); i += 1 ){           // diagonal direita
        cout << string(i, ' ') << str1[i] << endl;
    }
    for (int i = 0; i < str2.size(); i += 1 ){          // diagonal direita inversa
        cout << string(i, ' ') << str2[i] << endl;
    }
    for (int i = str1.size() - 1; i > -1; i -= 1 ){     // diagonal esquerda
        cout << string(i, ' ') << str1[i] << endl;
    }
    for (int i = str2.size() - 1; i > -1; i -= 1 ){     // diagonal esquerda inversa
        cout << string(i, ' ') << str2[i] << endl;
    }
    for (int i = 0; i < str1.size(); i += 1 ){          // em V
        cout << string(i, ' ') << str1[i] << string(2*str1.size() - (i + 1)*2, ' ') << str1[str1.size() - i - 1] << endl;
    }
    int inistr = 0;
    int lenstr = str1.size();
    int centro = lenstr / 2;
    int meio = 0;
    cout << " 1 " << centro << " 2 " << lenstr << endl;
    //for (int i = 0; i < str1.size(); i += 1) {
    //    strini = i;
    //    // strmeio = ;
    //    cout << string(strini, ' ') << str1[i] << string(strmeio, ' ') << str[i] << endl;
    //}
    for (int i = 0; i < centro; i += 1 ){   // em X
        cout << string(i, ' ') << str1[i] << string(lenstr+1 - i, ' ') << str1[i] << endl;
    }
    //for (int i = centro; i < lenstr; i += 1 ){          // em X
    //    cout << string(lenstr - i, ' ') << str1[i] << string(i + centro - lenstr, ' ') << str1[i] << endl;
    //}
    
}


int main()
{
    
    cout << "Hello World" << endl;

    funcao();
    
    teste();
    
    return 0;
}