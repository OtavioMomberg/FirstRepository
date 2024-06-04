#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void visaoSaida2(float agua, float peso, float *qtd2, float *prct, float total){
	if(total == agua){
		if(total > 999.9){
			total /= 1000.0;
			printf("\n\tQuantidade insuficiente, voc� precisa ingerir mais %.2fL de �gua\n", total);
		}else{
			printf("\n\tQuantidade insuficiente, voc� precisa ingerir mais %.2fml de �gua\n", total);
		}
	}
	if(*qtd2 < agua){
		if(peso <= 28.5 && *qtd2 > 0.0){
			printf("\n\tQuantidade insuficiente, voc� precisa ingerir mais %.2fml de �gua hoje\n", *qtd2);
		}else{
			if(*qtd2 > 999.9){
				*qtd2 /= 1000.0;
				printf("\n\tQuantidade insuficiente, voc� precisa ingerir mais %.2fL de �gua\n", *qtd2);
			}else{
				if(*qtd2 > 0.0 && *qtd2 < 1000.0){
					printf("\n\tQuantidade insuficiente, voc� precisa ingerir mais %.2fml de �gua\n", *qtd2);
				}	
			}
		}
	}else{
		if(*qtd2 > agua && *qtd2 < 5500.0){
			*qtd2 /= 1000.0;
			agua /= 1000.0;
			printf("\n\tVoc� ingeriu %.2fL de �gua e era necess�rio %.2fL de acordo com seu peso\n\n", *qtd2, agua);
			printf("\t(Quantidade %.2f%% acima do suficiente)\n", *prct);	
		}else{
			if(*qtd2 == agua){
				printf("\n\tQuantidade ideal de �gua ingerida!\n");		
			}
		}
		if(*qtd2 >= 5500.0){
		printf("\n\tATEN��O!!\n\tVoc� est� ingerindo uma quantidade extrema de �gua!\n\t(Quantidade %.2f%% acima)", *prct);
		}
	}
	printf("\n\t");
	system("pause");		
}

void controle2(float agua, float peso, float *qtd){
	float qtd2 = 0.0, prct = 0.0, total = 0.0;
	qtd2 = *qtd;
	if(peso > 28.5){
		agua *= 1000.0;
	}
	if(qtd2 == 0.0){
		total = agua;
	}
	if(qtd2 < agua){
		if(qtd2 > 0.0 && peso <= 28.5){
			qtd2 = agua - qtd2;
		}else{
			qtd2 = agua - qtd2;
		}
	}else{
		if(qtd2 > agua && qtd2 < 5500){
			qtd2 = qtd2;
			prct = qtd2 - agua;
			prct = qtd2 * 100 / agua; 
		}
		if(qtd2 >= 5500.0){
			prct = qtd2 - agua;
			prct = qtd2 * 100 / agua;		
		}		
	}
	if(total == agua){
		qtd2 = 0.0;
	}
	visaoSaida2(agua, peso, &qtd2, &prct, total);
}

void visaoEntrada2(float agua, float peso){
	float qtd = 0.0;
	printf("\n\tInsira a quantidade de �gua que voc� ingeriu hoje(em ml): ");
	scanf("%f", &qtd);
	printf("\n");
	system("cls");
	controle2(agua, peso, &qtd);
}

void visaoSaida(float agua, float peso){
	if(peso <= 28.5){
		printf("\tA quantidade de �gua que voc� precisa ingerir �: %.2fml\n", agua);
		visaoEntrada2(agua, peso);
	}else{
		printf("\tA quantidade de �gua que voc� precisa ingerir �: %.2fL\n", agua);
		visaoEntrada2(agua, peso);
	}
}

void controle(float agua, float peso){
	if(peso <= 28.5){
		agua = peso * 35.0;
		visaoSaida(agua, peso);
	}else{
		agua = peso * 0.35 / 10.0;
		visaoSaida(agua, peso);
	}
}

void visaoEntrada(float agua, float peso){
	printf("\n Veja quanta �gua voc� precisar� ingerir durante o dia de acordo com o seu peso!\n");
	printf(" Calculo feito segundo determina��es da OMS (massa corporal x 35ml)\n\n");
	printf("\tInsira seu peso (em kg): ");
	scanf("%f", &peso);
	printf("\n");
	controle(agua, peso);
}

void modelo(){
	float agua = 0.0, peso = 0.0;
	visaoEntrada(agua, peso);
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	modelo();
	return 0;
}

