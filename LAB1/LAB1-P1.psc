//Nombre: Alex Calero Revilla
//Código: 20206455
Algoritmo circunferencias_tangentes
	Escribir "Ingrese las coordenadas x e y del centro de la circunferencia 1:"
	Leer x1,y1
	Escribir "Ingrese las coordenadas x e y del centro de la circunferencia 2:"
	Leer x2,y2
	Escribir "Ingrese el radio de la circunferencia 1:"
	Leer radio1
	Escribir "Ingrese el radio de la circunferencia 2:"
	Leer radio2
	area_circunf1<-PI*(radio1^2)
	long_arco_circunf1<-2*PI*radio1
	area_circunf2<-PI*(radio2^2)
	long_arco_circunf2<-2*PI*radio2
	//Hallamos la distancia entre los centros de las circunferencias,
	//ya que la necesitaremos luego para identificar si son circunferencias tangentes.
	distancia_centros<-raiz(((x2-x1)^2)+((y2-y1)^2))
	//Hallamos la suma de radios de las circunferencias,
	//ya que la necesitaremos luego para identificar si son circunferencias tangentes.
	suma_radios<-radio1+radio2
	//Para identificar si las circunferencias son tangentes, realizamos una resta
	//entre la distancia de los centros de las circunferencias y la suma de radios;
	//luego aplicamos valor absoluto a dicha resta y observamos si el valor es menor a 0.0001,
	//lo cual indicará si son tangentes en un punto.
	son_tangentes<-abs(distancia_centros-suma_radios)<0.0001
	Escribir "Resultado de la circunferencia 1:"
	Escribir "El área es: ", area_circunf1
	Escribir "La longitud es: ",long_arco_circunf1
	Escribir "Resultado de la circunferencia 2:"
	Escribir "El área es: ", area_circunf2
	Escribir "La longitud es: ",long_arco_circunf2
	Escribir "¿Son circunferencias tangentes? ",son_tangentes
FinAlgoritmo
