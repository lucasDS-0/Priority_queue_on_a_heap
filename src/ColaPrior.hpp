
template<class T>
ColaPrior<T>::ColaPrior() : _heap({}) {

}

template<class T>
int ColaPrior<T>::tam() const {
    return _heap.size();
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
    _heap.push_back(elem);
    sift_up(_heap,_heap.size() - 1);
}

template<class T>
const T& ColaPrior<T>::proximo() const {
    return _heap[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	_heap[0] =_heap[_heap.size() - 1];
    _heap.pop_back();
	sift_down(_heap,0);
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    _heap = elems;
    for (int i = elems.size()/2; i > 0; ++i) {
        sift_down(_heap,i);
    }
}

template <class T>
int ColaPrior<T>::padre(int i) {
    return (i-1)/2;
}

template <class T>
int ColaPrior<T>::left(int i) {
    return 2*i + 1;
}

template <class T>
int ColaPrior<T>::right(int i) {
    return 2*i + 2;
}

template <class T>
void ColaPrior<T>::sift_down(vector<T>& v,int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= v.size() && v[l] > v[i]) {
        largest = l;
    }
    if (r <= v.size() && v[r] > v[largest]) {
        largest = r;
    }
    if (largest != i) {
        int aux = v[i];
        v[i] = v[largest];
        v[largest] = aux;
        sift_down(v,largest);
    }
}

template <class T>
void ColaPrior<T>::sift_up(vector<T>& v,int i) {
    if (i != 0 && v[i] > v[padre(i)]) {
        int aux = v[i];
        v[i] = v[padre(i)];
        v[padre(i)] = aux;
        sift_up(v,padre(i));
    }

}
