#include "pch.h"
#include "COpenGLControl.h"



void COpenGLControl::oglCreate(CRect rect, CWnd* parent)
{
	CString className = AfxRegisterWndClass(CS_HREDRAW |
		CS_VREDRAW | CS_OWNDC, NULL,
		(HBRUSH)GetStockObject(BLACK_BRUSH), NULL);

	CreateEx(0, className, LPCTSTR("OpenGL"), WS_CHILD | WS_VISIBLE |
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);

	// Set initial variables' values
	m_oldWindow = rect;
	m_originalRect = rect;

	hWnd = parent;
}