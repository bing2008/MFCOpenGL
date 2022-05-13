#include "pch.h"
#include "COpenGLControl.h"
//#include "gl/glew.h"
//#include "gl/wglew.h"
#include <gl/gl.h>
#include <gl/glu.h>

BEGIN_MESSAGE_MAP(COpenGLControl, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

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

void COpenGLControl::oglInitialize(void)
{
	// Initial Setup:
	//
	static PIXELFORMATDESCRIPTOR pfd =
	{
	   sizeof(PIXELFORMATDESCRIPTOR),
	   1,
	   PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
	   PFD_TYPE_RGBA,
	   32,    // bit depth
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   16,    // z-buffer depth
	   0, 0, 0, 0, 0, 0, 0,
	};

	// Get device context only once.
	hdc = GetDC()->m_hDC;

	// Pixel format.
	m_nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, m_nPixelFormat, &pfd);

	// Create the OpenGL Rendering Context.
	hrc = wglCreateContext(hdc);
	wglMakeCurrent(hdc, hrc);

	// Basic Setup:
	//
	// Set color to use when clearing the background.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	// Turn on backface culling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	// Turn on depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Send draw request
	OnDraw(NULL);
}




void COpenGLControl::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//				   // TODO: 在此处添加消息处理程序代码
	//				   // 不为绘图消息调用 CWnd::OnPaint()

	ValidateRect(NULL);
}


int COpenGLControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	oglInitialize();

	return 0;
}

void COpenGLControl::OnDraw(CDC* pDC)
{
	// TODO: Camera controls.
	glLoadIdentity();

}


void COpenGLControl::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


void COpenGLControl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void COpenGLControl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CWnd::OnTimer(nIDEvent);


	glClearColor(0.8f, 0.3f, 0.3f, 1.0f);

}
