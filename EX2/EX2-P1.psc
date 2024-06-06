//Alex Calero Revilla - 20206455
Algoritmo Pregunta1A
	Repetir
		Escribir "Ingrese el numerador y denominador de la primera fracción:"
		Leer num1
		Leer den1
		Escribir "Ingrese el numerador y denominador de la segunda fracción:"
		Leer num2
		Leer den2
		//Valido que los datos ingresados no sean iguales a 0
		Si num1<>0 y den1<>0 y num2<>0 y den2<>0 Entonces
			Escribir "Ingrese la operación a realizar: (+) suma o (-) resta:"
			Leer operacion
			Si operacion='+' o operacion='-' Entonces
				i<-1
				maxComDiv<-0
				//Con este "Mientras" hallo el max. común divisor de ambos denominadores
				Mientras i<=den1 y i<= den2 Hacer
					Si (den1 mod i = 0) y (den2 mod i = 0) Entonces
						//Evalúo que el divisor sea siempre el mayor encontrado
						Si i>maxComDiv Entonces
							maxComDiv<-i
						FinSi
					FinSi
					i<-i+1
				FinMientras
				minComMult<-trunc((den1*den2)/maxComDiv)
				num1DivGeneral<-trunc((minComMult/den1)*num1)
				num2DivGeneral<-trunc((minComMult/den2)*num2)
				//Selectiva dependiendo de la operación que ingrese el usuario
				Si operacion='+' Entonces
					resultSuma<-num1DivGeneral+num2DivGeneral
					//Selectiva para ver si la suma es fracción es propia o impropia
					Si resultSuma>minComMult Entonces
						Escribir "Fracción impropia. El resultado es: ",num1,"/",den1," + ",num2,"/",den2," = ",resultSuma,"/",minComMult
					SiNo
						Escribir "Fracción propia. El resultado es: ",num1,"/",den1," + ",num2,"/",den2," = ",resultSuma,"/",minComMult
					FinSi
				SiNo
					resultResta<-abs(num1DivGeneral-num2DivGeneral)
					//Selectiva para ver si la resta es fracción es propia o impropia
					Si resultResta>minComMult Entonces
						Escribir "Fracción impropia. El resultado es: ",num1,"/",den1," - ",num2,"/",den2," = ",resultResta,"/",minComMult
					SiNo
						Escribir "Fracción propia. El resultado es: ",num1,"/",den1," - ",num2,"/",den2," = ",resultResta,"/",minComMult
					FinSi
				FinSi
			SiNo
				Escribir "Solo se trabajará con sumas y restas"
			FinSi
		FinSi
	Mientras Que num1<>0 y den1<>0 y num2<>0 y den2<>0
FinAlgoritmo