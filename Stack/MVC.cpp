#include "Stack.h"
#include <string>
#include <Windows.h>
#include "resource.h"
#include <stdio.h>


using namespace std;
enum operation{INSERT,TO_DELETE};

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


void ShowAnswer( string str, HWND hDlg ) {
	char buf[2048];
	strcpy_s(buf, str.c_str());

	SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);
	
}

class View {
public :
	void UpdateWin(string str, HWND hDlg, int IDC,operation op, int pos)
	{
		switch (op) {
		case INSERT:{
			char buf[2048];
			strcpy_s(buf, str.c_str());
			SendDlgItemMessage(hDlg, IDC, LB_INSERTSTRING, pos, (LPARAM)buf);
			break;
			}
		
	 
		case TO_DELETE:{
			SendDlgItemMessage(hDlg, IDC, LB_DELETESTRING, pos, 0);
				
			}
			
		}

	};
	
};


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Stack st1;
	static View v;
	static int pos = 0;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
	{
		switch LOWORD(wParam) {
		
		case IDC_PUSH :	{
			int a;
			
			a = GetDlgItemInt(hDlg, IDC_EDIT_STACK, NULL, FALSE);
			st1.Push(a);
			//ShowAnswer(st1.ToString(), hDlg);
			pos = st1.GetSize() - 1;
			v.UpdateWin(st1.ToString(), hDlg, IDC_LIST1,INSERT,pos);
			

			
			
				
			break;
		}
		case IDC_POP: {
			if (st1.GetSize() == 0)
				break;
			st1.Pop();
			v.UpdateWin(st1.ToString(), hDlg, IDC_LIST1,TO_DELETE,pos);
			pos = st1.GetSize() - 1;
		//	//ShowAnswer(st1.ToString(), hDlg);
			/*char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/
			break;
		}
		case IDC_CLEAR : {
			
			for(int i = 0 ; i < st1.GetSize(); i++)
				v.UpdateWin(st1.ToString(), hDlg, IDC_LIST1, TO_DELETE, 0);
			st1.Clear();
			//ShowAnswer(st1.ToString(), hDlg);
		//	v.UpdateWin(st1.ToString(), hDlg, IDC_LIST1);
			/*char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/
				break;
			}
		case IDC_ISEMPTY :	{
			string str;
			if (st1.GetSize() == 0)
				str = "Yes";
			else
				str = "No";
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, NULL, MB_OK);
		//	v.UpdateWin(str, hDlg, IDC_LIST1);//ShowAnswer(str, hDlg);
		/*	char buf[20];
			strcpy_s(buf, str.c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/
				break;
			}
		case IDC_TOP :	{
			string str = "Top : " + to_string(st1.Top());
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, "", MB_OK);
		//	v.UpdateWin(str.c_str(), hDlg, IDC_LIST1);//ShowAnswer(str, hDlg);
		/*	char buf[20];
			strcpy_s(buf, str.c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/

				break;
			}
		case IDC_SIZE :	{
			string str = "Size: " + to_string(st1.GetSize());
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, "", MB_OK);
		//	v.UpdateWin(str.c_str(), hDlg, IDC_LIST1);//	ShowAnswer(str, hDlg);
		/*	char buf[20];
			strcpy_s(buf, str.c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/
				break;
			}
		case IDC_SHOW :	{
		//	v.UpdateWin(st1.ToString(), hDlg, IDC_LIST1);//	ShowAnswer(st1.ToString(), hDlg);
		/*	char buf[2048];
			strcpy_s(buf, st1.ToString().c_str());

			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, NULL, NULL);
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, NULL, (LPARAM)buf);*/
				break;
			}
		case IDC_EXIT: {
			EndDialog(hDlg, LOWORD(wParam));
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


