/**
 * @brief Clase plantilla para el árbol binario (AB).
 * 
 */

#ifndef AB_H_
#define AB_H_

#include <queue>
#include <iostream>

#include "NodoB.h"

/**
 * @class AB
 * @brief Clase plantila AB.
 * 
 * @tparam Key 
 */
template<class Key>
class AB {
  public:
    AB() : raiz_(NULL) {}

    ~AB() {
      this->podar(raiz_);
    } 

    // métodos virtuales
    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;

    // recorrido inorden
    void inorden() const;
    
    // recorrido por niveles
    std::ostream& operator>>(std::ostream& os);

  protected:
    NodoB<Key>* GetRaiz() const { return raiz_; }
    NodoB<Key>*& GetRaiz() { return raiz_; }
    void SetRaiz(NodoB<Key> *raiz) { raiz_ = raiz; } 

  private:
    // métodos privados de la clase AB
    void recorridoInorden(NodoB<Key> *nodo) const;
    void imprimeDato(Key dato) const;
    void podar(NodoB<Key>* nodo);

    NodoB<Key> *raiz_;  // puntero a la clase NodoB<Key>
};

/**
 * @brief Método para ir liberando la memoria a partir de un nodo  
 * 
 * @tparam Key
 * @param nodo
 */
template<class Key>
void AB<Key>::podar(NodoB<Key>* nodo) {
  if (nodo == NULL) return;
  podar(nodo->GetIzdo());  // podar subárbol izquierdo
  podar(nodo->GetDcho());  // podar subárbol derecho
  delete nodo;  // eliminar nodo
  nodo = NULL;  // puntero a nulo
}

/**
 * @brief Método para ir mostrando el árbol en inorden
 * 
 * @tparam Key
 */
template<class Key>
void AB<Key>::inorden() const {
  std::cout << "Mostrando el árbol binario en inorden" << std::endl;
  recorridoInorden(raiz_);
}

/**
 * @brief Método recursivo para ir mostrando el árbol en inorden
 * 
 * @tparam Key
 * @param nodo
 */
template <class Key>
void AB<Key>::recorridoInorden(NodoB<Key> *nodo) const {
  if (nodo == NULL) return;
  recorridoInorden(nodo->GetIzdo());
  imprimeDato(nodo->GetDato());
  recorridoInorden(nodo->GetDcho());    
}

/**
 * @brief Método para procesar un nodo
 * 
 * @tparam Key
 * @param dato
 */
template <class Key>
void AB<Key>::imprimeDato(Key dato) const {
  std::cout << dato << " ";
}

/**
 * @brief Método para procesar un nodo
 * 
 * @tparam Key
 * @param os
 * @return os
 */
template<class Key>
std::ostream& AB<Key>::operator>>(std::ostream& os) {
  // cola
  std::queue<std::pair<NodoB<Key>*, int>> Q;
  std::pair<NodoB<Key>*, int> aux_Q;
  NodoB<Key> *nodo;
  int level, current_level = 0;
  
  aux_Q.first = raiz_;
  aux_Q.second = 0;
  Q.push(aux_Q);
  std::cout << "Nivel 0:";  
  while (!Q.empty()) {
    aux_Q = Q.front();
    nodo = aux_Q.first;
    level = aux_Q.second;
    Q.pop();

    if(level > current_level) {
      current_level = level;
      std::cout << "\nNivel " << current_level << ":";  // nivel actual
    }  

    if(nodo != NULL) {      
      std::cout << "[" << nodo->GetDato() << "]";
      aux_Q.second = level + 1;
      aux_Q.first = nodo->GetIzdo();
      Q.push(aux_Q);
      aux_Q.first = nodo->GetDcho();
      Q.push(aux_Q);        
    }
    else {
      std::cout << "[.]";  // subárbol vacío
    }    
  }
  std::cout << std::endl;

  return os;
}

#endif  // AB_H_