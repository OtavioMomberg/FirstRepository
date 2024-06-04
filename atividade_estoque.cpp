#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int i, j, k;

struct Dados{
	int est, cod;
	float val;
	char nome[50];
};

void tabContinua(float n){
	bool teste;
		if(n >= 1000){
			teste = 0;	
		}else{
			teste = 1;
		}		
	if(teste){
 		printf("\t");
	 } 	
}

void tabDiscreto(int n){
	bool teste;
		if(n >= 1000000){
			teste = 0;	
		}else{
			teste = 1;
		}		
	if(teste){
 		printf("\t");
	 } 	
}

void tabNome(char nomeBom[]){
	int tam = 0;
	bool teste;
	tam = strlen(nomeBom);
	if(tam < 7){
		printf("\t\t");	
	}else{
		if(tam < 15){
			printf("\t");	
		}
	}	
} 

struct Dados2{
	int c, qtd, estFinal;
	float vFinal;
	char nomeF[50];
};
void imprimirFinalFinal(struct Dados2 vet2[], struct Dados vet[]){
	printf("\n\t\t\t     Condição Final da Loja\n\n\t-------------------------------------------------------------------------");
	printf("\n\t|        Produto\t|    Código     |     Valor     |    Estoque    |\n\t-------------------------------------------------------------------------\n");
	for(j=0; j<5; j++){
		printf("\t|%s\t", vet[j].nome);
		tabNome(vet[j].nome);
		printf("|%d\t", vet[j].cod);
		tabDiscreto(vet[j].cod);
		printf("|%.2f\t", vet[j].val);
		tabContinua(vet[j].val);
		printf("|%d\t", vet[j].est);
		tabDiscreto(vet[j].est);
		printf("|\n");
		printf("\t-------------------------------------------------------------------------\n");
	}	
}
void imprimirFinal(struct Dados2 vet2[], float vTotal, int n, struct Dados vet[]){
	system("cls");
	printf("\n\t\t\tTabela de Compras\n\n");
	printf("\t---------------------------------------------------------");
	printf("\n\t|        Produto\t|  Quantidade   |     Valor     |\n\t---------------------------------------------------------\n");
	int a=1;
	bool b[20];
	for(i=0; i<20; i++){
		b[i] = true;
	}
	for(i=0; i<n-2; i++){
		for(j=a; j<n-1; j++){
			if(vet2[i].c == vet2[j].c){
				vet2[i].qtd += vet2[j].qtd; 
				vet2[i].vFinal += vet2[j].vFinal;
				b[j] = false;
			}
		}
		a++;
	}
	for(i=0; i<n-1; i++){
		if(b[i]){
			printf("\t|%s\t", vet2[i].nomeF);
			tabNome(vet2[i].nomeF);
			printf("|%d\t", vet2[i].qtd);
			tabDiscreto(vet2[i].qtd);
			printf("|%.2f\t", vet2[i].vFinal);
			tabContinua(vet2[i].vFinal);
			printf("|\n\t---------------------------------------------------------\n");
		}
	}
	printf("\tValor total: R$%.2f\n", vTotal);
	imprimirFinalFinal(vet2, vet);
}

