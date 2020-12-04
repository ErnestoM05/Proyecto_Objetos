//Proyecto POO
//Autor: Ernesto Méndez Velasco
//A01708166
//03/12/2020
//Archivo: Main.cpp

//Bibliotecas
#include<iostream>
#include<stdlib.h>
//Archivo donde están las clases del programa
#include "Multi.h"
using namespace std;
/*
Creación de variables iniciales para uso de clases, y variables normales.
*/
Pelicula peli;
Serie serie;
string nombre = "";
int opcion = 0, anho = 0, duracion = 0, temporadas = 0, capitulos = 0;

/*
Función de menú que despliega las opciones disponibles para el usuario de consultar y agregar objetos a
su biblioteca
*/
void menu(){
	cout<<"\n \n¿Que deseas hacer? \n";
	cout<<"1. Consultar biblioteca \n";
	cout<<"2. Agregar pelicula o serie \n";
	cout<<"3. Salir \n";
}
/*
Menú que se despliega una vez seleccionada la opción de agregar objetos, en donde el usuario puede 
elegir entre agregar una serie o pelicula
*/
void agregar(){
	int opcion = 0;
	cout<<"\n¿Que deseas agregar? \n";
	cout<<"1. Serie \n";
	cout<<"2. Pelicula \n";
	cin >> opcion;
/*
Validación para que el usuario no introduzca un opción no disponible y evitar que el programa se cicle
*/
	while(opcion<1 or opcion>2){
		cout<<"Introduzca una opcion valida"<<endl;
		cin >> opcion;
	}
/*
En ambas opciones se comparte que se pide el nombre y el año de estreno, sin embargo, el
switch se aplica para que el programa cambié datos adicionales a pedir en base a si se eligió agregar
una pelicula o serie.
*/
	switch(opcion){
		//Caso 1 que pide datos adicionales para una serie, tal como el número de temporadas y capitulos totales
		case 1:
			cout<<"\nNombre: ";
			cin >> nombre;
			cout<<"Fecha de salida: ";
			cin >> anho;
			cout<<"Temporadas: ";
			cin>>temporadas;
			cout<<"Capitulos: ";
			cin>>capitulos;
		//Se manda a llamar el setter de una de las clases
			serie.setMultiS(nombre, anho, temporadas, capitulos);
			break;
		//Caso 2 que pide el dato adicional de la duración de la pelicula en minutos
		case 2:
			cout<<"\nNombre: ";
			cin >> nombre;
			cout<<"Fecha de salida: ";
			cin >> anho;
			cout<<"Duracion(minutos): ";
			cin>>duracion;
		//Se manda a llamar el setter de una de las clases
			peli.setMultiP (nombre, anho, duracion);
			break;
	}
}
/*
Menú que se despliega en caso de seleccionar la opción de consultar la biblioteca de multimedia, y que da
la opción de elegir entre consultar la bibilioteca de series o peliculas
*/
void biblioteca(){
	int opcion=0;
	cout<<"\n¿Que biblioteca deseas consultar? \n";
	cout<<"1. Series \n";
	cout<<"2. Peliculas \n";
	cin >> opcion;
/*
Validación para que el usuario no introduzca una opción no válida y evitar que el programa se cicle
*/
	while(opcion<1 or opcion>2){
		cout<<"Introduzca una opcion valida"<<endl;
		cin >> opcion;
	}
/*
Al igual que en la función 'agregar' se aplica un switch para mandar a llamar al método, de la clase correspondiente,
en base a la elección del usuario. 
*/
	switch(opcion){
		case 1:
			serie.mostrarSerie();
			break;
		case 2:
			peli.mostrarPelicula();
			break;
	}
}
/*
Función principal que se encarga de recibir la primera elección del usuario 
*/
int main(){
	char bandera = true;
/*
Ciclo para que el programa solo se cierre o detenga si se escoje la opción correspondiente
*/
	while(bandera){
		menu();
		cin >> opcion;
/*
Validación para que el usuario no introzca una opción no disponible y evitar que el programa se cicle
*/
		while(opcion<1 or opcion>3){
			cout<<"Introduzca una opcion valida"<<endl;
			cin >> opcion;
		}
/*
Switch para que el programa mande a llamar a la función correspondiente o en dado caso se cierre.
*/
		switch(opcion){
			case 1:
				biblioteca();
				break;
			case 2:
				agregar();
				break;
			case 3:
				bandera = false;
				break;
		}
	}
	return(0);
}
	
