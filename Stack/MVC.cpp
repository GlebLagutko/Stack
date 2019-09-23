#include "Stack.h"
#include <string>
#include <Windows.h>
#include "resource.h"
#include <stdio.h>


using namespace std;

/*int main()

{
	Stack st1;
	st1.Push(4);
	st1.Push(6);
	st1.Push(9);
	Stacklterator iter(&st1);

	iter.Next();
	iter++;
	iter--;
	

	Stack st2;
	st2.Push(9);
	st2.Swap(st1);
	

	cout << "Sum " << st2.CalcSum() << endl;
	  


	Stack st3(st2);
	Stack st4(move(st1));
	cout << st2.ToString() << endl;
	wcout << st2.IsEmpty() << endl;
	wcout << st2.Top() << endl;
	st2.Pop();
	wcout << st2.Top() << endl;
	cout << st2.ToString() << endl;

	st2.Clear();
	wcout << st2.IsEmpty() << endl;

	cout << st2.ToString() << endl;



	system("pause");

}*/




INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
	{
		switch LOWORD(wParam) {
		case IDOK:
		{
			EndDialog(hDlg, LOWORD(wParam));
			break;
		}
		case IDC_ADD:
		{
			int a;
			char buf[100];
			a = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE);
			sprintf_s(buf, 100, " %d ", a);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
			break;
		}
		case IDC_DEL:
		{
			/*auto SelIndex = SendMessage(hDlg, LB_GETCURSEL, 0, 0L);   // LB_GETCURSEL;
			SendMessage();*/
			auto item = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, item, NULL);
			break;
		}
		}
	}

	}
	return (INT_PTR)FALSE;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	//MessageBox(NULL, "Hello", "Hello", MB_OK);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, About);
	return 0;
}


