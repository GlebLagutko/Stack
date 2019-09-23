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
	static Stack st1;


	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
	{
		switch LOWORD(wParam) {
		case IDOK:	{
			EndDialog(hDlg, LOWORD(wParam));
			break;
		}
		case IDC_PUSH :	{
			int a;
			
			a = GetDlgItemInt(hDlg, IDC_EDIT_STACK, NULL, FALSE);
			st1.Push(a);
		

			char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
			
				
			break;
		}
		case IDC_POP: {
			if (st1.GetCapacity() == 0)
				break;
			st1.Pop();
			char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
			break;
		}
		case IDC_CLEAR : {
			st1.Clear();
			char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
				break;
			}
		case IDC_ISEMPTY :	{
			// if(st1.GetCapacity() == 0)
					
				break;
			}
		case IDC_TOP :	{
			/*char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)st1.Top());*/


				break;
			}
		case IDC_SIZE :
		{break; }
		case IDC_SHOW :	{
			char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
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


