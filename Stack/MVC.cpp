#include "List.h"
#include <string>
#include <Windows.h>
#include "resource.h"
#include <cstdio>
#include "Visitor.h"

using namespace std;
enum operation{INSERT,TO_DELETE,CLEAR};

class StackView {
private:
	HWND _hDlg;
    List* _list;
	int idcList;
public :

	StackView(HWND hDlg, int IDC,List* stack) : _hDlg(hDlg),_list(stack),idcList(IDC) {}



	void UpdateAll() {
			SendDlgItemMessage(_hDlg, idcList, LB_RESETCONTENT, 0, 0);
			SendDlgItemMessage(_hDlg, IDC_LIST_SIZE, LB_RESETCONTENT, 0, 0);
			Listlterator iter(_list);
			int pos = 0;
			ToStringComplexVisitor v;
			for(iter.First(); !iter.IsDone(); iter++) {
				v.visit(iter.Currentltem());
				SendDlgItemMessage(_hDlg, idcList, LB_INSERTSTRING, pos, (LPARAM)v.GetStr().c_str());
				pos++;
			}

			SendDlgItemMessage(_hDlg, IDC_LIST_SIZE, LB_ADDSTRING,0, (LPARAM)to_string(_list->GetSize()).c_str());
		
	}
	
};


INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	static List list1;
	static StackView v(hDlg,IDC_LIST1,&list1);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:	{
		switch LOWORD(wParam) {
		
		case IDC_PUSH_BACK :	{
			int real;
			int imag;
			real = GetDlgItemInt(hDlg, IDC_EDIT_REAL,NULL, TRUE);
			imag = GetDlgItemInt(hDlg, IDC_EDIT_IMAG,NULL, TRUE);
			Complex comp(real,imag);
			list1.PushBack(comp);			
			v.UpdateAll();
			break;
		}

		case IDC_PUSH_FRONT: {
			int real;
			int imag;
			real = GetDlgItemInt(hDlg, IDC_EDIT_REAL, NULL, TRUE);
			imag = GetDlgItemInt(hDlg, IDC_EDIT_IMAG, NULL, TRUE);

			Complex comp(real, imag);

			list1.PushFront(comp);
			v.UpdateAll();
			break;
		}
		case IDC_POP: {
			if (list1.GetSize() == 0)
				break;

			list1.PopFront();
			v.UpdateAll();
			break;
		}
		
		case IDC_SIZE :	{
			string str = "Size: " + to_string(list1.GetSize());
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


