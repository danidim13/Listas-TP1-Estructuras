#include <iostream>
#include <limits>
#include <string>
#include <sstream>



/* Para cambiar la implementación de los modelos
 * descomente la línea apropiada
 */
//#include "include/Listas_LDE.h"
//#include "include/Listas_LSE.h"
#include "include/Listas_Arreglo.h"


using namespace std;

/****************************/
/* Declaracion de funciones */
/****************************/

void MenuPrincipal();
void MenuListaPos();
void MenuListaIndex();
void MenuListaOrd();
void MenuPila();

template<typename E>
void ImprimirLista(ListaPos<E> *L);
template<typename E>
typename ListaPos<E>::pos_t BuscarPos(E elem, ListaPos<E> *L);

int LeerInt();
string LeerStr();
void Esperar();

/**********************/
/* Programa principal */
/**********************/

int main(int argc, char *argv[]) {

	MenuPrincipal();

	/*
	ListaPos<int> L;

	cout << L.NumElem() << endl;
	L.AgregarAlFinal(5);
	L.Insertar(L.Ultima(), -1);
	L.Insertar(L.Ultima(), 10);
	L.Insertar(L.Primera(), 69);
	L.Insertar(L.Primera(), 7);
	cout << L.NumElem() << endl;

	cout << "Recorrido desde el primero" << endl;
	ListaPos<int>::pos_t pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	cout << endl;

	cout << "Agregando un elemento en el medio de la lista" << endl;
	pos = L.Siguiente(L.Siguiente(L.Primera()));
	L.Insertar(pos, 666);
	cout << L.NumElem() << endl;

	cout << "Recorrido desde el primero" << endl;
	pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	cout << endl;

	cout << "Ahora borramos una posicion..." << endl;

	pos = L.Primera();
	pos = L.Siguiente(L.Siguiente(pos));
	//pos = L.Ultima();
	cout << "Borrando " << L.Recuperar(pos) << endl;
	cout << endl;
	L.Borrar(pos);
	cout << L.NumElem() << endl;


	cout << "Recorrido desde el primero" << endl;
	pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;

	int i = 0;
	if (i)
		cout << "null no es igual a 0!" << endl;
	if (!i)
		cout << "null es igual a 0!" << endl;

	*/
	return 0;
}

/****************************/
/* Funciones para los Menus */
/****************************/

void MenuPrincipal() {
	bool exit = false;
	cout << "Bienvenido a este Programa" << endl;
	cout << endl;

	int op_lista;
	while (!exit) {
		cout << "¿Qué tipo de lista desea usar?" << endl;
		cout << "\t1 - Lista Posicionada" << endl;
		cout << "\t2 - Lista Indexada" << endl;
		cout << "\t3 - Lista Ordenada" << endl;
		cout << "\t4 - Pila" << endl;
		cout << "\t5 - Salir" << endl;
		op_lista = LeerInt();
		switch (op_lista) {
			case 1:
				MenuListaPos();
				break;
			case 2:
				MenuListaIndex();
				break;
			case 3:
				MenuListaOrd();
				break;
			case 4:
				MenuPila();
				break;
			case 5:
				exit = true;
				break;
			default:
				cout << "Debe indicar un número del 1 al 5" << endl;
		}
	}
	cout << "Saliendo del programa" << endl;
}

