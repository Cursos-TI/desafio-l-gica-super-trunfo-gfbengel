#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[3];            // Estado (ex: SP)
    char codigo[4];            // Código da carta (ex: A01)
    char nome_cidade[51];      // Nome da cidade
    int populacao;             // População
    float area;                // Área
    float pib;                 // PIB
    int pontos_turisticos;     // Número de pontos turísticos
    float densidade;           // Densidade Populacional
    float pib_per_capita;      // PIB per capita
};

// Função para exibir o menu de atributos
void exibir_menu(int atributo_oculto) {
    printf("\nEscolha o atributo para comparar:\n");
    if (atributo_oculto != 1) printf("1 - População\n");
    if (atributo_oculto != 2) printf("2 - Área\n");
    if (atributo_oculto != 3) printf("3 - PIB\n");
    if (atributo_oculto != 4) printf("4 - Número de pontos turísticos\n");
    if (atributo_oculto != 5) printf("5 - Densidade Populacional\n");
    printf("Digite o número da opção desejada: ");
}

// Função para obter o valor do atributo de uma carta
float obter_valor_atributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Função para obter o nome do atributo
void nome_atributo(int atributo, char *dest) {
    switch (atributo) {
        case 1: strcpy(dest, "População"); break;
        case 2: strcpy(dest, "Área"); break;
        case 3: strcpy(dest, "PIB"); break;
        case 4: strcpy(dest, "Número de pontos turísticos"); break;
        case 5: strcpy(dest, "Densidade Populacional"); break;
        default: strcpy(dest, "Atributo desconhecido");
    }
}

int main() {
    struct Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado);
    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %50[^"]", carta1.nome_cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", carta2.estado);
    printf("Código da carta (ex: B02): ");
    scanf("%3s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %50[^"]", carta2.nome_cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculo dos atributos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Exibição dos dados cadastrados
    printf("\nDados da Carta 1:\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nome_cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta1.densidade);
    printf("PIB per Capita: %.2f\n", carta1.pib_per_capita);

    printf("\nDados da Carta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nome_cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta2.densidade);
    printf("PIB per Capita: %.2f\n", carta2.pib_per_capita);

    // Escolha dos dois atributos para comparação
    int atributo1 = 0, atributo2 = 0;
    while (atributo1 < 1 || atributo1 > 5) {
        exibir_menu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) printf("Opção inválida!\n");
    }
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        exibir_menu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) printf("Opção inválida!\n");
    }

    // Obter valores dos atributos para cada carta
    float valor1_c1 = obter_valor_atributo(carta1, atributo1);
    float valor1_c2 = obter_valor_atributo(carta2, atributo1);
    float valor2_c1 = obter_valor_atributo(carta1, atributo2);
    float valor2_c2 = obter_valor_atributo(carta2, atributo2);

    // Lógica de comparação para cada atributo (usando operador ternário)
    // Para densidade, menor vence; para os demais, maior vence
    int v1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0))
                              : (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));
    int v2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0))
                              : (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));

    // Soma dos valores dos atributos para cada carta
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // Determinação do vencedor final
    int vencedor = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1 ? 2 : 0);

    // Exibição clara do resultado
    char nome1[40], nome2[40];
    nome_atributo(atributo1, nome1);
    nome_atributo(atributo2, nome2);

    printf("\nComparação de cartas:\n");
    printf("Atributos escolhidos: %s e %s\n", nome1, nome2);
    printf("\n%-25s | %-20s | %-20s\n", "Atributo", carta1.nome_cidade, carta2.nome_cidade);
    printf("%-25s | %-20.2f | %-20.2f\n", nome1, valor1_c1, valor1_c2);
    printf("%-25s | %-20.2f | %-20.2f\n", nome2, valor2_c1, valor2_c2);
    printf("%-25s | %-20.2f | %-20.2f\n", "Soma dos atributos", soma_c1, soma_c2);

    if (vencedor == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (vencedor == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
} 