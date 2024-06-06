//Nombre: Alex Calero Revilla
//Código: 20206455

#include<stdio.h>
#include<math.h>

//Prototipos
void leerCoefCircunf(double *C,double *D,double *E,int i);
void hallarCentroRadio(double C,double D,double E,double Canterior,double Danterior,double Eanterior,double *radio1,double *radio2);
double hallarDistanciaEntrePuntos(double C,double D,double Canterior,double Danterior,double *distancia);
void leerCoefRecta(double *A,double *B,double *C,int j);
void comprobarRectas(double A,double B,double C,double Aanterior,double Banterior,double Canterior);

int main(){
	//Declaramos nuestras variables
	char opcion;
	int nVeces,i=1,j=1,sumaDeCruces=0;
	double A,B,C,D,E,Aanterior,Banterior,Canterior,Danterior,Eanterior,radio1,radio2,distancia;
	
	printf("Ingrese la opción que desea calcular:\n");
	printf("Circunferencias que se intersectan (A o a)\n");
	printf("Relación entre rectas (B o b)\n");
	scanf(" %c",&opcion);
	
	//Si no elige la opción correcta, el programa terminará
	if(opcion!='A' && opcion!='a' && opcion!='B' && opcion!='b'){
		printf("Error en la opción ingresada.\n");
	}
	//Por el contrario, el programa hará determinadas acciones, dependiendo de la elección del usuario
	else{
		if(opcion=='A' || opcion=='a'){
			//Imprimimos el mensaje para cuando eliga circunferencias
			printf("Ingrese la cantidad de veces que desea validar si 2 circunferencias de la forma x2 + y2 + Cx +Dy + E se cruzan:\n");
			scanf("%d",&nVeces);
			if(nVeces<1 && nVeces>20){
				printf("El valor de n no se encuentra dentro del rango solicitado.\n");
			}
			else{
				while(i<=nVeces){
					leerCoefCircunf(&C,&D,&E,i);
					leerCoefCircunf(&Canterior,&Danterior,&Eanterior,i+1);
					hallarCentroRadio(C,D,E,Canterior,Danterior,Eanterior,&radio1,&radio2);
					hallarDistanciaEntrePuntos(C,D,Canterior,Danterior,&distancia);
					if(radio1+radio2>=distancia){
						sumaDeCruces++;
						printf("Las circunferencias se cruzan.\n");
					}
					else{
						printf("Las circunferencias no se cruzan.\n");
					}
					i++;
				}
				printf("Se encontraron %d cruces entre circunferencias.\n",sumaDeCruces);
			}
		}
		else{
			//Imprimimos el mensaje para cuando eliga rectas
			printf("Ingrese la cantidad de veces que desea validar si 2 rectas son secantes, paralelas o coincidentes:\n");
			scanf("%d",&nVeces);
			if(nVeces<1 && nVeces>20){
				printf("El valor de n no se encuentra dentro del rango solicitado.\n");
			}
			else{
				while(j<=nVeces){
					leerCoefRecta(&A,&B,&C,j);
					leerCoefRecta(&Aanterior,&Banterior,&Canterior,j+1);
					comprobarRectas(A,B,C,Aanterior,Banterior,Canterior);
					j++;	
				}	
			}
		}
	}
	return 0;
}

//Módulo para leer los valores que ingresará el usuario de los coeficientes C,D,E
void leerCoefCircunf(double *C,double *D,double *E,int i){
	printf("Ingrese los coeficientes C, D y E de la circunferencia %d (x2 + y2 + Cx + Dy + E):\n",i);
	scanf("%lf %lf %lf",C,D,E);
}

//Módulo para hallar el centro y los radios de la circunferencias
void hallarCentroRadio(double C,double D,double E,double Canterior,double Danterior,double Eanterior,double *radio1,double *radio2){
	//Defino variables para hallar el centro y los radios
	double h1,h2,k1,k2;
	h1=-1*(C/2);
	h2=-1*(Canterior/2);
	k1=-1*(D/2);
	k2=-1*(Danterior/2);
	*radio1=sqrt(pow(h1,2)+pow(k1,2)-E);
	*radio2=sqrt(pow(h2,2)+pow(k2,2)-Eanterior);
}

//Módulo para hallar la distancia entre los centros
double hallarDistanciaEntrePuntos(double C,double D,double Canterior,double Danterior,double *distancia){
	//Defino variables para hallar la distancia entre los centros de la circunferencia
	double h1,h2,k1,k2;
	h1=-1*(C/2);
	h2=-1*(Canterior/2);
	k1=-1*(D/2);
	k2=-1*(Danterior/2);
	*distancia=sqrt(pow((h1-h2),2)+pow((k1-k2),2));
	//Devuelvo el valor de la distancia, para usarla en el main
	return *distancia;
}

//Módulo para leer los valores que ingresará el usuario de los coeficientes A,B,C
void leerCoefRecta(double *A,double *B,double *C,int j){
	printf("Ingrese los coeficientes A, B y C de la recta %d (Ax + By + C = 0):\n",j);
	scanf("%lf %lf %lf",A,B,C);
}

//Módulo para hallar si las rectas son coincidentes, paralelas o secantes
void comprobarRectas(double A,double B,double C,double Aanterior,double Banterior,double Canterior){
	if((A/Aanterior)==(B/Banterior) && (B/Banterior)==(C/Canterior)){
		printf("Las rectas son coincidentes.\n");
	}
	else{
		if((A/Aanterior)==(B/Banterior) && (B/Banterior)!=(C/Canterior)){
			printf("Las rectas son paralelas.\n");
		}
		else{
			printf("Las rectas son secantes.\n");
		}
	}
}
