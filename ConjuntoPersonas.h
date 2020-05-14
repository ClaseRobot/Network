#ifndef CONJUNTOPERSONAS_H_
#define CONJUNTOPERSONAS_H_

#include "Persona.h"
using UndavPersona::Persona;

namespace UndavConjuntoPersonas{
	struct ConjuntoPersonas;

	// Precondicion: Ninguna
	// Postcondicion: Crear un conjunto de personas vacio
	ConjuntoPersonas* Crear();

	// Precondicion: @conjunto y @persona son instancias validas
	// Postcondicion: Si @conjunto no contiene @persona lo agrega
	// Caso contrario no realiza ninguna accion.
	void Agregar(ConjuntoPersonas* conjunto, Persona* persona);

	// Precondicion: @conjunto y @persona son instancias validas
	// Postcondicion: Si @persona se encuentra en @conjunto devuelve true. Caso contrario devuelve false
	// Dos personas son iguales si tienen el mismo id
	bool Contiene(const ConjuntoPersonas* conjunto, const Persona* persona);

	// Precondicion: @conjunto es una instancia valida
	// Postcondicion: Devuelve la cantidad de personas que tiene @conjunto
	int CantidadPersonas(const ConjuntoPersonas* conjunto);

	// Precondicion: @conjunto es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @conjunto
	void Destruir(ConjuntoPersonas* conjunto);
}

#endif
