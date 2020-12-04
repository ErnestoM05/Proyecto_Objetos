//Proyecto POO
//Autor: Ernesto Méndez Velasco
//A01708166
//03/12/2020
//Archivo: Multi.h

//Bibliotecas
#include<iostream>
#include<stdlib.h>
#include<sstream>
using namespace std;
/*
Creación de constantes, variables y contadores a usar a futuro
*/
const int Max = 100;
int  ipeliculas=0, i=0, r=0, z=0, iseries=0, j=0, k=0, g=0, p=1, s=1;

/*
Clase principal que cuenta con 2 clases hijas (Peliculas y Series) a las que les hereda sus métodos
*/
class Multi{
	private:
/*
Declaración de atributos en forma de arreglos que permitiran el desplegar las bibliotecas completas en el main
*/
		string nombreP[Max], nombreS[Max];
		int anhoP[Max], anhoS[Max];
	public:
/*
Contructor, setter, getters y métodos que componen a la clase principal
*/
		Multi();
		int duracion[Max], capitulos[Max], temporadas[Max];
		void setMultiP(string nombre, int anho, int duracion);
		void setMultiS(string nombre, int anho, int temporadas, int capitulos);
		virtual void mostrarMultiP();
		virtual void mostrarMultiS();	
};
//Contructor por default de la clase padre ´Multi'
Multi::Multi(){
}
/*
Setter de la clase 'Multi' que permite modificar los datos que heredará a la clase hija 'Peliculas', que a la
par funcio para agregar los datos a los arreglos, y así poder armar las bibliotecas, adempas de dejar listo el siguiente
espacio por si el usuario desea agregar más objetos
*/
void Multi::setMultiP(string _nombre, int _anho, int _duracion){	
		nombreP[i] = _nombre;
		anhoP[i] = _anho;
		duracion[i] = _duracion;
		i+=1;
		ipeliculas=i-1;
}
/*
Setter de la clase 'Multi' que permite modificar los datos que heredará a la clase hija 'Series', que a la
par funciona para agregar datos a los arreglos, y así poder armar las bibliotecas, además de dejar listo el siguiente
espacio por si el usuario desea agregar más objetos
*/
void Multi::setMultiS(string _nombre, int _anho, int _temporadas,int _capitulos){
	nombreS[j] = _nombre;
	anhoS[j] = _anho;
	temporadas[j] = _temporadas;
	capitulos[j] = _capitulos;
	j+=1;
	iseries=j-1;
}
/*
Método que se encarga de mostrar el número que ocupar la pelicula en la biblioteca, su nombre y año de estreno, además
de modificar los contadores para seguir trabajando en más espacios de los arreglos
*/
void Multi::mostrarMultiP(){
	cout<<"\n \nPelicula "<<p<<"\nNombre: "<<nombreP[z]<<"\nFecha de estreno: "<<anhoP[z]<<endl;
	z+=1;
	p+=1;
}
/*
Método que se encarga de mostrar el número que ocupar la serie en la biblioteca, su nombre y año de estreno, además
de modificar los contadores para seguir trabajando en más espacios de los arreglos
*/
void Multi::mostrarMultiS(){
	cout<<"\n \nSerie "<<s<<"\nNombre: "<<nombreS[k]<<"\nFecha de estreno: "<<anhoS[k]<<endl;
	k+=1;
	s+=1;
}
/*
Clase hija 'Pelicula' que hereda todo lo publico de la clase padre 'Multi', además de implementar su constructor
y un método complementario propio
*/
class Pelicula : public Multi{
	public:
		Pelicula();
		void mostrarPelicula();
};
/*
Clase hija 'Pelicula' que hereda todo lo publico de la clase padre 'Multi', además de implementar su constructor
y un método complementario propio
*/
class Serie : public Multi{
	public:
		Serie();
		void mostrarSerie();
};
/*
Contructor por default de Pelicula
*/
Pelicula::Pelicula(){
}
/*
Contructor por default de Serie
*/
Serie::Serie(){
}
/*
Método que se encarga de mostrar la biblioteca completa de peliculas, llamando al método de la clase padre y que utiliza
atributos compartidos con Serie, y que de igual forma agrega y muestra atributos exclusivos de peliculas. Recorre todas las
posiciones de los arreglos y los imprime
*/
void Pelicula::mostrarPelicula(){
 	z=0;
 	p=1;
	for (int r = 0; r <= ipeliculas; r++){
		mostrarMultiP();
		cout<<"Duracion: "<<duracion[r]<<" minutos"<<endl;
	}
}
/*
Método que se encarga de mostrar la biblioteca completa de series, llamando al método de la clase padre y que utiliza
atributos compartidos con Pelicula, y que de igual forma agrega y muestra atributos exclusivos de series. Recorre todas las
posiciones de los arreglos y los imprime
*/
void Serie::mostrarSerie(){
	k=0;
	s=1;
	for (int g=0; g <= iseries; g++){
		mostrarMultiS();
		cout<<"Temporadas: "<<temporadas[g]<<"\nCapitulos: "<<capitulos[g]<<endl;
	}
}
