#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definicoes de unidades de velocidade
#define KMH 1
#define MS 2
#define MPH 3

// Funcao do conversor de velocidade
void conversorVelocidade() {
    int entrada, saida;
    float valor, convertido;

    // Menu de conversao de unidades de velocidade
    printf("Conversor de Unidades de Velocidade\n");
    printf("Escolha a unidade de entrada:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &entrada);

    printf("Digite o valor da velocidade: ");
    scanf("%f", &valor);

    printf("Escolha a unidade de saida:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &saida);

    // Validacao das escolhas de entrada e saida
    if (entrada < 1 || entrada > 3 || saida < 1 || saida > 3) {
        printf("Opcao invalida.\n");
        return;
    }

    // Conversao de unidades
    if (entrada == 1) {        
        valor /= 3.6;
    } else if (entrada == 3) {  
        valor /= 2.237;
    }

    if (saida == 1) {           
        convertido = valor * 3.6;
    } else if (saida == 2) {    
        convertido = valor;
    } else if (saida == 3) {    
        convertido = valor * 2.237;
    }

    printf("Velocidade convertida: %.2f\n", convertido);
}

// Definicoes de unidades de temperatura
#define CELSIUS 1
#define FAHRENHEIT 2
#define KELVIN 3

// Funcao para exibir o menu e receber a temperatura
int menu(float* temp) {
    int num;
    do {
        printf("Unidades de temperatura\n\n");
        printf("Selecione a temperatura inicial:\n");
        printf("[1] Celsius (C)\n");
        printf("[2] Fahrenheit (F)\n");
        printf("[3] Kelvin (K)\n");
        printf("[0] Sair\n");
        printf("> ");
        scanf("%d", &num);

        if (num  == 0) {
            continue;
        } else if (num < 1 || num > 3) {
            printf("\tDigite 0, 1, 2 ou 3 !!!\n\n");
        } else {
            printf("\nDigite a temperatura:\n> ");
            scanf("%f", temp);
        }
    } while (num < 0 || num > 3);

    return num;
}

// Funcoes de conversao de temperatura
void celPfah(float temp) {
    printf("%.2fC = %.2fF\n", temp, temp * 9 / 5 + 32);
}

void celPkel(float temp) {
    printf("%.2fC = %.2fK\n", temp, temp + 273.15);
}

void fahPcel(float temp) {
    printf("%.2fF = %.2fC\n", temp, (temp - 32) * 5 / 9);
}

void fahPkel(float temp) {
    printf("%.2fF = %.2fK\n", temp, (temp - 32) * 5 / 9 + 273.15);
}

void kelPcel(float temp) {
    printf("%.2fK = %.2fC\n", temp, temp - 273.15);
}

void kelPfah(float temp) {
    printf("%.2fK = %.2fF\n", temp, (temp - 273.15) * 9 / 5 + 32);
}

// Definicoes de unidades de volume
#define CUBIC_METER 1
#define LITER 2
#define CUBIC_CENTIMETER 3

// Funcoes para conversao de volume
double to_liters(double value, int unit) {
    switch (unit) {
        case CUBIC_METER:
            return value * 1000;  // 1 metro cubico = 1000 litros
        case LITER:
            return value;         // 1 litro = 1 litro
        case CUBIC_CENTIMETER:
            return value / 1000;  // 1 centimetro cubico = 0.001 litro
        default:
            printf("Unidade de entrada nao reconhecida!\n");
            return 0;
    }
}

double from_liters(double value, int unit) {
    switch (unit) {
        case CUBIC_METER:
            return value / 1000;  // 1 litro = 0.001 metro cubico
        case LITER:
            return value;         // 1 litro = 1 litro
        case CUBIC_CENTIMETER:
            return value * 1000;  // 1 litro = 1000 centimetros cubicos
        default:
            printf("Unidade de saida nao reconhecida!\n");
            return 0;
    }
}

// Funcao principal do conversor de volume
void conversorVolume() {
    int inputUnit, outputUnit;
    double inputValue, outputValue;
    char exit;

    while (1) {
        // Exibe as opcoes de unidades de volume (Entrada)
        printf("Conversor de Unidades de Volume\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1. Metro Cubico (Kilolitro)\n2. Litro\n3. Centimetro Cubico (Mililitro)\n");
        printf("Digite sua escolha (1-3): ");
        scanf("%d", &inputUnit);

        // Exibe as opcoes de unidades de volume (Saida)
        printf("Escolha a unidade de saida:\n");
        printf("1. Metro Cubico (Kilolitro)\n2. Litro\n3. Centimetro Cubico (Mililitro)\n");
        printf("Digite sua escolha (1-3): ");
        scanf("%d", &outputUnit);

        // Solicita o valor a ser convertido
        printf("Digite o VALOR que deseja converter: ");
        scanf("%lf", &inputValue);

        // Realiza a conversao
        outputValue = to_liters(inputValue, inputUnit);
        outputValue = from_liters(outputValue, outputUnit);

        // Exibe o valor convertido
        printf("Valor convertido: %.2lf\n", outputValue);

        // Pergunta se o usuario deseja continuar
        printf("Deseja continuar convertendo? (s/n): ");
        getchar();  // Limpa o buffer de entrada
        exit = getchar();  

        // Se o usuario nao quiser continuar, sai do loop
        if (exit == 'n') {
            break;
        }
    }
}

// Funcao principal
int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int op;

    while (1) {
        // Menu principal
        printf("Escolha o tipo de conversao:\n");
        printf("1 - Conversor de Velocidade\n");
        printf("2 - Conversor de Temperatura\n");
        printf("3 - Conversor de Volume\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                // Chamada para o conversor de velocidade
                conversorVelocidade();
                break;
            case 2: {
                // Chamada para o conversor de temperatura
                float temp;
                int tempOp = menu(&temp); 
                switch (tempOp) {
                    case 1:
                        printf("Conversao: \n\n");
                        celPfah(temp);
                        celPkel(temp);
                        break;
                    case 2:
                        printf("Conversao: \n\n");
                        fahPcel(temp);
                        fahPkel(temp);
                        break;
                    case 3:
                        printf("Conversao: \n\n");
                        kelPcel(temp);
                        kelPfah(temp);
                        break;
                    case 0:
                        break;
                }
                break;
            }
            case 3:
                // Chamada para o conversor de volume
                conversorVolume();
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }

        // Pergunta se o usuario deseja fazer outra conversao
        int continueConversion;
        printf("\nDeseja fazer outra conversao? [1] Sim / [0] Nao: ");
        scanf("%d", &continueConversion);
        if (continueConversion == 0) {
            break;
        }
    }

    return 0;
}