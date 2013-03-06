#include "headers/Communicate.h"

Communicate::Communicate(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(290, 150))
{
  m_parent = new wxPanel(this, wxID_ANY);

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  m_lp = new PanelL(m_parent, 0);
  m_rp = new PanelR(m_parent);

  hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
  hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

  m_parent->SetSizer(hbox);

  this->Centre();
}