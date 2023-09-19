#ifndef MAQUINA_DEL_TIEMPO_LINEADETIEMPO_H
#define MAQUINA_DEL_TIEMPO_LINEADETIEMPO_H
#include "vector"
using namespace std;

class LineaDeTiempo {
public:
    struct Node {
        Node* pasado;
        char cientifico;
        int numero;
        char evento;
        Node *futuro;

        Node(int valor): numero(valor), pasado(nullptr), futuro(nullptr) {}
    };
    Node* head;
    Node* cola;
    vector<char> listaDeEventos;
    vector<int> listaDeNumeros;

public:
    LineaDeTiempo();
    void agregarNodoAleatorio();
    void agregarNodo(int valor);
    char buscarCientifico();
    char buscarEvento(int numero,char cientifico);
    void imprimir();
    void imprimirEventos();
    int generarNumero(int rango);
    bool verificarPrimo(int n);
    bool verificarCoprimo(int n1,int n2);
    ~LineaDeTiempo();



};


#endif //MAQUINA_DEL_TIEMPO_LINEADETIEMPO_H
