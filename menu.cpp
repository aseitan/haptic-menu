/////////////////////////////////////////////////////////////////////////////
// Name:        samples/menu.cpp
// Purpose:     wxMenu/wxMenuBar sample
// Author:      Vadim Zeitlin
// Modified by:
// Created:     01.11.99
// RCS-ID:      $Id$
// Copyright:   (c) 1999 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#include "wx/textfile.h"
#include <wx/xml/xml.h>


#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/app.h"
    #include "wx/frame.h"
    #include "wx/menu.h"
    #include "wx/msgdlg.h"
    #include "wx/log.h"
    #include "wx/textctrl.h"
    #include "wx/textdlg.h"
	#include "wx/wx.h"
	#include "wx/wxprec.h"  
	#include "wx/statusbr.h"
	
	
#endif
	#include "wx/minifram.h"
	#include "wx/string.h"
	#include "wx/wfstream.h"
	#include "wx/txtstrm.h"
	#include "wx/arrstr.h"
	

	#include "headers/quizPanel.h"
	#include "headers/Communicate.h"


#ifdef __BORLANDC__
#pragma hdrstop
#endif


#if !wxUSE_MENUS
    // nice try...
    #error "menu sample requires wxUSE_MENUS=1"
#endif // wxUSE_MENUS

// not all ports have support for EVT_CONTEXT_MENU yet, don't define
// USE_CONTEXT_MENU for those which don't
#if defined(__WXMOTIF__) || defined(__WXPM__) || defined(__WXX11__)
    #define USE_CONTEXT_MENU 0
#else
    #define USE_CONTEXT_MENU 1
#endif

// this sample is useful when a new port is developed
// and usually a new port has majority of flags turned off


#include "copy.xpm"

#ifndef wxHAS_IMAGES_IN_RESOURCES
    #include "../sample.xpm"
#endif

// ----------------------------------------------------------------------------
// classes
// ----------------------------------------------------------------------------



// Define a new application
class MyApp: public wxApp
{
public:
    bool OnInit();
};

// Define a new frame
class MyFrame: public wxFrame
{
public:
    MyFrame();

    virtual ~MyFrame();

    

protected:
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	void OnEnabled(wxUpdateUIEvent& event);
	void OnAuthDisabled(wxUpdateUIEvent& event);
	void OnAdminLogin(wxUpdateUIEvent& event);
	void OnProfLogin(wxUpdateUIEvent& event);
    void OnGetMenuItemInfo(wxCommandEvent& event);
    void PasswordEntry(wxCommandEvent& event);
	void OnAuth(wxCommandEvent& event);
	void OnRegistration(wxCommandEvent& event);
	void OnQuizAddTip1(wxCommandEvent& event);


#if USE_CONTEXT_MENU
  //  void OnContextMenu(wxContextMenuEvent& event);
#else
    void OnRightUp(wxMouseEvent& event)
        { ShowContextMenu(event.GetPosition()); }
#endif

    

private:
   
    void ShowContextMenu(const wxPoint& pos);

    // the menu previously detached from the menubar (may be NULL)
    wxMenu *m_menu;


    DECLARE_EVENT_TABLE()
};

enum
{
	Menu_Sim_OpenApps = 10,
	Menu_Sim_CloseApps = 11,
	Menu_Sim_SubMenuApp1 = 12,
	Menu_Sim_SubMenuApp2 = 13,
    Menu_Sim_Quit = wxID_EXIT,

	Menu_Record_Auth = 14,
	Menu_Record_Register = 15,
	Menu_Help_File = 16,
	Menu_Help_File_SubMenu_Open = 17,
	Menu_Help_File_SubMenu_Save = 18,

	Menu_Quiz_Add = 19,
	Menu_Quiz_View = 20,
	Menu_Quiz_Add_Tip1 = 21,
	Menu_Quiz_Add_Tip2 = 22,
	Menu_Quiz_Add_Tip3 = 23,
	Menu_Quiz_Add_Tip4 = 24,

	Menu_Help_About
};

// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Menu_Sim_Quit, MyFrame::OnQuit)

    EVT_MENU(Menu_Help_About, MyFrame::OnAbout)

	EVT_MENU(Menu_Record_Register, MyFrame::OnRegistration)

	EVT_MENU(Menu_Record_Auth, MyFrame::OnAuth)
	EVT_UPDATE_UI(Menu_Record_Auth, MyFrame::OnAuthDisabled)


	EVT_UPDATE_UI(Menu_Sim_SubMenuApp1, MyFrame::OnEnabled)
	EVT_UPDATE_UI(Menu_Sim_SubMenuApp2, MyFrame::OnEnabled)

	EVT_UPDATE_UI(Menu_Sim_CloseApps, MyFrame::OnEnabled)
	EVT_UPDATE_UI(Menu_Sim_OpenApps, MyFrame::OnEnabled)
	EVT_UPDATE_UI(Menu_Help_File, MyFrame::OnAdminLogin)

	EVT_UPDATE_UI(Menu_Help_File_SubMenu_Open, MyFrame::OnAdminLogin)
	EVT_UPDATE_UI(Menu_Help_File_SubMenu_Save, MyFrame::OnAdminLogin)
	
	EVT_UPDATE_UI(Menu_Quiz_Add, MyFrame::OnProfLogin)
	EVT_UPDATE_UI(Menu_Quiz_View, MyFrame::OnProfLogin)
	EVT_UPDATE_UI(Menu_Quiz_Add, MyFrame::OnAdminLogin)
	EVT_UPDATE_UI(Menu_Quiz_View, MyFrame::OnAdminLogin)
	EVT_MENU(Menu_Quiz_Add_Tip1, MyFrame::OnQuizAddTip1)

	/*EVT_MENU(Menu_Sim_SubMenuApp1, MyFrame::OnCloseApp1)
	EVT_MENU(Menu_Sim_SubMenuApp2, MyFrame::OnCloseApp2)
	
	EVT_MENU(Menu_Help_File_SubMenu_Open, MyFrame::OnRecordFileOpen)
	EVT_MENU(Menu_Help_File_SubMenu_Save, MyFrame::OnRecordFileSave)
	EVT_MENU(Menu_Quiz_Add, MyFrame::OnQuizEdit)
	EVT_MENU(Menu_Quiz_View, MyFrame::OnQuizView)
	EVT_MENU(Menu_Quiz_Add_Tip1, MyFrame::OnQuizAddTip1)
	EVT_MENU(Menu_Quiz_Add_Tip2, MyFrame::OnQuizAddTip2)
	EVT_MENU(Menu_Quiz_Add_Tip3, MyFrame::OnQuizAddTip3)
	EVT_MENU(Menu_Quiz_Add_Tip4, MyFrame::OnQuizAddTip4)*/

#if USE_CONTEXT_MENU
//    EVT_CONTEXT_MENU(MyFrame::OnContextMenu)
#else
    EVT_RIGHT_UP(MyFrame::OnRightUp)
#endif

    EVT_MENU_OPEN(MyFrame::OnMenuOpen)
    EVT_MENU_CLOSE(MyFrame::OnMenuClose)

    EVT_SIZE(MyFrame::OnSize)
END_EVENT_TABLE()



// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// MyApp
// ----------------------------------------------------------------------------

IMPLEMENT_APP(MyApp)

// The `main program' equivalent, creating the windows and returning the
// main frame
bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    // Create the main frame window
    MyFrame* frame = new MyFrame;

    frame->Show(true);
	
	//frame->SetSize(1200,800);
	frame->Maximize(true);
	//frame->SetWindowStyle(wxFULLSCREEN_ALL);

#if wxUSE_STATUSBAR
    frame->SetStatusText(wxT("Bine ai venit...Inca nu esti logat!"));
#endif // wxUSE_STATUSBAR
//	Communicate *communicate = new Communicate(wxT("Widgets communicate"));
 //   communicate->Show(true);

    
    return true;
}

// ----------------------------------------------------------------------------
// MyFrame
// ----------------------------------------------------------------------------

