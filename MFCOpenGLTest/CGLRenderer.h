#pragma once
#include "pch.h"
#include <afxwin.h>

//--------------

class CGLRenderer
{
public:
	CGLRenderer(void);
	virtual ~CGLRenderer(void);
	bool CreateGLContext(CDC* pDC); 	// Creates OpenGL Rendering Context
	void PrepareScene(CDC* pDC);		// Scene preparation stuff
	//void Reshape(CDC* pDC, int w, int h);	// Changing viewport
	//void DrawScene(CDC* pDC);		// Draws the scene
	//void DestroyScene(CDC* pDC);		// Cleanup

private:
	CWnd* hWnd;
	HDC     hdc;
	HGLRC   hrc;
	int     m_nPixelFormat;
	CRect   m_rect;
	CRect   m_oldWindow;
	CRect   m_originalRect;

protected:
	void SetData();	                        // Creates VAO and VBOs and fill them with data

protected:
	HGLRC	 m_hrc;                        // OpenGL Rendering Context 
	//CGLProgram* m_pProgram;	               // Program
	//CGLShader* m_pVertSh;		       // Vertex shader
	//CGLShader* m_pFragSh;		       // Fragment shader

	//GLuint m_vaoID[2];			// two vertex array objects, one for each drawn object
	//GLuint m_vboID[3];			// three VBOs
};