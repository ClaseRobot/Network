#include "Persona.h"
#include <string>
#include <stdlib.h>
#include <ctime>

using std::string;
using std::to_string;

using namespace UndavPersona;

struct UndavPersona::Persona{
    int id;
    string nombre;
    string apellido;
    int cantidadAmigos;
    Persona** amigos;
};



int GenerarId(string nombre) {
    srand(time(NULL));
    int largoNombre = nombre.length();
    int id = largoNombre * (1 + rand() % (500 - 1));    

    return id;
}

Persona* UndavPersona::CrearPersona(string nombre, string apellido) {
Persona* nuevaPersona = new Persona;
nuevaPersona->id = GenerarId(nombre);
nuevaPersona->nombre = nombre;
nuevaPersona->apellido = apellido;
nuevaPersona->cantidadAmigos = 0;

return nuevaPersona;
}

	
int UndavPersona::ObtenerId(const Persona* persona) {
    return persona->id;
}

	
string UndavPersona::ObtenerNombre(const Persona* persona) {
    return persona->nombre;
}

	
string UndavPersona::CambiarNombre(Persona* persona, string nombre) {
        persona->nombre = nombre;
}

	
string UndavPersona::ObtenerApellido(const Persona* persona) {
    return persona->apellido;
}

	
string UndavPersona::CambiarApellido(Persona* persona, string apellido) {
    persona->apellido = apellido;
}

	
void UndavPersona::AgregarAmigo(Persona* persona, Persona* amigo) {
    Persona** amigos = new Persona*[persona->cantidadAmigos + 1];
    for(int i = 0; i < persona->cantidadAmigos; ++i) {
        amigos[i] = persona->amigos[i];
    }
    amigos[persona->cantidadAmigos] = amigo;
    delete []persona->amigos;
    persona->amigos = amigos;
    persona->cantidadAmigos++;
}

	
int UndavPersona::ObtenerCantidadAmigos(Persona* persona) {
    return persona->cantidadAmigos;
}

	
bool UndavPersona::SonAmigos(const Persona* persona, Persona* otraPersona) {
    int i = 0;
    while (persona->amigos[i]->id != otraPersona->id)
    {
        i++;
    }

    if (i == persona->cantidadAmigos + 1)
    {
        return false;
    }
    
    return true;
}

	
string UndavPersona::Serializar(const Persona* persona, TipoFormato formato) {
    string formatoSerializado;
    if (formato == Expresivo)
    {
        formatoSerializado = "[" + to_string(persona->id) + "] " + persona->nombre + " " + persona->apellido + " tiene " + to_string(persona->cantidadAmigos) + " amigos.";
    } else if (formato == CSV)
    {
        formatoSerializado = to_string(persona->id) + "," + persona->nombre + "," + persona->apellido + "," + to_string(persona->cantidadAmigos);
    }
    
    return formatoSerializado;
}

	
void UndavPersona::Destruir(Persona* persona) {
    delete persona;
}