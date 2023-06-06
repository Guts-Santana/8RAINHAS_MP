#include <bits/stdc++.h>
using namespace std;
bool formatacao(string teste) {
    string line;
    ifstream arquivo (teste);
    if (arquivo.is_open()){
        int i = 0;
        int qntd_rainhas = 0;
        while (! arquivo.eof()) {
            if (i == 8){
                return true;
            }
            getline(arquivo,line);
            if (line.length() != 8) {
                return true;
            } else {
                for (int j = 0; j < 8; j++) {
                    if (line[j] == '1') {
                        qntd_rainhas++;
                    }
                }
            }
            i++;
        }
        if (qntd_rainhas != 8) {
            return true;
        }
        arquivo.close();
    }
    return false;
}


int main(){
  if (formatacao("testagem.txt")) {
    return -1;
  }
  return 0;
  
}