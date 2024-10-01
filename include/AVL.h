/**
 * @brief Clase plantilla para el árbol binario de búsqueda balanceado (AVL).
 * 
 */

// A continuación, se define MODO_TRAZA para compilar o no con dicho modo activado.
// En el directorio raíz del programa, se encuentra un ejecutable main y otro main_traza
// para poder ejecutar el programa en el modo deseado. Recordar modificar el Makefile
// según se desee sobreescribir el ejecutable correspondiente.
//#define MODO_TRAZA

#ifndef AVL_H_
#define AVL_H_

#include <iostream>

#include "ABB.h"
#include "NodoAVL.h"

/**
 * @class AVL
 * @brief Clase plantila AVL.
 * 
 * @tparam Key 
 */
template<class Key>
class AVL : public ABB<Key> {
  public:
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
  
  protected:
    NodoAVL<Key>* GetRaizAVL() const {
      return reinterpret_cast<NodoAVL<Key>*>(this->GetRaiz());
    }
    NodoAVL<Key>*& GetRaizAVL() {
      return reinterpret_cast<NodoAVL<Key>*&>(this->GetRaiz());
    }

    // inserción
    void inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece, bool& introduce);
    void insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool& crece);
    void insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& crece);

    // búsqueda
    bool buscarRama(NodoAVL<Key>* nodo, Key clave_dada) const;
   
    // rotaciones para balanceo
    void rotacionII(NodoAVL<Key>* &nodo);
    void rotacionDD(NodoAVL<Key>* &nodo);
    void rotacionID(NodoAVL<Key>* &nodo);
    void rotacionDI(NodoAVL<Key>* &nodo);
};

/**
 * @brief Inserta un nodo nuevo 
 * 
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template<class Key>
bool AVL<Key>::insertar(const Key& k) {
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(k);
  bool crece = false;
  bool introduce = false;
  inserta_bal(GetRaizAVL(), nuevo, crece, introduce);
  return introduce;
}

/**
 * @brief Inserta un nodo nuevo de manera recursiva
 * 
 * @tparam Key
 * @param nodo
 * @param nuevo
 * @param introduce
 */
template<class Key>
void AVL<Key>::inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece, bool& introduce) {
  if (nodo == NULL) {
    nodo = nuevo;
    crece = true;
    introduce = true;    
  } 
  if (nodo->GetDato() == nuevo->GetDato()) {
    return;
  } else if(nuevo->GetDato() < nodo->GetDato()) {
    inserta_bal(nodo->GetIzdoAVL(), nuevo, crece, introduce);
    if (crece) insert_re_balancea_izda(nodo, crece);
  } else {
    inserta_bal(nodo->GetDchoAVL(), nuevo, crece, introduce);
    if (crece) insert_re_balancea_dcha(nodo, crece);
  }
}

/**
 * @brief Rebalancea la rama izquierda tras insertar
 * 
 * @tparam Key
 * @param nodo
 * @param crece
 */
template<class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool& crece) {
  switch(nodo->GetBal()) {
    case -1: 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(1);
      break;
    case 1:
      NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();  // mirar bal del hijo izq
      if (nodo1->GetBal() == 1) {
        rotacionII(nodo);
      } else {
        rotacionID(nodo);
      }
      crece = false;    
      break;
  }
}

/**
 * @brief Rebalancea la rama derecha tras insertar
 * 
 * @tparam Key
 * @param nodo
 * @param crece
 */
template<class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& crece) {
  switch(nodo->GetBal()) {
    case 1: 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(-1);
      break;
    case -1:
      NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();  // mirar bal del hijo dcho
      if (nodo1->GetBal() == -1) {
        rotacionDD(nodo);
      } else {
        rotacionDI(nodo);
      }
      crece = false;    
      break;
  }
}

/**
 * @brief Busca un valor en el árbo AVL
 * 
 * @tparam Key
 * @param k
 * @return true
 * @return false
 */
template<class Key>
bool AVL<Key>::buscar(const Key& k) const {
  return buscarRama(GetRaizAVL(), k);
}


/**
 * @brief Método para buscar una clave en el árbol AVL recursivamente
 * 
 * @tparam Key
 * @param nodo
 * @param clave_dada
 * @return true
 * @return false
 */
