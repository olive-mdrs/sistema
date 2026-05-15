#include "interface.h"
#include "servico.h"
#include <iostream>

using namespace std;

string lerEntrada(const string &mensagem) {
  cout << mensagem;
  string entrada;
  getline(cin, entrada);
  return entrada;
}

void exibirNoticias(const vector<Noticia> &bancoNoticias) {
  if (bancoNoticias.empty()) {
    cout << "\nO banco de noticias esta vazio.\n" << endl;
    return;
  }

  for (const auto &noticia : bancoNoticias) {
    cout << "Texto: " << noticia.texto << endl;
    cout << "Classificacao: " << noticia.classificacao << endl;
    cout << "-------------------" << endl;
  }
}

void interagirAdicaoManual(vector<Noticia> &bancoNoticias) {
  string texto = lerEntrada("Digite o texto: ");
  string classificacao = lerEntrada("Digite classificacao: ");

  adicionarNoticia(bancoNoticias, texto, classificacao);
}

void interagirAdicaoAutomatica(vector<Noticia> &bancoNoticias) {
  string texto = lerEntrada("Digite o texto: ");
  string classificacao = analisarConfiabilidade(texto);

  adicionarNoticia(bancoNoticias, texto, classificacao);
}

void executarMenu(vector<Noticia> &bancoNoticias) {
  while (true) {
    cout << "1 - adicionar manual" << endl;
    cout << "2 - adicionar automatico" << endl;
    cout << "3 - listar" << endl;
    cout << "4 - sair" << endl;

    string opcao;
    getline(cin, opcao);

    if (opcao == "1") {
      interagirAdicaoManual(bancoNoticias);
    } else if (opcao == "2") {
      interagirAdicaoAutomatica(bancoNoticias);
    } else if (opcao == "3") {
      exibirNoticias(bancoNoticias);
    } else if (opcao == "4") {
      break;
    } else {
      cout << "Erro: '" << opcao << "' nao e uma opcao valida. Tente novamente."
           << endl;
    }
  }
}
