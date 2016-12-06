//
// Copyright � 2016 Neat Decisions. All rights reserved.
//
// This file is part of NeatMouse.
// The use and distribution terms for this software are covered by the 
// Microsoft Public License (http://opensource.org/licenses/MS-PL) 
// which can be found in the file LICENSE at the root folder.
//

#include <atldlgs.h>
#include <atlwin.h>

namespace neatcommon {
namespace ui {

//=====================================================================================================================
// CInputBox
//=====================================================================================================================
class CInputBox : public CIndirectDialogImpl<CInputBox, CMemDlgTemplate>
{
public:
	BEGIN_DIALOG(0, 0, kWindowWidth, kWindowHeight)
		DIALOG_STYLE(DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU)
	END_DIALOG()

	BEGIN_CONTROLS_MAP()
		CONTROL_LTEXT(_T(""), ID_STATIC, 4, 4, kWindowWidth - 50 - 4 - 4 - 4, 14, WS_VISIBLE | WS_CHILD, 0);
		CONTROL_EDITTEXT(ID_EDIT, 4, 21, kWindowWidth - 50 - 4 - 4 - 4, 12,	WS_VISIBLE | WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL, 0);
		CONTROL_PUSHBUTTON(_T("OK"), IDOK, kWindowWidth - 50 - 4, 4, 50, 14, WS_VISIBLE | WS_CHILD | WS_TABSTOP, 0);
		CONTROL_PUSHBUTTON(_T("Cancel"), IDCANCEL, kWindowWidth - 50 - 4, 20, 50, 14, WS_VISIBLE | WS_CHILD | WS_TABSTOP, 0);
	END_CONTROLS_MAP()
	
	BEGIN_MSG_MAP(CInputBox)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnButtonOk)
		COMMAND_ID_HANDLER(IDCANCEL, OnButtonCancel)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

	CInputBox(const WTL::CString & caption, const WTL::CString & prompt, const WTL::CString & ok, const WTL::CString & cancel);
	WTL::CString getText() const;

private:
	typedef CIndirectDialogImpl<CInputBox, CMemDlgTemplate> PARENT;
	const short kWindowWidth = 240;
	const short kWindowHeight = 38;

	static const WORD ID_EDIT = 3;
	static const WORD ID_STATIC = 4;

	const WTL::CString m_caption;
	const WTL::CString m_prompt;
	const WTL::CString m_ok;
	const WTL::CString m_cancel;

	WTL::CString _text;

	LRESULT OnButtonOk(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnButtonCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
};

}}
