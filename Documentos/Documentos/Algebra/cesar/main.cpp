#include<iostream>

using namespace std;

int main()
{
    char msg[100], ch;
    int i, key = 3;
    cout << "Inserta el Mensaje: ";
    cin.getline(msg, 100);

    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z')
                ch = ch - 'z' + 'a' - 1;
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;
            msg[i] = ch;
        }
    }
    cout << "Mensaje Encryptado: " << msg <<"\n";

    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a')
                ch = ch + 'z' - 'a' + 1;
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch > 'a')
                ch = ch + 'Z' - 'A' + 1;
            msg[i] = ch;
        }
    }

    cout << "Mesaje Desencriptado: " << msg << "\n";

    return 0;
}