template<class Key>
bool AVL<Key>::buscarRama(NodoAVL<Key>* nodo, Key clave_dada) const {
 if (nodo == NULL) return false;
 if (clave_dada == nodo->GetDato()) return true;
 if (clave_dada < nodo->GetDato()) return buscarRama(nodo->GetIzdoAVL(), clave_dada);
 return buscarRama(nodo->GetDchoAVL(), clave_dada);
}   

/**
 * @brief Rotación izquierda-izquierda
 * 
 * @tparam Key
 * @param nodo
 */
template<class Key>
void AVL<Key>::rotacionII(NodoAVL<Key>* &nodo) {
  #ifdef MODO_TRAZA
  std::cout << "Desbalanceo:" << std::endl;
  this->operator>>(std::cout);
  std::cout << "Rotación II en [" << nodo->GetDato() << "]:" << std::endl;
  #endif  

  NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
  nodo->SetIzdo(nodo1->GetDcho());
  nodo1->SetDcho(nodo);
  if (nodo1->GetBal() == 1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else {
    nodo->SetBal(1);
    nodo1->SetBal(-1);    
  }
  nodo = nodo1;
}

/**
 * @brief Rotación derecha-derecha
 * 
 * @tparam Key
 * @param nodo
 */
template<class Key>
void AVL<Key>::rotacionDD(NodoAVL<Key>* &nodo) {
  #ifdef MODO_TRAZA
  std::cout << "Desbalanceo:" << std::endl;
  this->operator>>(std::cout);
  std::cout << "Rotación DD en [" << nodo->GetDato() << "]:" << std::endl;
  #endif 

  NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
  nodo->SetDcho(nodo1->GetIzdoAVL());
  nodo1->SetIzdo(nodo);
  if (nodo1->GetBal() == -1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else {
    nodo->SetBal(-1);
    nodo1->SetBal(1);    
  }
  nodo = nodo1;
}

/**
 * @brief Rotación izquierda-derecha
 * 
 * @tparam Key
 * @param nodo
 */
template<class Key>
void AVL<Key>::rotacionID(NodoAVL<Key>* &nodo) {
  #ifdef MODO_TRAZA
  std::cout << "Desbalanceo:" << std::endl; 
  this->operator>>(std::cout);
  std::cout << "Rotación ID en [" << nodo->GetDato() << "]:" << std::endl;
  #endif  

  NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
  NodoAVL<Key>* nodo2 = nodo1->GetDchoAVL();
  nodo->SetIzdo(nodo2->GetDchoAVL());
  nodo2->SetDcho(nodo);
  nodo1->SetDcho(nodo2->GetIzdoAVL());
  nodo2->SetIzdo(nodo1);
  if (nodo2->GetBal() == -1) {
    nodo1->SetBal(1);
  } else {
    nodo1->SetBal(0);
  } 
  if (nodo2->GetBal() == 1) {
    nodo->SetBal(-1);
  } else {
    nodo->SetBal(0);
  }
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief Rotación derecha-izquierda
 * 
 * @tparam Key
 * @param nodo
 */
template<class Key>
void AVL<Key>::rotacionDI(NodoAVL<Key>* &nodo) {
  #ifdef MODO_TRAZA
  std::cout << "Desbalanceo:" << std::endl; 
  this->operator>>(std::cout);
  std::cout << "Rotación DI en [" << nodo->GetDato() << "]:"<< std::endl; 
  #endif  

  NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
  NodoAVL<Key>* nodo2 = nodo1->GetIzdoAVL();
  nodo->SetDcho(nodo2->GetIzdoAVL());
  nodo2->SetIzdo(nodo);
  nodo1->SetIzdo(nodo2->GetDchoAVL());
  nodo2->SetDcho(nodo1);
  if (nodo2->GetBal() == 1) {
    nodo1->SetBal(-1);
  } else {
    nodo1->SetBal(0);
  } 
  if (nodo2->GetBal() == -1) {
    nodo->SetBal(1);
  } else {
    nodo->SetBal(0);
  }
  nodo2->SetBal(0);
  nodo = nodo2;
}

#endif  // AVL_H_