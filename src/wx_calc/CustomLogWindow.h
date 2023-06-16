#ifndef _KHL_CALC_CUSTOM_LOG_WINDOW_H_
#define _KHL_CALC_CUSTOM_LOG_WINDOW_H_

#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/filename.h>

#include "wx_calc_common.h"

KHL_CALC_START

#define LOG_INFO(msg) wxLogMessage(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);
#define LOG_WARN(msg) wxLogWarning(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);
#define LOG_ERROR(msg) wxLogError(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);

class CustomLogWindow : public wxFrame
{
public:
    CustomLogWindow(wxFrame* parent);

private:
    wxTextCtrl* m_textCtrl;
};

KHL_CALC_END

#endif // !_KHL_CALC_CUSTOM_LOG_WINDOW_H_
