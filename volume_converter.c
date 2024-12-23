#include <stdio.h>

#define CUBIC_METER 1
#define LITER 2
#define CUBIC_CENTIMETER 3

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

        getchar();
        exit = getchar();  
        if (exit == 'n')
        {
            break;
        }
    }
    return 0;
}

double to_liters(double value, int unit)
{
    switch (unit)
    {
    case CUBIC_METER:
        return value*1000;
        break;
    case LITER:
        return value;
        break;
    case CUBIC_CENTIMETER: 
        return value/1000;
        break;
    default:
        printf("Unidade de entrada não reconhecida!!\n");
        return 0;
        break;  
    }
}

double from_liters(double value, int unit)
{
    switch (unit)
    {
    case CUBIC_METER:
        return value/1000;
        break;
    case LITER:
        return value;
        break;
    case CUBIC_CENTIMETER: 
        return value*1000;
        break;
    default:
        printf("Unidade de saída não reconhecida!!\n");
        return 0;
        break;  
    }
}