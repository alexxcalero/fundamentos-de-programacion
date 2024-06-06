//Nombre: Alex Calero Revilla
//Código: 20206455

#include<stdio.h>
#include<math.h>

//Parámetro
double hallarRazonAurea(int numIteraciones);

int main(){
	//Defino mis variables
	int numIteraciones;
	char objeto;
	printf("Ingrese el número de iteraciones para calcular la razón aurea: ");
	scanf("%d",&numIteraciones);
	//Hago la validación del número de iteraciones
	if(10<=numIteraciones){
		double razonAurea;
		//Una vez validada la cantidad de iteraciones, puedo invocar al módulo que va hallar la Razón Áurea
		razonAurea=hallarRazonAurea(numIteraciones);
		printf("Ingrese el tipo de objeto (Rectángulo [R], Triángulo [T] o Trapecio [P]): ");
		scanf(" %c",&objeto);
		//Valido que el caracter ingresado sea el correcto
		if(objeto=='R' || objeto=='T' || objeto=='P'){
			//Conjunto de acciones, si el usuario ingresó el caracter R
			if(objeto=='R'){
				double baseRectangulo,alturaRectangulo;
				printf("Ingrese la base del rectángulo áureo: ");
				scanf("%lf",&baseRectangulo);
				//Hallo la altura del rectángulo áureo, haciendo uso de la fórmula proporcionada
				alturaRectangulo=razonAurea*baseRectangulo;
				printf("La altura de un rectángulo áureo de base %.2lf es %.2lf",baseRectangulo,alturaRectangulo);
			//Conjunto de acciones, si el usuario ingresó el caracter T
			}else if(objeto=='T'){
				double baseTriangulo,alturaTriangulo,ladoIgual;
				printf("Ingrese la base del triángulo áureo: ");
				scanf("%lf",&baseTriangulo);
				//Hallo el lado igual del triángulo áureo, haciendo uso de la fórmula proporcionada
				ladoIgual=razonAurea*baseTriangulo;
				//Uso pitágoras para hallar la altura del triángulo:
				//(lado igual)^2 = (base del triángulo / 2)^2 + (altura del triángulo)^2
				//altura del triángulo = sqrt((lado igual)^2 - (base del triángulo / 2)^2)
				alturaTriangulo=sqrt(pow(ladoIgual,2)-pow(baseTriangulo/2,2));
				printf("La altura de un triángulo áureo de base %.2lf es %.2lf y sus lados iguales son de %.2lf",baseTriangulo,alturaTriangulo,ladoIgual);
			//Conjunto de acciones, si el usuario ingresó el caracter P
			}else{
				double ladoTrapecio,baseMayor,baseMenor;
				printf("Ingrese el lado lateral del trapecio áureo: ");
				scanf("%lf",&ladoTrapecio);
				//Hallo la base mayor y la base menor, haciendo uso de la fórmula proporcionada
				baseMayor=razonAurea*ladoTrapecio;
				baseMenor=ladoTrapecio/razonAurea;
				printf("Las bases de un trapecio áureo de lado lateral %.2lf son %.2lf y %.2lf",ladoTrapecio,baseMayor,baseMenor);
			}
		}else{
			//En caso el usuario ingrese un caracter incorrecto, imprimo el mensaje de error
			printf("El tipo de objeto ingresado no es válido.");
		}
	}else{
		//Si el usuario ingresó una cantidad de iteraciones menor a 10, imprimo el mensaje de error
		printf("El número de iteraciones debe ser mayor o igual a 10.");
	}
	return 0;
}

//Módulo que halla la Razón Áurea
double hallarRazonAurea(int numIteraciones){
	int i=1;
	//Inicializo la razon áurea en raiz de 1, ya que es el valor para cuando la iterador vale 1
	double razonAurea=0;
	do{
		//La razon áurea se va a ir actualizando, siguiendo la fórmula proporcionada
		razonAurea=sqrt(1+razonAurea);
		i++;	
	}while(i<=numIteraciones);
	return razonAurea;
}
