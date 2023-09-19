#include "LineaDeTiempo.h"
#include "iostream"
#include <random>

using namespace std;

LineaDeTiempo::LineaDeTiempo() {
    head = nullptr;
    cola = nullptr;
}

void LineaDeTiempo::agregarNodo(int n) {
    Node *nuevo = new Node(n);
    nuevo->cientifico = buscarCientifico();
    nuevo->evento = buscarEvento(n, nuevo->cientifico);

    if (!head) {
        head = nuevo;
    } else {
        Node *current = head;
        while (current->futuro != nullptr) {
            current = current->futuro;
        }
        current->futuro = nuevo;
        nuevo->pasado = current;
    }
}

void LineaDeTiempo::agregarNodoAleatorio() {
    agregarNodo(generarNumero(100));
}

char LineaDeTiempo::buscarEvento(int numero, char cientifico) {
    if (verificarPrimo(numero) || listaDeEventos.size() == 2) {
        if (cientifico == 'E' && listaDeEventos.empty()) {
            listaDeEventos.push_back('A');
            listaDeNumeros.push_back(numero);
            return 'A';
        } else if (listaDeEventos.size() == 1) {
            listaDeEventos.push_back('B');
            listaDeNumeros.push_back(numero);
            return 'B';
        } else if (listaDeEventos.size() == 2 && verificarCoprimo(numero, listaDeNumeros[0])) {
            if (verificarPrimo(numero)) {
                listaDeEventos.clear();
                listaDeNumeros.clear();
                return 'C';
            } else {
                listaDeEventos.clear();
                listaDeNumeros.clear();
                return 'c';
            }
        } else {
            return ' ';
        }
    } else {
        return ' ';
    }
}


char LineaDeTiempo::buscarCientifico() {
    int numero = generarNumero(2);
    return numero == 1 ? 'E' : 'R';
}

void LineaDeTiempo::imprimir() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->pasado << " " << current->numero << " " << current->cientifico << " " << current->evento
             << " " << current->futuro << endl;
        current = current->futuro;
    }
    cout << endl;
}

void LineaDeTiempo::imprimirEventos() {
    listaDeEventos.clear();
    Node *current = head;
    while (current) {
        if (current->evento != ' ') {
            string compartirDatos = current->evento == 'C' ? "Transferencia de Datos Exitosa" : "";
            compartirDatos = current->evento == 'c' ? "Transferencia de Datos Fallida" : compartirDatos;
            cout << "Sucedio un evento de tipo: " << current->evento << endl << "El cientifico que participo fue: "
                 << current->cientifico << endl << compartirDatos << endl;
            listaDeEventos.push_back(current->evento);
            listaDeNumeros.push_back(current->numero);
            int count = 0;
            Node *current2 = head;
            while (count != listaDeEventos.size()  && current2 != nullptr) {

                if (current2->numero == listaDeNumeros[count] && current2->evento == listaDeEventos[count]) {
                    cout << "|" << current2->numero << "|" << current2->cientifico << "|"
                         << current2->evento << "|";
                    if (current2->futuro != nullptr) {
                        cout << "--->";
                        count++;
                    }

                }

                current2 = current2->futuro;
            }

            cout << endl;
            cout << "-----------------" << endl;
        }
        if(listaDeEventos.size() == 3){
            listaDeEventos.clear();
            listaDeNumeros.clear();
        }
        current = current->futuro;
    }
}


int LineaDeTiempo::generarNumero(int rango) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, rango);
    return dis(gen);
}

LineaDeTiempo::~LineaDeTiempo() {

}

bool LineaDeTiempo::verificarPrimo(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool LineaDeTiempo::verificarCoprimo(int n1, int n2) {
    int mcd = 1;
    int a = n1;
    int b = n2;
    int r = 0;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    mcd = a;
    return mcd == 1;
}




