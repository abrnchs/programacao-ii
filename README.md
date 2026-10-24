# Programação II

Repositório para organizar os trabalhos da unidade curricular de Programação II.

## Estrutura

- `parte-1/Se1/` — material recebido para a primeira parte: programas `prog11` a `prog15`, os ficheiros partilhados `norm.c` e `norm.h`, e entradas de exemplo.
- `parte-2/` — reservado para a segunda parte.
- `parte-3/` — reservado para a terceira parte.

As partes 2 e 3 serão preenchidas quando o respetivo material estiver disponível. O diretório recebido não incluía o enunciado do trabalho; por isso, este repositório organiza os ficheiros fornecidos sem acrescentar requisitos ao trabalho.

## Compilar

Requer um compilador C e `make`. Na raiz do repositório:

```sh
make
```

Os executáveis são criados em `build/parte-1/Se1/`. Para remover os ficheiros gerados:

```sh
make clean
```

Cada programa lê a entrada conforme implementado no respetivo código. Os ficheiros `teste_prog*.txt` são entradas de exemplo fornecidas com o material.
