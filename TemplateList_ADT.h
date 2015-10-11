#ifndef TEMPLATELIST_ADT_H
#define TEMPLATELIST_ADT_H
using namespace std;
#include <string>
#include <cstdlib>
//#include <>
template <class T>

class TemplateList_ADT
{
	public:
		TemplateList_ADT(T*);
		void TL_ADD(T);
		void TL_REMOVE(int);
	
	private:
		T *TL_ARRAY;
		int TL_Index;

};

#endif
