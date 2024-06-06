#include<stdio.h>
#include<math.h>
#define PI 3,14159

//Parámetros
int validar_figura_y_opciones(char tipo_de_figura,int opcion_figura_circular);
double hallar_area_sec_circular(double radio,double cuerda,double angulo,double altura);
double hallar_area_coro_circular(double radio_mayor,double radio_menor);

int main(){
	int opcion_figura_circular,validacion;
	double radio,radio_mayor,radio_menor,angulo,cuerda,altura,long_seg_circular,area_sec_circular,long_coro_circular,area_coro_circular;
	char tipo_de_figura,resultado_a_calcular;
	
	printf("Ingrese el tipo de figura a evaluar (C)Círculo: ");
	scanf(" %c",&tipo_de_figura);
	printf("Ingrese la opción de la figura circular a analizar (1)Segmento circular (2)Corona Circular (3)Trapecio Circular: ");
	scanf("%d",&opcion_figura_circular);
	
	//Recurrimos al submodulo para realizar la validación de los datos ingresados
	validacion=validar_figura_y_opciones(tipo_de_figura,opcion_figura_circular);
	
	if(validacion){
		printf("Ingrese el resultado que desea calcular (L)Longitud (A)Área: ");
		scanf(" %c",&resultado_a_calcular);
		if(resultado_a_calcular=='L' || resultado_a_calcular=='A'){
			if(opcion_figura_circular==1 && resultado_a_calcular=='L'){
				printf("Ingrese los valores de radio, cuerda, alfa, altura: ");
				scanf("%lf %lf %lf %lf",&radio,&cuerda,&angulo,&altura);
				long_seg_circular=0.01745*radio*angulo+cuerda;
				printf("La longitud del segmento circular es: %lf",long_seg_circular);
			}
			else{
				if(opcion_figura_circular==1 && resultado_a_calcular=='A'){
					printf("Ingrese los valores de radio, cuerda, alfa, altura: ");
					scanf("%lf %lf %lf %lf",&radio,&cuerda,&angulo,&altura);
					area_sec_circular=hallar_area_sec_circular(radio,cuerda,angulo,altura);
					printf("El área del segmento circular es: %lf",area_sec_circular);
				}
				else{
					if(opcion_figura_circular==2 && resultado_a_calcular=='L'){
						printf("Ingrese los valores de radio mayor y radio menor: ");
						scanf("%lf %lf",&radio_mayor,&radio_menor);
						long_coro_circular=2*PI*(radio_mayor+radio_menor);
						printf("La longitud de la corona circular es: %lf",long_coro_circular);
					}
					else{
						if(opcion_figura_circular==2 && resultado_a_calcular=='A'){
							printf("Ingrese los valores de radio mayor y radio menor: ");
							scanf("%lf %lf",&radio_mayor,&radio_menor);
							area_coro_circular=hallar_area_coro_circular(radio_mayor,radio_menor);
							printf("El area de la corona circular es: %lf",area_coro_circular);
						}
					}
				}
			}	
		}
		else{
			printf("Ingresó una opción inválida para el cálculo a realizar.");
		}			
	}
	else{
		printf("Ingresó una opción inválida para identificar a la figura circular.");
	}
		
	return 0;
}

int validar_figura_y_opciones(char tipo_de_figura,int opcion_figura_circular){
	int validacion;
	if(tipo_de_figura=='C' && (opcion_figura_circular==1 || opcion_figura_circular==2 || opcion_figura_circular==3)){
		validacion=1;
	}
	else{
		validacion=0;
	}
	return validacion;
}

double hallar_area_sec_circular(double radio,double cuerda,double angulo,double altura){
	int area;
	area=(PI*pow(radio,2)*angulo/360)-((cuerda*(radio-altura))/2);
	return area;
}

double hallar_area_coro_circular(double radio_mayor,double radio_menor){
	int area;
	area=PI*(pow(radio_mayor,2)-pow(radio_menor,2));
	return area;
}
