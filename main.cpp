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

/**
 * @brief Checa se uma string contém apenas espaços e/ou caracteres invisiveis
 * @param str string a ser checada
 */
bool contemApenasEspacos(const string& str){
    return str.find_first_not_of(" \t\n\v\f\r") == string::npos;
}

/**
 * @brief Adiciona uma nova notícia à base de dados.
 *
 * Se a classificação não for informada ou não for uma das classificações pré-existentes, assume "duvidosa" como padrão.
 * Se o texto for vazio ou conter apenas espaços, exibe mensagem de erro e não insere.
 *
 * @param texto Texto da notícia. Se vazio, a função apenas imprime "erro" (mudar pra throw?).
 * @param classificacao Classificação desejada. Se omitida ou vazia, usa "duvidosa".
 */
bool adicionarNoticia(vector<Noticia>& bancoNoticias, const string& texto, const string& classificacao = "") {
    if (texto.empty() || contemApenasEspacos(texto)) {
        cerr << "Erro: Texto da noticia é vazio ou invalido." << endl;
        return false; 
    }

    Noticia novaNoticia;
    novaNoticia.texto = texto;
    novaNoticia.classificacao = classificacao.empty() ? CLASSIFICACAO_DUVIDOSA : classificacao;
    if (classificacao != CLASSIFICACAO_CONFIAVEL &&
        classificacao != CLASSIFICACAO_DUVIDOSA &&
        classificacao != CLASSIFICACAO_FALSA){
        cout << "Classificacao vazia ou invalida: o texto sera automaticamente classificado como duvidoso." << endl; 
    }

    bancoNoticias.push_back(novaNoticia);
    return true;
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
 * @param texto Texto a ser analisado.
 * @return string Classificação resultante.
 */
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

/**
 * @brief Função de suporte para ler inputs
 * @param mensagem texto a ser printado na tela antes de receber o input
 * @return entrada entrada digitada pelo usuario
 */
string lerEntrada(const string& mensagem) {
    cout << mensagem;
    string entrada;
    getline(cin, entrada);
    return entrada;
}

/**
 * @brief Lista todas as notícias cadastradas, exibindo texto e classificação.
 */
void exibirNoticias(const vector<Noticia>& bancoNoticias) {

    if (bancoNoticias.empty()){
        cout << "\nO banco de noticias esta vazio.\n" << endl;
        return;
    }

    for (const auto& noticia : bancoNoticias) {
        cout << "Texto: " << noticia.texto << endl;
        cout << "Classificacao: " << noticia.classificacao << endl;
        cout << "-------------------" << endl;
    }
}

/**
 * @brief Interface para adicionar uma notícia com classificação manual.
 *
 * Solicita texto e classificação ao usuário. Se a classificação for deixada em branco,
 * a função 'adicionarNoticia' assumirá o valor padrão "duvidosa".
 */
void interagirAdicaoManual(vector<Noticia>& bancoNoticias) {
    string texto = lerEntrada("Digite o texto: ");
    string classificacao = lerEntrada("Digite classificacao: ");

    adicionarNoticia(bancoNoticias, texto, classificacao);
}

/**
 * @brief Interface para adicionar uma notícia com classificação automática.
 *
 * Solicita apenas o texto, a classificação é determinada pela função 'analisarConfiabilidade'.
 * 
 */
void interagirAdicaoAutomatica(vector<Noticia>& bancoNoticias) {
    string texto = lerEntrada("Digite o texto: ");
    string classificacao = analisarConfiabilidade(texto);
    
    adicionarNoticia(bancoNoticias, texto, classificacao);
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
            cout << "Erro: '" << opcao << "' nao e uma opcao valida. Tente novamente." << endl; 
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
    vector<Noticia> bancoDeNoticias;
    executarMenu(bancoDeNoticias);
    return 0;
}
