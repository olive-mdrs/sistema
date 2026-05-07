#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string CLASSIFICACAO_CONFIAVEL = "confiavel";
const string CLASSIFICACAO_DUVIDOSA = "duvidosa";
const string CLASSIFICACAO_FALSA = "falsa";

struct Noticia {
    string texto;
    string classificacao;
};

//antiga função "que faz tudo" adotando PRU
bool adicionarNoticia(vector<Noticia>& bancoNoticias, const string& texto, const string& classificacao = "") {
    if (texto.empty()) {
        return false; 
    }

    Noticia novaNoticia;
    novaNoticia.texto = texto;
    novaNoticia.classificacao = classificacao.empty() ? CLASSIFICACAO_DUVIDOSA : classificacao;

    bancoNoticias.push_back(novaNoticia);
    return true;
}

string analisarConfiabilidade(const string& texto) {
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

string lerEntrada(const string& mensagem) {
    cout << mensagem;
    string entrada;
    getline(cin, entrada);
    return entrada;
}

//antiga func2
void exibirNoticias(const vector<Noticia>& bancoNoticias) {
    for (const auto& noticia : bancoNoticias) {
        cout << "Texto: " << noticia.texto << endl;
        cout << "Classificacao: " << noticia.classificacao << endl;
        cout << "-------------------" << endl;
    }
}

//antiga função "que faz tudo"
void interagirAdicaoManual(vector<Noticia>& bancoNoticias) {
    string texto = lerEntrada("Digite o texto: ");
    string classificacao = lerEntrada("Digite classificacao: ");

    if (!adicionarNoticia(bancoNoticias, texto, classificacao)) {
        cout << "erro" << endl;
    }
}

//antiga função "que faz tudo"
void interagirAdicaoAutomatica(vector<Noticia>& bancoNoticias) {
    string texto = lerEntrada("Digite o texto: ");
    string classificacao = analisarConfiabilidade(texto);
    
    if (!adicionarNoticia(bancoNoticias, texto, classificacao)) {
        cout << "erro" << endl;
    }
}

void executarMenu(vector<Noticia>& bancoNoticias) {
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
            cout << "errado" << endl;
        }
    }
}

int main() {
    vector<Noticia> bancoDeNoticias;
    executarMenu(bancoDeNoticias);
    return 0;
}
