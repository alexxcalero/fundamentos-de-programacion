Algoritmo PlanoInclinado
	Escribir "Ingrese la altura del bloque al piso y su unidad de medida (c:cent�metros, d: dec�metros, m: metros):"
	Leer altura,unidad
	Si (altura>0) y (unidad='c' o unidad='d' o unidad='m') Entonces
		Escribir "Ingrese el coseno del �ngulo:"
		Leer cosAngulo
		Si (cosAngulo>=-1 y cosAngulo<=1) Entonces
			Escribir "Ingrese si existe fricci�n entre el bloque y el plano inclinado, s� (S o s), no (N o n):"
			Leer hayFriccion
			Si (hayFriccion='S' o hayFriccion='s') Entonces
				//Angulo en radianes
				anguloRad<-acos(cosAngulo)
				//Angulo en grados sexagesimales
				anguloSex<-anguloRad*180/PI
				Si anguloSex>0 y anguloSex<90 Entonces
					Escribir "Ingrese el coeficiente de rozamiento din�mico:"
					Leer coefRozamiento
					//Hallamos la tangente del �ngulo para realizar la verificaci�n
					tangAng<-tan(anguloRad)
					Si coefRozamiento>0 y coefRozamiento<=tangAng Entonces
						aceleracion<-9.81*sen(anguloRad)-coefRozamiento*9.81*cosAngulo
						tiempo<-(1/rc(sen(anguloRad)*sen(anguloRad)-coefRozamiento*cosAngulo))*rc((2*altura)/9.81)
						velocidad<-rc((sen(anguloRad)-coefRozamiento*cosAngulo)/sen(anguloRad))*rc(2*9.81*altura)
						Escribir "Cuando S� existe fricci�n entre el objeto y el plano inclinado:"
						Escribir "La aceleracion es ",aceleracion," m/min2"
						Escribir "El tiempo que tarda el bloque en llegar al final del plano inclinado es: ",tiempo," min"
						Escribir "La velocidad final del bloque es ",velocidad," m/min"
					SiNo
						Escribir "El coeficiente debe ser positivo o no existe movimiento porque el coeficiente es mayor a la tangente del �ngulo"
					FinSi
				SiNo
					Escribir "El �ngulo debe ser mayor a 0 y menor a 90 grados sexagesimales"
				FinSi
			SiNo
				Si (hayFriccion='N' o hayFriccion='n') Entonces
					//Angulo en radianes
					anguloRad<-acos(cosAngulo)
					//Angulo en grados sexagesimales
					anguloSex<-anguloRad*180/PI
					Si anguloSex>0 y anguloSex<90 Entonces
						aceleracion<-9.81*sen(anguloRad)
						tiempo<-(1/sen(anguloRad))*rc((2*altura)/9.81)
						velocidad<-rc(2*9.81*altura)
					SiNo
						Escribir "El �ngulo debe ser mayor a 0 y menor a 90 grados sexagesimales"
					FinSi
				SiNo
					Escribir "No se ingres� correctamente si existe o no fricci�n entre el bloque y el plano inclinado"
				FinSi
			FinSi
		SiNo
			Escribir "El coseno del �ngulo no es correcto"
		FinSi
	SiNo
		Escribir "Los datos de la altura no son correctos"
	FinSi
	
FinAlgoritmo
