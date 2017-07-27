#pragma once

#include <vector>



template <class T> class vector2d 
{
public:
	int w,h;
	std::vector<T> field;

	vector2d();
	vector2d(int w_, int h_, T type);
	virtual ~vector2d();

};