void MenuListaPos(){
	cout << "Usted escogio la Lista Posicionada" << endl;
	ListaPos<string> *L = nullptr;
	bool continuar = true;
	int opcion;
	while(continuar){
		cout << "¿Qué acción desea realizar?" << endl;
		cout << "\t0 - Imprimir Lista" << endl;
		cout << "\t1 - Iniciar" << endl;
		cout << "\t2 - Destruir" << endl;
		cout << "\t3 - Vacía" << endl;
		cout << "\t4 - Vaciar" << endl;
		cout << "\t5 - Primera" << endl;
		cout << "\t6 - Ultima" << endl;
		cout << "\t7 - Siguiente" << endl;
		cout << "\t8 - Anterior" << endl;
		cout << "\t9 - Recuperar" << endl;
		cout << "\t10 - Insertar" << endl;
		cout << "\t11 - AgregarAlFinal" << endl;
		cout << "\t12 - Borrar" << endl;
		cout << "\t13 - ModificarElem" << endl;
		cout << "\t14 - Intercambiar" << endl;
		cout << "\t15 - NumElem" << endl;
		cout << "\t16 - Salir" << endl;
		
		opcion = LeerInt();
		string s;
		ListaPos<string>::pos_t p;
		ListaPos<string>::pos_t p2;

		if (!L && (opcion != 1 && opcion != 16)) {
			cout << "Debe inicializar la lista primero!" << endl;
			Esperar();
			continue;
		}

		switch (opcion) {
			case 0:
				ImprimirLista(L);
				Esperar();
				break;
			case 1:
				cout << "Iniciando la lista!" << endl;
				if (!L)
					L = new ListaPos<string>();
				Esperar();
				break;
			case 2:
				cout << "Destruyendo la lista!" << endl;
				if (L)
					delete L;
				L = nullptr;
				Esperar();
				break;
			case 3:
				if (L->Vacia())
					cout << "La lista está vacía." << endl;
				else
					cout << "La lista no está vacía." << endl;
				Esperar();
				break;
			case 4:
				cout << "Vaciando la lista..." << endl;
				L->Vaciar();
				Esperar();
				break;
			case 5:
				p = L->Primera();
				if(!p){
					cout << "La posición del primer elemento es: pos_nula" << p << endl;
					break;
				}
				cout << "La posición del primer elemento es: " << p << endl;
				cout << "El primer elemento es: " << L->Recuperar(L->Primera()) << endl;
				Esperar();
				break;
			case 6:
				p = L->Ultima();
				if(!p){
					cout << "La posición del último elemento es: pos_nula" << p << endl;
					break;
				}
				cout << "La posición del último elemento es: " << p << endl;
				cout << "El último elemento es: " << L->Recuperar(L->Ultima()) << endl;
				Esperar();
				break;
			case 7:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				p = L->Siguiente(p);
				if(!p){
					cout << "La posición siguiente es pos_nula." << endl;
				} else {
					cout << "La posición siguiente es: " << p << endl;
					cout << "El elemento siguiente es: " << L->Recuperar(p) << endl;
				}
				Esperar();
				break;
			case 8:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				p = L->Anterior(p);
				if(!p){
					cout << "La posición anterior es pos_nula." << endl;
				} else {
					cout << "La posición anterior es: " << p << endl;
					cout << "El elemento anterior es: " << L->Recuperar(p) << endl;
				}
				Esperar();
				break;
			case 9:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				cout << "El elemento es: " << L->Recuperar(p) << endl;
				Esperar();
				break;
			case 10:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				cout << "Indique un elemento para insertar." << endl;
				s = LeerStr();
				L->Insertar(p, s);
				Esperar();
				break;
			case 11:
				cout << "Indique un elemento para insertar." << endl;
				s = LeerStr();
				L->AgregarAlFinal(s);
				Esperar();
				break;
			case 12:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				L->Borrar(p);
				Esperar();
				break;
			case 13:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				cout << "Indique otro nuevo elemento para modificarlo." << endl;
				s = LeerStr();
				L->ModificarElem(p, s);
				Esperar();
				break;
			case 14:
				cout << "Indique un elemento de la lista." << endl;
				s = LeerStr();
				p = BuscarPos(s, L);
				cout << "Indique otro elemento de la lista." << endl;
				s = LeerStr();
				p2 = BuscarPos(s, L);
				cout << "Intercambiando " << L->Recuperar(p) << " y " << L->Recuperar(p2) << endl;
				L->Intercambiar(p, p2);
				Esperar();
				break;
			case 15:
				cout << "La lista tiene " << L->NumElem() << " elementos." << endl;
				Esperar();
				break;
			case 16:
				cout << "Volviendo al menu principal." << endl;
				continuar = false;
				Esperar();
				break;
			default:
				cout << "Por favor indique un numero del 0 al 16." << endl;
				Esperar();
				break;
		}
	}
	if (L) {
		delete L;
		L = nullptr;
	}
}

