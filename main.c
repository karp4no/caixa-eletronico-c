/* ============================================================
 * PROGRAMA: Simulador de Caixa Eletrônico
 * DISCIPLINA: Algoritmos e Pensamento Computacional
 * ============================================================ */

#include <stdio.h>

int main() {
    // Definindo o saldo base inicial
    float saldo = 1000.00;
    float valor = 0.0;
    int opcao;

    do {
        // --- TELA DE APRESENTAÇÃO E MENU PRINCIPAL ---
        printf("\n==========================================\n");
        printf("       BANCO DIGITAL - CAIXA ELETRONICO   \n");
        printf("==========================================\n");
        printf("1. Consultar Saldo\n");
        printf("2. Realizar Deposito\n");
        printf("3. Realizar Saque\n");
        printf("0. Sair da Conta\n");
        printf("==========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // --- TRATAMENTO E ESTRUTURA DE DECISÃO ---
        switch (opcao) {
            case 1:
                printf("\n[SALDO] Seu saldo atual e: R$ %.2f\n", saldo);
                break;

            case 2:
                printf("\nDigite o valor para deposito (R$): ");
                scanf("%f", &valor);
                
                if (valor > 0) {
                    saldo += valor;
                    printf("[SUCESSO] Deposito de R$ %.2f realizado!\n", valor);
                    printf("Novo saldo: R$ %.2f\n", saldo);
                } else {
                    printf("[ERRO] Valor de deposito invalido.\n");
                }
                break;

            case 3:
                printf("\nDigite o valor para saque (R$): ");
                scanf("%f", &valor);

                // Regra do Bônus: Impedir saque maior que o saldo base disponível
                if (valor <= 0) {
                    printf("[ERRO] Valor de saque invalido.\n");
                } else if (valor > saldo) {
                    printf("[ALERTA - SALDO INSUFICIENTE] Transacao recusada!\n");
                    printf("Voce tentou sacar R$ %.2f, mas seu saldo atual e de R$ %.2f\n", valor, saldo);
                } else {
                    saldo -= valor;
                    printf("[SUCESSO] Saque de R$ %.2f realizado!\n", valor);
                    printf("Saldo remanescente: R$ %.2f\n", saldo);
                }
                break;

            case 0:
                printf("\nSessao encerrada de forma segura. Obrigado por utilizar nossos servicos!\n");
                break;

            default:
                printf("\n[OPCAO INVALIDA] Por favor, selecione uma opcao de 0 a 3.\n");
        }

    } while (opcao != 0); // O loop repete até a escolha do usuário ser 0

    return 0;
}