// Define my frame constructor
MyFrame::MyFrame()
       : wxFrame((wxFrame *)NULL, wxID_ANY, wxT("HapticMed - CeRVA"))
{
    SetIcon(wxICON(sample));
    m_menu = NULL;
  

#if wxUSE_STATUSBAR
    CreateStatusBar();
#endif // wxUSE_STATUSBAR

    // create the menubar
    wxMenu *simMenu = new wxMenu;


	wxMenu* Menu_Sim_SubMenu = new wxMenu;
	Menu_Sim_SubMenu->Append(Menu_Sim_SubMenuApp1, wxT("Simulator 1\tCtrl-1"), wxT("Simulator 1")); 
	Menu_Sim_SubMenu->Append(Menu_Sim_SubMenuApp2, wxT("Simulator 2\tCtrl-2"), wxT("Simulator 2")); 

	simMenu->Append(Menu_Sim_OpenApps,wxT("Deschide simulator"), Menu_Sim_SubMenu);
	simMenu->Append(Menu_Sim_CloseApps, wxT("Inchide simulator\tCtrl-F4"), wxT("Inchide simulator"));
	
	simMenu->Append(Menu_Sim_Quit, wxT("Iesire\tAlt-F4"), wxT("Iesire din aplicatie"));

	wxMenu* Menu_Reg = new wxMenu;

	Menu_Reg->Append(Menu_Record_Register, wxT("Inregistrare\tCtrl-I"), wxT("Inregistrare"));
	Menu_Reg->Append(Menu_Record_Auth, wxT("Autentificare\tCtrl-A"), wxT("Autentificare"));
	

	wxMenu* Menu_Quiz = new wxMenu;


	wxMenu* Menu_Quiz_Add_SubMenu = new wxMenu;

	Menu_Quiz_Add_SubMenu->Append(Menu_Quiz_Add_Tip1, wxT("Ficat normal"), wxT("Ficat normal"));
	Menu_Quiz_Add_SubMenu->Append(Menu_Quiz_Add_Tip2, wxT("Ficat cirotic"), wxT("Ficat cirotic"));
	Menu_Quiz_Add_SubMenu->Append(Menu_Quiz_Add_Tip3, wxT("Ficat tumoral"), wxT("Ficat tumoral"));
	Menu_Quiz_Add_SubMenu->Append(Menu_Quiz_Add_Tip4, wxT("Ficat hepatitic"), wxT("Ficat hepatitic"));


	Menu_Quiz->Append(Menu_Quiz_Add, wxT("Adaugare\tCtrl-E"),Menu_Quiz_Add_SubMenu);
	Menu_Quiz->Append(Menu_Quiz_View, wxT("Vizualizare\tCtrl-W"), wxT("Vizualizare"));



    wxMenu *helpMenu = new wxMenu;
	wxMenu* Menu_Help_SubMenu = new wxMenu;
    helpMenu->Append(Menu_Help_File, wxT("Fisier\tCtrl-G"), Menu_Help_SubMenu);
	
	
	Menu_Help_SubMenu->Append(Menu_Help_File_SubMenu_Open,wxT("Deschide"),wxT("Deschide"));
	Menu_Help_SubMenu->Append(Menu_Help_File_SubMenu_Save,wxT("Salveaza"),wxT("Salveaza"));

	helpMenu->Append(Menu_Help_About, wxT("Des&pre\tF1"), wxT("Despre"));
	
    wxMenuBar* menuBar = new wxMenuBar( wxMB_DOCKABLE );

    menuBar->Append(simMenu, wxT("&Simulator"));

    
	menuBar->Append(Menu_Reg,wxT("In&registrare"));
	menuBar->Append(Menu_Quiz, wxT("Actiuni intrebari"));

    menuBar->Append(helpMenu, wxT("&Ajutor"));

  

    // associate the menu bar with the frame
    SetMenuBar(menuBar);


    wxPanel *m_parent = new wxPanel(this, wxID_ANY);
  
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    PanelL *m_lp;
    PanelR *m_rp;
    m_lp = new PanelL(m_parent, 1);
    m_rp = new PanelR(m_parent);

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(hbox);



}

MyFrame::~MyFrame()
{
    delete m_menu;

    // delete the event handler installed in ctor
   // PopEventHandler(true);

}




