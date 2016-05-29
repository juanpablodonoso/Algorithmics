#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
using namespace std; 



/**
 * @brief Matriz para representar la tabla de soluciones
 **/
template<class T>
class Matrix
{
private:
	// Dynamic two-dimensional array container 
	T **ptr_data;

	// number of rows and columns 
	int rows,cols;
	
	// Keeps track of the total size of the table
	int size;

	//reserva de memoria para una tabla
	void allocate(int _rows, int _cols);
	
	//liberar la memoria asociada a una tabla
	void destroy(); 
	
	//redimensionar la matriz 
	void resize(int new_rows, int new_cols); 
	
	//eliminar una fila
	void delete_row();
	
	//eliminar una columna
	void delete_col(); 
public:
	//ctor por defecto
	Matrix();
	//ctor por parámetros
	Matrix(const Matrix<T> &other);
	//destructor
	~Matrix();

	//operador de asignación
	Matrix<T>& operator=(const Matrix<T> &rht);
	//operador de operación sobre una posición
	T& operator()(int i, int j)const; 
	const T& operator()(int i,int j)const; 

	// total size 
	int size()const; 
	
	//number of rows
	int matrix_rows()const{return rows;}
	//number of cols
	int matrix_colums()const{return cols;}


	//set a matrix position (i,j)
	void set(int i,int j,T elem);
	
}; //end of matrix class

template<class T>
ostream& operator<<(ostream &os,const Matriz<T>&M); 




#include "matrix.cpp"
#endif