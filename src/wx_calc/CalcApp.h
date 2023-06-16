#ifndef _KHL_CALC_APP_H_
#define _KHL_CALC_APP_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx_calc_common.h"

KHL_CALC_START

class CalcApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

wxDECLARE_APP(CalcApp);

KHL_CALC_END

#endif // !_KHL_CALC_APP_H_
