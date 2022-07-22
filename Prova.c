#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void selectionsort(int vet[], int tam){
	
	
	
	
	
	int posMen;
	for(int i = 0; i <= tam; i++){
		posMen = i;
		
		for(int j = i + i; j <= tam; j++)
			if(vet[j] < vet[posMen])
				posMen = j;
		
		if(posMen != i){
			int troca;
			
			troca = vet[i];
			vet[i] = vet[posMen];
			vet[posMen] = troca;
			
			}
		
		printf("\n[ ");
		for(int a = 0; a <= tam; a++)
			printf("%d ", vet[a]);
		printf("]");
		
		}
	
	printf("\n\nOrdenação por seleção: \n[ ");
	for(int i = 0; i <= tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	}


void shellsort(int vet[], int tam){
	
	//Complexidade: Melhor Caso{ f(n) = O(n log n) }, Pior Caso{ f(n) = O(n^2) }
	
	printf("> Shell Sort");
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Ordenação
	
	int h, i, j;
	int troca;
	
	for(h = 1; h < tam; h = h * 3 + 1);
	
	//printf("\n%d\n", h);
	
	while(h > 0){
		h = (h - 1) / 3;
		
		//printf("%d = %d\n", h, vet[h]);
		
		for(i = h; i < tam; i++){
			troca = vet[i];
			j = i;
			
			while(vet[j - h] > troca){
				vet[j] = vet[j - h];
				
				//printf("h = %d, V[h] = %d | j = %d, V[j] = %d | V[j - h] = %d\n", h, vet[h], j, vet[j], vet[j - h]);
				
				j -= h; // j = j - h
				
				if(j < h)
					break;
				
				}
				
				vet[j] = troca;
			
			}
		
		}
	
	printf("\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	}

//================================	FUNCAO Quick Sort	==================================

int qparticao(int vet[], int esq, int dir){
	int meio = (esq + dir) / 2;
	int pivot = vet[meio];
	int i = esq - 1;
	int j = dir + 1;
	
	do{
		do{
			i++;
			
			}while(vet[i] < pivot);
		
		do{
			j--;
			
			}while(vet[j] > pivot);
		
		if(i >= j){
			return j;
			
			}
		
		int aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
		
	}while(1);
	
}

void qesqdir(int vet[], int esq, int dir){
	
	if(esq < dir){
		
		printf("\n\t. [ ");
		for(int i = 0; i < 15; i++)
			printf("%d ", vet[i]);
		printf("]\n");
		
		int p = qparticao(vet, esq, dir);
		
		/*printf("\n\t[ ");
		for(int i = 0; i < 15; i++)
			printf("%d ", vet[i]);
		printf("]\n");*/
		printf("\tPivot = %d; Esq.: %d; Dir.: %d\n", p, esq, dir);
		
		qesqdir(vet, esq, p);
		
		//printf("Rangô\n");
		
		qesqdir(vet, p + 1, dir);
		
		}
	
	}

void quicksort(int vet[], int tam){
	
	//Complexidade: Melhor Caso{ f(n) = O(n log n) }, Pior Caso{ f(n) = O(n^2) }
	
	printf("> Quick Sort");
	
	qesqdir(vet, 0, tam - 1);
	
	printf("\n\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	}

//================================	FUNCAO Heap Sort	==================================

void aplicarHeap(int vet[], int tam, int i){
	
	/*printf("\n\t. [ ");
	for(int i = 0; i < 15; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	setbuf(stdin, NULL);
	getchar();*/
	
	int raiz = i;
	int esq = 2 * i + 1;
	int dir = 2 * i + 2;
	
	if(esq < tam && vet[esq] > vet[raiz]){
		raiz = esq;
		
		}
	
	if(dir < tam && vet[dir] > vet[raiz]){
		raiz = dir;
		
		}
	
	if(raiz != i){
		int aux = vet[i];
		
		vet[i] = vet[raiz];
		vet[raiz] = aux;
		
		/*printf("\n\t. [ ");
		for(int i = 0; i < 15; i++)
			printf("%d ", vet[i]);
		printf("]\n");
		
		setbuf(stdin, NULL);
		getchar();*/
		
		aplicarHeap(vet, tam, raiz);
		
		}
	
	/*printf("\n\t. [ ");
	for(int i = 0; i < 15; i++)
		printf("%d ", vet[i]);
	printf("]\n");*/
	
	}

void heapsort(int vet[], int tam){
	
	//Complexidade: f(n) = O(n log n)
	
	printf("> Heap Sort\n");
	
	//==================================================================
	//							Ordenação
	
	printf("\n\t. [ ");
	for(int i = 0; i < 15; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	for(int i = tam / 2 - 1; i >= 0; i--){
		aplicarHeap(vet, tam, i);
		
		}
	
	for(int i = tam - 1; i > 0; i--){
		int aux = vet[0];
		
		vet[0] = vet[i];
		vet[i] = aux;
		
		aplicarHeap(vet, i, 0);
		
		}
	
	printf("\n\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	
	}

//================================	  Busca Binária	    ==================================

void buscabinaria(int vet[], int tam){
	
	// Necessário Ordenação prévia do vetor
	
	//Complexidade: f(n) = O(log n)
	
	printf("> Busca Binária");
	
	shellsort(vet, tam);
	
	//==================================================================
	//							Busca
	
	printf("\n\t. Qual número você busca: ");
	int buscado;
	scanf("%d", &buscado);
	
	
	int achou = 0;
	int inicio = 0, fim = tam - 1, meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(vet[meio] == buscado){
			achou = 1;
			break;
			
			}
		
		if(vet[meio] < buscado)
			inicio = meio + 1;
			
		if(vet[meio] > buscado)
			fim = meio - 1;
		
		printf("\n%d", meio);
		
		
		}
	
	if(achou == 1){
		printf("\n\t\tNúmero encontrado");
		
		}else{
			printf("\t\tNúmero não encontrado\n\n");
			
			}
	
	}


int main(){
	
	int nome[15];
	
	//int i = 0;
	nome[0] = 7;
	nome[1] = 21;
	nome[2] = 9;
	nome[3] = 12;
	nome[4] = 8;
	nome[5] = 5;
	nome[6] = 18;
	nome[7] = 13;
	nome[8] = 14;
	nome[9] = 17;
	nome[10] = 4;
	nome[11] = 15;
	nome[12] = 1;
	nome[13] = 6;
	nome[14] = 19;
	
	/*printf("\nVetor = [ ");
	for(int a = 0; a <= 14; a++)
		printf("%d ", nome[a]);
	printf("]\n\n");*/
	
	//selectionsort(nome, 14);
	
	//shellsort(nome, 15);
	
	//quicksort(nome, 15);
	
	//heapsort(nome, 15);
	
	buscabinaria(nome, 15);
	
	}
