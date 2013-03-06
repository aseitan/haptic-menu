#ifndef MENU_H
#define MENU_H

#include "headers/quizPanel.h"
#include <wx/wxprec.h>


class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);


    PanelL *m_lp;
    PanelR *m_rp;
    wxPanel *m_parent;

};
#endif