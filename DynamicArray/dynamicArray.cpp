#include "dynamicArray.h"
#include <algorithm>

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

DynamicArray::DynamicArray(const DynamicArray& _source)
	:tabElements(new int[_source.getCapacite()]),
	capacite(_source.getCapacite())
{
	for (unsigned int i = 0; i < capacite; ++i)
	{
		tabElements[i] = _source.tabElements[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& _source)
{
	if (&_source != this)
	{
		delete[] tabElements;
		tabElements = new int[_source.getCapacite()];
		capacite = _source.getCapacite();
		for (unsigned int i = 0; i < capacite; ++i)
		{
			tabElements[i] = _source.tabElements[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& _source)
{
	if (capacite != _source.capacite)
	{
		return false;
	}
	for (int i = 0; i < _source.getCapacite(); i++)
	{
		if (tabElements[i] != _source.tabElements[i])
		{
			return false;
		}
	}
	return true;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _source)
{
	return *this;
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
		setCapacite(index_element + 1);
	}

	tabElements[index_element] = nouvelle_valeur_element;
}

void DynamicArray::setCapacite(const int nouvelle_capacite)
{
	if (nouvelle_capacite <= 0) throw std::invalid_argument("received a value smaller than 1");
	int * newTableau = new int[nouvelle_capacite];

	for (int i = 0; i < std::min(capacite, nouvelle_capacite); ++i)
	{
		newTableau[i] = tabElements[i];
	}

	for (int i = capacite; i < nouvelle_capacite; ++i)
	{
		newTableau[i] = 0;
	}

	delete[] tabElements;

	capacite = nouvelle_capacite;

	tabElements = newTableau;
}