#pragma once


// CLogoDlg dialog

class CLogoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogoDlg)

public:
	CLogoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLogoDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGO_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

private:
	HBITMAP m_hLogoImg;

private:
	void DrawImage(CDC* pDC, HBITMAP hBitmap);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
