#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    struct nodo *derecho;
    struct nodo *izquierdo;
    int id;
}nodo;

typedef struct arbol{
    nodo *raiz;
}arbol;

void inicializarArbol(arbol **a){
    (*a)->raiz = NULL;
}

nodo *crearNodoArbol(int id){
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->id = id;
    nuevo->derecho = NULL;
    nuevo->izquierdo = NULL;
}

void insertarArbol(nodo **n, int id){
    if((*n) == NULL){
        (*n) = crearNodoArbol(id);
        return;
    }else{
        if((*n)->id >id){
            insertarArbol(&(*n)->izquierdo, id);
        }else if((*n)->id < id){
            insertarArbol(&(*n)->derecho, id);
        }else if((*n)->id == id){
            printf("El dato ya existe en el arbol\n");
        }
    }
}

void recorridoInOrden(nodo *padre){
    if(padre != NULL){
        recorridoInOrden(padre->izquierdo);
        printf("%i ", padre->id);
        recorridoInOrden(padre->derecho);
    }
}

void recorridoPreOrden(nodo *padre){
    if(padre != NULL){
        printf("%i ", padre->id);
        recorridoPreOrden(padre->izquierdo);
        recorridoPreOrden(padre->derecho);
    }
}

void recorridoPostOrden(nodo *padre){
    if(padre != NULL){
        recorridoPostOrden(padre->izquierdo);
        recorridoPostOrden(padre->derecho);
        printf("%i ", padre->id);
    }
}



int main()
{
    arbol *a = (arbol*) malloc(sizeof(arbol));
    inicializarArbol(&a);
    insertarArbol(&(a->raiz), 2);
    insertarArbol(&(a->raiz), 0);
    insertarArbol(&(a->raiz), 1);
    insertarArbol(&(a->raiz), 6);
    insertarArbol(&(a->raiz), 0);
    insertarArbol(&(a->raiz), 2);
    insertarArbol(&(a->raiz), 4);
    insertarArbol(&(a->raiz), 3);
    insertarArbol(&(a->raiz), 4);





    return 0;
}