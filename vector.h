/**********************************************************
*	           											  *
*	 Vector.h  											  *
*    5.7.16    									          *
*	 Anton Gulyaev                                        *
*                                                         *
*	 Creation and manipulation of dynamic vector.         *
*	 Indexes in vector start with 0.					  *
*														  *
***********************************************************/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../ADTDefs.h"
#include <stdlib.h>

typedef struct Vector Vector;

/*Create vector. Function recieves initial vector size and size by which vector size will be incremented each time there is not enough space. Returns pointer to the created vector*/
Vector* VectorCreate(size_t _initialSize, size_t _extensionBlockSize);

/*Destroys vector and deallocated all allocated memory*/
void VectorDestroy(Vector* _vector);

/*Adds item to the end of the vector. Recieves pointer to the vector and the value to be added. Returns error code*/
ADTErr VectorAdd(Vector* _vector, int _item);

/*Retrieves and deletes last value added to the vector. Recieves pointer to vector and pointer to a variables to which the retrieved value will be passed. Returns error code*/
ADTErr VectorDelete(Vector* _vector, int* _item);
ADTErr VectorGet(Vector* _vector, size_t _index, int* _item);
ADTErr VectorSet(Vector* _vector, size_t _index, int _item);
ADTErr VectorItemsNum(Vector* _vector, size_t* _numOfItems);

/*Unit-Test functions*/
void VectorPrint(Vector* _vector);

#endif /*#ifndef __VECTOR_H__*/


















