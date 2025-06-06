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

int main() {
    // Declaração das duas cartas
    struct Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado);
    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %50[^"]", carta1.nome_cidade); // Lê até 50 caracteres, incluindo espaços
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

    // --- COMPARAÇÃO DE UM ATRIBUTO ---
    // Escolha do atributo para comparação: altere a variável abaixo para mudar o atributo
    // 1 = População, 2 = Área, 3 = PIB, 4 = Densidade Populacional, 5 = PIB per capita
    int atributo_comparacao = 1; // Altere este valor para comparar outro atributo

    printf("\nComparação de cartas (Atributo: ");
    if (atributo_comparacao == 1) printf("População):\n");
    else if (atributo_comparacao == 2) printf("Área):\n");
    else if (atributo_comparacao == 3) printf("PIB):\n");
    else if (atributo_comparacao == 4) printf("Densidade Populacional):\n");
    else if (atributo_comparacao == 5) printf("PIB per Capita):\n");
    else printf("Atributo desconhecido):\n");

    // Variáveis auxiliares para os valores comparados
    float valor1 = 0, valor2 = 0;
    char nome_atributo[30] = "";
    int vencedor = 0; // 1 = carta1, 2 = carta2, 0 = empate

    // Lógica de comparação usando if e if-else
    if (atributo_comparacao == 1) { // População
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
        strcpy(nome_atributo, "População");
        if (valor1 > valor2) vencedor = 1;
        else if (valor2 > valor1) vencedor = 2;
        else vencedor = 0;
    } else if (atributo_comparacao == 2) { // Área
        valor1 = carta1.area;
        valor2 = carta2.area;
        strcpy(nome_atributo, "Área");
        if (valor1 > valor2) vencedor = 1;
        else if (valor2 > valor1) vencedor = 2;
        else vencedor = 0;
    } else if (atributo_comparacao == 3) { // PIB
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        strcpy(nome_atributo, "PIB");
        if (valor1 > valor2) vencedor = 1;
        else if (valor2 > valor1) vencedor = 2;
        else vencedor = 0;
    } else if (atributo_comparacao == 4) { // Densidade Populacional (menor vence)
        valor1 = carta1.densidade;
        valor2 = carta2.densidade;
        strcpy(nome_atributo, "Densidade Populacional");
        if (valor1 < valor2) vencedor = 1;
        else if (valor2 < valor1) vencedor = 2;
        else vencedor = 0;
    } else if (atributo_comparacao == 5) { // PIB per capita
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
        strcpy(nome_atributo, "PIB per Capita");
        if (valor1 > valor2) vencedor = 1;
        else if (valor2 > valor1) vencedor = 2;
        else vencedor = 0;
    }

    // Exibição do resultado da comparação
    printf("\n%s da Carta 1 - %s (%s): %.2f\n", nome_atributo, carta1.nome_cidade, carta1.estado, valor1);
    printf("%s da Carta 2 - %s (%s): %.2f\n", nome_atributo, carta2.nome_cidade, carta2.estado, valor2);

    if (vencedor == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (vencedor == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
} 