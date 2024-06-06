#include<stdio.h>
#include<math.h>

//Parametros
int hallar_cant_digitos(int minuendo);
int hallar_compl_a_nueve_sustraendo(int sustraendo,int cant_dig_minuendo,int cant_dig_sustraendo);

int main(){
	int minuendo,sustraendo,cant_dig_minuendo,cant_dig_sustraendo,comp_nueve;
	
	printf("Ingrese el Minuendo y Sustraendo de la operación: ");
	scanf("%d %d",&minuendo,&sustraendo);
	
	if(minuendo<0 || sustraendo<0){
		printf("El Minuendo y Sustraendo deben ser enteros mayores iguales a cero.");
	}
	else{
		if(minuendo<sustraendo){
			printf("El Minuendo debe ser mayor o igual al Sustraendo.");
		}
		else{
			cant_dig_minuendo=hallar_cant_digitos(minuendo);
			cant_dig_sustraendo=trunc(log10(sustraendo)+1);
			comp_nueve=hallar_compl_a_nueve_sustraendo(sustraendo,cant_dig_minuendo,cant_dig_sustraendo);
			printf("%d",comp_nueve);
		}
	}
	return 0;
}

int hallar_cant_digitos(int minuendo){
	int cantDigitos;
	cantDigitos=trunc(log10(minuendo)+1);
	return cantDigitos;
}

int hallar_compl_a_nueve_sustraendo(int sustraendo,int cant_dig_minuendo,int cant_dig_sustraendo){
	int i=1,suma_de_9s=0;
	while(i<=(cant_dig_sustraendo-1)){
		suma_de_9s+=9+(9*pow(10,i));
		i++;
	}
	int comp_a9_del_sustraendo=suma_de_9s-sustraendo;
}
