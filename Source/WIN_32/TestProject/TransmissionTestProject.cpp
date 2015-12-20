//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "b_basicclass.h"

//---------------------------------------------------------------------------
USEFORM("TransmissionTestForm.cpp", Form16);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE hi, HINSTANCE hpi, LPTSTR cmd, int sh)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm16), &Form16);
		Application->Run();


	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
