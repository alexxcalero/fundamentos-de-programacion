//Nombre: Alex Calero Revilla
//C�digo: 20206455

#include<stdio.h>
#include<math.h>

//Par�metro
double hallarRazonAurea(int numIteraciones);

int main(){
	//Defino mis variables
	int numIteraciones;
	char objeto;
	printf("Ingrese el n�mero de iteraciones para calcular la raz�n aurea: ");
	scanf("%d",&numIteraciones);
	//Hago la validaci�n del n�mero de iteraciones
	if(10<=numIteraciones){
		double razonAurea;
		//Una vez validada la cantidad de iteraciones, puedo invocar al m�dulo que va hallar la Raz�n �urea
		razonAurea=hallarRazonAurea(numIteraciones);
		printf("Ingrese el tipo de objeto (Rect�ngulo [R], Tri�ngulo [T] o Trapecio [P]): ");
		scanf(" %c",&objeto);
		//Valido que el caracter ingresado sea el correcto
		if(objeto=='R' || objeto=='T' || objeto=='P'){
			//Conjunto de acciones, si el usuario ingres� el caracter R
			if(objeto=='R'){
				double baseRectangulo,alturaRectangulo;
				printf("Ingrese la base del rect�ngulo �ureo: ");
				scanf("%lf",&baseRectangulo);
				//Hallo la altura del rect�ngulo �ureo, haciendo uso de la f�rmula proporcionada
				alturaRectangulo=razonAurea*baseRectangulo;
				printf("La altura de un rect�ngulo �ureo de base %.2lf es %.2lf",baseRectangulo,alturaRectangulo);
			//Conjunto de acciones, si el usuario ingres� el caracter T
			}else if(objeto=='T'){
				double baseTriangulo,alturaTriangulo,ladoIgual;
				printf("Ingrese la base del tri�ngulo �ureo: ");
				scanf("%lf",&baseTriangulo);
				//Hallo el lado igual del tri�ngulo �ureo, haciendo uso de la f�rmula proporcionada
				ladoIgual=razonAurea*baseTriangulo;
				//Uso pit�goras para hallar la altura del tri�ngulo:
				//(lado igual)^2 = (base del tri�ngulo / 2)^2 + (altura del tri�ngulo)^2
				//altura del tri�ngulo = sqrt((lado igual)^2 - (base del tri�ngulo / 2)^2)
				alturaTriangulo=sqrt(pow(ladoIgual,2)-pow(baseTriangulo/2,2));
				printf("La altura de un tri�ngulo �ureo de base %.2lf es %.2lf y sus lados iguales son de %.2lf",baseTriangulo,alturaTriangulo,ladoIgual);
			//Conjunto de acciones, si el usuario ingres� el caracter P
			}else{
				double ladoTrapecio,baseMayor,baseMenor;
				printf("Ingrese el lado lateral del trapecio �ureo: ");
				scanf("%lf",&ladoTrapecio);
				//Hallo la base mayor y la base menor, haciendo uso de la f�rmula proporcionada
				baseMayor=razonAurea*ladoTrapecio;
				baseMenor=ladoTrapecio/razonAurea;
				printf("Las bases de un trapecio �ureo de lado lateral %.2lf son %.2lf y %.2lf",ladoTrapecio,baseMayor,baseMenor);
			}
		}else{
			//En caso el usuario ingrese un caracter incorrecto, imprimo el mensaje de error
			printf("El tipo de objeto ingresado no es v�lido.");
		}
	}else{
		//Si el usuario ingres� una cantidad de iteraciones menor a 10, imprimo el mensaje de error
		printf("El n�mero de iteraciones debe ser mayor o igual a 10.");
	}
	return 0;
}

//M�dulo que halla la Raz�n �urea
double hallarRazonAurea(int numIteraciones){
	int i=1;
	//Inicializo la razon �urea en raiz de 1, ya que es el valor para cuando la iterador vale 1
	double razonAurea=0;
	do{
		//La razon �urea se va a ir actualizando, siguiendo la f�rmula proporcionada
		razonAurea=sqrt(1+razonAurea);
		i++;	
	}while(i<=numIteraciones);
	return razonAurea;
}
