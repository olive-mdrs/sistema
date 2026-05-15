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
```
Em terminais Linux/Mac ou no Git Bash do Windows, você pode simplificar usando g++ -I include src/*.cpp -o sistema
## Execução
```bash
./sistema
```
## Estrutura do Projeto
```bash
.
├── include/           # Arquivos de cabeçalho (.h) contendo as declarações
│   ├── interface.h
│   ├── modelo.h
│   └── servico.h
├── src/               # Arquivos de código-fonte (.cpp) contendo as implementações
│   ├── interface.cpp  # Lida com a interação com o usuário (menus, entrada e saída de tela) 
│   ├── main.cpp       # Ponto de entrada do programa, responsável por inicializar o sistema
│   ├── modelo.cpp     # Contém as estruturas de dados (Noticia) e constantes 
│   └── servico.cpp    # Lógica de negócios (regras de classificação, validações e banco) 
└── README.md── sistema.cpp
```
## Contexto e Melhorias Aplicadas
Esse é um projeto da disciplina **DIM0501 – Boas Práticas de Programação** da Universidade Federal do Rio Grande do Norte (UFRN). A partir de uma implementação inicial do código fornecida pelo professor, foram dadas ao grupo as seguintes tarefas:
- Identificação de problemas (legibilidade, organização, code smells)
- Refatorar nomes e funções (renomear variáveis, estruturas, funções)
- Organizar em módulos (separação de responsabilidades)
- Adicionar validações (programação defensiva, tratamento de erros)
- Melhorar documentação (comentários úteis, README, docstrings)
Com a execução delas, esse é o resultado.
