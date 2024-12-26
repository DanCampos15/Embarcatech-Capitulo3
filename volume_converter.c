#include <stdio.h>

#define CUBIC_METER 1
#define LITER 2
#define CUBIC_CENTIMETER 3

// Menu a ser exibido ao usuário com a legenda das unidades de volume
char menuText[] = "1 - Metro Cubico(Kilolitro)\n2 - Litro\n3 - Centimetros Cubico(Mililitro)\nDigite o número correspondente a unidade que deseja.\n";

double to_liters(double value, int unit);
double from_liters(double value, int unit);

int volume_converter()
{
    int inputUnit, outputUnit;
    double inputValue, outputValue;
    char exit;
    while (1)
    {    
        printf("%s", menuText);

        printf("DE qual unidade deseja converter(entrada)?:");
        scanf("%d", &inputUnit);

        printf("PARA qual unidade deseja converter(saída)?:");
        scanf("%d", &outputUnit);

        printf("Digite o VALOR que deseja converter:");
        scanf("%lf", &inputValue);

        outputValue = to_liters(inputValue, inputUnit);
        outputValue = from_liters(outputValue, outputUnit);
        printf("Valor convertido: %lf\nContinuar covertendo?(s/n)", outputValue);

        getchar(); // flush no buffer de input
        exit = getchar();  
        if (exit == 'n')
        {
            break;
        }
    }
    return 0;
}

/*Converte um valor em uma outra unidade para unidade de litros
double value: Valor a ser convertido.
int unit: Unidade do valor a ser convertido.*/
double to_liters(double value, int unit)
{
    switch (unit)
    {
        case CUBIC_METER: 
            // 1 metro cubico = 1000 litros
            return value*1000;
            break;
        case LITER:
            // 1 litro = 1 litro
            return value;
            break;
        case CUBIC_CENTIMETER: 
            // 1 centimetro cubico = 0.001 litro
            return value/1000;
            break;
        default:
            printf("Unidade de entrada não reconhecida!!\n");
            return 0;
            break;  
    }
}


/*Converte um valor em unidades de litros para uma outra unidade.
double value: Valor EM LITROS ser convertido.
int unit: Unidade do valor da saída.*/
double from_liters(double value, int unit)
{
    switch (unit)
    {
        case CUBIC_METER:
            // 1 litro = 0.001 metro cubico
            return value/1000;
            break;
        case LITER:
            // 1 litro = 1 litro
            return value;
            break;
        case CUBIC_CENTIMETER: 
            // 1 litro = 1000 metros cubicos
            return value*1000;
            break;
        default:
            printf("Unidade de saída não reconhecida!!\n");
            return 0;
            break;  
    }
}
