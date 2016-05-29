// Resolución del problema de la mochila 0/1 mediante programación dinámica
// NOTA: el proceso está a medias ya que esta es la primera versión
// TODO: revisión 
// TODO: mejoras y revisión de la encapsulación para poder realizar una medición de tiempos con un método similar a:
//       
//        clock_t init;     //tiempo de inición de la ejecucíón del algoritmo 
//        init = clock(); 
//        
//        kanpsack_DP( // argumentos del problema ); 
//        
//        clock_t endt;    //tiempo de finalización del algoritmo
//        endt = clock(); 
//        
//        // Resultado del tiempo de ejecucuión 
//        cout << (endt - init)/(double)CLOCKS_PER_SEC << endl; 
//      
//      La medición de tiempos servirá para una comparacińo del problema de la mochila implementado con 
//      - Método greedy 
//      - Programación dinámica
//      - Ramificación y Poda 
//        
// Autor: Juan Pablo Donoso 



#include <iostream>
#include <limits>
#include <stdlib.h>
#include <unisdt.h>
#include <matrix.h> // Implemetación del contenedor de la tabla de soluciones
using namespace std;



/**
 * @brief           Construye la tabal de soluciones partiendo de los casos base del problema
 * @param b         Contenedor de los beneficios por producto
 * @param p         Contenedor de los pesos por producto
 * @param sol_table Contenedor de la tabla de soluciones (modificado y devuelto por referencia)
 */
void sub_sols_knapsack(std::vector<int> & b, std::vector<int> & p, Matrix<int> & sol_table)
{

  int n = b.size(); 
  int m = p.size(); 

  // incilización del caso base: m = 0 (no se pueden incluir objetos),
  // knapsack(m,0) = 0  
  for(int i=0; i<n; i++){ sol_table.set(i,0,0); }

  //incialización del caso base: k = 0,  knapsack(0,m) = 0
  for(int i=0; i<m; i++){ sol_table(0,i,0); } 

  // rellenar la tabla de soluciones
  for(int i = 1; i < n; i++) {
    for(int j = 1; i < m; j++) {
      
      // Control del caso en el que al restar el peso del producto 
      // a la capacidad total de la mochila el resutado sea negativo:
      
      if(j-p[i] < 0)  // resultado negativo: el objeto no se coge
        v.set(i,j,v(i-1,j));
      else          // resultado positivo:  decisión que nos de mayor beneficio
        v.set(i,j,max(v(i-1),v(i-1,j-p[i])+b[i])); 
    }
  }

}


/**
   * @brief           Devuelve la solción al problema de la mochila 0/1
   * @param sol       Contenedor de la solución (devuelto por referencia)
   * @param b         Contenedor de los beneficios de cada productor
   * @param p         Contenedor de los pesos de cada producto 
   * @param sol_table Contenedor de la tabla de subsoluciones al problema
   * @param n         Número de objetos del problema
   * @param m         Capacidad máxima de la mochila
   *
   * Recorre la tabla de soluciones y reconstruye la solución final almacenandola en un vector
   * donde cada posición corresponden con la decisión coger (1) o no coger (0) el objeto determinado 
   * por el indice de la posición. 
   * Este recorrido se realiza desde la última posición de la tabla de soluciones, correspondiente a la solución 
   * óptima para el problena sol_table(n,m) hasta la primera posición donde se encuentran datos del problema
   * (la posición sol_table(1,1,) ya que en sol_table(0,0) se almacenan los casos base)
   */
  void knapsack(std::vector<float> & sol, std::vector<int> & b, std::vector<int> & p,
                                                    Matrix<int> & sol_table, int n, int m)
  {
    int j = m; 
    int i = n; 
    while(i!=0) {

      if(sol_table(i,j) == sol_table(i-1,j) {
        sol[i-1] = 0; 
      } else {                // sol_table(i,j) == sol_table(i-1,j-p[i])+b[i])
        sol[i] = 1; 
        j = j - p[i]; 
      }

      i--;
    }
  }






int main(int argc, char const *argv[]) {

 
  int n = 3;   // número de objetos 
  int m = 6;  // capacidad máxima 
  

  std::vector<int> b(n);   //contenedor de beneficios
  std::vector<int> p(n);   //contenedor de pesos
  std::vector<int> sol; //contenedor de la solución

  b = {1, 2, 5}; 
  p = {2, 3, 4}; 

  
  // el tamaño de la tabla de soluciones sol_table viene determinado por 
  // sol_table(0..n,0..M)
  Matrix<int> sol_table(n + 1, m + 1); 

  //creación de la tabla de subsoluciones 
  sub_sols_knapsack(b,p,sol_table); 


  // imprimir la tabla de soluciones 
  cout << sol_table; 


  // recomponer la solución 
  vector<float> sol(n); 
  
  
  // imprimir solución 
  cout << sol; 

  return 0;
}
