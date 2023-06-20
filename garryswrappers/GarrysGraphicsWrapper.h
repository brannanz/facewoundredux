#ifndef __GARRYSGFXWRAPPER
#define __GARRYSGFXWRAPPER


#include <windows.h>
#include <stdio.h>
#include <d3dx9.h>
#include <dxerr9.h>
#include <dinput.h>
#include <time.h> // to timestamp the logs
#include <sys/stat.h>

#define KEYDOWN(name, key) (name[key] & 0x80)
#define MOUSEBUTTONDOWN(key) (key & 0x80)

typedef struct GARRYSRECT
{
    float    left;
    float    top;
    float    right;
    float    bottom;
}GRECT;

class CCore;

class CGarrysGraphics
{
public:
	void WindowResize(unsigned int width, unsigned int height);
	void Flip(int x, int y, int x2, int y2);
	void SpriteDrawFull(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty, float scalex, float scaley, float src_x, float src_y, float sizex, float sizey,  int a, int r, int g, int b);
	D3DPRESENT_PARAMETERS m_d3dpp;
	bool CreateDisplay (UINT width , UINT height, BOOL windowed, HWND* p_hWnd);
	void WindowResize(HWND *hWnd);
	bool ResetDevice(UINT width, UINT height);
	void Clear(UINT r,UINT g, UINT b);
	bool Windowed;
	
	//text drawing
	LPD3DXFONT m_pFont;
	D3DXFONT_DESC FontDescription;
	bool CreateDXFont(int size, int weight, LPCTSTR face);
	void DrawText(float x, float y,LPCTSTR string, int r, int g, int b);
	void DrawTextEx(float x, float y, int r, int g, int b, char *lpszText, ...);


	// sprite drawing
	LPD3DXSPRITE		m_pSprite;
	void SpriteDraw(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y);
	void SpriteDraw(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, int a, int r, int g, int b);
	void SpriteDraw(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty);
	void SpriteDraw(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float scalex, float scaley);
	void SpriteDraw(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty, float scalex, float scaley);
	void SpriteDrawEx(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float src_x, float src_y, float sizex, float sizey);
	void SpriteDrawEx(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float scalex, float scaley, float src_x, float src_y, float sizex, float sizey);
	void SpriteDrawEx(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty, float scalex, float scaley, float src_x, float src_y, float sizex, float sizey);
	void SpriteDrawEx(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty, float scalex, float scaley, float src_x, float src_y, float sizex, float sizey,  int a, int r, int g, int b);
	void SpriteDrawEx(LPDIRECT3DTEXTURE9 pSrcTexture, float x, float y, float rot, float rotx, float roty, float scalex, float scaley, int a, int r, int g, int b);

	// directinput
	LPDIRECTINPUT8			m_pDirectInput;
	LPDIRECTINPUTDEVICE8	m_pKeyboard;
	LPDIRECTINPUTDEVICE8	m_pMouse;
	char KeyboardState[256];
	bool CreateDirectInput(HINSTANCE* hInst, HWND* hWnd);
	bool InputRefreshKeyboard();
	bool InputKeyDown(UINT key);
	bool InputRefreshMouse();
	bool ReAquireDevices();
	bool m_bMouse1 ;
	bool m_bMouse2 ;
	bool m_bMouse3 ;
	bool m_bMouse4 ;
	bool m_bMouse1Click;
	bool m_bMouse2Click;
	bool m_bMouse3Click;
	bool m_bMouse4Click;
	long m_nMouseX ;
	long m_nMouseY ;
	long m_nMouseZ ;

	//logging
	void WriteToLog(char *lpszText, ...);
	void EnableLogging();
	bool b_EnableLogging;



	void Begin();
	void End();
	void Flip();

	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pd3dDevice;

	// timer functions
	double tick, lasttick, RealTick;
	void UpdateTimer();


	bool bSuspended;
	bool inscene;

	D3DCAPS9 D3DCaps;

	CCore* pcore;


private:
	// called by create display and the reset routine (when you resize the window)
	bool SetUpSprites();
	bool ReleaseSprites();
	bool ReleaseDXFont();
	bool ReCreateDXFont();
	
public:
	bool CheckDirectXVersion(void);
};

void CopyGRect(GRECT* r1, GRECT* r2);
void SetGRect(GRECT* r, float left, float top, float right, float bottom);
void UnionGRect(GRECT* r, GRECT* r1, GRECT* r2);
bool IntersectGRect(GRECT* r1, GRECT* r2);
bool FileExists(char* filename);
bool DirectoryExists(const char* FileName);
extern HRESULT GetDXVersion( DWORD* pdwDirectXVersion, TCHAR* strDirectXVersion, int cchDirectXVersion );

#endif