//Nombre: Alex Calero Revilla
//Código: 20206455

#include<stdio.h>
#include<math.h>
#define PI 3.141592

//Parámetros
int ValidarFigura(char letra);
double HallarVolumen(int cantBase,double radio,double altura);
void HallarPorcentajesDeConosCilindros(int cantTotalConos,int cantTotalCilindros,double *porcentajeConos,double *porcentajeCilindros);

int main(){
	char figura;
	int cantBases;
	int cantTotalConos=0;
	int cantTotalCilindros=0;
	double porcentajeConos,porcentajeCilindros;
	double mayorVolCono=0;
	double menorVolCilindro=9999;
	while(1){
		printf("Ingrese el tipo de figura a analizar: ");
		scanf(" %c",&figura);
		if(ValidarFigura(figura)==1){
			int i=1;
			int cantConosEvaluar,cantCilindrosEvaluar;
			double radioCono,alturaCono,volCono,radioCilindro,alturaCilindro,volCilindro;
			printf("Ingrese la cantidad de bases del grupo de figuras a evaluar: ");
			scanf("%d",&cantBases);
			if(cantBases==1){
				printf("Figura identificada:-----CONO-----\n");
				printf("Ingrese la cantidad de conos a evaluar: ");
				scanf("%d",&cantConosEvaluar);
				while(i<=cantConosEvaluar){
					printf("Cono %d - Ingrese el radio de la base: ",i);
					scanf("%lf",&radioCono);
					printf("Cono %d - Ingrese la altura del cono: ",i);
					scanf("%lf",&alturaCono);
					if(radioCono>0 && alturaCono>0){
						volCono=HallarVolumen(cantBases,radioCono,alturaCono);
						printf("El volumen del cono %d es: %.2lf\n",i,volCono);
						//Validación del volumen del cono, para corroborar si el valor del mayorVolCono se actuliazará o no
						if(volCono>mayorVolCono){
							mayorVolCono=volCono;
						}
						cantTotalConos++;
					}else
						printf("El radio y la altura deben ser mayores a 0\n");
					i++;
				}
			}else if(cantBases==2){
				printf("Figura identificada:-----CILINDRO-----\n");
				printf("Ingrese la cantidad de cilindros a evaluar: ");
				scanf("%d",&cantCilindrosEvaluar);
				while(i<=cantCilindrosEvaluar){
					printf("Cilindro %d - Ingrese el radio de la base: ",i);
					scanf("%lf",&radioCilindro);
					printf("Cilindro %d - Ingrese la altura del cilindro: ",i);
					scanf("%lf",&alturaCilindro);
					if(radioCilindro>0 && alturaCilindro>0){
						volCilindro=HallarVolumen(cantBases,radioCilindro,alturaCilindro);
						printf("El volumen del cilindro %d es: %.2lf\n",i,volCilindro);
						//Validación del volumen del cilindro, para corroborar si el valor del menorVolCilindro se actuliazará o no
						if(volCilindro<menorVolCilindro){
							menorVolCilindro=volCilindro;
						}
						cantTotalCilindros++;
					}else
						printf("El radio y la altura deben ser mayores a 0\n");
					i++;
				}
			//Si ingresa un número diferente de 1 o 2, el programa muestra un mensaje de error y termina
			}else{
				printf("Figura no identificada\n");
				break;
			}
		}else if(ValidarFigura(figura)==2){
			
		}else{
			break;
		}
	}
	//Valido la cantidad de bases, ya que si ingresa un número erróneo, el programa termina y no debe imprimir nada del reporte
	if(cantBases==1 || cantBases==2){
		HallarPorcentajesDeConosCilindros(cantTotalConos,cantTotalCilindros,&porcentajeConos,&porcentajeCilindros);
		printf("REPORTE\n");
		printf("-------\n");
		printf("El total de figuras es: %d\n",cantTotalConos+cantTotalCilindros);
		//Considero los porcentajes, como tipo "double" para poder considerar las cifras decimales y tener un resultado más exacto
		printf("El porcentaje de conos analizados es: %.2lf\n",porcentajeConos);
		printf("El porcentaje de cilindros analizados es: %.2lf\n",porcentajeCilindros);
		printf("El mayor volumen de los conos es: %.2lf\n",mayorVolCono);
		printf("El menor volumen de los cilindros es: %.2lf\n",menorVolCilindro);
	}
	return 0;
}

//Módulo que valida la letra que el usuario ingresa
int ValidarFigura(char letra){
	if(letra=='C'){
		return 1;
	}else if(letra!='Z'){
		return 2;
	}else
		return 0;
}

//Módulo que halla el volumen dependiendo de la figura
double HallarVolumen(int cantBases,double radio,double altura){
	double volumen;
	if(cantBases==1)
		//No hago el casteo a "int", xq quiero tomar el valor exacto que da el "pow"
		volumen=(PI*pow(radio,2)*altura)/3;
	else
		//No hago el casteo a "int", xq quiero tomar el valor exacto que da el "pow"
		volumen=PI*pow(radio,2)*altura;
	return volumen;
}

//Módulo que halla los porcentajes de conos y cilindros
void HallarPorcentajesDeConosCilindros(int cantTotalConos,int cantTotalCilindros,double *porcentajeConos,double *porcentajeCilindros){
	int total=cantTotalConos+cantTotalCilindros;
	*porcentajeConos=((double)cantTotalConos/total)*100;
	*porcentajeCilindros=((double)cantTotalCilindros/total)*100;
}
