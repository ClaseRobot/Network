#include "Persona.h"
#include "TipoFormato.h"
#include <iostream>

using namespace UndavPersona;
using std::cout;
using std::endl;

const int CantidadUsuarios = 8;

void MostrarListado(Persona** redSocial, TipoFormato formato);
void Conectar(Persona* persona, Persona* otraPersona);
void Conectar(Persona** redSocial);
void Destruir(Persona** redSocial);

int main() {
	Persona* redSocial[CantidadUsuarios] = {
			CrearPersona("Dante", "Serres"),
			CrearPersona("Renata", "Serres"),
			CrearPersona("Ciro", "Diaz"),
			CrearPersona("Helena", "Diaz"),
			CrearPersona("Juan", "Valdez"),
			CrearPersona("Tomas", "Diaz"),
			CrearPersona("Lucia", "Zelada"),
			CrearPersona("Juan", "Lopez"),
	};

	MostrarListado(redSocial, CSV);
	cout<<endl;
	MostrarListado(redSocial, Expresivo);
	cout<<endl;
	Conectar(redSocial);
	MostrarListado(redSocial, CSV);
	cout<<endl;
	MostrarListado(redSocial, Expresivo);
	Destruir(redSocial);

	return 0;
}

void MostrarListado(Persona** redSocial, TipoFormato formato){
	if(formato == Expresivo){
		cout<<"Listado de la red social: "<<endl;
	}else{
		cout<<"Nombre, Apellido, CantidadAmigos"<<endl;
	}

	for(int i=0; i < CantidadUsuarios; ++i){
		cout<<Serializar(redSocial[i], formato)<<endl;
	}
}

void Conectar(Persona* persona, Persona* otraPersona){
	AgregarAmigo(persona, otraPersona);
	AgregarAmigo(otraPersona, persona);
}

void Conectar(Persona** redSocial){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			Conectar(redSocial[i], redSocial[j]);
		}
	}
}

void Destruir(Persona** redSocial){
	for(int i=0; i < CantidadUsuarios; ++i){
		Destruir(redSocial[i]);
	}
}