// ----------------------------------------------------------------------------
// menu callbacks
// ----------------------------------------------------------------------------

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    (void)wxMessageBox(wxT("Copyright (c) CeRVA - 2012"),
                       wxT("HapticMed"),
                       wxOK | wxICON_INFORMATION);
}


void MyFrame::PasswordEntry(wxCommandEvent& WXUNUSED(event))
{
    
	wxTextCtrl* pass_TextCtl;
	wxTextCtrl* user_TextCtl;
	pass_TextCtl = new wxTextCtrl(this, wxID_ANY, "Test Message Box");
	user_TextCtl = new wxTextCtrl(this, wxID_ANY, "Test Message Box");

}



#include "wx/richtooltip.h"

bool ok = false, logat=false, adminLogat = false, profLogat = false;
class AuthDialog : public wxDialog
{
public:
	
    AuthDialog(wxWindow* parent)
        : wxDialog(parent, wxID_ANY, "Autentificare",
                   wxDefaultPosition, wxDefaultSize,
				   wxDEFAULT_FRAME_STYLE | wxSTATIC_BORDER)
    {
        // Create the controls.
	
        m_textTitle = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
		m_pass = new wxTextCtrl(this,wxID_ANY, wxEmptyString, wxDefaultPosition,wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, wxTextCtrlNameStr);


        wxButton* btnShowText = new wxButton(this, wxID_ANY, "OK");
        wxButton* btnShowBtn = new wxButton(this, wxID_ANY, "Anulare");

		m_textTitle->SetMinSize(wxSize(300, 25));
		m_pass->SetMinSize(wxSize(300, 25));

        wxBoxSizer* const sizer = new wxBoxSizer(wxVERTICAL);
		
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Utilizator:"));
        sizer->Add(m_textTitle, wxSizerFlags().Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Parola:"));
		sizer->Add(m_pass, wxSizerFlags(2).Expand().Border());

        wxBoxSizer* const sizerBtns = new wxBoxSizer(wxHORIZONTAL);
        
		sizerBtns->Add(btnShowText, wxSizerFlags().Border(wxRIGHT));
        sizerBtns->Add(btnShowBtn, wxSizerFlags().Border(wxLEFT));
        
		sizer->Add(sizerBtns, wxSizerFlags().Centre().Border());
      

        SetSizerAndFit(sizer);


        // And connect the event handlers.
        btnShowText->Connect
                     (
                        wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(AuthDialog::OnOK),
                        NULL,
                        this
                     );

        btnShowBtn->Connect
                    (
                        wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(AuthDialog::OnCancel),
                        NULL,
                        this
                    );
    }

	bool Logat()
	{
		

			if(logat){
				return true; 
				}
			else return false;
	}

	bool adminLogin()
	{
	if (adminLogat)
		{
		return true;
		}
	else return false;
	}

	bool profLogin()
	{
	if (profLogat)
		{
		return true;
		}
	else return false;
	}

private:
   
     void OnOK(wxCommandEvent& WXUNUSED(event))
    {
		wxFileInputStream input("c:\\users.txt");
		wxTextInputStream text(input);
		while(input.IsOk() && !input.Eof())
			{
			wxString line=text.ReadLine();
			wxArrayString words;		
			words = wxSplit(line,' ','\\');
			if(words.Count()!=0)
			{
				wxString id = words[2];
				wxString pass = words[3];
				wxString id2 = m_textTitle->GetValue();
				wxString pass2 = m_pass->GetValue();
				if(wxStricmp(id,id2) == 0 && wxStricmp(pass,pass2) == 0)
					{

					this->Show(false);
					ok=true;
				wxMessageBox(wxT("Autentificare reusita!"),
								wxT("HapticMed"),
								wxOK | wxICON_INFORMATION);
					break;
				
					}
			}
		}
		wxFileInputStream inputAdmin("c:\\rxu.txt");
		wxTextInputStream textAdmin(inputAdmin);
		while(inputAdmin.IsOk() && !inputAdmin.Eof() )
			{
				wxString line = textAdmin.ReadLine();
				wxArrayString words;		
				words = wxSplit(line,' ','\\');
				if(words.Count()!=0){
					if(wxStricmp(words[0],m_textTitle->GetValue()) == 0){
						if(wxStricmp(words[1],"admin")==0)
							{ 
								adminLogat = true; profLogat = true; logat = true;
								
								break;
							}
						else if(wxStricmp(words[1],"Profesor")==0)
							{ 
								profLogat = true; logat = true; 
								
								break;
							}
						else if(wxStricmp(words[1],"Elev")==0)
							{
								logat = true; 
								
								break;
							}
						}
					}

			}

		
		if(!ok)
		{
			logat = false;
			adminLogat = false;
			profLogat = false;
			
			wxMessageBox(wxT("Date de logare invalide!"),
                       wxT("HapticMed"),
					   wxOK | wxICON_ERROR);
		}
		
                             
    }

    void OnCancel(wxCommandEvent& WXUNUSED(event))
    {
      //  DoShowTip(FindWindow(wxID_OK));
		this->Show(false);
		m_textTitle->SetValue("");
		m_pass->SetValue("");
    }

    wxTextCtrl* m_textTitle;
	wxTextCtrl* m_pass;
    
};

void MyFrame::OnAuth(wxCommandEvent& WXUNUSED(event))
{
    AuthDialog dialog(this);
    dialog.ShowModal();
	
}
void MyFrame::OnEnabled(wxUpdateUIEvent& event)
{
	AuthDialog dialog(this);

	event.Enable((dialog.Logat()));
}

void MyFrame::OnAuthDisabled(wxUpdateUIEvent& event)
{
	AuthDialog dialog(this);

	event.Enable((!dialog.Logat()) && (!dialog.adminLogin()) && (!dialog.profLogin()));
}


void MyFrame::OnAdminLogin(wxUpdateUIEvent& event)
{
	AuthDialog dialog(this);

	event.Enable((dialog.adminLogin()));
}

void MyFrame::OnProfLogin(wxUpdateUIEvent& event)
{
	AuthDialog dialog(this);

	event.Enable((dialog.profLogin()));
}


class RegDialog : public wxDialog
{
public:
    RegDialog(wxWindow* parent)
        : wxDialog(parent, wxID_ANY, "Inregistrare",
                   wxDefaultPosition, wxDefaultSize,
				   wxDEFAULT_FRAME_STYLE | wxSTATIC_BORDER)
    {
        // Create the controls.
	
    wxString* weights = new wxString[2];
    
    weights[0] = _("Profesor");
    weights[1] = _("Elev");
    


        nume = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
		prenume = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
		id = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
		parola = new wxTextCtrl(this,wxID_ANY, wxEmptyString, wxDefaultPosition,wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, wxTextCtrlNameStr);
		chkParola = new wxTextCtrl(this,wxID_ANY, wxEmptyString, wxDefaultPosition,wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, wxTextCtrlNameStr);
		tipUtilizator = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 2, weights, 1);
		

