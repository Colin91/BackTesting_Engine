/*
	Create an Template ADT that accepts any type of type or object
	functions: ADD, REMOVE, SEARCH, SIZE
*/
#include "TemplateList_ADT.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;

template <class T>
TemplateList_ADT<T>::TemplateList_ADT(T *Object_In)
{
	string* Name = new string[1];
	TL_ARRAY = Object_In;	
	cout<<"Input Name of List : "<<endl;
	cin>>*Name;
	TL_Index = 0;
}
template <class T>
void TemplateList_ADT<T>::TL_ADD(T Object_In)
{
	TL_ARRAY[TL_Index] = Object_In;
	TL_Index++; 
	
} 
template <class T>
void TemplateList_ADT<T>::TL_REMOVE(int Index_In)
{
	TL_ARRAY[TL_Index] = NULL;
	TL_Index--;
}





