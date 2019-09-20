#include "Stack.h"
#include "StackIterator.h"
using namespace std;

int main()

{
	Stack st1;
	st1.Push(4);
	st1.Push(6);
	st1.Push(9);
	Stacklterator iter(&st1);

	iter.Next();
	iter++;
	iter--;
	wcout << iter.Currentltem() << " iter " << endl;

	Stack st2;
	st2.Push(9);
	st2.Swap(st1);
	Increase inc;
	inc.visit(st2);


	Stack st3(st2);
	Stack st4(move(st1));

	wcout << st2.IsEmpty() << endl;
	wcout << st2.Top() << endl;
	st2.Pop();
	wcout << st2.Top() << endl;
	st2.Clear();
	wcout << st2.IsEmpty() << endl;



	system("pause");

}

