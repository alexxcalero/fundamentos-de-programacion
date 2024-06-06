//Nombre: Alex Calero Revilla
//Código: 20206455

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
		printf("Ingrese el número en la base ingresada: ");
		scanf("%d",&numero);
		//Imprimo el mensaje en pantalla, si es que el usuario ingresó un número igual a cero
		if(numero==0){
			printf("El numero debe ser mayor que 0.\n");
		//Valido el número invocando al módulo "validarNumeroIngresado"
		}else if(validarNumeroIngresado(baseOriginal,numero)){
			//Acciones para cuando el usuario ingrese un número correcto
			int nuevaBase,Kvalido,numeroEnNuevaBase;
			printf("Ingrese la nueva base a donde desea pasar el número: ");
			scanf("%d",&nuevaBase);
			//Si el usuario ingresa una nueva base menor o igual a la original, imprimo el mensaje de error
			if(nuevaBase<=baseOriginal){
				printf("La nueva base no puede ser menor o igual que la base original.\n");
			//Si el usuario ingresa una nueva base mayor o igual a diez, imprimo el mensaje de error
			}else if(10<=nuevaBase){
				printf("La nueva base no puede ser mayor o igual que 10.\n");
			//Si el módulo "encontrarExpKvalido" no encontró un K válido, imprimo el mensaje de error
			}else if(encontrarExpKvalido(baseOriginal,nuevaBase,&Kvalido)==0){
				printf("No se pudo determinar un exponente k entero de la forma baseˆk = nuevaBase.\n");
			}else{
				//Acciones para cuando el módulo "encontrarExpKvalido" encuentre un K válido
				numeroEnNuevaBase=encontrarNumeroEnNuevaBase(baseOriginal,numero,Kvalido);
				printf("El número %d en base %d es igual al número %d en base %d.",numero,baseOriginal,numeroEnNuevaBase,nuevaBase);
			}
		//Si el usuario ingresa un número que no corresponde a la base ingresada, imprimo el mensaje de error
		}else{
			printf("El número ingresado no corresponde a la base ingresada.\n");
		}
	//Si el usuario ingresa una base inválida, imprimo el mensaje de error
	}else{
		printf("La base n ingresada no es correcta.\n");
	}
	return 0;
}

//Módulo que verificará que todos los dígitos del número ingresado sean menores que la base
int validarNumeroIngresado(int baseOriginal,int numero){
	//Asumo que el número ingresado ya es válido
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

//Módulo que me dirá si existe o no un Kvalido, en caso exista, también me duevuelve dicho valor de K
int encontrarExpKvalido(int baseOriginal,int nuevaBase,int *Kvalido){
	//Inicializo mi variable en 0, suponiendo que nunca va a cumplir la condición
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

//Módulo que encuentra el valor del número en la nueva base
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
