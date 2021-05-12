#include  <stdio.h>
#include <math.h>

// Calculando um valor de integrais, tendo um arquivo txt com os valores dos pontos da função da integral desejada
// Arquivo dados tem pontos de x^2

int main()
{
     float Dados[1000][2];  // Declara uma matriz que vai receber as informações do arquivo txt
     int i, j; // São variáveis auxiliares para fazer a contagem das linhas (i) de das colunas (j) da matriz
	
    FILE *abrir = fopen("Dados.txt","r");// Abre o arquivo "Dados.txt"

    // Abre o arquivo e verifica se tem conteúdo   
    if(abrir == NULL)
	{
		printf("NAO FOI POSSIVEL ABRIR O ARQUIVO"); // Aviso de erro caso o programa não encontre o programa que foi pedido em "FILE *abrir=fopen("Dados.txt","r")"
		return 0;
	}

	// Começa a fazer a leitura do arquivo em txt
    for (i = 0; i < 1001;  i++) // Vai varrer todas as 1000 linhas do arquivo
    {
        for (j=0;j<2;j++) // Vai varrer as 2 colunas do arquivo
        { 
                 fscanf(abrir, "%f,", &Dados[i][j]); // Le os 2 dados de cada linha, salvando cada um em uma coluna da matriz Dados[][]
        }
    }

    // Fecha o arquivo.txt que contém os dados
    fclose(abrir); 
    
    /*
    //Essa parte é só pra imprimir a matriz Dados[][] pra fazer a leitura dela
    for (i=0;i<1001;i++)//Vai varrer todas as 1000 linhas do arquivo
    {
        for (j=0;j<2;j++)//Vai varrer as 2 colunas do arquivo
        { 
            printf("%.3f ", Dados[i][j]);//Imprime a matriz de dados
        }
        printf("\n");//É só um código pra pular linha pra deixar a matriz com cara de matriz haha
    }   
    */
    

    int a = 0, b = 0, auxiliar = 0;
    float somaf = 0, soma = 0, h = 0.01, integral = 0;
    printf("Digite o intervalo de integracao 0 < x < 10,  *** b > a ***: \n");
    printf("Limite Inferior \n");
    scanf("%d",&a);
    printf("Limite Superior \n");
    scanf("%d",&b);

    //auxiliar = b - a;

    // Corrigindo os parametros da matriz usando a definição h = 0.01
    a = a*(1/h); 
    b = b*(1/h);
   
    // Fazendo somas parciais
    for(i = a; i <= b; i++)
    {
        soma = soma + Dados[i][1];
    }

    // Definição da integral de somas por partes
    somaf = soma*2;

    // Dando valor para integral e imprimindo o valor
    integral = (h/2) * (Dados[a][2] + Dados[b][2] + somaf);
    printf("\nIntegral: %.3f\n", integral);
    
    
    system("PAUSE");
    return(0);

}