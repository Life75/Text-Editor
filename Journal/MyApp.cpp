#include "MyApp.h"
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)


bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame(wxT("Journal Entry Logger"));
	frame->ClientToScreen(wxPoint(0, 0));

	frame->SetSize(wxSize(1440,1080));
	//shows 
	frame->Show(true);
	return true;
}