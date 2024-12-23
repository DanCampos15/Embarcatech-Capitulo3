#include <stdio.h>
#include <locale.h>

void conversor (){
    
    int t;
    float v, r;

        do{

            printf("---------------------------\n");
            printf("1 - g para kg\n");
            printf("2 - g para t\n");
            printf("3 - kg para t\n");
            printf("4 - kg para g\n");
            printf("5 - t para kg\n");
            printf("6 - t para g\n");
            printf("---------------------------\n");
            scanf("%d", &t);

            if(t>6){
                printf("Valor inválido!\n");
            }
            else{
            printf("Valor para converter: ");
            scanf("%f", &v);
            }
            
        }while(t>6);
            

            switch (t)
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

    setlocale(LC_ALL, "portugese");

    int s;

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