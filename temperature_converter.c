#include <stdio.h>
#include <stdlib.h>

// Função para exibir o menu e receber a temperatura
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

		if (num  == 0){
			continue;
		}
        else if (num < 1 || num > 3) {
            printf("\tDigite 0, 1, 2 ou 3 !!!\n\n");
        } else {
            printf("\nDigite a temperatura:\n> ");
            scanf("%f", temp);
        }
    } while (num < 0 || num > 3);

    return num;
}

// Função para verificar se o usuário deseja continuar ou encerrar o programa
int menuExit() {
    int num;
    do {
        printf("\nDeseja continuar?\n");
        printf("[1] Fazer outra conversao\n[0] Sair\n> ");
        scanf("%d", &num);
        if (num != 0 && num != 1) {
            printf("\tDigite 0 ou 1 !!!\n");
        }else if(num == 1){
        	system("cls");
		}else if(num == 0){
			printf("Encerrando...\n");
		}
    } while (num != 0 && num != 1);
    return num;
}

// Funções de conversão
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

// Função principal
int main() {
   	
	float temp;
    int op = menu(&temp); 

    switch (op) {
        case 1:
            system("cls"); 
            printf("Conversao: \n\n");
            celPfah(temp);
            celPkel(temp);
            break;

    	case 2:
            system("cls");
            printf("Conversao: \n\n");
            fahPcel(temp);
            fahPkel(temp);
            break;

        case 3:
    	    system("cls");
            printf("Conversao: \n\n");
            kelPcel(temp);
            kelPfah(temp);
            break;
			
		case 0:
			printf("Encerrando...");
			return 0;
        }
        
        if(menuExit() == 1){
        	main();
		}
    
    return 0;
}
