/**
 * @file sistema.cpp
 * @brief Sistema de Monitoramento de Fake News e Qualidade da Informação (versão inicial).
 *
 * Permite inserir textos de notícias, classificá‑las como confiável, duvidosa ou falsa
 * com base em critérios simples (ausência de fonte, linguagem sensacionalista, tamanho),
 * e listar as notícias cadastradas.
 *
 * @note Este código é a base para o trabalho de Boas Práticas de Programação.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Estrutura que representa uma notícia. (Deletar comentário no futuro)
 */
struct D {
  string t;
  string c;
};

/// Base de dados de notícias (Deletar)
vector<D> data;

/**
 * @brief Adiciona uma nova notícia à base de dados.
 *
 * Se a classificação não for informada, assume "duvidosa" como padrão.
 * Se o texto for vazio, exibe "erro" e não insere.
 *
 * @param a Texto da notícia. Se vazio, a função apenas imprime "erro" (mudar pra throw?).
 * @param b Classificação desejada. Se omitida ou vazia, usa "duvidosa".
 */
void f(string a, string b = "") {
  if (a != "") {
    D d;
    d.t = a;

    if (b == "") {
      d.c = "duvidosa";
    } else {
      d.c = b;
    }

    data.push_back(d);
  } else { // MELHORAR (exceção, log, etc.)
    cout << "erro" << endl;
  }
}

/**
 * @brief Lista todas as notícias cadastradas, exibindo texto e classificação.
 */
void func2() {
  for (int i = 0; i < data.size(); i++) {
    cout << "Texto: " << data[i].t << endl;
    cout << "Classificacao: " << data[i].c << endl;
    cout << "-------------------" << endl;
  }
}

/**
 * @brief Analisa um texto e retorna sua classificação baseada em regras simples.
 *
 * Critérios:
 * - Ausência da palavra "FONTE" - aumenta o score.
 * - Presença de "!!!" - aumenta o score (linguagem sensacionalista).
 * - Presença de "URGENTE" - aumenta o score.
 * - Texto com menos de 10 caracteres - aumenta o score.
 *
 * Retorno:
 * - score 0 → "confiavel"
 * - score 1 → "duvidosa"
 * - score >=2 → "falsa"
 *
 * @param txt Texto a ser analisado.
 * @return string Classificação resultante.
 */
string analisar(string txt) {
  int score = 0;

  if (txt.find("FONTE") == string::npos) {
    score = score + 1;
  }
  if (txt.find("!!!") != string::npos) {
    score = score + 1;
  }
  if (txt.find("URGENTE") != string::npos) {
    score = score + 1;
  }
  if (txt.length() < 10) {
    score = score + 1;
  }

  if (score == 0) {
    return "confiavel";
  } else if (score == 1) {
    return "duvidosa";
  } else {
    return "falsa";
  }
}

/**
 * @brief Interface para adicionar uma notícia com classificação manual.
 *
 * Solicita texto e classificação ao usuário. Se a classificação for deixada em branco,
 * a função 'f' (MUDAR) assumirá o valor padrão "duvidosa".
 */
void add_manual() {
  string t, c; // VALIDAR ENTRADAS (c deveria ser confiavel, duvidosa ou falsa?)

  cout << "Digite o texto: ";
  getline(cin, t);

  cout << "Digite classificacao: ";
  getline(cin, c);

  if (c == "") {
    f(t);
  } else {
    f(t, c);
  }
}

/**
 * @brief Interface para adicionar uma notícia com classificação automática.
 *
 * Solicita apenas o texto, a classificação é determinada pela função 'analisar' (MUDAR?).
 */
void add_auto() {
  string t;

  cout << "Digite o texto: ";
  getline(cin, t);

  string c = analisar(t);
  f(t, c);
}

/**
 * @brief Exibe o menu principal e direciona para as operações escolhidas.
 *
 * Opções:
 * 1 - Adicionar notícia manualmente
 * 2 - Adicionar notícia com classificação automática
 * 3 - Listar todas as notícias
 * 4 - Sair
 */

void menu() {
  while (true) {
    cout << "1 - adicionar manual" << endl // MUDAR TEXTOS?
    cout << "2 - adicionar automatico" << endl;
    cout << "3 - listar" << endl;
    cout << "4 - sair" << endl;

    string op;
    getline(cin, op);

    if (op == "1") {
      add_manual();
    } else if (op == "2") {
      add_auto();
    } else if (op == "3") {
      func2();
    } else if (op == "4") {
      break;
    } else {
      cout << "errado" << endl;
    }
  }
}

/**
 * @brief Ponto de entrada do programa.
 *
 * Inicia o menu principal.
 *
 * @return int Código de saída (0 indica sucesso).
 */
int main() {
  menu();
  return 0;
}
