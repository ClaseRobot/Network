#include <iostream>
#include <string>

using namespace std;

struct Persona{
	string nombre;
	string apellido;
};

struct ColeccionPersonas{
	int cantidad;
	Persona** personas;
};

struct UsuarioRedSocial{
	Persona *persona;
	ColeccionPersonas* amigos;
};

// Precondicion: Ninguna
// Postcondicion: Crea una instancia valida de persona con @nombre nombre y apellido @apellido
Persona* CrearPersona(string nombre, string apellido);

// Precondicion: Ninguna
// Postcondicion: Crea una instancia valida de ColeccionPersonas que se encuentra vacia
ColeccionPersonas* CrearColeccionVacia();

// Precondicion: @personas tiene un tamano igual a @cantidadPersonas
// Postcondicion: Devuelve una instancia valida de ColeccionPersonas que tiene los elementos @personas
ColeccionPersonas* CrearColeccion(Persona* personas[], int cantidadPersonas);

// Precondicion: Ninguna
// Postcondicion: Devuelve una instancia valida de UsuarioRedSocial que es una persona de
// nombre y apellido igual a @nombre y @apellido, que no tiene amigos
UsuarioRedSocial* CrearUsuario(string nombre, string apellido);

// Precondicion: @persona y @amigos son instancias validas
// Postcondicion: Devuelve una instancia valida de UsuarioRedSocial
UsuarioRedSocial* CrearUsuario(Persona* persona, ColeccionPersonas* amigos);

// Precondicion: @coleccion es una instancia valida
// Postcondicion: Agrega en @coleccion a @persona
void Agregar(ColeccionPersonas* coleccion, Persona* persona);

// Precondicion: @personas tiene un tamano igual a @cantidadPersonas
// Postcondicion: Muestra por salida estandard las personas
void Mostrar(Persona** personas, int cantidad);

// Precondcion: @usuario es una instancia valida
// Postcondicion: Libera todos los recursos asociados
void Destruir(UsuarioRedSocial* usuario);

int main() {
	Persona* personas[3] = {CrearPersona("Juan", "Gomez"), CrearPersona("Jeannette", "Torrez"), CrearPersona("Helena", "Diaz")};
	UsuarioRedSocial* yo = CrearUsuario("Federico", "Diaz");
	cout<<"Personas: "<<endl;
	Mostrar(personas, 3);
	cout<<"Yo: ";
	Mostrar(&yo->persona, 1);
	cout<<"Mis amigos: "<<endl;
	for(int i=0; i < 3; i++){
		Agregar(yo->amigos, personas[i]);
	}
	Mostrar(yo->amigos->personas, yo->amigos->cantidad);
	Destruir(yo);

	return 0;
}

Persona* CrearPersona(string nombre, string apellido){
	Persona* persona = new Persona;
	persona->nombre = nombre;
	persona->apellido = apellido;

	return persona;
}

ColeccionPersonas* CrearColeccionVacia(){
	ColeccionPersonas* coleccion = new ColeccionPersonas;
	coleccion->cantidad = 0;

	return coleccion;
}

ColeccionPersonas* CrearColeccion(Persona* personas[], int cantidadPersonas){
	ColeccionPersonas* coleccion =CrearColeccionVacia();
	for(int i=0; i<cantidadPersonas;++i){
		Agregar(coleccion, personas[i]);
	}

	return coleccion;
}

/*
ColeccionPersonas* CrearColeccion(Persona* personas[], int cantidadPersonas){
	ColeccionPersonas* coleccion =new ColeccionPersonas;
	coleccion->personas = new Persona*[cantidadPersonas];
	for(int i=0; i<cantidadPersonas;++i){
		coleccion->personas[i]=personas[i];
	}
	coleccion->cantidad = cantidadPersonas;

	return coleccion;
}

ColeccionPersonas* CrearColeccion(Persona* personas[], int cantidadPersonas){
	ColeccionPersonas* coleccion =new ColeccionPersonas;
	coleccion->personas = new Persona*[cantidadPersonas];
	for(int i=0; i<cantidadPersonas;++i){
		coleccion->personas[i] = CrearPersona(personas[i]->nombre, personas[i]->apellido);
	}
	coleccion->cantidad = cantidadPersonas;

	return coleccion;
}

ColeccionPersonas* CrearColeccion(Persona* personas[], int cantidadPersonas){
	ColeccionPersonas* coleccion =new ColeccionPersonas;
	coleccion->personas = new Persona*[cantidadPersonas];
	for(int i=0; i<cantidadPersonas;++i){
		coleccion->personas = new Persona;
		coleccion->personas[i]->nombre  = personas[i]->nombre;
		coleccion->personas[i]->apellido = personas[i]->apellido;
	}
	coleccion->cantidad = cantidadPersonas;

	return coleccion;
}
*/

UsuarioRedSocial* CrearUsuario(string nombre, string apellido){
	UsuarioRedSocial* nuevoUsuario = new UsuarioRedSocial;
	nuevoUsuario->persona = CrearPersona(nombre, apellido);
	nuevoUsuario->amigos = CrearColeccionVacia();

	return nuevoUsuario;
}

UsuarioRedSocial* CrearUsuario(Persona* persona, ColeccionPersonas* amigos){
	UsuarioRedSocial* nuevoUsuario = new UsuarioRedSocial;
	nuevoUsuario->persona = persona;
	nuevoUsuario->amigos = amigos;
	return nuevoUsuario;
}

void Agregar(ColeccionPersonas* coleccion, Persona* persona){
	// reservar memoria
	Persona** personas = new Persona*[coleccion->cantidad + 1];
	// Copio lo de coleccion en mi variable auxiliar (personas)
	for(int i=0; i<coleccion->cantidad; ++i){
		personas[i] = coleccion->personas[i];
	}
	// agrego en mi variable auxiliar a persona
	personas[coleccion->cantidad] = persona;
	// Destruir el vector coleccion->personas
	delete []coleccion->personas;
	// Asignar mi variable auxiliar en coleccion
	coleccion->personas = personas;
	coleccion->cantidad++;
}

void Mostrar(Persona** personas, int cantidad){
	if (cantidad != 0){
		cout<<personas[0]->nombre<<", "<<personas[0]->apellido<<endl;
		Mostrar(personas+1,cantidad-1);
	}
}

void Destruir(Persona* persona){
	delete persona;
}

void Destruir(ColeccionPersonas* coleccion){
	delete []coleccion->personas;
}

void Destruir(UsuarioRedSocial* usuario){
	Destruir(usuario->persona);
	Destruir(usuario->amigos);

	delete usuario;
}