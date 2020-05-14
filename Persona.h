#ifndef PERSONA_H_
#define PERSONA_H_

#include "TipoFormato.h"
#include <string>

using std::string;

namespace UndavPersona{
	struct Persona;

	// Precondicion: Ninguna
	// Postcondicion: Crea una instancia valida de persona con @nombre nombre, apellido @apellido
	// con un identificador entero unico (id) y que no tiene amigos
	Persona* CrearPersona(string nombre, string apellido);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve el identificador unico de @persona
	int ObtenerId(const Persona* persona);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve el nombre de @persona
	string ObtenerNombre(const Persona* persona);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Cambia el nombre de @persona por @nombre
	string CambiarNombre(Persona* persona, string nombre);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve el apellido de @persona
	string ObtenerApellido(const Persona* persona);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Cambia el apellido de @persona por @apellido
	string CambiarApellido(Persona* persona, string apellido);

	// Precondicion: @persona y @amigos son instancias validas
	// Postcondicion: Si @amigo y @persona son iguales o @amigo ya es una amigo entonces no realiza ninguna accion
	// Caso contrario agrega @amigo como amigo de @persona
	// Dos personas son iguales si tienen el mismo identificador.
	void AgregarAmigo(Persona* persona, Persona* amigo);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve la cantidad de amigos de  @persona
	int ObtenerCantidadAmigos(Persona* persona);

	// Precondicion: @persona y @otraPersona son instancias validas
	// Postcondicion: Devuelve true si @persona es amigo de @otraPersona
	bool SonAmigos(const Persona* persona, Persona* otraPersona);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve un string que representa a persona segun @formato
	// Si @formato es Expresivo, devuelve un string en el siguiente formato: [@ID] @nombre @Apellido tiene @CantidadAmigos amigos
	// Si @formato es CSV, devuelve un string en el siguiente formato: @ID,@nombre,@Apellido,@CantidadAmigos
	// donde @CantidadAmigos es la cantidad de amigos de @persona
	string Serializar(const Persona* persona, TipoFormato formato);

	// Precondicion: @persona es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @persona
	void Destruir(Persona* persona);
}

#endif
