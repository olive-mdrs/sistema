#ifndef INTERFACE_H
#define INTERFACE_H

#include "modelo.h"
#include <string>
#include <vector>

/**
 * @brief Função de suporte para ler inputs
 * @param mensagem texto a ser printado na tela antes de receber o input
 * @return entrada entrada digitada pelo usuario
 */
std::string lerEntrada(const std::string &mensagem);

/**
 * @brief Lista todas as notícias cadastradas, exibindo texto e classificação.
 */
void exibirNoticias(const std::vector<Noticia> &bancoNoticias);

/**
 * @brief Interface para adicionar uma notícia com classificação manual.
 *
 * Solicita texto e classificação ao usuário. Se a classificação for deixada em
 * branco, a função 'adicionarNoticia' assumirá o valor padrão "duvidosa".
 */
void interagirAdicaoManual(std::vector<Noticia> &bancoNoticias);

/**
 * @brief Interface para adicionar uma notícia com classificação automática.
 *
 * Solicita apenas o texto, a classificação é determinada pela função
 * 'analisarConfiabilidade'.
 */
void interagirAdicaoAutomatica(std::vector<Noticia> &bancoNoticias);

/**
 * @brief Exibe o menu principal e direciona para as operações escolhidas.
 *
 * Opções:
 * 1 - Adicionar notícia manualmente
 * 2 - Adicionar notícia com classificação automática
 * 3 - Listar todas as notícias
 * 4 - Sair
 */
void executarMenu(std::vector<Noticia> &bancoNoticias);

#endif // INTERFACE_H
