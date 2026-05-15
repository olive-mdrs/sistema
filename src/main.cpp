#include "../include/interface.h"
#include "../include/modelo.h"
#include <vector>

using namespace std;

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
