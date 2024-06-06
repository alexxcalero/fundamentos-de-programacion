/*Nombre: Alex Calero Revilla*/
/*C�digo: 20206455*/

#include<stdio.h>
#include<math.h>

/*Prototipos*/
void validarEsCanada(int numero,int cantDigitos,int *sumaDivNoTriviales,int *esCanada);
int sumarCuadradoDigitos(int numero,int cantDigitos);
void mostrarResultados(int numero,int cantDigitos,int sumaDivNoTriviales,int esCanada);

int main(){
	int numero,cantDigitos,sumaDivNoTriviales,esCanada;
	
	printf("Ingrese el n�mero a evaluar y la cantidad de d�gitos: ");
	scanf("%d %d",&numero,&cantDigitos);
	
	validarEsCanada(numero,cantDigitos,&sumaDivNoTriviales,&esCanada);
	mostrarResultados(numero,cantDigitos,sumaDivNoTriviales,esCanada);
	
	return 0;
}

void validarEsCanada(int numero,int cantDigitos,int *sumaDivNoTriviales,int *esCanada){
	/*Como piden divisores no triviales del n�mero, inicio el iterador en 2, ya que si lo
	inicio en 1, al momento de dividir n�mero entre el primer valor del iterador (que va a
	ser 1), me va a dar como resultado el mismo n�mero.*/
	int i=2;
	*sumaDivNoTriviales=0;
	/*Como piden divisores no triviales del n�mero, coloco iterador menor que el n�mero,
	ya que si coloco iterador menor igual que el n�mero, al momento de dividir n�mero entre
	el �ltimo valor del iterador (que va a tener el mismo valor que el n�mero), esto me dar� 1.*/
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
		/*"cifra" va a ser igual al primer d�gito de la izquierda del n�mero ingresado.
		Por eso dividimos el valor del n�mero entre 10 elevado a la cantidad de d�gitos
		de dicho n�mero menos el valor del iterador.*/
		cifra=numero/pow(10,cantDigitos-i);
		sumatoria+=pow(cifra,2);
		/*Tenemos que actualizar el valor del n�mero, ya que una vez obtenida la primera
		cifra de la izquierda, necesitamos que ahora el n�mero solo sea las otras cifras
		restantes.
		Por eso usamos el operador "%", ya que este nos dar� el residuo del valor original
		del n�mero ingresado entre 10 elevado a la cantidad de d�gitos del n�mero menos el
		valor del iterador.*/
		numero=numero%(int)pow(10,cantDigitos-i);
		i++;
	}
	/*Retornamos el valor de la suma de los cuadrados de los d�gitos del n�mero.*/
	return sumatoria;
}

void mostrarResultados(int numero,int cantDigitos,int sumaDivNoTriviales,int esCanada){
	int sumaCuadradoDigitos=sumarCuadradoDigitos(numero,cantDigitos);
	if(esCanada==1){
		printf("El n�mero es Canada\n");
	}else{
		printf("El n�mero no es Canada\n");
	}
	printf("La suma de los cuadrados de sus d�gitos es %d y de sus divisores es %d\n",sumaCuadradoDigitos,sumaDivNoTriviales);
}

