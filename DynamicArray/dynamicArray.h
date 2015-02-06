#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_
#include <iostream>


class DynamicArray
{

public:
	DynamicArray() :
		capacite(100)
	{
		tabElements = new int[capacite];
		for (int i = 0; i < capacite; i++)
		{
			tabElements[i] = 0;
		}
	}

	DynamicArray(unsigned int index);
	DynamicArray(const DynamicArray  & _source);
	DynamicArray& operator=(const DynamicArray  & _source);
	bool operator==(const DynamicArray  & _source);
	DynamicArray& operator+=(const DynamicArray  & _source);

	//~DynamicArray();
	int getCapacite() const;
	int getElement(int i) const;
	void setElement(const int index_element, const int nouvelle_valeur_element);
	void setCapacite(const int nouvelle_capacite);

private:
	int *tabElements;
	int capacite;
};


#endif //DYNAMICARRAY_H_