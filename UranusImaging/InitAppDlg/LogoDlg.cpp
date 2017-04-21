// LogoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InitAppDlg.h"
#include "LogoDlg.h"
#include "afxdialogex.h"


// CLogoDlg dialog

IMPLEMENT_DYNAMIC(CLogoDlg, CDialogEx)

CLogoDlg::CLogoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGO_DISPLAY, pParent)
{

}

CLogoDlg::~CLogoDlg()
{
}

void CLogoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogoDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLogoDlg message handlers


BOOL CLogoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	m_hLogoImg = LoadBitmap(NULL, MAKEINTRESOURCE(IDB_BMP_LOGO));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CLogoDlg::DrawImage(CDC* pDC, HBITMAP hBitmap)
{
	CRect rRect;
	GetClientRect(&rRect);

	CBitmap bmpBuffer;
	bmpBuffer.CreateCompatibleBitmap(pDC, rRect.Width(), rRect.Height());

	CDC DoubleBufferDC;
	DoubleBufferDC.CreateCompatibleDC(pDC);
	DoubleBufferDC.SelectObject(&bmpBuffer);
	DoubleBufferDC.FillSolidRect(&rRect, pDC->GetBkColor());

	if (hBitmap != INVALID_HANDLE_VALUE)
	{
		CBitmap bmp;
		bmp.Attach((HBITMAP)hBitmap);
		BITMAP imgInfo;
		bmp.GetObject(sizeof(BITMAP), &imgInfo);

		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bmp);

		DoubleBufferDC.SetStretchBltMode(HALFTONE);
		DoubleBufferDC.StretchBlt(0, 0, rRect.Width(), rRect.Height(), &memDC, 0, 0, imgInfo.bmWidth, imgInfo.bmHeight, SRCCOPY);
		bmp.Detach();
		DeleteObject(&bmp);
	}

	pDC->BitBlt(0, 0, rRect.Width(), rRect.Height(), &DoubleBufferDC, 0, 0, SRCCOPY);

	DeleteObject(&bmpBuffer);
}

void CLogoDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages

	DrawImage(this->GetDC(), m_hLogoImg);
}
