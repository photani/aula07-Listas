# Aulas: Listas encadeadas

Este projeto contém implementações de listas encadeadas em C, organizadas em diferentes diretórios para cada abordagem. Novo conteúdo será adicionado progressivamente, começando com uma implementação clássica e evoluindo para versões mais avançadas.

## Estrutura

```
linked_list_classic/
├── element.h        # Definição do tipo de elemento
├── element.c        # Implementação de operações do elemento
├── linked_list.h    # Interface da lista ligada
├── linked_list.c    # Implementação da lista ligada
├── main.c           # Programa de demonstração
├── Makefile         # Configuração de build
└── build/
    └── main         # Executável compilado
```

## Compilação

```bash
cd linked_list_classic
make
```

Ou manualmente:

```bash
clang -Wall -pedantic -o build/main *.c
```

## Execução

```bash
cd linked_list_classic
./build/main
```


## Ambiente de desenvolvimento (opcional)

Este projeto inclui configuracao de Dev Container para VS Code em [.devcontainer](.devcontainer). O container usa Alpine Linux e instala `clang` e `valgrind`.

### GitHub Codespaces

Voce pode usar o Codespaces para abrir o projeto no navegador:

1. No GitHub, clique em **Code**.
2. Selecione a aba **Codespaces**.
3. Clique em **Create codespace on main**.

Ao iniciar, o ambiente ja vem configurado pelo dev container.

### Docker

Caso tenha Docker instalado na sua máquina, você pode usar o dev container localmente:

```bash
docker build -t aed-i-c -f .devcontainer/Dockerfile .
docker run --rm -it -v "$PWD":/work -w /work aed-i-c
```

Dentro do container, compile e execute normalmente:

```bash
mkdir -p build
clang -Wall -pedantic -o build/app src/main.c
./build/app
```
