#include <wx/stattext.h>
#include "headers/Communicate.h"
#include "wx/xml/xml.h"
#include "wx/xrc/xmlres.h"
#include "wx/wx.h"
#include "headers/quizPanel.h"
#include "headers/quiz.h"
#include "wx/textctrl.h"
#include "wx/textdlg.h"

#include "wx/wxprec.h"  
#include "wx/minifram.h"
#include "wx/string.h"
#include "wx/wfstream.h"
#include "wx/txtstrm.h"
#include "wx/arrstr.h"

//IMPLEMENT_DYNAMIC_CLASS(PanelL, wxPanel)

BEGIN_EVENT_TABLE(PanelL, wxPanel)
//	EVT_UPDATE_UI( ID_bt_SaveQuestion, PanelL::OnAdd)
	//EVT_BUTTON( ID_bt_SaveQuestion, PanelL::OnAdd)
END_EVENT_TABLE()

PanelL::PanelL(wxPanel * parent, int type)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{

  lType = type;
  count = -1;
  m_parent = parent;
   
  st_LiverType = new wxStaticText(this, wxID_ANY, "Tip ficat: "+wxString::Format(wxT("%d"), lType), wxPoint(10, 10));

  st_QTitle = new wxStaticText(this, wxID_ANY, "Titlul intrebarii", wxPoint(10,60));
  tc_QTitle = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(100,50),wxSize(400, 40),wxTE_MULTILINE); 
  

  st_QText = new wxStaticText(this, wxID_ANY, "Intrebarea", wxPoint(50,130));
  tc_QText = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(120,110),wxSize(380, 60),wxTE_MULTILINE);
  
  cb_Active = new wxCheckBox(this, ID_cb_qActive, "Intrebare activa", wxPoint(570,130));
  cb_Active->SetToolTip("Bifat->Activ; Debifat->Inactiv");

  st_AText1 = new wxStaticText(this, wxID_ANY, "Raspunsul 1", wxPoint(100,200));
  tc_AText1 = new wxTextCtrl(this, ID_tc_AText1, wxEmptyString,wxPoint(170,180),wxSize(330, 60),wxTE_MULTILINE);
  rb_Valid1 = new wxRadioButton(this, ID_rb_Valid1, "Raspuns corect", wxPoint(570,200));

  st_AText2 = new wxStaticText(this, wxID_ANY, "Raspunsul 2", wxPoint(100,270));
  tc_AText2 = new wxTextCtrl(this, ID_tc_AText2, wxEmptyString,wxPoint(170,250),wxSize(330, 60),wxTE_MULTILINE);
  rb_Valid2 = new wxRadioButton(this, ID_rb_Valid2, "Raspuns corect", wxPoint(570,270));

  st_AText3 = new wxStaticText(this, wxID_ANY, "Raspunsul 3", wxPoint(100,340));
  tc_AText3 = new wxTextCtrl(this, ID_tc_AText3, wxEmptyString,wxPoint(170,320),wxSize(330, 60),wxTE_MULTILINE);
  rb_Valid3 = new wxRadioButton(this, ID_rb_Valid3, "Raspuns corect", wxPoint(570,340));

  st_AText4 = new wxStaticText(this, wxID_ANY, "Raspunsul 4", wxPoint(100,410));
  tc_AText4 = new wxTextCtrl(this, ID_tc_AText4, wxEmptyString,wxPoint(170,390),wxSize(330, 60),wxTE_MULTILINE);
  rb_Valid4 = new wxRadioButton(this, ID_rb_Valid4, "Raspuns corect", wxPoint(570,410));

  st_AText5 = new wxStaticText(this, wxID_ANY, "Raspunsul 5", wxPoint(100,480));
  tc_AText5 = new wxTextCtrl(this, ID_tc_AText5, wxEmptyString,wxPoint(170,460),wxSize(330, 60),wxTE_MULTILINE);
  rb_Valid5 = new wxRadioButton(this, ID_rb_Valid5, "Raspuns corect", wxPoint(570,480));

  

 // bt_AddAnswer = new wxButton(this, 101, "Adauga raspuns", wxPoint(400,250)); 
  bt_SaveQuestion = new wxButton(this, ID_bt_SaveQuestion, "Salveaza intrebarea", wxPoint(150,560)); 
  bt_SaveQuestion->SetToolTip("Salveaza intrebarea curenta si adauga alta");
  bt_Cancel = new wxButton(this, ID_bt_Cancel, "Sterge intrebarea", wxPoint(300,560)); 
  bt_Cancel->SetToolTip("Sterge intrebarea curenta");

  bt_Previous = new wxButton(this, ID_bt_Previous, "Intrebarea anterioara", wxPoint(50,640)); 
  bt_Previous->SetToolTip("Intrebarea anterioara");
  bt_Next = new wxButton(this, ID_bt_Next, "Intrebarea urmatoare", wxPoint(400,640)); 
  bt_Next->SetToolTip("Intrebarea urmatoare");
