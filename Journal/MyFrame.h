
#pragma once
#include "wx/wx.h"
#include "wx/stc/stc.h"
class MyFrame : public wxFrame
{

public:
	MyFrame(const wxString& title);
	//event handlers 

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event); //save data from text box
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);


	wxPanel* panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(1440, 1080));
	//wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(50, 200), wxSize(200, 300));
	wxStyledTextCtrl* editor = new wxStyledTextCtrl(panel, wxID_ANY, wxPoint(0, 0), wxSize(1440, 1080));
	
	~MyFrame();

private:
	wxString CurrentDocPath;
	DECLARE_EVENT_TABLE();

	enum
	{
		BUTTON_Hello = wxID_HIGHEST + 1,
		BUTTON_Goodbye = wxID_HIGHEST + 2,
		BUTTON_ENEMY1 = wxID_HIGHEST + 3,
		BUTTON_ALLIE1 = wxID_HIGHEST + 4,
		BUTTON_ATTACK = wxID_HIGHEST + 5,
		MENU_SaveAs,
		MENU_ONOPEN,
		MENU_Save
	};
};



