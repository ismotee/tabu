#include "vector2d.h"

template <class T> vector2d<T>::vector2d():w(0),h(0)
{
}

template <class T> vector2d<T>::vector2d(int w_, int h_, T type) 
{
	w = w_;
	h = h_;
	
	field.resize(w*h , type);
}

template <class T> vector2d<T>::~vector2d()
{
	
	
	
}