//  bt_SaveSet = new wxButton(this, ID_bt_SaveSet, "Salveaza setul", wxPoint(225,600)); 
//  bt_SaveSet->SetToolTip( "Salveaza setul de intrebari");

 // m_plus = new wxButton(this, ID_PLUS, wxT("+"), 
    //  wxPoint(10, 10));
 // m_minus = new wxButton(this, ID_MINUS, wxT("-"), 
  //    wxPoint(10, 60));
//  Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, 
    // wxCommandEventHandler(PanelL::OnPlus));
//  Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, 
      //wxCommandEventHandler(PanelL::OnMinus));

  Connect(ID_bt_SaveQuestion, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PanelL::OnAdd));
  Connect(ID_bt_Cancel, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PanelL::OnCancel));	

}


PanelL::~PanelL()
{

//delete quiz;
}

void PanelL::OnPlus(wxCommandEvent & WXUNUSED(event))
{
  count++;

  Communicate *comm = (Communicate *) m_parent->GetParent();
  comm->m_rp->m_text->SetLabel(wxString::Format(wxT("%d"), count));
}

void PanelL::OnMinus(wxCommandEvent & WXUNUSED(event))
{
  count--;

  Communicate *comm = (Communicate *) m_parent->GetParent();
  comm->m_rp->m_text->SetLabel(wxString::Format(wxT("%d"), count));
}


PanelR::PanelR(wxPanel * parent)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition, 
         wxSize(270, 150), wxBORDER_SUNKEN)
{
  //  m_text = new wxStaticText(this, -1, wxT("0"), wxPoint(40, 60));
}
 
void PanelL::OnAdd(wxCommandEvent& WXUNUSED(event))
{  

int valid1 = 0, valid2 = 0, valid3 = 0, valid4 = 0, valid5 = 0;

	qIndex = 1;
//qIndex = getLastIndex(lType);

if(rb_Valid1->GetValue() == true)
	valid1 = 1;
else if(rb_Valid2->GetValue() == true)
	valid2 = 1;
else if(rb_Valid3->GetValue() == true)
	valid3 = 1;
else if(rb_Valid4->GetValue() == true)
	valid4 = 1;
else if(rb_Valid5->GetValue() == true)
	valid5 = 1;


if(cb_Active->IsChecked())
	qActive = 1;

quiz = new Quiz(qActive, qIndex, tc_QTitle->GetValue(), tc_QText->GetValue(), tc_AText1->GetValue(), valid1, tc_AText2->GetValue(), valid2, tc_AText3->GetValue(),valid3, tc_AText4->GetValue(),valid4, tc_AText5->GetValue(),valid5);

wxXmlDocument *wxDoc = new wxXmlDocument();

if(wxDoc->Load("LiverType_"+wxString::Format(wxT("%d"), lType)+".xml"))
	{
		quiz->append( lType );
	}
else{
		quiz->save( lType );	
	}

}

void PanelL::OnCancel(wxCommandEvent& WXUNUSED(event))
{
	tc_QTitle->SetValue("");
	tc_QText->SetValue("");
	tc_AText1->SetValue("");
	tc_AText2->SetValue("");
	tc_AText3->SetValue("");
	tc_AText4->SetValue("");
	tc_AText5->SetValue("");
	cb_Active->SetValue(false);
	rb_Valid1->SetValue(false);
	rb_Valid2->SetValue(false);
	rb_Valid3->SetValue(false);
	rb_Valid4->SetValue(false);
	rb_Valid5->SetValue(false);
}