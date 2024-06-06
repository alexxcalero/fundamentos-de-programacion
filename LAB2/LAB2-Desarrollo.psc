//Nombre: Alex Calero Revilla
//Código: 20206455
Algoritmo SemejanzaTriangulos
	Escribir "Datos del escenario 1"
	Escribir "Ingrese la altura del poste 1 (en centímetros):"
	Leer altPost1cm
	Escribir "Ingrese el seno del ángulo entre el piso y la sombra de los edificios:"
	Leer senAngPisoSombra
	Escribir "Ingrese la distancia entre los postes (en metros):"
	Leer distEntrePostesm
	Escribir "Ingrese la distancia entre el segundo poste y el punto del ángulo (en centímetros):"
	Leer distPoste2Angcm
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 Entonces
		//Pasamos la altura del 1er poste y la distancia del 2do poste al ángulo a metros
		altPost1m<-altPost1cm/100
		distPoste2Angm<-distPoste2Angcm/100
		
		//(distancia del 2do poste al ángulo)/(altura del 2do poste)=(distancia del 2do poste al ángulo+distancia entre postes)/(altura del 1er poste)
		//(altura del 2do poste)=(distancia del 2do poste al ángulo)*(altura del 1er poste)/(distancia del 2do poste al ángulo+distancia entre postes)
		altPost2m<-(distPoste2Angm)*(altPost1m)/(distPoste2Angm+distEntrePostesm)
		
		//(distancia del 1er poste al ángulo)=(distancia entre postes)+(distancia del 2do poste al ángulo)
		distPoste1Angm<-distEntrePostesm+distPoste2Angm
		
		//(ángulo entre el piso y la línea de la sombra)=arcsen(seno del ángulo ingresado)
		angPisoSombraRad<-asen(senAngPisoSombra)
		
		//(ángulo sexagesimal)=(ángulo radianes)*180 
		angPisoSombraSex<-(angPisoSombraRad*180)/PI
		
		//(ángulo entre el edificio y la línea de la sombra)=90-(ángulo entre el piso y la línea de la sombra de los postes)
		angEdifSombra<-90-angPisoSombraSex
		
		//(longitud de la línea de la sombra)=rc((altura del 1er poste al cuadrado)+(distancia entre postes + distancia del 2do poste al ángulo y todo al cuadrado))
		longLineaSombra<-rc(((altPost1m)^2)+((distEntrePostesm+distPoste2Angm)^2))
		
		Escribir "Resultados del escenario 1"
		Escribir "La altura del segundo poste es ",altPost2m," m"
		Escribir "La distancia del primer poste al punto del ángulo es ",distPoste1Angm," m"
		Escribir "El ángulo que se forma entre el piso y la línea de sombra de los edificios es ",angPisoSombraSex," grados sexagesimales"
		Escribir "El ángulo que se forma entre los edificios y la línea de sombra de los edificios es ",angEdifSombra," grados sexagesimales"
		Escribir "La longitud de la línea de la sombra es ",longLineaSombra," m"
	SiNo
		Escribir "Los datos ingresados del escenario 1 no son válidos"
	Fin Si
	
	Escribir "Datos del escenario 2"
	Escribir "Ingrese la hipotenusa del triángulo (en decímetros):"
	Leer hipTriandcm
	Escribir "Ingrese el ángulo inferior del triángulo (en grados sexagesimales):"
	Leer angTrianSex
	
	Si hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 Entonces
		//pasamos el ángulo inferior del triángulo a radianes
		angTrianRad<-(angTrianSex*PI)/180
		
		//pasamos la hipotenusa del triángulo a m
		hipTriandm<-hipTriandcm/10
		
		//seno(ángulo del tríangulo)=(altura del edificio)/(hipotenusa del triángulo)
		//(altura del edificio)=seno(ángulo del tríangulo)*(hipotenusa del triángulo)
		altEdfim<-(sen(angTrianRad))*hipTriandm
		
		//cos(ángulo del tríangulo)=(base del edificio)/(hipotenusa del triángulo)
		//(base del edificio)=cos(ángulo del tríangulo)*(hipotenusa del triángulo)
		baseEdifm<-(cos(angTrianRad))*hipTriandm
		
		Escribir "Resultado del escenario 2"
		Escribir "La altura del edificio es ",altEdfim," m"
		Escribir "La base del edificio es ",baseEdifm," m"
	SiNo
		Escribir "Los datos ingresados del escenario 2 no son válidos"
	Fin Si
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 y hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 y altEdfim>=altPost1m y altEdfim>=altPost2m Entonces
		Escribir "El edificio es más alto o de la misma altura que los postes"
	Fin Si
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 y hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 y altEdfim<altPost1m y altEdfim<altPost2m Entonces
		Escribir "El edificio tiene menos altura que los postes"
	Fin Si
	
FinAlgoritmo
