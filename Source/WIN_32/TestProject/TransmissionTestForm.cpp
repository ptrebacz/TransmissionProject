//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TransmissionTestForm.h"
#include "b_transmission.h"
#include "b_collection.h"

//#include "Web.HTTPApp.hpp"
//#include "ALXmlDoc.hpp"

#include <windows.h>
#include <winsock2.h>
#include <System.hpp>

#pragma comment (lib, "WS2_32.lib")
#pragma comment (lib, "Wininet.lib")

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma resource "*.dfm"
TForm16 *Form16;

//---------------------------------------------------------------------------

//const WINAPI WndProc(TMessage &Message)
//{
//	switch(Message.Msg)
//	{
//		case WM_CLOSE:
//			int i =0;
//		break;
//	}
//
//	Form16->WndProc(Message);
//}

//---------------------------------------------------------------------------
__fastcall TForm16::TForm16(TComponent* Owner)
	: TForm(Owner)
{
//	this->WndProc = WndProc;
//	this->WindowProc = WndProc;

}
//---------------------------------------------------------------------------
void __fastcall TForm16::cxButton2Click(TObject *Sender)
{

//	CTransmission *transmission = new CTransmission();
//
//	for(int i=0; i<10000000; i++)
//	{
//		CTransaction *transaction1 = new CTransaction();
//		transaction1->name = "abc"+(UnicodeString)i;
//		transmission->Add(transaction1);
//	}
//
//	SAFEDELETE(transmission);
//
//	CTransaction *transaction1 = new CTransaction();
//	CTransaction *transaction2 = transaction1;
//
//	SAFEDELETE(transaction1);
//	int i =0;

}
//---------------------------------------------------------------------------

void __fastcall TForm16::FormCloseQuery(TObject *Sender, bool &CanClose)
{
//	int ex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm16::FormDestroy(TObject *Sender)
{
//	int ex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm16::cxButton1Click(TObject *Sender)
{
//	TALXMLDocument *document = new TALXMLDocument("Doc");
//	TALXMLNode *child = document->AddChild("Main");
//	for(int i=0; i<10000; i++)
//	{
//		TALXMLNode *node = child->AddChild("i");
//		node->NodeValue = (UnicodeString)i;
//		for(int ii=0; ii<5; ii++)
//		{
//			TALXMLNode *node1 = node->AddChild("ii");
//			node1->NodeValue = (UnicodeString)ii;
//
//		}
//	}
//
//	TMemoryStream *ms = new TMemoryStream();
//	ms->Position = 0;
//	document->SaveToStream(ms);
//	ms->SaveToFile("C:\\test\\ms.xml");
//	SAFEDELETE(document);
//	SAFEDELETE(ms);
}
//---------------------------------------------------------------------------

void __fastcall TForm16::cxButton3Click(TObject *Sender)
{
//	for(int i=0; i<100; i++)
//	{
//		TMemoryStream *ms = new TMemoryStream();
//		ms->Position = 0;
//		ms->LoadFromFile("C:\\test\\ms.xml");
//		ms->Position = 0;
//		TALXMLDocument *document = new TALXMLDocument("Doc");
//		document->LoadFromStream(ms);
//		SAFEDELETE(document);
//		SAFEDELETE(ms);
//	}
}
//---------------------------------------------------------------------------

