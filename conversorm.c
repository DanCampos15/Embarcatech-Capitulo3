#include <stdio.h>
#include <locale.h>

void conversor (){
    
    //Defini as variáveis: "c" para o usuário escolher a conversão, "v" para o valor que será convertido e "r" para o resultado da conversão
    int c;
    float v, r;

        //Utilizei novamente o "do" para evitar que o usuário digite um valor inválido
        do{

            printf("---------------------------\n");
            printf("1 - g para kg\n");
            printf("2 - g para t\n");
            printf("3 - kg para t\n");
            printf("4 - kg para g\n");
            printf("5 - t para kg\n");
            printf("6 - t para g\n");
            printf("---------------------------\n");
            scanf("%d", &c);

            if(c>6){
                printf("Valor inválido!\n");
            }
            else{
            printf("Valor para converter: ");
            scanf("%f", &v);
            }
        
        }while(c>6);
            
            switch (c)
            {
            case 1:
                r = v/1000;
                break;

            case 2:
                r = v/1000000;
                break;
            
            case 3:
                r = v/1000;
                break;
            
            case 4:
                r = v*1000;
                break;

            case 5:
                r = v*1000;
                break;
            
            case 6:
                r = v*1000000;
            default:
                
                break;
            }

            printf("Valor convertido: %f\n", r);
}
int main(){

    //Utilizei a biblioteca locale.h para poder usar a acentuação em português
    setlocale(LC_ALL, "portuguese");

    //Inicialmente só defini a variável "s" referente a seleção que o usiário fará no menu abaixo
    int s;

    //Fiz um sistema de repetição para um menu. Não sei se será necessário, porém facilita no teste da função
    do{

        printf("---------------------------\n");
        printf("1 - Converter unidade de medida\n");
        printf("0 - Sair\n");
        printf("---------------------------\n");
        scanf("%d", &s);

        switch (s)
        {
        case 1:{

            conversor();

            break;
        }
        
        case 0:{
            break;
        }
        default:
            printf("Valor inválido!\n1");
            break;
        }

    }while(s != 0);
    

}