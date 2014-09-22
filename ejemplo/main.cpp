#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
       cout<<"escrivir una cadena de texto....: ";
    getline(cin,str,'\n');

    char c = 'a';
    string reemplazo = "x";

    for (int i = 0; i < (int)str.length(); ++i) {
        if(str[i]==c)
        {
            str.replace(i,1,reemplazo);
        }
    }

    cout << str << endl;
    return 0;
}
