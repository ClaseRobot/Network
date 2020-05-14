#include "Persona.h"
#include <string>

using std::string;

using namespace UndavPersona;

struct UndavPersona::Persona{
    int id;
    string nombre;
    string apellido;
    int cantidadAmigos;
    // Persona* amigos[8];
};

Persona* CrearPersona(string nombre, string apellido) {
//Para el @id hacer: GenerarId() la cual dentro llamaria a una funcion que ObtenerUltimoId() y le sumaria 1 para generar un id unico
Persona* nuevaPersona = new Persona;
nuevaPersona->id = GenerarId();
nuevaPersona->nombre = nombre;
nuevaPersona->apellido = apellido;
nuevaPersona->cantidadAmigos = 0;
// nuevaPersona->amigos = new amigos[];

return nuevaPersona;
}

	
int ObtenerId(const Persona* persona) {
    return persona->id;
}

	
string ObtenerNombre(const Persona* persona) {
    return persona->nombre;
}

	
string CambiarNombre(Persona* persona, string nombre) {
    
}

	
string ObtenerApellido(const Persona* persona) {
    return persona->apellido;
}

	
string CambiarApellido(Persona* persona, string apellido) {

}

	
void AgregarAmigo(Persona* persona, Persona* amigo) {

}

	
int ObtenerCantidadAmigos(Persona* persona) {
    return persona->cantidadAmigos;
}

	
bool SonAmigos(const Persona* persona, Persona* otraPersona) {

}

	
string Serializar(const Persona* persona, TipoFormato formato) {

}

	
void Destruir(Persona* persona) {
    delete persona;
}