#include <iostream>
using namespace std;

struct nodo {
    int proceso;
    int prioridad;
    nodo* sig;
};

struct listacircular {
    int proceso;
    int prioridad;
    
    listacircular* sig;
} *cabeza, *cola;

struct Arbol {
	int valor;
	int prioridad;
	
	Arbol* der;
	Arbol* izq;
	
	Arbol(int valor, int prioridad): valor (valor), prioridad (prioridad), izq (NULL, NULL), der (NULL, NULL) {}
};

nodo* pila = NULL;

void inser_proc();
void mostrar_lista();
void procesar();
void duplicarEnLC();
void duplicarEnArbol();

int main() {
    int menu_prin = 0;

    while (menu_prin != 3) {

        cout << "\n\nIngrese el numero correspondiente a la accion que desea realizar: \n\n";
        cout << "1). Crear una nueva lista de procesos.\n";
        cout << "2). Mostrar listas creadas.\n";
        cout << "3). Salir del programa.\n\n";

        cin >> menu_prin;

        switch (menu_prin) {

            case 1:
                inser_proc();
                break;

            case 2:
                procesar();
                break;

            case 3:
                cout << "\nPrograma terminado.\n\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n\n";
                break;
        }
    }

    return 0;
}

void inser_proc() {
    nodo* nuevo = new nodo();
    cout << "Ingrese el numero correspondiente al proceso (Ingrese 0 en prioridad para terminar la lista): ";
    cin >> nuevo->proceso;

    cout << "Ingrese la prioridad de este proceso: ";
    cin >> nuevo->prioridad;

	while (nuevo->prioridad != 0){
	
    	if (pila == NULL || nuevo->prioridad > pila->prioridad) {
        	nuevo->sig = pila;
        	pila = nuevo;
    	} else {
        	nodo* temp = pila;

        	while (temp->sig != NULL && nuevo->prioridad <= temp->sig->prioridad) {
            	temp = temp->sig;
        	}
	    cout << "\n\nNumero ingresado a la lista.\n\n";
        nuevo->sig = temp->sig;
        temp->sig = nuevo;
		}
	}
	duplicarEnLC();
	duplicarEnArbol();
}

void duplicarEnLC(){
	nodo* actual = pila;
	listacircular* nuevo = new listacircular();
	
	nuevo->prioridad = actual->prioridad;
	nuevo->proceso = actual->proceso;

	
	while (actual != NULL) {

        if (cabeza == NULL) {
        	
       		cabeza = nuevo;
    	    cabeza->sig = cabeza;
       		cola = nuevo; 
    	} else {
        	
        	cola->sig = nuevo;
			nuevo->sig = cabeza;
			cola = nuevo;
        	
    	}
    
    actual = actual->sig;
    
    nuevo->prioridad = actual->prioridad;
	nuevo->proceso = actual->proceso;
    
	}
	
}

void duplicarEnArbol(){

	nodo* actual = pila;
	Arbol* nuevo = new Arbol();
	
	nuevo->prioridad = actual->prioridad;
	nuevo->valor = actual->proceso;

	class arbol{
	
	private:
		Arbol* raiz;

	public:

		void insert(int valor, int prioridad) {
		
    		if (raiz == NULL) {
        	
				raiz = new Arbol(valor, prioridad);
    		} else {
        
				resurInsert(raiz, valor, prioridad);
    		}
		}
	
	
	Arbol* resurInsert(Arbol* actual, int valor, int prioridad) {
    	
		if (actual == NULL){
		
			return new Arbol(valor, prioridad);
		} else if (valor < actual->valor) {
        	
			actual->izq = resurInsert(actual->izq, valor, prioridad);
    	} else if (valor > actual->valor) {
        	
			actual->der = resurInsert(actual->der, valor, prioridad);
    	} else if (valor == actual->valor) {
		
			cout << "Este numero ya fue ingresado. No se permiten duplicados";
			return actual;
		} else {
		
			cout << "\n\nNo se ha ingresado el valor puesto que es menor o mayor a los ya ingresados en la hilera de hijos #2. \n\n"; 
			return actual;
	    }

	    return actual;

	}
	
};
	
}


void mostrar_lista() {
    nodo* actual = pila;

    if (actual != NULL) {
        cout << "Proceso | Prioridad" << endl;

        while (actual != NULL) {
            cout << "   " << actual->proceso << "  |  " << actual->prioridad << endl;
            actual = actual->sig;
        }
    } else {
        cout << "\n\nNo ha insertado ningun numero aun.\n\n";
    }
}
