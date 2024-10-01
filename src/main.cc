/**
 * @brief Programa principal para la implementación del TDA Árbol.
 *  
 */

#include <iostream>

#include "../include/AB.h"
#include "../include/ABB.h"
#include "../include/AVL.h"

/**
 * @brief Main secundario del programa
 * 
 * @param argc
 * @param argv
 * @return int
 */
int secondary_main(int argc, char * argv[]) {  
  std::cout << "Bienvenido/a al programa para la implementación del TDA Árbol\n" << std::endl;
  bool quit = false;
  int option = 0;
  long value = 0;  // tipo de dato que va a tener Key
  AB<long> *ab;  // crea un puntero AB para que después apunte a ABB o AVL

  // menú con los tipos de árboles binarios disponibles
  quit = false;
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Tipos de árboles binarios disponibles, seleccione uno: " << std::endl;
    std::cout << "1. Usar árbol binario de búsqueda" << std::endl;
    std::cout << "2. Usar árbol AVL" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
    switch (option) {
      case 1:
        ab = new ABB<long>;  // crea un árbol binario de búsqueda
        quit = true;
        break;
      case 2:
        ab = new AVL<long>;  // crea un árbol AVL
        quit = true;
        break;
      default:
        break;
    }
  }

  // menú con las acciones a realizar
  quit = false;
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Acciones a realizar: " << std::endl;
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar clave" << std::endl;
    std::cout << "[2] Buscar clave" << std::endl;
    std::cout << "[3] Mostrar árbol inorden" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
    switch (option) { 
      case 1:
        std::cout << "\U00002795 Introduzca la clave a insertar: " << std::endl;  // U+2795 (plus)
        std::cout << "→  ";
        std::cin >> value;
        if (ab->insertar(value)) {
          std::cout << "\U0001F44D Clave insertada" << std::endl;  // U+1F44D (thumbs up)
          ab->operator>>(std::cout);  // se muestra el árbol por niveles
        } else {
          std::cout << "\U0001F44E La clave NO se pudo insertar" << std::endl;  // U+1F44E (thumbs down)
        }
        std::cout << std::endl;
        break;
      case 2:
        std::cout << "\U0001F50E Introduzca la clave a buscar: " << std::endl;  // U+1F50E	(magnifying glass tilted right)
        std::cout << "→  ";
        std::cin >> value;
        if (ab->buscar(value)) {
          std::cout << "\U0001F44D La clave se encuentra en el árbol binario" << std::endl;  // U+1F44D (thumbs up)
        } else {
          std::cout << "\U0001F44E La clave NO se encuentra en el árbol binario" << std::endl;  // U+1F44E (thumbs down)
        }
        std::cout << std::endl;
        break;
      case 3:
        ab->inorden();  // se muestra el árbol en inorden
        std::cout << std::endl;
        break;
      case 0:
        quit = true;        
        break;   
      default:
        break;        
    }
  }  
  
  delete ab;  // se borra el puntero
  std::cout << std::endl;
  std::cout << "Programa finalizado..." << std::endl;
  return 0;
}

/**
 * @brief Main principal del programa
 * 
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char * argv[]) {
  try {
    return secondary_main(argc, argv);  // menú main secundario bajo control de excepciones
  }
  catch(std::system_error& e) {
    std::cerr << "\U000026D4 Error árbol binario: " << e.what() << std::endl;  // U+26D4 (no entry)
    return 2;
  }
  catch (...) {  // resto de errores
    std::cout << "\U000026D4 Error inesperado..." << std::endl;  // U+26D4 (no entry)
    return 3; 
  } 
}