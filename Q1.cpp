#include <stdio.h>
#include <time.h>
#define MAX 50

struct Data {
    int dia, mes, ano;
};
void lerData(struct Data *data) {
    scanf("%d/%d/%d%*c", &data->dia, &data->mes, &data->ano);
}
void imprimirData(struct Data data) {
    printf("%02d/%02d/%04d\n", data.dia, data.mes, data.ano);
}
int calcularIdade(struct Data data) {
    int diaAtual = 11, mesAtual = 4, anoAtual = 2024;

    if (data.mes < mesAtual || (data.mes == mesAtual && data.dia <= diaAtual)) {
        return anoAtual - data.ano;
    } else {
        return anoAtual - data.ano - 1;
    }
}
struct Cliente {
    char nome[100];
    struct Data nascimento;
    int idade;
    char sexo;
};
void lerCliente(struct Cliente *cliente) {
    printf("Escreva seu nome:\n");
    scanf("%[^\n]%*c", cliente->nome);
    printf("Escreva sua data de nascimento:\n");
    lerData(&cliente->nascimento);
    cliente->idade = calcularIdade(cliente->nascimento);
    printf("Digite M para masculino ou F para feminino:\n");
    scanf("%c%*c", &cliente->sexo);
}
void imprimirCliente(struct Cliente cliente) {
    printf("\n\nO nome do cliente eh:\n");
    printf("%s\n", cliente.nome);
    printf("\nSua data de nascimento eh:\n");
    imprimirData(cliente.nascimento);
    printf("\nSua idade eh:\n");
    printf("%d\n", cliente.idade);
    printf("\nSeu sexo eh:\n");
    printf("%c\n\n", cliente.sexo);
}
int main() {
    struct Cliente clientes[MAX];
    int ultimo = 0, opcao;

    do {
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                lerCliente(&clientes[ultimo]);
                ultimo++;
                break;
            case 2:
                for (int i = 0; i < ultimo; i++) {
                    imprimirCliente(clientes[i]);
                }
                break;
        }
    } while (opcao == 1 || opcao == 2);

    return 0;
}
