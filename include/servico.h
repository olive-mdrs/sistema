#ifndef SERVICO_H
#define SERVICO_H

#include "modelo.h"
#include <string>
#include <vector>

/**
 * @brief Checa se uma string contém apenas espaços e/ou caracteres invisiveis
 * @param str string a ser checada
 */
bool contemApenasEspacos(const std::string &str);

/**
 * @brief Adiciona uma nova notícia à base de dados.
 *
 * Se a classificação não for informada ou não for uma das classificações
 * pré-existentes, assume "duvidosa" como padrão. Se o texto for vazio ou conter
 * apenas espaços, exibe mensagem de erro e não insere.
 *
 * @param bancoNoticias Vetor contendo a base de dados.
 * @param texto Texto da notícia. Se vazio, a função apenas imprime "erro".
 * @param classificacao Classificação desejada. Se omitida ou vazia, usa
 * "duvidosa".
 */
bool adicionarNoticia(std::vector<Noticia> &bancoNoticias,
                      const std::string &texto,
                      const std::string &classificacao = "");

/**
 * @brief Analisa um texto e retorna sua classificação baseada em regras
 * simples.
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
std::string analisarConfiabilidade(const std::string &texto);

#endif // SERVICO_H
