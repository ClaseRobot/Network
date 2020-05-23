#include "ConjuntoPersonas.h"
#include "Persona.h"

using namespace UndavConjuntoPersonas;
using namespace UndavPersona;

struct UndavConjuntoPersonas::ConjuntoPersonas {
    int cantidad;
    UndavPersona::Persona** personas;
};

	
ConjuntoPersonas* Crear() {
    ConjuntoPersonas* conjunto = new ConjuntoPersonas;
    conjunto->cantidad = 0;

    return conjunto;
}

	
void Agregar(ConjuntoPersonas* conjunto, Persona* persona) {
    Persona** personas = new Persona*[conjunto->cantidad + 1];
    for (int i=0; i<conjunto->cantidad; ++i)
    {
        personas[i] = conjunto->personas[i];
    }

    personas[conjunto->cantidad] = persona;
    
    delete []conjunto->personas;
    conjunto->personas = personas;
    conjunto->cantidad++;   
}

	
bool Contiene(const ConjuntoPersonas* conjunto, const Persona* persona) {
    int i = 0;
    while (conjunto->personas[i]->id != persona->id)
    {
        i++;
    }
    if (i == conjunto->cantidad + 1)
    {
        return false;
    }
    return true;
}

	
int CantidadPersonas(const ConjuntoPersonas* conjunto) {
    return conjunto->cantidad;
}

	
void Destruir(ConjuntoPersonas* conjunto) {
    delete []conjunto->personas;
}