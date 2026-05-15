# Sistema de Monitoramento de Fake News e Qualidade da Informação

Sistema de console para cadastro e classificação automática ou manual de notícias. Permite:

- Inserir textos de notícias;
- Classificá-las como **confiável**, **duvidosa** ou **falsa** com base em regras simples (ausência de fonte, uso de sensacionalismo, tamanho do texto);
- Listar todas as notícias cadastradas.

## Funcionalidades

1. **Adicionar notícia manualmente** O usuário informa o texto e a classificação desejada. Se a classificação for omitida ou for inválida, o sistema assume o padrão *duvidosa*.

2. **Adicionar notícia com classificação automática** O sistema analisa o texto e determina a classificação com base nos seguintes critérios:
   - Texto sem a palavra "FONTE": aumenta suspeita.
   - Presença de "!!!": indica sensacionalismo.
   - Presença de "URGENTE": indica sensacionalismo.
   - Texto com menos de 10 caracteres: aumenta suspeita.
   
   A classificação final é:
   - `confiavel` (0 pontos de suspeita)
   - `duvidosa`  (1 ponto)
   - `falsa`     (2 ou mais pontos)

3. **Listar notícias** Exibe no console todos os textos cadastrados com sua respectiva classificação.

4. **Menu interativo** Loop principal que oferece as opções acima e permite encerrar o programa de forma limpa.

## Como compilar e executar

### Pré‑requisitos

- Compilador C++ (g++, clang++, MSVC) com suporte a C++11 ou superior.
- Terminal ou prompt de comando.

### Compilação

Como o projeto utiliza uma estrutura modular, é necessário indicar ao compilador onde encontrar os arquivos de cabeçalho e informar todos os códigos-fonte. Na raiz do projeto, execute:

```bash
g++ -I include src/main.cpp src/modelo.cpp src/servico.cpp src/interface.cpp -o sistema
