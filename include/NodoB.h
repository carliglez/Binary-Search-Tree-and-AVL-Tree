/**
 * @brief Clase plantilla NodoB para representar los nodos de un AB.
 * 
 */

#ifndef NODOB_H_
#define NODOB_H_

/**
 * @class NodoB
 * @brief Clase plantila NodoB.
 * 
 * @tparam Key 
 */
template<class Key>
class NodoB {
  public:
    NodoB(const Key dato, NodoB<Key> *izdo = NULL, NodoB<Key> *dcho = NULL) :
      dato_(dato), izdo_(izdo), dcho_(dcho) {}

    // getters
    Key GetDato() const {
      return dato_;
    }
    NodoB<Key>* GetIzdo() const {
      return izdo_;
    }   
    NodoB<Key>* GetDcho() const {
      return dcho_;
    }
    NodoB<Key>*& GetIzdo() {
      return izdo_;
    }
    NodoB<Key>*& GetDcho() {
      return dcho_;
    }
    
    // setters
    void SetDato(Key dato) {
      dato_ = dato;
    }
    void SetIzdo(NodoB<Key> *izdo) {
      izdo_ = izdo;
    } 
    void SetDcho(NodoB<Key> *dcho) {
      dcho_ = dcho;
    }

  protected:
    Key dato_;  // información a almacenar en el árbol
    NodoB<Key> *izdo_;  // hijo izquierdo del nodo binario
    NodoB<Key> *dcho_;  // hijo derecho del nodo binario
};

#endif  // NODOB_H_