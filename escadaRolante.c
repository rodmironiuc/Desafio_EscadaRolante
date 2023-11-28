#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int direcao;
    int tempo;
} Passageiro;

void entrada(char* caminhoArquivo, Passageiro* passageiros, int* qtd) {
    FILE* arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", caminhoArquivo);
        exit(1);
    }
    fscanf(arquivo, "%d", qtd);
    for (int i = 0; i < *qtd; i++) {
        fscanf(arquivo, "%d %d", &passageiros[i].tempo, &passageiros[i].direcao);
    }
    fclose(arquivo);
}

int escadaRolante(Passageiro* passageiros, int qtd) {
    Passageiro passageiroAtual = passageiros[0];

    int pos = 0;
    int chegada;

    Passageiro passageirosPendentes[10000];
    int passageirosRestantes = qtd;

    int momentoFinal = 0;
    int direcao = -1;
    int momento = 0;

    bool pendente = false;

    while (passageirosRestantes > 0) {
        if (pendente && (passageiros[pos].tempo > chegada || pos >= qtd)) {
          passageiroAtual = passageirosPendentes[0];
          momento += 10;
          direcao = passageiroAtual.direcao;
          chegada = momento + 10;
          passageirosRestantes--;
          pendente = false;
      } else {
        passageiroAtual = passageiros[pos];

        if (direcao == -1) {
          momento = passageiroAtual.tempo < momento ? momento : passageiroAtual.tempo;
          direcao = passageiroAtual.direcao;
          chegada = passageiroAtual.tempo + 10;

          pos++;
          passageirosRestantes--;
        } else if (direcao == passageiroAtual.direcao) {
            momento = passageiroAtual.tempo;
            chegada = passageiroAtual.tempo + 10;

            pos++;
            passageirosRestantes--;
        } else {
            if (passageiros[pos + 1].tempo - passageiros[pos].tempo > passageiros[pos - 1].tempo) {
              momento = chegada;
              direcao = -1;
            }
          else if (passageiros[pos + 1].tempo <= chegada) {
            passageirosPendentes[0] = passageiros[pos]; 
            pendente = true;
            pos++;
          }
        }
      }
    }
  momento += 10;
  momentoFinal = momento;
    return momentoFinal;
  }

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: ./programa <arquivo_de_entrada>\n");
        return 1;
    }

    Passageiro passageiros[10000];
    int qtd;

    entrada(argv[1], passageiros, &qtd);
    int momentoFinal = escadaRolante(passageiros, qtd);

    printf("%d\n", momentoFinal);
    return 0;
}

