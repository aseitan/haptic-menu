#ifndef QUIZ_H
#define QUIZ_H

#include "wx/textfile.h"
#include "wx/msgdlg.h"
#include <wx/wx.h>

class Quiz
{
public:
	Quiz *quiz;
	Quiz();
    Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1);
	Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2);
	Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3);
	Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3, wxString qAText4, int qCBValid4);
	Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3, wxString qAText4, int qCBValid4, wxString qAText5, int qCBValid5);

	void set_qTitle(wxString qTitle);
	void get_qTitle(wxString qTitle);

	void save(int);
	void fillQuiz(void);
	void append(int);
	
	wxString qSetTitle, qTitle, qText, qAText1, qAText2, qAText3, qAText4, qAText5;
	int qCBValid1, qCBValid2, qCBValid3, qCBValid4, qCBValid5, qActive, qIndex;


};
#endif
