// Definición de métodos para el contenedor de la tabla de soluciones
// para el problema de la mochila resuelto mediante programación dinámica
// NOTA: Esta implementación no está acabada ni revisada 
// Para ver la implementación del problema consultar documentación o src/kanpsack.cpp, donde se ecuentra
// el punto de entrada del programa




#include <iostream>

using namespace std; 


// ==== Métodos privados ==== 

void Matrix<T>::allocate(int rows, int cols)
{
	ptr_data = new T*[rows]; 	
	for(int i=0; i<rows; i++)
		ptr_data = new T[cols];
}



/// dellocated the memory space occupied by the dataset allocated in 
/// the matrix ptr_data 
void Matrix<T>::destroy()
{
	if(ptr_data != 0) {
		for(int i = 0; i < rows; i++){delete[] ptr_data[i];}
		delete[] ptr_data; 
	}
	else {
		cout<<"DEBUGGUING::"<<'\t'<<"What is dead may never die"<<endl;
	}
}

/**********************************************************************/

///copy one matrix in other
void Matriz<T>::copy(const Matrix<T>&M)
{
	for(int i=0; i<rows;i++){
		for(int j=0;j<cols;j++)
			ptr_data[i][j] = M.ptr_data[i][j]; 
	}
}


/**********************************************************************/



// Redimensiona al matriz para un nuevo tamaño de filas y columnas
// Este método se emplea cuando la matriz se contruye dinámicamente a medida 
// que se extraen y procesan datos desde un fichero 
template<class T>
void Matriz<T>::resize(int new_rows, int new_cols)
{
	
		// copia temporal de los datos almacenado en la matriz actual
	Matrix<T> temp(*this); 

		// liberación de memoria pra los datos actuales
	destroy(); 

		// reserva de memoria para los nuevos datos 
	allocate(new_rows, new_cols);

		// copia en la nueva matriz de los datos de la antigua matriz 
	copy(temp); 
}


// ==== Métodos públicos ====


//crea una matriz vacía
template<class T>
Matrix<T>::Matrix() : rows(0), cols(0); {}

//constructor por parámetros
//reserva memoria para un numero de filas y columnas
//sin inicializar
template<class T>
Matriz<T>::Matriz(int _rows, int _cols)
{	
		if(_rows > 0 && _cols > 0)
		{
			this->rows=_rows; 
			this->cols=_cols;
			allocate(rows,cols); 
		}
}

/**********************************************************************/

//constructor de copia
template<class T>
Matrix<T>::Matrix(const Matrix<T>&M)
{
	rows = M.rows; 
	cols = M.cols; 
	
	//reserva de memoria para la copia
	allocate(rows,cols); 

	//copia de los elementos
	copy(); 
}

/**********************************************************************/

//destructor 
template<class T>
Matrix<T>::~Matriz()
{
	//dellocated de memory
	destroy(); 
	
}

// establecer un posición (i,j) de la matriz
// pre: la posicion i debe ser positiva y menor que el número actual de filas
// 		la posición j debe ser positiva y menor que el número actual de columnas
template<class T>
void Matrix<T>::set(int i, int j, T element)
{
	if( (i >= 0 && i <= rows) &&  (j >= 0 && j <= cols ))
		ptr_data[i][j]; 
	
}


// sobrecarga del operador () para poder realizar operaciones sobre una posición (i,j) de
// la tabla de soluciones
// pre: la posición (i,j) debe pertenecer a la tabla
template<class T>
T & Matrix<T>::operator()(int i, int j)
{	
	if( (i >= 0 && i <= rows) &&  (j >= 0 && j <= cols ))
		return ptr_data[i][j]; 
}



// sobrecarga del operador de inserción para mostrar por pantalla el contenido 
// de la tabla de soluciones 
// Se emplea la sobrecarga del operador () definida para la clase Matrix
template<class T>
ostream & operator<<(ostream & os, const Matrix<T> & M)
{
	os << '\n'; 
	for(int i = 0; i < M.matrix_rows(); i++) {
		for(int j = 0; j < M.matrix_columns(); j++)
			os << M(i,j) << '\t'; 
	}
	os << '\n'; 
}