        wxButton* btnShowText = new wxButton(this, wxID_ANY, "Acceptare");
        wxButton* btnShowBtn = new wxButton(this, wxID_ANY, "Anulare");

		nume->SetMinSize(wxSize(300, 25));
		prenume->SetMinSize(wxSize(300, 25));
		id->SetMinSize(wxSize(300, 25));
		parola->SetMinSize(wxSize(300, 25));
		chkParola->SetMinSize(wxSize(300, 25));
		tipUtilizator->SetMinSize(wxSize(300, 25));

        wxBoxSizer* const sizer = new wxBoxSizer(wxVERTICAL);
		
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Nume:"));
        sizer->Add(nume, wxSizerFlags().Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Prenume:"));
		sizer->Add(prenume, wxSizerFlags(2).Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&ID:"));
		sizer->Add(id, wxSizerFlags(2).Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Parola:"));
		sizer->Add(parola, wxSizerFlags(2).Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Confirmare parola:"));
		sizer->Add(chkParola, wxSizerFlags(2).Expand().Border());
		sizer->Add(new wxStaticText(this, wxID_ANY, "&Tipul utilizatorului:"));
		sizer->Add(tipUtilizator, wxSizerFlags(2).Expand().Border());




        wxBoxSizer* const sizerBtns = new wxBoxSizer(wxHORIZONTAL);
        
		sizerBtns->Add(btnShowText, wxSizerFlags().Border(wxRIGHT));
        sizerBtns->Add(btnShowBtn, wxSizerFlags().Border(wxLEFT));
        
		sizer->Add(sizerBtns, wxSizerFlags().Centre().Border());
      

        SetSizerAndFit(sizer);


        // And connect the event handlers.
        btnShowText->Connect
                     (
                        wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(RegDialog::OnOK),
                        NULL,
                        this
                     );

        btnShowBtn->Connect
                    (
                        wxEVT_COMMAND_BUTTON_CLICKED,
                        wxCommandEventHandler(RegDialog::OnCancel),
                        NULL,
                        this
                    );
    }

private:
   


    void OnOK(wxCommandEvent& WXUNUSED(event))
    {	//wxTextFile file( wxT("c:/"+nume->GetValue()+"_"+prenume->GetValue()+".txt"));
		
		bool gasit = false;

/** Da eroare! **/

		/*wxFileInputStream kill(wxT("c:\\users.txt"));
		wxTextInputStream inpt(kill);
		
			while(kill.IsOk() && !kill.Eof() )
			{
				wxString line = inpt.ReadLine();
			
				if(line.Contains(id->GetValue()))
				{
					wxMessageBox(wxT("ID-ul exista deja!"),
								wxT("HapticMed"),
								wxOK | wxICON_EXCLAMATION);
					gasit = true;
					if(gasit) { break; }
					
				}
			}*/
				
			


		if(nume->IsEmpty() || prenume->IsEmpty() || id->IsEmpty() || parola->IsEmpty() || tipUtilizator->GetStringSelection().IsEmpty())
		{
			wxMessageBox(wxT("Unul dintre câmpuri este liber!"),
								wxT("HapticMed"),
								wxOK | wxICON_ERROR);
			
		}
		
		else if(parola->GetValue().compare(chkParola->GetValue())!=0)
			{
				wxMessageBox(wxT("Parolele nu corespund!"),
								wxT("HapticMed"),
								wxOK | wxICON_ERROR);
			}
		
		

			else if(gasit==false){
		
					wxTextFile file( wxT("c:/users.txt") );
					wxTextFile fileRXU( wxT("c:/rxu.txt") );
					file.Open();
					fileRXU.Open();
					wxDateTime dt;
					
					file.AddLine( (nume->GetValue()+" "+prenume->GetValue()+" "+id->GetValue()+" "+parola->GetValue())+ " "+dt.Now().FormatISOCombined(' ') );
					fileRXU.AddLine( id->GetValue()+" "+tipUtilizator->GetStringSelection());
					file.Write();
					file.Close();
					fileRXU.Write();
					fileRXU.Close();
					this->Show(false);
			}

			
		
	}
    void OnCancel(wxCommandEvent& WXUNUSED(event))
    {
      //  DoShowTip(FindWindow(wxID_OK));
		this->Show(false);
		//m_textTitle->SetValue("");
		//m_pass->SetValue("");
    }

    wxTextCtrl* nume;
	wxTextCtrl* prenume;
	wxTextCtrl* id;
	wxTextCtrl* parola;
	wxTextCtrl* chkParola;
	wxChoice*   tipUtilizator;

    
};

void MyFrame::OnRegistration(wxCommandEvent& WXUNUSED(event))
{
    RegDialog dialog(this);
    dialog.ShowModal();
}
void MyFrame::OnQuizAddTip1(wxCommandEvent & WXUNUSED(event))
{
	 wxPanel *m_parent = new wxPanel(this, wxID_ANY);
  
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    PanelL *m_lp;
    PanelR *m_rp;
    m_lp = new PanelL(m_parent, 1);
    m_rp = new PanelR(m_parent);

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 5);

	m_parent->SetSizer(hbox);
	m_parent->SetSize((this->GetSize()));
	
}
