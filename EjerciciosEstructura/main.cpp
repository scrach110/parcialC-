#include <iostream>

using namespace std;


int main()
{

    struct datosPersona
    {
        string nombre;
        char inicial;
        int edad;
        float nota;
    };

    datosPersona *persona = new datosPersona;
/*
    for (int i=0; i<5; i++)
    {
        cout << "Dime el nombre de la persona"<< i << endl;
        cin >> persona[i].nombre;
    }

    cout << "la persona 3 es" << persona[2].nombre << endl;
    */
    persona -> nombre = "Juan";
    persona -> inicial = 'J';
    persona -> edad = 24;
    persona -> nota = 10;
    cout << "Se llama" << persona -> nombre << endl;
    cout << "la edad" << "" << (*persona).edad << endl;

    delete persona;




/*
    struct duracion {
        int minutos;
        int segundos;
    };

    struct MP3
    {
            string artista;
            string titulo;
            struct duracion duracionCancion;
            float tamanoFichero;
    };

    MP3 *cancion = new MP3[100];

void crearCancion(string artista, string titulo, duracion minuto, duracion segundos,  float tamanoFichero) {
    cancion c = new cancion;
    c-> c.artista = artista;
    c-> c.titulo = titulo;
    c-> c.duracionCancion.minutos = minuto;
    c-> c.duracionCancion.segundos = segundos;
    c-> c.tamanoFichero = tamanoFichero;
    delete c;

};

    for (int i=0; i<1; i++)
    {
        cout << "Dime el artista de la cancion"<< i << endl;
        cin >> cancion[i].artista;
        cout << "dime el titulo" << i << endl;
        cin >> cancion[i].titulo;
        cout << "dime los minutos que dura la cancion" << i << endl;
        cin >> cancion[1].duracionCancion.minutos;
        cout << "dime los segundos que dura la cancion" << i << endl;
        cin >> cancion[i].duracionCancion.segundos;
        cout << "dime el tamaño" << i << endl;
        cin >> cancion[i].tamanoFichero;

        crearCancion(cancion[i].artista, cancion[i].titulo, cancion[1].duracionCancion.minutos,cancion[i].duracionCancion.segundos,
                       cancion[i].tamanoFichero);
    }

/*

    cin>> cancion.artista;
    cin>> cancion.titulo;
    cin>> cancion.duracion;
    cin>> cancion.tamanoFichero;
    */
/*
    cout<< "la cancion del artista 2 es" << " "  << cancion[1].artista << endl;
    cout<< "el titulo del artista 4 es" << " " << cancion[1].titulo << endl;
    cout<< "duracion del artista 3" << " " << cancion[2].duracionCancion.minutos << endl;
    cout<< "el tamaño del 1 es" << " " << cancion[0].tamanoFichero << endl;
*/
    return 0;
}
