
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ComputerGraphics1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}


void DrawRect(CPaintDC& dc, int top, int left, int width, int height, CBrush& brush) {
	dc.FillRect(CRect(left, top, left + width, top + height), &brush);
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CBrush brush{ RGB(255, 0, 0) };
	//	brush.CreateSolidBrush(0x000000FF);

	long int colors[]{ RGB(255,0,0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(0, 255, 255) /*Cyan*/,
		RGB(255, 0, 255) /*Magenta*/, RGB(255, 255, 0) /* Yellow */ };

	for (int top = 20, left = 20, i = 0; i < 6; i++) {
		DrawRect(dc, top, left, 30, 50, CBrush(colors[i]));
		if (i == 2) {
			top += 50;
			left = 20;
		}
		else {
			left += 30;
		}

	}

	int styles[]{ HS_HORIZONTAL, HS_VERTICAL, HS_BDIAGONAL, HS_FDIAGONAL, HS_CROSS, HS_DIAGCROSS };

	CRect r;
	GetClientRect(&r);

	 for (int top = r.bottom-130, left = 30, i = 0; i < 6; i++, left += 50) {
		CBrush brush; 
		brush.CreateHatchBrush(styles[i], RGB(0, 0, 0));
		DrawRect(dc, top, left, 50, 100, brush);
	}

}

