
#include "MyFrame.h"
#include "time.h"
#include <iostream>
#include <sstream>
#include <string>



BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
EVT_MENU(MENU_SaveAs, MyFrame::OnSaveAs)
EVT_MENU(MENU_ONOPEN, MyFrame::OnOpen)
EVT_BUTTON(BUTTON_Goodbye, MyFrame::OnQuit)
EVT_BUTTON(MENU_Save, MyFrame::OnSave)
END_EVENT_TABLE()

/*Short summary of what I've learned, the event table is actually huge and maps all the different events of the buttons that are created using IDs, you can map a button's event with their id num and from there creating an ID to map that button to its event and towards the functions within the classes performing actions you want to */

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	//Set frame icon
	//SetIcon(wxIcon(mondrian_xpm));
	wxMenu* fileMenu = new wxMenu;
	wxMenu* helpMenu = new wxMenu;
	//wxSizer* sizer = new wxSizer(wxVERTICAL);
	//wxMenu* listMenu = new wxMenu;
	//wxSizer* sizer = new wxSizer(wx_Vertical);
	//p//anel->SetSizerAndFit()
	//listMenu->Append(wxID_ABOUT, wxT("hey"), wxT("hi"), wxT("yo"));
	//panel->GetBackgroundStyle();
	panel->Show(true);
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Austyn Washington's journal program"));

	fileMenu->Append(MENU_SaveAs, wxT("&Save as.."), wxT("Save this file as txt"));
	fileMenu->Append(MENU_ONOPEN, wxT("Open..."), wxT("Open a file"));
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

	
	//buttonHello = new wxButton(this, BUTTON_Hello, wxT("hello"), wxPoint(20, 20));
	//buttonGoodbye = new wxButton(panel, BUTTON_Goodbye, wxT("goodbye"), wxPoint(60, 50));
	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));
	//menuBar->Append(listMenu, wxT("&random"));
	SetMenuBar(menuBar);
	//wxVSCROLL* scrollBar = new wxVSCROLL();
	CreateStatusBar(4);
	SetStatusText(wxT("Journal Entry"));
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString msg;
	msg.Printf(wxT("Austyn Washington's journal program"));

	//In memory of Monet Mendez, one of the greatest and best friends I've ever had in this journey of life. 
	wxMessageBox(msg, wxT("Info"), wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnSaveAs(wxCommandEvent& event)
{
	wxFileDialog* SaveDialog = new wxFileDialog(
		this, ("Save Filez As _?"), wxEmptyString, wxEmptyString,
		("Text files (*.txt)|*.txt|C++ Source Filess (*.cpp)|*.cpp|C Source files(*.c) | *.c | C header files(*.h) | *.h | All files | *"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
		CurrentDocPath = SaveDialog->GetPath();
		// set the path of our current document to the file the user chose to save under
		editor->SaveFile(CurrentDocPath); // Save the file to the selected path
		// Set the Title to reflect the file open
		SetTitle(wxString("Edit - ") << SaveDialog->GetFilename());
	}

	// Clean up after ourselves
	SaveDialog->Destroy();
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
	wxFileDialog* openDialog = new wxFileDialog(this, wxT("Open.. "), wxEmptyString, wxEmptyString, ("Text files (*.txt) |*.txt| C++ Source Files (*.cpp) |*.cpp| C++ Header files (*.h) |*.h"), wxFD_OPEN, wxDefaultPosition);

	if (openDialog->ShowModal() == wxID_OK)
	{
		CurrentDocPath = openDialog->GetPath();
		editor->LoadFile(CurrentDocPath);
		SetTitle(wxString("Edit -") << openDialog->GetFilename());
	}
}

void MyFrame::OnSave(wxCommandEvent& event)
{
	
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
	//Destroy frame
	//~MyFrame();
	Close();
}


MyFrame::~MyFrame()
{

}