#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "rainhas.hpp"

using namespace std;

bool formatacao(string teste) {
    string line;
    ifstream arquivo(teste);
    if (arquivo.is_open()) {
        int i = 0;
        int qntd_rainhas = 0;
        while (!arquivo.eof()) {
            if (i == 8) {
                return true;
            }
            getline(arquivo, line);
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
        int y = 0, x = 0;
        while (!arquivo.eof()) {
            getline(arquivo, line);
            for (int i = 0; i < 8; i++) {
                if (line[i] == '1') {
                    ums[x][0] = i + 1;
                    ums[x][1] = y + 1;
                    x++;
                }
            }
            y++;
        }
        arquivo.close();
    }
    return ums;
}

void arquivo_saida(vector<vector<int>> atq, string tx) {
    ofstream arquivo("ataques.txt", ios::app);
    arquivo << tx << endl;
    for (int i = 0; i < atq.size() - 1; i=i+2) {
        arquivo << atq[i][0] << ',' << atq[i][1] <<' ';
        arquivo << atq[i+1][0] << ',' << atq[i+1][1] <<endl;
    }
    arquivo << '\n';
    arquivo.close();
}

bool ataques(int **queens, string tx) {
    vector<vector<int>> ameacas;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (queens[i][0] == queens[j][0]) {
                vector<int> aux;
                vector<int> aux2;
                aux.push_back(queens[i][0]);
                aux.push_back(queens[i][1]);
                ameacas.push_back(aux);
                aux2.push_back(queens[j][0]);
                aux2.push_back(queens[j][1]);
                ameacas.push_back(aux2);
                break;
            }
            if (queens[i][1] == queens[j][1]) {
                vector<int> aux;
                vector<int> aux2;
                aux.push_back(queens[i][0]);
                aux.push_back(queens[i][1]);
                ameacas.push_back(aux);
                aux2.push_back(queens[j][0]);
                aux2.push_back(queens[j][1]);
                ameacas.push_back(aux2);
                break;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (fabs(queens[i][1] - queens[j][1])/fabs(queens[i][0] - queens[j][0]) == 1) {
                vector<int> aux;
                vector<int> aux2;
                aux.push_back(queens[i][0]);
                aux.push_back(queens[i][1]);
                ameacas.push_back(aux);
                aux2.push_back(queens[j][0]);
                aux2.push_back(queens[j][1]);
                ameacas.push_back(aux2);
                break;
            }
        }
    }
    if (ameacas.size() == 0) {
        return false;
    }
    arquivo_saida(ameacas, tx);
    return true;
}

int chamada(string a) {
    if (formatacao(a)) {
        return -1;
    }
  int **rainhas = matriz(a);
    if (ataques(rainhas, a)) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        free(rainhas[i]);
    }
    free(rainhas);
  return 0;
}