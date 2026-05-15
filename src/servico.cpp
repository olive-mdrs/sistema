#include "servico.h"
#include <iostream>

using namespace std;

bool contemApenasEspacos(const string &str) {
  return str.find_first_not_of(" \t\n\v\f\r") == string::npos;
}

bool adicionarNoticia(vector<Noticia> &bancoNoticias, const string &texto,
                      const string &classificacao) {
  if (texto.empty() || contemApenasEspacos(texto)) {
    cerr << "Erro: Texto da noticia é vazio ou invalido." << endl;
    return false;
  }

  Noticia novaNoticia;
  novaNoticia.texto = texto;
  novaNoticia.classificacao =
      classificacao.empty() ? CLASSIFICACAO_DUVIDOSA : classificacao;

  if (classificacao != CLASSIFICACAO_CONFIAVEL &&
      classificacao != CLASSIFICACAO_DUVIDOSA &&
      classificacao != CLASSIFICACAO_FALSA) {
    novaNoticia.classificacao = CLASSIFICACAO_DUVIDOSA;
    if (!classificacao.empty()) {
      cout << "Classificacao invalida: o texto sera automaticamente "
              "classificado como duvidoso."
           << endl;
    }
  } else {
    novaNoticia.classificacao = classificacao;
  }

  bancoNoticias.push_back(novaNoticia);
  return true;
}

string analisarConfiabilidade(const string &texto) {
  int pontuacaoFakeNews = 0;

  if (texto.find("FONTE") == string::npos) {
    pontuacaoFakeNews++;
  }
  if (texto.find("!!!") != string::npos) {
    pontuacaoFakeNews++;
  }
  if (texto.find("URGENTE") != string::npos) {
    pontuacaoFakeNews++;
  }
  if (texto.length() < 10) {
    pontuacaoFakeNews++;
  }

  if (pontuacaoFakeNews == 0) {
    return CLASSIFICACAO_CONFIAVEL;
  } else if (pontuacaoFakeNews == 1) {
    return CLASSIFICACAO_DUVIDOSA;
  } else {
    return CLASSIFICACAO_FALSA;
  }
}
