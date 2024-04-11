#include<stdio.h>
#define MAX 10

struct Funcionario {

    char nome[100], cargo[100];
    double salario, beneficios, descontos;

    void ler() {
        printf("\nDigite o nome do funcionario:\n");
        scanf("%[^\n]%*c", nome);
        printf("Digite o cargo do funcionario:\n");
        scanf("%[^\n]%*c", cargo);
        printf("Digite o salario do funcionario:\n");
        scanf("%lf%*c", &salario);
        printf("Digite os beneficio que o funcionario recebe:\n");
        scanf("%lf%*c", &beneficios);
        printf("Digite o valor de descontos:\n");
        scanf("%lf%*c", &descontos);
    }

    void imprimir() {
        printf("\nO funcionario:\n");
        printf("%s\n", nome);
        printf("Cujo cargo eh:\n");
        printf("%s\n", cargo);
        printf("Recebe como salario a quantia de:\n");
        printf("R$ %.2lf\n", salario);
        printf("Recebe como beneficio a quantia de:\n");
        printf("R$ %.2lf\n", beneficios);
        printf("Eh descontado de seu salario o valor de:\n");
        printf("R$ %.2lf\n", descontos);
        printf("Seu salario final eh:\n");
        printf("R$ %.2lf", calcularSalarioFinal());
    }

    double calcularSalarioFinal() {
        return (salario + beneficios) - descontos;
    }
};

struct Loja {

    Funcionario f[MAX];
    int ultimo = 0;

    void ler() {
        if (ultimo >= MAX) {
            printf("Loja cheia\n");
            return;
        }
        f[ultimo].ler();
        ultimo++;
    }

    void imprimir() {
        for (int i = 0; i < ultimo; i++) {
            f[i].imprimir();
        }
    }

    double calcularMediaSalarial() {
        if (ultimo == 0) {
            return 0;
        }
        double media = 0;
        for (int i = 0; i < ultimo; i++) {
            media += f[i].calcularSalarioFinal();
        }
        return media / ultimo;
    }

    void exibirMaiorSalario() {
        if (ultimo == 0) {
            printf("Loja vazia\n");
            return;
        }
        double maximo = f[0].calcularSalarioFinal();
        int posicao = 0;
        for (int i = 1; i < ultimo; i++) {
            if (f[i].calcularSalarioFinal() > maximo) {
                maximo = f[i].calcularSalarioFinal();
                posicao = i;
            }
        }
        printf("O maior salario eh:");
        f[posicao].imprimir();
    }

};

int main() {

    Loja l;
    int opcao;

    do {
        printf("1. Ler funcionario.\n");
        printf("2. Listar os funcionarios.\n");
        printf("3. Exibir media salarial.\n");
        printf("4. Exibir maior valor de salario.\n");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                l.ler();
                break;
            case 2:
                l.imprimir();
                break;
            case 3:
                printf("R$ %.2lf\n", l.calcularMediaSalarial());
                break;
            case 4:
                l.exibirMaiorSalario();
                break;
        }

    } while (opcao >= 1 && opcao <= 4);

    return 0;
}
