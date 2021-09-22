#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>
#include <math.h>

using namespace std;

/* La clase T debe tener definido un operator<
 * que implemente una relación de orden total. */
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	// Encola un elemento.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	void encolar(const T& elem);

	// Devuelve el elemento de mayor prioridad.
	// Pre: tam() > 0
	const T& proximo() const;

	// Saca el elemento de mayor prioridad.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	// Pre: tam() > 0
	void desencolar();

	// Constructor que hace heapify.
	ColaPrior(const vector<T>& elems);

private:
	// COMPLETAR
	vector<T> _heap;
	int padre(int i);
	int left(int i);
	int right(int i);
    void sift_up(vector<T> &v, int i);
	void sift_down(vector<T>& v,int i);
};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
