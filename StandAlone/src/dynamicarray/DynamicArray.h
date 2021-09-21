#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <Arduino.h>

template<typename T>
class DynamicArray
{
	public:
		DynamicArray() = default;
		DynamicArray(size_t const &);
		DynamicArray(size_t const &, T const &);
		
		DynamicArray(const DynamicArray &);
		
		DynamicArray& operator= (const DynamicArray &);
		T& operator[](int const &);
		T const & operator[](int const &) const;
		
		~DynamicArray();
		
		size_t get_size() const;
		size_t get_max_size() const;
		
		void push_back(T &);
		void pop_back();
	
	private:
		size_t actualSize = 0;
		size_t maxSize = 0;
		T * array = nullptr;
};

template <typename T>
T& DynamicArray<T>::operator[](int const &i)
{
	return array[i];
}

template <typename T>
T const & DynamicArray<T>::operator[](int const &i) const
{
	return array[i];
}

template <typename T>
void DynamicArray<T>::pop_back()
{
	--actualSize;
}

template <typename T>
void DynamicArray<T>::push_back(T &val)
{
	if (actualSize > maxSize)
	{
		maxSize += 10;			// TODO: Umbauen
		T * newArr = new T[maxSize]();
		for (size_t i = 0; i < actualSize; ++i)
		{
			newArr[i] = array[i];
		}
		
		auto ptr = array;
		array = newArr;
		delete [] ptr;
	}
	array[actualSize] = val;
	++actualSize;
}

template <typename T>
size_t DynamicArray<T>::get_max_size() const
{
	return maxSize;
}

template <typename T>
size_t DynamicArray<T>::get_size() const
{
	return actualSize;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= ( const DynamicArray<T> &rhs)
{
		maxSize = rhs.maxSize();
		delete [] array;
		array = new T[maxSize]();
		actualSize = rhs.actualSize;
		for (size_t i=0; i < rhs.actualSize; ++i)
		{
			array[i] = rhs[i];							// evtl umbauen?
		}
		
		return *this;
}

template <typename T>		// Copy Constructor
DynamicArray<T>::DynamicArray (DynamicArray<T> const &orig) : maxSize(orig.maxSize)
{
	for (size_t i = 0; i < orig.actualSize; ++i)
	{
		array[i] = orig[i];
	}
}

template <typename T>		// Constructor 1
DynamicArray<T>::DynamicArray(size_t const &size) : maxSize(size*2)
{
	array = new T[maxSize]();
}

template <typename T>		// Constructor 2
DynamicArray<T>::DynamicArray(size_t const &size, T const &val) : DynamicArray(size)
{
	for (size_t i = 0; i < actualSize; ++i)
	{
		array[i] = val;
	}
}

template <typename T>		// Destructor
DynamicArray<T>::~DynamicArray()
{
	delete [] array;
	array = nullptr;
}



#endif