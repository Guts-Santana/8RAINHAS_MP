#include <bits/stdc++.h>
#include "rainhas.hpp"

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

int** matriz(string teste) {
    string line;
    int **ums = (int**)malloc(sizeof(int*)*8);
    for (int i = 0; i < 8; i++) {
        ums[i]= (int*)malloc(sizeof(int)*2);
    }
    
    

    ifstream arquivo (teste);
    if (arquivo.is_open()) {
        int x=0;
        while (! arquivo.eof()) {
            getline(arquivo,line);
            for (int i = 0; i < 8; i++) {
                if (line[i]=='1') {
                    ums[i][0] = i + 1;
                    ums[i][1] = x + 1;
                }
            }
            x++;
            
        }
        arquivo.close();
    }
    //return ums;
    return ums;
}

int ataques(string arquivos){
  cout<<formatacao(arquivos)<<endl;
  int **rainhas = matriz(arquivos);
  for (int i = 0; i < 8; i++) {
        cout<<rainhas[i][0]<<rainhas[i][1]<<"\n";
    }

    for (int i = 0; i < 8; i++) {
        free(rainhas[i]);
    }
    free(rainhas);
  return 0;
  
}