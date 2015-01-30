#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


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
	int getCapacite() const;
	int getElement(int i) const;
	//void setElement(const int index_element, const int nouvelle_valeur_element);
private:
	int *tabElements;
	unsigned int capacite;
};


#endif //DYNAMICARRAY_H_