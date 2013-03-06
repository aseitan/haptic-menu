#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include "headers/quizPanel.h"
#include <wx/wxprec.h>


class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);


    PanelL *m_lp;
    PanelR *m_rp;
    wxPanel *m_parent;

};
#endif