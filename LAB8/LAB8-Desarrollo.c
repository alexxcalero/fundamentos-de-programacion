//Nombre: Alex Calero Revilla
//Código: 20206455

#include<stdio.h>

//Parámetros
int ValidarCaracteres(char carac1,char carac2,char carac3,char carac4);
void PermutarCaracteres(char *carac1,char *carac2,char *carac3,char *carac4,int *cantPermutaciones,int *mayorNumeroFormado,int *permutDelMayorNumero);
int FormarNumero(char caracPermutado1,char caracPermutado2,char caracPermutado3,char caracPermutado4);
char DevolverElCaracterPorPosicion(char carac1,char carac2,char carac3,char carac4,int posicion);

int main(){
	char carac1,carac2,carac3,carac4;
	printf("Ingrese 4 caracteres: ");
	scanf("%c %c %c %c",&carac1,&carac2,&carac3,&carac4);
	
	if(ValidarCaracteres(carac1,carac2,carac3,carac4)){
		int cantPermutaciones,mayorNumeroFormado,permutDelMayorNumero;
		PermutarCaracteres(&carac1,&carac2,&carac3,&carac4,&cantPermutaciones,&mayorNumeroFormado,&permutDelMayorNumero);
		printf("Cantidad de permutaciones: %d\n",cantPermutaciones);
		printf("El mayor número formado es: %d\n",mayorNumeroFormado);
		printf("Es el resultado de la permutación %d de las letras %c%c%c%c %dx1000+%dx100+%dx10+%d = %d\n",permutDelMayorNumero+1,carac1,carac2,carac3,carac4,carac1,carac2,carac3,carac4,mayorNumeroFormado);
	//Mensaje para cuando el usuario ingrese caracteres incorrectos
	}else{
		printf("Las letras ingresadas no son mayúsculas o no son diferentes entre sí.\n");
	}
	return 0;
}

//Módulo que verifica que los caracteres ingresados sean correctos
int ValidarCaracteres(char carac1,char carac2,char carac3,char carac4){
	//Asumo que no ingresó caracteres incorrectos
	int esValido=0;
	
	//Compruebo que los caracteres ingresados sean mayúsculas
	int carac1_correcto=carac1>='A' && carac1<='Z';
	int carac2_correcto=carac2>='A' && carac2<='Z';
	int carac3_correcto=carac3>='A' && carac3<='Z';
	int carac4_correcto=carac4>='A' && carac4<='Z';
	
	int caracteresCorrectos=carac1_correcto && carac2_correcto && carac3_correcto && carac4_correcto;
	
	//Compruebo que los caracteres ingresados sean únicos
	int carac1_unico=(carac1!=carac2) && (carac1!=carac3) && (carac1!=carac4);
	int carac2_unico=(carac2!=carac3) && (carac2!=carac4);
	int carac3_unico=(carac3!=carac4);
	
	//Valido si se cumplen las condiciones para que los caracteres ingresados sean correctos
	if(caracteresCorrectos && carac1_unico && carac2_unico && carac3_unico)
		esValido=1;
	
	return esValido;
}

//Módulo que imprimirá todas las permutaciones de los caracteres posibles, hallará la cantidad de permutaciones y el mayor numero formado
void PermutarCaracteres(char *carac1,char *carac2,char *carac3,char *carac4,int *cantPermutaciones,int *mayorNumeroFormado,int *permutDelMayorNumero){
	int pos1,pos2,pos3,pos4,numeroFormado;
	char caracPermutado1,caracPermutado2,caracPermutado3,caracPermutado4;
	char carac1_copia=*carac1;
	char carac2_copia=*carac2;
	char carac3_copia=*carac3;
	char carac4_copia=*carac4;
	int contador=0;
	*cantPermutaciones=0;
	*mayorNumeroFormado=0;
	for(pos1=1;pos1<=4;pos1++){
		for(pos2=1;pos2<=4;pos2++){
			for(pos3=1;pos3<=4;pos3++){
				for(pos4=1;pos4<=4;pos4++){
					//Hallo cada caracter, correspondiente a cada posicion ayudandome del módulo que devuelve un caracter
					caracPermutado1=DevolverElCaracterPorPosicion(carac1_copia,carac2_copia,carac3_copia,carac4_copia,pos1);
					caracPermutado2=DevolverElCaracterPorPosicion(carac1_copia,carac2_copia,carac3_copia,carac4_copia,pos2);
					caracPermutado3=DevolverElCaracterPorPosicion(carac1_copia,carac2_copia,carac3_copia,carac4_copia,pos3);
					caracPermutado4=DevolverElCaracterPorPosicion(carac1_copia,carac2_copia,carac3_copia,carac4_copia,pos4);
					
					//Verifico que las posiciones sean diferentes
					int pos1_unica=(pos1!=pos2) && (pos1!=pos3) && (pos1!=pos4);
					int pos2_unica=(pos2!=pos3) && (pos2!=pos4);
					int pos3_unica=(pos3!=pos4);
					
					if(pos1_unica && pos2_unica && pos3_unica){
						printf("%d) %c %c %c %c\n",contador+1,caracPermutado1,caracPermutado2,caracPermutado3,caracPermutado4);
						
						//Hallo el número que forma cada permutacion
						numeroFormado=FormarNumero(caracPermutado1,caracPermutado2,caracPermutado3,caracPermutado4);
						
						//Verifico, para obtener el valor del mayor número formado
						if(numeroFormado>*mayorNumeroFormado){
							*mayorNumeroFormado=numeroFormado;
							*permutDelMayorNumero=contador;
							*carac1=caracPermutado1;
							*carac2=caracPermutado2;
							*carac3=caracPermutado3;
							*carac4=caracPermutado4;
						}
						contador++;
						(*cantPermutaciones)++;
					}
				}
			}
		}
	}
}

//Módulo que armará el número correspondiente a cada permutacion de las letras
int FormarNumero(char caracPermutado1,char caracPermutado2,char caracPermutado3,char caracPermutado4){
	int millar=1000*caracPermutado1;
	int centenas=100*caracPermutado2;
	int decenas=10*caracPermutado3;
	int unidades=caracPermutado4;
	return millar+centenas+decenas+unidades;
}

//Módulo que va a devolver el caracter que le corresponde a cierta posicion
char DevolverElCaracterPorPosicion(char carac1,char carac2,char carac3,char carac4,int posicion){
	char caracter;
	switch(posicion){
		case 1:{
			caracter=carac1;
			break;
		}
		case 2:{
			caracter=carac2;
			break;
		}
		case 3:{
			caracter=carac3;
			break;
		}
		case 4:{
			caracter=carac4;
			break;
		}
	}
	return caracter;
}
