
/**
 * RESOLUCIÓN DEL PROBLEMA DE LA SUBSECUENCIA COMÚN MÁXIMA PARA LA COMPARACIÓN DE DOS CADENAS DE ADN
 * Juan Pablo Donoso - Computación y Sistemas Inteligentes UGR
 *
 * NOTA: esta implementación no está revisada aún
 *
 * Dadas dos cadenas de ADN X e Y con: 
 *
 * 		x = ABCB
 *   	y = BDCAB
 *
 * La resolución del problema LCS (Longest Common Subsecuence) para x e y sería:
 * 		 L(x,y) = BCB 
 *
 * Debemos tener en cuaenta que si x tiene m elementos, podemos formar 2^m subsecuencias que debemos comparar
 * con los elemenost de y. Si y tiene un número de elementos n, el tiempo de ejecución será n*2^m en el peor de 
 * los casos. 
 * 
 * 
 * A continuación se intenta daŕ una solución a este problema empleando un algoritmo basado
 * en Programación Dinámica
 * 
 *  Juan Pablo Donoso 
 * 
 */

//Conjunto de indicaciones para poder movernos por la tabla de 
//soluciones
enum DIRECCION={SUP,IZQ,DIA}; 

/**
 * Estructura que corresponde a posición en la tabla 
 * de soluciones
 */
struct info
{
	unsigned int value; //valor de la solución 
	DIRECCION dir; 		//dirección para recomponer la solución 
};

/**
 * Devuelve la solución al problema de la máxima subsecuencia común creciente
 * mediante programación dinámica.
 * @param  x Cadena de referencia 
 * @param  y Cadena a comparar con la cadena de referencia
 * @param  L Tabla de soluciones para el problema 
 * @return   Matriz de soluciones al problema MCS
 */
int MCS(string &x, string &y, M<info>&L)
{
	int n = x.size(); 
	int m = y.size(); 

	int i; 
	for(i=0; i<=m; i++)
		L(0,i).value = 0; 

	for(i=0;i<=n;i++)
		L(i,0).value = 0; 

	for(i=1;i<=m;i++){
		for(int j=1;i<=n;j++){
			if(x[j]==y[i]){
				L(i,j).value = L(i-1,j-1).value+1; 
				L(i,j).dir = DIA; 
			}else{
				if(L(i-1,j).value > L(i,j-1).value){
					L(i,j).value = L(i,j-1).value;
					L(i,j).dir=SUP; 
				}else{
					L(i,j).value=L(i,j-1).value; 
					L(i,j),dir=IZQ; 
				}
			}
		}
	}
	return L(m,n); 
}

void print_solution(string &x, string &y, M<info>&L,int i, int j)
{
	if(i=0||j==0)return; 
	else
		if(L(i,j).dir==DIA){
			cout<<x[j]<<" "; 
			print_solution(x,y,L,i-1,j-1);
		}else{
			if(L(i,j).dir==SUP)
				print_solution(x,y,L,i-1,j);
			else
				print_solution(x,y,L,i,j-1);
		}
}


int main(){

}