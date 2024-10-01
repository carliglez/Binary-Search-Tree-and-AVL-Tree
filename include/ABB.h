/**
 * @brief Clase plantilla para el árbol binario de búsqueda (ABB).
 * 
 */

#ifndef ABB_H_
#define ABB_H_

#include "AB.h"

/**
 * @class ABB
 * @brief Clase plantila ABB.
 * 
 * @tparam Key 
 */
template<class Key>
class ABB : public AB<Key> {
  public:
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
  
  protected:
    bool insertarRama(NodoB<Key>* nodo, Key clave_dada);
    bool buscarRama(NodoB<Key>* nodo, Key clave_dada) const; 
};

/**
 * @brief Método para insertar una clave en el árbol binario de búsqueda
 * 
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template<class Key>
bool ABB<Key>::insertar(const Key& k) {
  if (this->GetRaiz() == NULL) {
    this->SetRaiz(new NodoB<Key>(k, NULL, NULL));
    return true;
  }
  return insertarRama(this->GetRaiz(), k);
}

/**
 * @brief Método para insertar una clave en el árbol binario de búsqueda de forma recursiva
 * 
 * @tparam Key
 * @param nodo
 * @param clave_dada
 * @return true
 * @return false
 */
template<class Key>
bool ABB<Key>::insertarRama(NodoB<Key>* nodo, Key clave_dada) {
  if (nodo->GetDato() == clave_dada) return false;
  if (clave_dada < nodo->GetDato()) {
    if (nodo->GetIzdo() == NULL) {
      nodo->SetIzdo(new NodoB<Key>(clave_dada, NULL, NULL));
      return true;
    } else {
      return insertarRama(nodo->GetIzdo(), clave_dada);
    }
  } else {
    if (nodo->GetDcho() == NULL) {
      nodo->SetDcho(new NodoB<Key>(clave_dada, NULL, NULL));
      return true;
    } else {
      return insertarRama(nodo->GetDcho(), clave_dada);
    }
  }
}

/**
 * @brief Método para buscar una clave en el árbol binario de búsqueda
 * 
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template<class Key>
bool ABB<Key>::buscar(const Key& k) const {
  return buscarRama(this->GetRaiz(), k);
}

/**
 * @brief Método para buscar una clave en el árbol binario de búsqueda recursivamente
 * 
 * @tparam Key
 * @param nodo
 * @param clave_dada
 * @return true
 * @return false
 */
template<class Key>
bool ABB<Key>::buscarRama(NodoB<Key>* nodo, Key clave_dada) const {
 if (nodo == NULL) return false;
 if (clave_dada == nodo->GetDato()) return true;
 if (clave_dada < nodo->GetDato()) return buscarRama(nodo->GetIzdo(), clave_dada);
 return buscarRama(nodo->GetDcho(), clave_dada);
}

#endif  // ABB_H_