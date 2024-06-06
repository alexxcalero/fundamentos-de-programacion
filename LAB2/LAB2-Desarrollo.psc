//Nombre: Alex Calero Revilla
//C�digo: 20206455
Algoritmo SemejanzaTriangulos
	Escribir "Datos del escenario 1"
	Escribir "Ingrese la altura del poste 1 (en cent�metros):"
	Leer altPost1cm
	Escribir "Ingrese el seno del �ngulo entre el piso y la sombra de los edificios:"
	Leer senAngPisoSombra
	Escribir "Ingrese la distancia entre los postes (en metros):"
	Leer distEntrePostesm
	Escribir "Ingrese la distancia entre el segundo poste y el punto del �ngulo (en cent�metros):"
	Leer distPoste2Angcm
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 Entonces
		//Pasamos la altura del 1er poste y la distancia del 2do poste al �ngulo a metros
		altPost1m<-altPost1cm/100
		distPoste2Angm<-distPoste2Angcm/100
		
		//(distancia del 2do poste al �ngulo)/(altura del 2do poste)=(distancia del 2do poste al �ngulo+distancia entre postes)/(altura del 1er poste)
		//(altura del 2do poste)=(distancia del 2do poste al �ngulo)*(altura del 1er poste)/(distancia del 2do poste al �ngulo+distancia entre postes)
		altPost2m<-(distPoste2Angm)*(altPost1m)/(distPoste2Angm+distEntrePostesm)
		
		//(distancia del 1er poste al �ngulo)=(distancia entre postes)+(distancia del 2do poste al �ngulo)
		distPoste1Angm<-distEntrePostesm+distPoste2Angm
		
		//(�ngulo entre el piso y la l�nea de la sombra)=arcsen(seno del �ngulo ingresado)
		angPisoSombraRad<-asen(senAngPisoSombra)
		
		//(�ngulo sexagesimal)=(�ngulo radianes)*180 
		angPisoSombraSex<-(angPisoSombraRad*180)/PI
		
		//(�ngulo entre el edificio y la l�nea de la sombra)=90-(�ngulo entre el piso y la l�nea de la sombra de los postes)
		angEdifSombra<-90-angPisoSombraSex
		
		//(longitud de la l�nea de la sombra)=rc((altura del 1er poste al cuadrado)+(distancia entre postes + distancia del 2do poste al �ngulo y todo al cuadrado))
		longLineaSombra<-rc(((altPost1m)^2)+((distEntrePostesm+distPoste2Angm)^2))
		
		Escribir "Resultados del escenario 1"
		Escribir "La altura del segundo poste es ",altPost2m," m"
		Escribir "La distancia del primer poste al punto del �ngulo es ",distPoste1Angm," m"
		Escribir "El �ngulo que se forma entre el piso y la l�nea de sombra de los edificios es ",angPisoSombraSex," grados sexagesimales"
		Escribir "El �ngulo que se forma entre los edificios y la l�nea de sombra de los edificios es ",angEdifSombra," grados sexagesimales"
		Escribir "La longitud de la l�nea de la sombra es ",longLineaSombra," m"
	SiNo
		Escribir "Los datos ingresados del escenario 1 no son v�lidos"
	Fin Si
	
	Escribir "Datos del escenario 2"
	Escribir "Ingrese la hipotenusa del tri�ngulo (en dec�metros):"
	Leer hipTriandcm
	Escribir "Ingrese el �ngulo inferior del tri�ngulo (en grados sexagesimales):"
	Leer angTrianSex
	
	Si hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 Entonces
		//pasamos el �ngulo inferior del tri�ngulo a radianes
		angTrianRad<-(angTrianSex*PI)/180
		
		//pasamos la hipotenusa del tri�ngulo a m
		hipTriandm<-hipTriandcm/10
		
		//seno(�ngulo del tr�angulo)=(altura del edificio)/(hipotenusa del tri�ngulo)
		//(altura del edificio)=seno(�ngulo del tr�angulo)*(hipotenusa del tri�ngulo)
		altEdfim<-(sen(angTrianRad))*hipTriandm
		
		//cos(�ngulo del tr�angulo)=(base del edificio)/(hipotenusa del tri�ngulo)
		//(base del edificio)=cos(�ngulo del tr�angulo)*(hipotenusa del tri�ngulo)
		baseEdifm<-(cos(angTrianRad))*hipTriandm
		
		Escribir "Resultado del escenario 2"
		Escribir "La altura del edificio es ",altEdfim," m"
		Escribir "La base del edificio es ",baseEdifm," m"
	SiNo
		Escribir "Los datos ingresados del escenario 2 no son v�lidos"
	Fin Si
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 y hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 y altEdfim>=altPost1m y altEdfim>=altPost2m Entonces
		Escribir "El edificio es m�s alto o de la misma altura que los postes"
	Fin Si
	
	Si altPost1cm>0 y senAngPisoSombra>0 y senAngPisoSombra<1 y distEntrePostesm>0 y distPoste2Angcm>0 y hipTriandcm>0 y angTrianSex>0 y angTrianSex<90 y altEdfim<altPost1m y altEdfim<altPost2m Entonces
		Escribir "El edificio tiene menos altura que los postes"
	Fin Si
	
FinAlgoritmo
