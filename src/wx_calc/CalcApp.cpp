// #define WXUSINGDLL
// #define __WXMSW__
// #define _UNICODE

#include <wx/log.h>
#include <wx/frame.h>
#include <wx/textctrl.h>


#include "CalcApp.h"
#include "CustomLogWindow.h"

#include "CalcKernel.h"

KHL_CALC_START

bool CalcApp::OnInit()
{
    MyFrame* frame = new MyFrame();

    CustomLogWindow* log_window_m = new CustomLogWindow(frame);
    log_window_m->Show(true);

    // MyFrame* frame = new MyFrame();
    frame->SetSize(wxSize(800, 600));
    frame->Center();
    frame->Show(true);

    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, _T("第一个窗口"))
{

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(khl::calc::ID_Hello, wxT("&你好...\tCtrl-H"),
        wxT("此菜单的提示文本显示在状态栏"));
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, wxT("文件(&F)"));
    menuBar->Append(menuHelp, wxT("帮助(&H)"));

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, khl::calc::ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    LOG_INFO("Hello world from wxWidgets!");
    auto kernel = std::make_unique<Calculator>();
    
    LOG_INFO(wxString::Format("Calculator:%f", kernel->add(1, 2)));
}

wxIMPLEMENT_APP(CalcApp);

KHL_CALC_END
