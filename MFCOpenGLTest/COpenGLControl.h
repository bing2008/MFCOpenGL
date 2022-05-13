#pragma once
#include <afxwin.h>
class COpenGLControl :
    public CWnd
{
public:
	/******************/
	/* PUBLIC MEMBERS */
	/******************/
	// Timer
	UINT_PTR m_unpTimer;

private:
	/*******************/
	/* PRIVATE MEMBERS */
	/*******************/
	// Window information
	CWnd* hWnd;
	HDC     hdc;
	HGLRC   hrc;
	int     m_nPixelFormat;
	CRect   m_rect;
	CRect   m_oldWindow;
	CRect   m_originalRect;

public:
    void oglCreate(CRect rect, CWnd* parent);
};

