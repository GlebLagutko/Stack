#include "Stack.h"
#include <string>
#include <Windows.h>
#include "resource.h"
#include <stdio.h>


using namespace std;
enum operation{INSERT,TO_DELETE};

class StackView {
private:
	HWND _hDlg;
	Stack* _stack;
	int idcList;
public :

	StackView(HWND hDlg, int IDC,Stack* stack) : _hDlg(hDlg),_stack(stack),idcList(IDC) {}

	void UpdateWin(operation op, int pos) {
		switch (op) {
		case INSERT:{
			char buf[2048];
			strcpy_s(buf, _stack->ToString().c_str());
			SendDlgItemMessage(_hDlg, idcList, LB_INSERTSTRING, pos, (LPARAM)buf);
			break;
			}
		case TO_DELETE:{
			SendDlgItemMessage(_hDlg, idcList, LB_DELETESTRING, pos, 0);				
			}
			
		}

	};
	
};


INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	static Stack st1;
	static StackView v(hDlg,IDC_LIST1,&st1);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:	{
		switch LOWORD(wParam) {
		
		case IDC_PUSH :	{
			int a;
			a = GetDlgItemInt(hDlg, IDC_EDIT_STACK,NULL, TRUE);
			st1.Push(a);
			
			v.UpdateWin(INSERT,st1.GetSize() -  1);
			break;
		}
		case IDC_POP: {
			if (st1.GetSize() == 0)
				break;
			st1.Pop();
			v.UpdateWin(TO_DELETE, st1.GetSize() - 1);
			break;
		}
		case IDC_CLEAR : {	
			for(int i = 0 ; i < st1.GetSize(); i++)
				v.UpdateWin( TO_DELETE, 0);
			st1.Clear();
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
			MessageBox(NULL, buf, "", MB_OK);
			break;
			}
		case IDC_TOP :	{
			string str = "Top : " + to_string(st1.Top());
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, "", MB_OK);
			break;
			}
		case IDC_SIZE :	{
			string str = "Size: " + to_string(st1.GetSize());
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, "", MB_OK);
			break;
			}
		case IDC_SUM :	{
			string str = "Summa: " + to_string(st1.CalcSum());
			char buf[30];
			strcpy_s(buf, str.c_str());
			MessageBox(NULL, buf, "", MB_OK);
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
	_In_ int       nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Controller);
	return 0;
}