void MenuListaIndex(){
	cout << "Usted escogio la Lista Indexada" << endl;
	ListaIndex<string> *L = nullptr;
    //LIndexLSE<int> L;
    bool continuar = true;
	int opcion;
	while(continuar){
		cout << "¿Qué acción desea realizar?" << endl;
		cout << "\t0 - Imprimir Lista" << endl;
		cout << "\t1 - Iniciar" << endl;
		cout << "\t2 - Destruir" << endl;
		cout << "\t3 - Vacía" << endl;
		cout << "\t4 - Vaciar" << endl;;
		cout << "\t5 - Recuperar" << endl;
		cout << "\t6 - Insertar" << endl;
		cout << "\t7 - Borrar" << endl;
		cout << "\t8 - ModificarElem" << endl;
		cout << "\t9 - Intercambiar" << endl;
		cout << "\t10 - NumElem" << endl;
		cout << "\t11 - Salir" << endl;

		cin >> opcion;
		string s;
        int i, i2;

		if (!L && (opcion != 1 && opcion != 11)) {
			cout << "Debe inicializar la lista primero!" << endl;
			Esperar();
			continue;
		}

		switch (opcion) {
			case 0:
				L->Imprimir();
				break;
			case 1:
				cout << "Iniciando la lista!" << endl;
				L = new ListaIndex<string>();
				Esperar();
				break;
			case 2:
				cout << "Destruyendo la lista!" << endl;
				if (L)
					delete L;
				L = nullptr;
				Esperar();
				break;
			case 3:
				if (L->Vacia())
					cout << "La lista está vacía." << endl;
				else
					cout << "La lista no está vacía." << endl;
				Esperar();
				break;
			case 4:
				cout << "Vaciando la lista..." << endl;
				L->Vaciar();
				Esperar();
				break;
			case 5:
				cout << "Indique un índice de la lista." << endl;
				i = LeerInt();
				cout << "El elemento es: " << L->Recuperar(i) << endl;
				Esperar();
				break;
			case 6:
				cout << "Indique un indice de la lista." << endl;
				i = LeerInt();
				cout << "Indique un elemento para insertar." << endl;
				s = LeerStr();
				L->Insertar(i, s);
				Esperar();
				break;
			case 7:
				cout << "Indique un indice de la lista." << endl;
				i = LeerInt();
				L->Borrar(i);
				Esperar();
				break;
			case 8:
				cout << "Indique un indice de la lista." << endl;
				i = LeerInt();
				cout << "Indique un elemento para modificarlo." << endl;
				s = LeerInt();
				L->ModificarElem(i, s);
				Esperar();
				break;
			case 9:
				cout << "Indique un indice de la lista." << endl;
				i = LeerInt();
				cout << "Indique otro indice de la lista." << endl;
				i2 = LeerInt();
				cout << "Intercambiando " << L->Recuperar(i) << " y " << L->Recuperar(i2) << endl;
				L->Intercambiar(i, i2);
				Esperar();
				break;
			case 10:
				cout << "La lista tiene " << L->NumElem() << " elementos." << endl;
				Esperar();
				break;
			case 11:
				cout << "Volviendo al menu principal." << endl;
				continuar = false;
				Esperar();
				break;
			default:
				cout << "Por favor indique un numero del 0 al 16." << endl;
				Esperar();
				break;
		}
	}
}

void MenuListaOrd(){
	cout << "Usted escogio la Lista Ordenada" << endl;
    ListaOrdenada<string> *L = nullptr;
    //ListaOrdenadaLSE<int> L;
    bool continuar = true;
    int opcion;
    while(continuar)
    {
        cout<< "¿Qué acción desea realizar?" <<endl;
        cout<< "\t0 - Imprimir Lista" <<endl;
        cout<< "\t1 - Iniciar" <<endl;
        cout<< "\t2 - Destruir" <<endl;
        cout<< "\t3 - Vacía" <<endl;
        cout<< "\t4 - Vaciar" <<endl;
        cout<< "\t5 - Insertar" <<endl;
        cout<< "\t6 - Borrar" <<endl;
        cout<< "\t7 - NumElem" <<endl;
        cout<< "\t8 - Primero" <<endl;
        cout<< "\t9 - Ultimo" <<endl;
        cout<< "\t10 - Siguiente" <<endl;
        cout<< "\t11 - Anterior" <<endl;
        cout<< "\t12 - Salir" <<endl;

        cin >> opcion;
        string s;
        string i;

		if (!L && (opcion != 1 && opcion != 12)) {
			cout << "Debe inicializar la lista primero!" << endl;
			Esperar();
			continue;
		}

        switch(opcion)
        {
        case 0:
            L->Imprimir();
            break;
        case 1:
            cout << "Iniciando la lista!" << endl;
			L = new ListaOrdenada<string>();

            Esperar();
            break;
        case 2:
            cout << "Destruyendo la lista!" << endl;
			if (L)
				delete L;
            //L->Destruir();
            L = NULL;
            Esperar();
            break;
        case 3:
            if (L->Vacia())
                cout << "La lista está vacía." << endl;
            else
                cout << "La lista no está vacía." << endl;
            Esperar();
            break;
        case 4:
            cout << "Vaciando la lista..." << endl;
            L->Vaciar();
            Esperar();
            break;
        case 5:
            cout << "Indique un elemento para insertar." << endl;
			s = LeerStr();
            L->Insertar(s);
            Esperar();
            break;
        case 6:
            cout << "Indique un elemento de la lista para borrar." << endl;
            s = LeerStr();
            L->Borrar(s);
            Esperar();
            break;
        case 7:
            cout << "La lista tiene " << L->NumElem() << " elementos." << endl;
            Esperar();
            break;
        case 8:
            if(L->Vacia())
                cout << "No hay primer elemento" << endl;
			else
				cout << "El primer elemento es: " << L->Primero() << endl;
            Esperar();
            break;
        case 9:
			if(L->Vacia())
				cout << "No hay ultimo elemento" << endl;
			else
				cout << "El último elemento es: " << L->Ultimo() << endl;
            Esperar();
            break;
        case 10:
            cout << "Indique un elemento de la lista." << endl;
			s = LeerStr();
            if(L->Ultimo()== s)
                cout << "No hay posición siguiente." << endl;
            else
                cout << "El elemento siguiente es: " << L->Siguiente(s) << endl;
            Esperar();
            break;
        case 11:
            cout << "Indique un elemento de la lista." << endl;
            s = LeerStr();
            if(L->Primero() == s)
                cout << "No hay posición anterior." << endl;
            else
                cout << "El elemento anterior es: " << L->Anterior(s) << endl;
            Esperar();
            break;
        case 15:
            cout << "La lista tiene " << L->NumElem() << " elementos." << endl;
            Esperar();
            break;
        case 12:
            cout << "Volviendo al menu principal." << endl;
            continuar = false;
            Esperar();
            break;
        default:
            cout << "Por favor indique un numero del 0 al 16." << endl;
            Esperar();
            break;
        }


    }
}

