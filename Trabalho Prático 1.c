#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//================================	   CABECALHO		==================================

void printLine(char a, int tam){
	printf("\n");

	for(int i = 0; i < tam; i++)
		printf("%c", a);

	printf("\n");

}

void continuacao(){
	printLine('_', 31);

	printf("Pressione enter para continuar!\n");

	setbuf(stdin, NULL);
	getchar();

}

void cabecalho(){
	
	printLine('=', 70);
	
	printf("\t\t\tNÚMEROS INTEIROS");
	
	printLine('=', 70);
	
	printf("\n");
	
	}

//================================	FUNCAO PRINCIPAL	==================================

int main(){
	
	cabecalho(0);
	int tamVet;
	int a;
	
	printf("Digite a quantidade de números a serem cadastrados: ");
	scanf("%d", &tamVet);
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int vet[tamVet];
	
	int cont = 0;
	do{
		a = rand() % (tamVet * 10);
		
		if(a > 0){
			vet[cont] = a;
			cont++;
			
			}
		
		}while(cont < tamVet);
	
	printf("\nNúmeros Cadastrados: \n[ ");
	for(int i = 0; i < tamVet; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							CÓPIA DO VETOR
	
	int vet2[tamVet];
	
	for(int i = 0; i < tamVet; i++)
		vet2[i] = vet[i];
	
	//==================================================================
	//							ORDENAÇÃO POR SELEÇÃO
	
	int posMen;
	for(int i = 0; i < tamVet; i++){
		posMen = i;
		
		for(int j = i + 1; j < tamVet; j++)
			if(vet[j] < vet[posMen])
				posMen = j;
		
		if(posMen != i){
			int troca;
			
			troca = vet[i];
			vet[i] = vet[posMen];
			vet[posMen] = troca;
			
			}		
		
		}
	
	printf("\nOrdenação por seleção: \n[ ");
	for(int i = 0; i < tamVet; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							ORDENAÇÃO POR INSERÇÃO
	
	int aux, j;
	
	for(int i = 1; i < tamVet; i++){
		
		aux = vet2[i];
		j = i - 1;
		
		while(j >= 0 && vet2[j] > aux){
			
			vet2[j + 1] = vet2[j];
			j--;
			
			//printf("\ni = %d, j = %d", i, j);
			
			}
		
		vet2[j + 1] = aux;
		
		}
	
	printf("\nOrdenação por inserção: \n[ ");
	for(int i = 0; i < tamVet; i++)
		printf("%d ", vet2[i]);
	printf("]\n");
	
	}
