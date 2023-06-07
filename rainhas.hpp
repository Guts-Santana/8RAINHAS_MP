#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <string>

/**
 * @brief essa primeira funcao lê o arquivo e descobre se é 8x8
 * e se tem exatas 8 rainhas
 * 
 * 
 * A funçao lê linha por linha do arquivo e ja vai contando se
 * se a linha é de 8 termos, após isso ele vai rodar a linha e 
 * ver se há 1 nessa linha e aumentar a qntd_rainhas em 1;
 * se algum desses for diferente de 8;
 * @param teste o nome do arquivo;
 * @return true se o tabuleiro não é 8 por 8 ou n tem 8 rainhas;
 * @return false se o tabuleiro é 8x8 e tem 8 rainhas;
 */
bool formatacao(string teste);

/**
 * @brief Cria uma matriz de coordenadas das rainhas com base no arquivo de entrada.
 * em que é contado em eixo x e y, sendo a linha 0 do arquivo a linha 1 do tabuleiro;
 * @param arquivos o arquivo do tabuleiro;
 * @return int retorna a uma matriz com a posicao de cada rainhas
 */
int chamada(string arquivos);

/**
 * Verifica se há ataques entre as rainhas.
 * @param queens Matriz de coordenadas das rainhas.
 * @param tx Nome do arquivo de entrada.
 * @return Retorna verdadeiro se houver ataques entre as rainhas, falso caso contrário.
 */
bool ataques(int **queens, string tx);

/**
 * Salva os ataques entre rainhas em um arquivo de saída.
 * @param atq O vetor com as coordenadas das rainhas que se atacam.
 * @param tx Nome do arquivo de entrada.
 */
void arquivo_saida(vector<vector<int>> atq, string tx);

/**
 * Função principal que faz a chamada para verificar o arquivo de entrada.
 * @param a Nome do arquivo de entrada.
 * @return Retorna -1 se a formatação estiver incorreta, 1 se houver ataques entre as rainhas e 0 caso contrário.
 */
int** matriz(string teste);