void MenuPila(){
	cout << "Usted escogio la Pila" << endl;

	Pila<string> *P = nullptr;
	bool continuar = true;
	int opcion;
	while(continuar){
		cout << "¿Qué acción desea realizar?" << endl;
		cout << "\t0 - Imprimir Pila" << endl;
		cout << "\t1 - Iniciar" << endl;
		cout << "\t2 - Destruir" << endl;
		cout << "\t3 - Vacía" << endl;
		cout << "\t4 - Vaciar" << endl;
		cout << "\t5 - Meter" << endl;
		cout << "\t6 - Sacar" << endl;
		cout << "\t7 - Tope" << endl;
		cout << "\t8 - NumElem" << endl;
		cout << "\t9 - Salir" << endl;
		
		opcion = LeerInt();
		string s;

		if (!P && (opcion != 1 && opcion != 9 )) {
			cout << "Debe inicializar la pila primero!" << endl;
			Esperar();
			continue;
		}

		//Pila<string>::pos_t p;
		switch (opcion) {
			case 0:
				P->Imprimir();
				Esperar();
				break;
			case 1:
				cout << "Iniciando la pila!" << endl;
				P = new Pila<string>();
				Esperar();
				break;
			case 2:
				cout << "Destruyendo la pila!" << endl;
				if (P)
					delete P;
				P = nullptr;
				Esperar();
				break;
			case 3:
				if (P->Vacia())
					cout << "La pila está vacía." << endl;
				else
					cout << "La pila no está vacía." << endl;
				Esperar();
				break;
			case 4:
				cout << "Vaciando la pila..." << endl;
				P->Vaciar();
				Esperar();
				break;
			case 5:
				cout << "Indique un elemento para insertar." << endl;
				s = LeerStr();
				P->Meter(s);
				Esperar();
				break;
			case 6:
				cout << "Sacando el tope de la pila: " << P->Tope() << endl;
				P->Sacar();
				Esperar();
				break;
			case 7:
				cout << "El elemento al tope de la pila es: " << P->Tope() << endl;
				Esperar();
				break;
			case 8:
				cout << "La pila tiene " << P->NumElem() << " elementos." << endl;
				Esperar();
				break;
			case 9:
				cout << "Volviendo al menu principal." << endl;
				continuar = false;
				Esperar();
				break;
			default:
				cout << "Por favor indique un numero del 0 al 9." << endl;
				Esperar();
				break;
		}
	}
	if (P) {
		delete P;
		P = nullptr;
	}
}
/***********************************/
/* Utilidades para usar las listas */
/***********************************/

template<typename E>
void ImprimirLista(ListaPos<E> *L){
	if (!L) {
		cout << "Lista no inicializada" << endl;
		return;
	}
	typename ListaPos<E>::pos_t pos = L->Primera();
	if (!pos) {
		cout << "Lista vacía" << endl;
		return;
	}
	cout << "Recorrido desde el primero" << endl;
	while (pos) {
		cout << L->Recuperar(pos) << " ";
		pos = L->Siguiente(pos);
	}
	cout << endl;
}

template<typename E>
typename ListaPos<E>::pos_t BuscarPos(E elem, ListaPos<E> *L){
	typename ListaPos<E>::pos_t p = L->Primera();
	while(p) {
		if (elem == L->Recuperar(p))
			break;
		p = L->Siguiente(p);
	}
	return p;
}

/*******************************/
/* Utilidades para leer de cin */
/*******************************/

int LeerInt(){
	int opcion;
	while (true) {
		cin >> opcion;
		if (!cin.fail()) {
			break;
		} else {
			cout << "Por favor indique un numero entero" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return opcion;
}

string LeerStr(){
	string opcion;
	while (true) {
		cin >> opcion;
		if (!cin.fail()) {
			break;
		} else {
			cout << "Error, intente de nuevo" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return opcion;
}

void Esperar(){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	cout << "Presione ENTER para continuar..." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
}
