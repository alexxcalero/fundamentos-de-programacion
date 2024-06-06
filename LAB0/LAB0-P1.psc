//Nombre: Alex Calero Revilla
//Código: 20206455
Algoritmo diagnosticar_peritonitis
	Escribir "¿Presenta dolor abdominal?"
	Leer dolor_abdominal
	Escribir "¿Presenta sensibilidad al tacto?"
	Leer sensibilidad_tacto
	Escribir "¿Presenta hinchazón?"
	Leer hinchazon
	Escribir "¿Presenta sensación de pesadez en el abdomen?"
	Leer sensacion_pesadez_abdomen
	Escribir "¿Presenta fiebre?"
	Leer fiebre
	Escribir "¿Presenta náuseas?"
	Leer nauseas
	Escribir "¿Presenta vómitos?"
	Leer vomitos
	peritonitis<-(dolor_abdominal o sensibilidad_tacto) y (hinchazon o sensacion_pesadez_abdomen) y (fiebre) y (nauseas o vomitos)
	Escribir "¿El paciente presenta peritonitis? ", peritonitis
FinAlgoritmo
