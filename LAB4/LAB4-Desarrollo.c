/*Nombre: Alex Calero Revilla*/
/*Código: 20206455*/

#include<stdio.h>
#include<math.h>

/*Prototipos*/
void validarEsCanada(int numero,int cantDigitos,int *sumaDivNoTriviales,int *esCanada);
int sumarCuadradoDigitos(int numero,int cantDigitos);
void mostrarResultados(int numero,int cantDigitos,int sumaDivNoTriviales,int esCanada);

int main(){
	int numero,cantDigitos,sumaDivNoTriviales,esCanada;
	
	printf("Ingrese el número a evaluar y la cantidad de dígitos: ");
	scanf("%d %d",&numero,&cantDigitos);
	
	validarEsCanada(numero,cantDigitos,&sumaDivNoTriviales,&esCanada);
	mostrarResultados(numero,cantDigitos,sumaDivNoTriviales,esCanada);
	
	return 0;
}

void validarEsCanada(int numero,int cantDigitos,int *sumaDivNoTriviales,int *esCanada){
	/*Como piden divisores no triviales del número, inicio el iterador en 2, ya que si lo
	inicio en 1, al momento de dividir número entre el primer valor del iterador (que va a
	ser 1), me va a dar como resultado el mismo número.*/
	int i=2;
	*sumaDivNoTriviales=0;
	/*Como piden divisores no triviales del número, coloco iterador menor que el número,
	ya que si coloco iterador menor igual que el número, al momento de dividir número entre
	el último valor del iterador (que va a tener el mismo valor que el número), esto me dará 1.*/
	while(i<numero){
		if(numero%i==0){
			*sumaDivNoTriviales+=i;
		}
		i++;
	}
	
	int sumaCuadradoDigitos=sumarCuadradoDigitos(numero,cantDigitos);
	if(sumaCuadradoDigitos==*sumaDivNoTriviales){
		*esCanada=1;
	}else{
		*esCanada=0;
	}
}

int sumarCuadradoDigitos(int numero,int cantDigitos){
	int i=1,sumatoria=0,cifra;
	while(numero!=0){
		/*"cifra" va a ser igual al primer dígito de la izquierda del número ingresado.
		Por eso dividimos el valor del número entre 10 elevado a la cantidad de dígitos
		de dicho número menos el valor del iterador.*/
		cifra=numero/pow(10,cantDigitos-i);
		sumatoria+=pow(cifra,2);
		/*Tenemos que actualizar el valor del número, ya que una vez obtenida la primera
		cifra de la izquierda, necesitamos que ahora el número solo sea las otras cifras
		restantes.
		Por eso usamos el operador "%", ya que este nos dará el residuo del valor original
		del número ingresado entre 10 elevado a la cantidad de dígitos del número menos el
		valor del iterador.*/
		numero=numero%(int)pow(10,cantDigitos-i);
		i++;
	}
	/*Retornamos el valor de la suma de los cuadrados de los dígitos del número.*/
	return sumatoria;
}

void mostrarResultados(int numero,int cantDigitos,int sumaDivNoTriviales,int esCanada){
	int sumaCuadradoDigitos=sumarCuadradoDigitos(numero,cantDigitos);
	if(esCanada==1){
		printf("El número es Canada\n");
	}else{
		printf("El número no es Canada\n");
	}
	printf("La suma de los cuadrados de sus dígitos es %d y de sus divisores es %d\n",sumaCuadradoDigitos,sumaDivNoTriviales);
}

