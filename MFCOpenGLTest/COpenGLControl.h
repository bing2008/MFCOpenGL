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
	BOOL	m_bIsMaximized;

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
	void oglInitialize(void);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	afx_msg void OnDraw(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

