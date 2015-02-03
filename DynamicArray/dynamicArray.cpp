#include "dynamicArray.h"

DynamicArray::DynamicArray(unsigned index)
{
	if (index <= 0) throw std::invalid_argument("received a value smaller than 0");
	capacite = index;
	tabElements = new int[capacite];

	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

/*DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}*/

int DynamicArray::getCapacite() const
{
	return capacite;
}

int DynamicArray::getElement(int i) const
{
	if (i >= capacite) throw std::out_of_range("surpass the limit of the array");
	return tabElements[i];
}

void DynamicArray::setElement(const int index_element, const int nouvelle_valeur_element)
{
	if (index_element > capacite)
	{
		setCapacite(index_element);
	}

	for (int i = 0; i <= index_element; i++)
	{
		if (i == index_element)
		{
			tabElements[i] = nouvelle_valeur_element;
		}
	}
}

void DynamicArray::setCapacite(const int nouvelle_capacite)
{
	if (nouvelle_capacite <= 0) throw std::invalid_argument("received a value smaller than 1");
	capacite = nouvelle_capacite;
	int * newTableau = new int[nouvelle_capacite];

	for (int i = 0; i < capacite; i++)
	{
		if (getElement(i) >= NULL)
		{
			newTableau[i] = getElement(i);
		}
		else
		{
			newTableau[i] = 0;
		}
	}
	delete[] tabElements;
	tabElements = newTableau;
}