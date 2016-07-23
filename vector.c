#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "../ADTDefs.h"

#define ALLOCATED 78578762
#define DEALLOCATED 0

struct Vector
{
	int* m_items;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nItems;
	size_t m_blockSize;
	int m_memoryAllocSign; 
};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBlockSize)
{
	Vector* vec;
	if(0 == _initialSize && 0 == _extensionBlockSize)
	{
		return NULL;
	}
	
	if((vec = (Vector*) malloc(sizeof(Vector))) == NULL)
	{		
		return NULL;
	}

	if((vec->m_items = (int*) malloc(_initialSize * sizeof(int))) == NULL)	
	{
		free(vec);		
		return NULL;	
	}

	vec->m_originalSize = _initialSize;
	vec->m_size = _initialSize;
	vec->m_nItems = 0;
	vec->m_blockSize = _extensionBlockSize;
	vec->m_memoryAllocSign = ALLOCATED;

	return vec;
}

void VectorDestroy(Vector* _vector)
{
	if(NULL != _vector && _vector->m_memoryAllocSign == ALLOCATED)
	{
		_vector->m_memoryAllocSign = DEALLOCATED;
		free(_vector->m_items);
		free(_vector);
	}
}

ADTErr VectorAdd(Vector* _vector, int _item)
{
	int* temp = NULL;	

	if(NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}

	if(_vector->m_nItems == _vector->m_size)
	{
		if(0 == _vector->m_blockSize)
		{
			return ERR_OVERFLOW;
		}

		temp = (int*)realloc(_vector->m_items, (_vector->m_size + _vector->m_blockSize) * sizeof(int));

		if(NULL != temp)
		{
			_vector->m_items = temp;
			_vector->m_size += _vector->m_blockSize;
		}
		else
		{
			return ERR_OVERFLOW;
		}
	}

	_vector->m_items[_vector->m_nItems] = _item;
	_vector->m_nItems++;

	return ERR_OK;
}

ADTErr VectorDelete(Vector* _vector, int* _item)
{
	int* temp;	

	if(NULL == _vector || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}

	if(0 == _vector->m_nItems)
	{
		return ERR_UNDERFLOW;
	}

	*_item = _vector->m_items[_vector->m_nItems - 1];
	--_vector->m_nItems;

	if(_vector->m_size - _vector->m_nItems > _vector->m_blockSize * 2 && _vector->m_size > _vector->m_originalSize + _vector->m_blockSize)
	{
		temp = (int*) realloc(_vector->m_items, _vector->m_size - _vector->m_blockSize);
		if(NULL != temp)
		{
			_vector->m_items = temp;
			_vector->m_size -= _vector->m_blockSize;
		}
	}
	
	return ERR_OK;
}

ADTErr VectorGet(Vector* _vector, size_t _index, int* _item)
{
	if(NULL == _vector || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}

	if(_index > _vector->m_nItems - 1 || _vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}

	*_item = _vector->m_items[_index];

	return ERR_OK;
}

ADTErr VectorSet(Vector* _vector, size_t _index, int _item)
{
	if(NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}

	if(_index > _vector->m_nItems - 1)
	{
		return ERR_UNDERFLOW;
	}

	_vector->m_items[_index] = _item;

	return ERR_OK;
}

ADTErr VectorItemsNum(Vector* _vector, size_t* _numOfItems)
{
	if(NULL == _vector || NULL == _numOfItems)
	{
		return ERR_NOT_INITIALIZED;
	}

	*_numOfItems = _vector->m_nItems;

	return ERR_OK;
}

void VectorPrint(Vector* _vector)
{
	int i, numItems;
	if(NULL == _vector)
	{
		return;
	}

	putchar('\n');

	if(_vector->m_nItems > 0)
	{	
		for(i = 0, numItems = _vector->m_nItems; i < numItems; ++i)
		{
			printf("%d ", _vector->m_items[i]);
		}
	}
	putchar(' ');
}



















