void codigo2(struct Dados vet[]){
	struct Dados2 vet2[20];
	int co, quan, r, n = 1, cont = 0;
	float vTotal = 0.0;
	for(i=0; i<n; i++){
		printf("\nInforme o código do produto que deseja comprar:\n");
		do{
			scanf("%d", &co);
		}while(co != vet[0].cod && co != vet[1].cod && co != vet[2].cod && co != vet[3].cod && co != vet[4].cod);
		system("cls");
		if(co == vet[0].cod){
			if(vet[0].est > 0){
				do{
					system("cls");
					printf("Infome a quantidade desejada (de acordo com o estoque):		Estoque: %d		Valor (R$): %.2f\n", vet[0].est, vet[0].val);	
					scanf("%d", &quan);
				}while(quan > vet[0].est);
				vet2[i].c = co;
				vet2[i].qtd = quan;
				vet[0].est -= vet2[i].qtd;
				vet2[i].vFinal= vet2[i].qtd * vet[0].val;
				strcpy(vet2[i].nomeF, vet[0].nome);
				cont++;			
			}else{
				n--;
				i--;
			}
		}else{
			if(co == vet[1].cod){
				if(vet[1].est > 0){
					do{
						system("cls");
						printf("Infome a quantidade desejada (de acordo com o estoque):		Estoque: %d		Valor (R$): %.2f\n", vet[1].est, vet[1].val);	
						scanf("%d", &quan);
					}while(quan > vet[1].est);
					vet2[i].c = co;
					vet2[i].qtd = quan;
					vet[1].est -= vet2[i].qtd;
					vet2[i].vFinal= vet2[i].qtd * vet[1].val;
					strcpy(vet2[i].nomeF, vet[1].nome);
					cont++;
				}else{
					n--;
					i--;
				}	
			}else{
				if(co == vet[2].cod){
					if(vet[2].est > 0){
						do{
							system("cls");
							printf("Infome a quantidade desejada (de acordo com o estoque):		Estoque: %d		Valor (R$): %.2f\n", vet[2].est, vet[2].val);	
							scanf("%d", &quan);
						}while(quan > vet[2].est);
						vet2[i].c = co;
						vet2[i].qtd = quan;
						vet[2].est -= vet2[i].qtd;
						vet2[i].vFinal= vet2[i].qtd * vet[2].val;
						strcpy(vet2[i].nomeF, vet[2].nome);	
						cont++;
					}else{
						n--;
						i--;
					}
				}else{
					if(co == vet[3].cod){
						if(vet[3].est > 0){
							do{
								system("cls");
								printf("Infome a quantidade desejada (de acordo com o estoque):		Estoque: %d		Valor (R$): %.2f\n", vet[3].est, vet[3].val);	
								scanf("%d", &quan);
							}while(quan > vet[3].est);
							vet2[i].c = co;
							vet2[i].qtd = quan;
							vet[3].est -= vet2[i].qtd;
							vet2[i].vFinal= vet2[i].qtd * vet[3].val;
							strcpy(vet2[i].nomeF, vet[3].nome);
							cont++;
							
						}else{
							n--;
							i--;
						}	
					}else{
						if(co == vet[4].cod){
							if(vet[4].est > 0){
								do{
									system("cls");
									printf("Infome a quantidade desejada (de acordo com o estoque):		Estoque: %d		Valor (R$): %.2f\n", vet[4].est, vet[4].val);	
									scanf("%d", &quan);
								}while(quan > vet[4].est);
									vet2[i].c = co;
									vet2[i].qtd = quan;
									vet[4].est -= vet2[i].qtd;
									vet2[i].vFinal= vet2[i].qtd * vet[4].val;
									strcpy(vet2[i].nomeF, vet[4].nome);	
									cont++;
							}else{
								n--;
								i--;
							}
						}
					}
				}
			}
		}
		n++;
		if(vet[0].est == 0){
			if(vet[1].est == 0){
				if(vet[2].est == 0){
					if(vet[3].est == 0){
						if(vet[4].est == 0){
							break;
						}
					}
				}
			}
		}
		do{
			system("cls");
			printf("Deseja comprar mais itens ? (SIM- 1 ou NÃO- 0): ");
			scanf("%d", &r);
		}while(r != 1 && r != 0);
		if(r == 0){
			break;
		}else{
			if(r == 1){
				printf("\n\t-------------------------------------------------------------------------");
				printf("\n\t|        Produto\t|    Código     |     Valor     |    Estoque    |\n\t-------------------------------------------------------------------------\n");
				for(j=0; j<5; j++){
					printf("\t|%s\t", vet[j].nome);
					tabNome(vet[j].nome);
					printf("|%d\t", vet[j].cod);
					tabDiscreto(vet[j].cod);
					printf("|%.2f\t", vet[j].val);
					tabContinua(vet[j].val);
					printf("|%d\t", vet[j].est);
					tabDiscreto(vet[j].est);
					printf("|\n");
					printf("\t-------------------------------------------------------------------------\n");
				}	
			}
		}
	}
	for(i=0; i<cont; i++){
		vTotal += vet2[i].vFinal;
	}
	imprimirFinal(vet2, vTotal, n, vet);
}

