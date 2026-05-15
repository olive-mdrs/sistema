#ifndef MODELO_H
#define MODELO_H

#include <string>

extern const std::string CLASSIFICACAO_CONFIAVEL;
extern const std::string CLASSIFICACAO_DUVIDOSA;
extern const std::string CLASSIFICACAO_FALSA;

/**
 * @brief Estrutura que representa uma notícia.
 */
struct Noticia {
  std::string texto;
  std::string classificacao;
};

#endif // MODELO_H
