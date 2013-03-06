#ifndef QUIZPANEL_H
#define QUIZPANEL_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/xml/xml.h>
#include "headers/quiz.h"
#include "wx/textctrl.h"
#include "wx/textdlg.h"
#include "wx/radiobox.h"

#include "wx/wxprec.h"  


class PanelL : public wxPanel
{


public:
    PanelL(wxPanel *parent, int type);
	PanelL();

	virtual ~PanelL();

	Quiz *quiz;

	wxStaticText *st_LiverType;
	wxStaticText *st_QTitle;
	wxStaticText *st_QText;
	wxStaticText *st_AText1;
	wxStaticText *st_AText2;
	wxStaticText *st_AText3;
	wxStaticText *st_AText4;
	wxStaticText *st_AText5;

	wxTextCtrl *tc_QTitle;
	wxTextCtrl *tc_QText; 
	wxTextCtrl *tc_AText1;
	wxTextCtrl *tc_AText2;
	wxTextCtrl *tc_AText3;
	wxTextCtrl *tc_AText4;
	wxTextCtrl *tc_AText5;
	
	wxRadioButton *rb_Valid1;
	wxRadioButton *rb_Valid2;
	wxRadioButton *rb_Valid3;
	wxRadioButton *rb_Valid4;
	wxRadioButton *rb_Valid5;

	wxCheckBox	*cb_Active;

	wxButton *bt_AddAnswer;
	wxButton *bt_SaveQuestion;
	wxButton *bt_Cancel;
	wxButton *bt_SaveSet;
	wxButton *bt_Previous;
	wxButton *bt_Next;

	wxXmlDocument *doc;

	wxXmlNode *root;
	wxXmlNode *node2;

    wxButton *m_plus;
    wxButton *m_minus;
    wxPanel *m_parent;

    int count, qIndex, qActive, lType;

//	DECLARE_DYNAMIC_CLASS(PanelL)
	DECLARE_EVENT_TABLE()
    void OnPlus(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);
	void OnAdd(wxCommandEvent& (event));
	void OnCancel(wxCommandEvent& (event));

};

class PanelR : public wxPanel
{
public:
    PanelR(wxPanel *parent);

    void OnSetText(wxCommandEvent & event);

    wxStaticText *m_text;

};

//const int ID_PLUS = 103;
//const int ID_MINUS = 102;

const int ID_tc_AText1 = 101;
const int ID_tc_AText2 = 102;
const int ID_tc_AText3 = 103;
const int ID_tc_AText4 = 104;
const int ID_tc_AText5 = 105;
	
const int ID_rb_Valid1 = 106;
const int ID_rb_Valid2 = 107;
const int ID_rb_Valid3 = 108;
const int ID_rb_Valid4 = 109;
const int ID_rb_Valid5 = 110;

const int ID_bt_AddAnswer = 201;
const int ID_bt_SaveQuestion = 202;
const int ID_bt_Cancel = 203;
const int ID_bt_SaveSet = 204;

const int ID_cb_qActive = 205;

const int ID_bt_Previous = 206;
const int ID_bt_Next = 207;

#endif