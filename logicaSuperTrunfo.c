#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[20];
    int populacao;     // em milhões
    int area;          // em mil km²
    int pib;           // em bilhões USD
    int idh;           // multiplicado por 1000 (para evitar float)
    int densidade;     // hab/km²
} Carta;

// Função para exibir o menu de atributos
void mostrarMenu(int excluir) {
    printf("Escolha um atributo para comparação:\n");
    if (excluir != 1) printf("1. População\n");
    if (excluir != 2) printf("2. Área\n");
    if (excluir != 3) printf("3. PIB\n");
    if (excluir != 4) printf("4. IDH\n");
    if (excluir != 5) printf("5. Densidade Demográfica\n");
}

int obterAtributo(Carta pais, int escolha) {
    switch(escolha) {
        case 1: return pais.populacao;
        case 2: return pais.area;
        case 3: return pais.pib;
        case 4: return pais.idh;
        case 5: return pais.densidade;
        default: return -1;
    }
}

const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "IDH";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta brasil = {"Brasil", 213, 8516, 1847, 765, 25};
    Carta argentina = {"Argentina", 45, 2780, 491, 842, 16};

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        mostrarMenu(0);
        printf("Escolha o primeiro atributo (1 a 5): ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) printf("Opção inválida. Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo
    do {
        mostrarMenu(atributo1);
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5)
            printf("Opção inválida. Tente novamente.\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5);

    // Comparação dos atributos
    int val1_brasil = obterAtributo(brasil, atributo1);
    int val1_arg = obterAtributo(argentina, atributo1);

    int val2_brasil = obterAtributo(brasil, atributo2);
    int val2_arg = obterAtributo(argentina, atributo2);

    // Determina vencedores parciais
    int vencedor1 = (atributo1 == 5) ?
        (val1_brasil < val1_arg ? 1 : (val1_brasil > val1_arg ? 2 : 0)) :
        (val1_brasil > val1_arg ? 1 : (val1_brasil < val1_arg ? 2 : 0));

    int vencedor2 = (atributo2 == 5) ?
        (val2_brasil < val2_arg ? 1 : (val2_brasil > val2_arg ? 2 : 0)) :
        (val2_brasil > val2_arg ? 1 : (val2_brasil < val2_arg ? 2 : 0));

    // Soma dos atributos
    int somaBrasil = val1_brasil + val2_brasil;
    int somaArg = val1_arg + val2_arg;

    // Vencedor final
    int vencedorFinal = (somaBrasil > somaArg) ? 1 : (somaBrasil < somaArg ? 2 : 0);

    // Exibição dos resultados
    printf("\n--- Resultado da Rodada ---\n");
    printf("%s vs %s\n", brasil.nome, argentina.nome);
    printf("%s: %d (Brasil) x %d (Argentina)\n", nomeAtributo(atributo1), val1_brasil, val1_arg);
    printf("%s: %d (Brasil) x %d (Argentina)\n", nomeAtributo(atributo2), val2_brasil, val2_arg);
    printf("Soma dos atributos:\nBrasil: %d\nArgentina: %d\n", somaBrasil, somaArg);

    if (vencedorFinal == 1)
        printf("Resultado Final: Brasil venceu!\n");
    else if (vencedorFinal == 2)
        printf("Resultado Final: Argentina venceu!\n");
    else
        printf("Resultado Final: Empate!\n");

    return 0;
}
