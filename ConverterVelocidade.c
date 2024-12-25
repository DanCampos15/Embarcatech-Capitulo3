void conversorVelocidade() {
    int entrada, saida;
    float valor, convertido;

    printf("Conversor de Unidades de Velocidade\n");
    printf("Escolha a unidade de entrada:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &entrada);

    printf("Digite o valor da velocidade: ");
    scanf("%f", &valor);

    printf("Escolha a unidade de saída:\n");
    printf("1. km/h\n2. m/s\n3. mph\n");
    printf("Digite sua escolha (1-3): ");
    scanf("%d", &saida);

    if (entrada < 1 || entrada > 3 || saida < 1 || saida > 3) {
        printf("Opção inválida.\n");
        return;
    }

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
