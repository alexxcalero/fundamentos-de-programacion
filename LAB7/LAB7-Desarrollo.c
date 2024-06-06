//Nombre: Alex Calero Revilla
//C�digo: 20206455

#include<stdio.h>
#include<math.h>

//Prototipos
int validarNumeroIngresado(int baseOriginal,int numero);
int encontrarExpKvalido(int baseOriginal,int nuevaBase,int *Kvalido);
int encontrarNumeroEnNuevaBase(int baseOriginal,int numero,int Kvalido);
int voltearNumero(int nuevoNumero);

int main(){
	int baseOriginal;
	printf("Ingrese la base: ");
	scanf("%d",&baseOriginal);
	//Verifico que el dato ingresado por el usuario cumpla las condiciones del problema
	if(2<=baseOriginal && baseOriginal<=9){
		int numero;
		printf("Ingrese el n�mero en la base ingresada: ");
		scanf("%d",&numero);
		//Imprimo el mensaje en pantalla, si es que el usuario ingres� un n�mero igual a cero
		if(numero==0){
			printf("El numero debe ser mayor que 0.\n");
		//Valido el n�mero invocando al m�dulo "validarNumeroIngresado"
		}else if(validarNumeroIngresado(baseOriginal,numero)){
			//Acciones para cuando el usuario ingrese un n�mero correcto
			int nuevaBase,Kvalido,numeroEnNuevaBase;
			printf("Ingrese la nueva base a donde desea pasar el n�mero: ");
			scanf("%d",&nuevaBase);
			//Si el usuario ingresa una nueva base menor o igual a la original, imprimo el mensaje de error
			if(nuevaBase<=baseOriginal){
				printf("La nueva base no puede ser menor o igual que la base original.\n");
			//Si el usuario ingresa una nueva base mayor o igual a diez, imprimo el mensaje de error
			}else if(10<=nuevaBase){
				printf("La nueva base no puede ser mayor o igual que 10.\n");
			//Si el m�dulo "encontrarExpKvalido" no encontr� un K v�lido, imprimo el mensaje de error
			}else if(encontrarExpKvalido(baseOriginal,nuevaBase,&Kvalido)==0){
				printf("No se pudo determinar un exponente k entero de la forma base�k = nuevaBase.\n");
			}else{
				//Acciones para cuando el m�dulo "encontrarExpKvalido" encuentre un K v�lido
				numeroEnNuevaBase=encontrarNumeroEnNuevaBase(baseOriginal,numero,Kvalido);
				printf("El n�mero %d en base %d es igual al n�mero %d en base %d.",numero,baseOriginal,numeroEnNuevaBase,nuevaBase);
			}
		//Si el usuario ingresa un n�mero que no corresponde a la base ingresada, imprimo el mensaje de error
		}else{
			printf("El n�mero ingresado no corresponde a la base ingresada.\n");
		}
	//Si el usuario ingresa una base inv�lida, imprimo el mensaje de error
	}else{
		printf("La base n ingresada no es correcta.\n");
	}
	return 0;
}

//M�dulo que verificar� que todos los d�gitos del n�mero ingresado sean menores que la base
int validarNumeroIngresado(int baseOriginal,int numero){
	//Asumo que el n�mero ingresado ya es v�lido
	int esValido=1;
	int digito;
	do{
		digito=numero%10;
		numero/=10;
		if(digito>baseOriginal){
			esValido=0;
		}
	}while(numero>0);
	return esValido;
}

//M�dulo que me dir� si existe o no un Kvalido, en caso exista, tambi�n me duevuelve dicho valor de K
int encontrarExpKvalido(int baseOriginal,int nuevaBase,int *Kvalido){
	//Inicializo mi variable en 0, suponiendo que nunca va a cumplir la condici�n
	int hayKvalido=0;
	int i;
	for(i=1;i<=nuevaBase;i++){
		if(pow(baseOriginal,i)==nuevaBase){
			hayKvalido=1;
			*Kvalido=i;
		}
	}
	return hayKvalido;
}

//M�dulo que encuentra el valor del n�mero en la nueva base
int encontrarNumeroEnNuevaBase(int baseOriginal,int numero,int Kvalido){
	int nuevoNumero=0,digitos,descomposicion;
	do{
		digitos=numero%(int)pow(10,Kvalido);
		numero/=(int)pow(10,Kvalido);
		int i=0,digitosEnNuevaBase=0;
		do{
			descomposicion=(digitos%10)*(int)pow(baseOriginal,i);
			digitos/=(int)pow(10,Kvalido-1);
			digitosEnNuevaBase+=descomposicion;
			i++;
		}while(i<=Kvalido-1);
		nuevoNumero=nuevoNumero*10+digitosEnNuevaBase;
	}while(numero>0);
	nuevoNumero=voltearNumero(nuevoNumero);
	return nuevoNumero;
}

int voltearNumero(int nuevoNumero){
	int volteo=0,digito;
	while(nuevoNumero>0){
		digito=nuevoNumero%10;
		nuevoNumero/=10;
		volteo=volteo*10+digito;
	}
	return volteo;
}
