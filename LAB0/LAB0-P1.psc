//Nombre: Alex Calero Revilla
//C�digo: 20206455
Algoritmo diagnosticar_peritonitis
	Escribir "�Presenta dolor abdominal?"
	Leer dolor_abdominal
	Escribir "�Presenta sensibilidad al tacto?"
	Leer sensibilidad_tacto
	Escribir "�Presenta hinchaz�n?"
	Leer hinchazon
	Escribir "�Presenta sensaci�n de pesadez en el abdomen?"
	Leer sensacion_pesadez_abdomen
	Escribir "�Presenta fiebre?"
	Leer fiebre
	Escribir "�Presenta n�useas?"
	Leer nauseas
	Escribir "�Presenta v�mitos?"
	Leer vomitos
	peritonitis<-(dolor_abdominal o sensibilidad_tacto) y (hinchazon o sensacion_pesadez_abdomen) y (fiebre) y (nauseas o vomitos)
	Escribir "�El paciente presenta peritonitis? ", peritonitis
FinAlgoritmo
