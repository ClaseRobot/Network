#include "Persona.h"
#include <string>

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

int GenerarId() {
    int i = 000000;
    return i;
}

Persona* CrearPersona(string nombre, string apellido) {
//Para el @id hacer: GenerarId() la cual dentro llamaria a una funcion que ObtenerUltimoId() y le sumaria 1 para generar un id unico
Persona* nuevaPersona = new Persona;
nuevaPersona->id = GenerarId();
nuevaPersona->nombre = nombre;
nuevaPersona->apellido = apellido;
nuevaPersona->cantidadAmigos = 0;

return nuevaPersona;
}

	
int ObtenerId(const Persona* persona) {
    return persona->id;
}

	
string ObtenerNombre(const Persona* persona) {
    return persona->nombre;
}

	
string CambiarNombre(Persona* persona, string nombre) {
        persona->nombre = nombre;
}

	
string ObtenerApellido(const Persona* persona) {
    return persona->apellido;
}

	
string CambiarApellido(Persona* persona, string apellido) {
    persona->apellido = apellido;
}

	
void AgregarAmigo(Persona* persona, Persona* amigo) {
    Persona** amigos = new Persona*[persona->cantidadAmigos + 1];
    for(int i = 0; i < persona->cantidadAmigos; ++i) {
        amigos[i] = persona->amigos[i];
    }
    amigos[persona->cantidadAmigos] = amigo;
    delete []persona->amigos;
    persona->amigos = amigos;
    persona->cantidadAmigos++;
}

	
int ObtenerCantidadAmigos(Persona* persona) {
    return persona->cantidadAmigos;
}

	
bool SonAmigos(const Persona* persona, Persona* otraPersona) {
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

	
string Serializar(const Persona* persona, TipoFormato formato) {
    string formatoSerializado;
    if (formato == Expresivo)
    {
        formatoSerializado = "["+to_string(persona->id)+"] "+persona->nombre+" "+persona->apellido+" tiene "+to_string(persona->cantidadAmigos)+" amigos.";
    } else if (formato == CSV)
    {
        formatoSerializado = to_string(persona->id)+","+persona->nombre+","+persona->apellido+","+to_string(persona->cantidadAmigos);
    }
    
    return formatoSerializado;
}

	
void Destruir(Persona* persona) {
    delete persona;
}