/**
 * @brief Clase plantilla NodoAVL para representar los nodos de un AVL.
 * 
 */

#ifndef NODOBAVL_H_
#define NODOBAVL_H_

#include "NodoB.h"

/**
 * @class NodoAVL
 * @brief Clase plantila NodoAVL.
 * 
 * @tparam Key 
 */
template<class Key>
class NodoAVL : public NodoB<Key> {
  public:
    NodoAVL(const Key dato, NodoAVL<Key> *izdo = NULL, NodoAVL<Key> *dcho = NULL):
      NodoB<Key>(dato, izdo, dcho), bal_(0) {}

    // getters
    Key GetBal() const {
      return bal_;
    }
    NodoAVL<Key>* GetIzdoAVL() const {
      return reinterpret_cast<NodoAVL<Key>*>(this->izdo_);
    }   
    NodoAVL<Key>* GetDchoAVL() const {
      return reinterpret_cast<NodoAVL<Key>*>(this->dcho_);
    }
    NodoAVL<Key>*& GetIzdoAVL() {
      return reinterpret_cast<NodoAVL<Key>*&>(this->izdo_);
    }   
    NodoAVL<Key>*& GetDchoAVL() {
      return reinterpret_cast<NodoAVL<Key>*&>(this->dcho_);
    }
    
    // setters
    void SetBal(int bal) {
      bal_ = bal;
    }  

  private:
    int bal_;  // factor de balanceo del nodo
};

#endif  // NODOBAVL_H_