void codigo(struct Dados vet[]){
	int codi = 0;
	printf("\nInsira o código de um produto: ");
	scanf("%d", &codi);
	printf("\n");
	if(codi == vet[0].cod){
		printf("Código: %d\n", vet[0].cod);
		printf("Nome: %s\n", vet[0].nome);
		printf("Valor: R$%.2f\n", vet[0].val);
		printf("Estoque: %d\n", vet[0].est);
	}else{
		if(codi == vet[1].cod){
			printf("Código: %d\n", vet[1].cod);
			printf("Nome: %s\n", vet[1].nome);
			printf("Valor: R$%.2f\n", vet[1].val);
			printf("Estoque: %d\n", vet[1].est);
		}else{
			if(codi == vet[2].cod){
				printf("Código: %d\n", vet[2].cod);
				printf("Nome: %s\n", vet[2].nome);
				printf("Valor: R$%.2f\n", vet[2].val);
				printf("Estoque: %d\n", vet[2].est);
			}else{
				if(codi == vet[3].cod){
					printf("Código: %d\n", vet[3].cod);
					printf("Nome: %s\n", vet[3].nome);
					printf("Valor: R$%.2f\n", vet[3].val);
					printf("Estoque: %d\n", vet[3].est);
				}else{
					if(codi == vet[4].cod){
						printf("Código: %d\n", vet[4].cod);
						printf("Nome: %s\n", vet[4].nome);
						printf("Valor: R$%.2f\n", vet[4].val);
						printf("Estoque: %d\n", vet[4].est);
					}else{
						printf("Código não encontrado\n");
					}
				}
			}
		}
	}
	codigo2(vet);
}

void imprimir(struct Dados vet[]){
	printf("\t-------------------------------------------------------------------------");
	printf("\n\t|        Produto\t|    Código     |     Valor     |    Estoque    |\n\t-------------------------------------------------------------------------\n");
	for(i=0; i<5; i++){
		printf("\t|%s\t", vet[i].nome);
		tabNome(vet[i].nome);
		printf("|%d\t", vet[i].cod);
		tabDiscreto(vet[i].cod);
		printf("|%.2f\t", vet[i].val);
		tabContinua(vet[i].val);
		printf("|%d\t", vet[i].est);
		tabDiscreto(vet[i].est);
		printf("|\n");
		printf("\t-------------------------------------------------------------------------\n");
	}
	codigo(vet);
}

void inserir(struct Dados vet[]){
	int a;
	bool b;
	for(i=0; i<5; i++){
		vet[i].cod = -2174981764871+i;
	}
	for(i=0; i<5; i++){
		printf("%i° Produto:\n\n", i+1);
		printf("\tInsira o nome: \t");
		scanf(" %[^\n]", vet[i].nome);
		printf("\tInsira o código: ");
		do{
			system("cls");
			printf("%iº Produto:\n\n", i+1);
			printf("\tInsira o nome: %s\n", vet[i].nome);
			printf("\tInsira o código: ");
			scanf("%d", &vet[i].cod);
			b = false;
			a = 1;
			for(j=0; j<4; j++){
				for(k=a; k<5; k++){
					if(vet[j].cod == vet[k].cod){
						b = true;
					}
				}
				a++;
			}
		}while(b);
		printf("\tInsira o valor (R$): ");
		scanf("%f", &vet[i].val);
		printf("\tQuantidade em estoque: ");
		scanf("%d", &vet[i].est);
		printf("\n");
		system("cls");
	}
	imprimir(vet);
}

int main (){
	struct Dados vet[5];
	inserir(vet);
	setlocale(LC_ALL, "Portuguese");
	return 0;
}

