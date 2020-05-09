// DlgDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "ddrawYUV.h"
#include "DlgDisplay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "ddraw.h"
#include "mmsystem.h"
#pragma comment(lib,"ddraw.lib")
/////////////////////////////////////////////////////////////////////////////
// CDlgDisplay dialog


CDlgDisplay::CDlgDisplay(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDisplay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDisplay)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDisplay)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDisplay, CDialog)
	//{{AFX_MSG_MAP(CDlgDisplay)
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDisplay message handlers

CWnd *pDdrawDisplay;
FILE *pFileYUV=NULL;

#define HEIGHT         480
#define WIDTH          720
#define DRAW_TOP       0
#define DRAW_LEFT      0
#define DRAW_HEIGHT    480
#define DRAW_WIDTH     720

HWND hWnd;
HANDLE hEvent;
HANDLE hThread;
DWORD dwThreadID;
BOOL DrawYV12();
BOOL CDlgDisplay::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	hEvent=CreateEvent(NULL,FALSE,FALSE,NULL);
	hThread=CreateThread(NULL,
				         0,
                         (LPTHREAD_START_ROUTINE)DrawYV12,
				         NULL,
						 CREATE_SUSPENDED,//0,
                         &dwThreadID);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CDlgDisplay::OnStart() 
{
	// TODO: Add your control notification handler code here
	SetEvent(hEvent);
	ResumeThread(hThread);
}
void CDlgDisplay::OnStop() 
{
	// TODO: Add your control notification handler code here
	ResetEvent(hEvent);
	SuspendThread(hThread);
}
BOOL DrawYV12()
{
	CString               strFrameNum;
	LPDIRECTDRAW          lpDD;           //DirectDraw对象指针
	LPDIRECTDRAWSURFACE   lpDDSPrimary;   //DirectDraw主表面指针
	LPDIRECTDRAWSURFACE   lpDDSOffScr;    //DirectDraw离屏表面指针
	DDSURFACEDESC         ddsd;           //DirectDraw表面描述
	RECT                  rctDest;        //目标区域
	RECT                  rctSour;        //源区域
	HRESULT               ddRval;         //DirectDraw函数返回值
	hWnd=pDdrawDisplay->GetSafeHwnd();
	//创建DirectDraw对象
	ddRval=DirectDrawCreate(NULL,&lpDD,NULL);
	if(DD_OK!=ddRval)
	{
		AfxMessageBox("DirectDraw对象创建不成功！");
		return FALSE;
	}
	
	//设置协作层
	ddRval=lpDD->SetCooperativeLevel(hWnd,DDSCL_NORMAL|DDSCL_NOWINDOWCHANGES);
    if(DD_OK!=ddRval)
	{
		AfxMessageBox("协作层设置不成功！");
		return FALSE;
	}

	//创建主表面
	ZeroMemory(&ddsd,sizeof(ddsd));
	ddsd.dwSize=sizeof(ddsd);
	ddsd.dwFlags=DDSD_CAPS;
	ddsd.ddsCaps.dwCaps=DDSCAPS_PRIMARYSURFACE;
	ddRval=lpDD->CreateSurface(&ddsd,&lpDDSPrimary,NULL);
	if(DD_OK!=ddRval)
	{
		AfxMessageBox("主表面创建不成功！");
		return FALSE;
	}

	//创建离屏表面对象
	ZeroMemory(&ddsd,sizeof(ddsd));
	ddsd.dwSize=sizeof(ddsd);
	ddsd.ddsCaps.dwCaps=DDSCAPS_OVERLAY;//DDSCAPS_OFFSCREENPLAIN|DDSCAPS_VIDEOMEMORY
	ddsd.dwFlags=DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH|DDSD_PIXELFORMAT;
	ddsd.dwWidth=DRAW_WIDTH;
	ddsd.dwHeight=DRAW_HEIGHT;
	ddsd.ddpfPixelFormat.dwSize=sizeof(DDPIXELFORMAT);
	ddsd.ddpfPixelFormat.dwFlags=DDPF_FOURCC|DDPF_YUV;
	ddsd.ddpfPixelFormat.dwFourCC=MAKEFOURCC('Y','V','1','2');//('Y','U','Y','2');
	ddsd.ddpfPixelFormat.dwYUVBitCount=8;
	ddRval=lpDD->CreateSurface(&ddsd,&lpDDSOffScr,NULL);
	if(DD_OK!=ddRval)
	{
		AfxMessageBox("离屏表面创建不成功！");
		return FALSE;
	}
	
	//加载yv12图象文件
	FILE *fYUV=fopen("E://directdraw//YUVPlayer//testdata//D1.yuv","rb+");
	LPBYTE lpAllYUV=new BYTE[WIDTH*HEIGHT*3/2];

	for(int f=0;f<500;f++)
	{
		WaitForSingleObject(hEvent,INFINITE);
		strFrameNum.Format("%d",f);
		pDdrawDisplay->SetWindowText(strFrameNum);
		UINT iLen=fread(lpAllYUV,1,WIDTH*HEIGHT*3/2,fYUV);
		if(0==iLen)
		{
			AfxMessageBox("Can not find the YUV input file!");
		}
		LPBYTE lpYUV=lpAllYUV;
		LPBYTE lpY=lpYUV;
		LPBYTE lpV=lpY+WIDTH*HEIGHT;//lpYUV+WIDTH*HEIGHT;
		LPBYTE lpU=lpV+WIDTH*HEIGHT/4;//lpYUV+WIDTH*HEIGHT*3/2;
		ddRval=lpDDSOffScr->Lock(NULL,&ddsd,DDLOCK_WAIT|DDLOCK_WRITEONLY,NULL);
		while(DDERR_WASSTILLDRAWING==ddRval);
		if(DD_OK!=ddRval)
		{
			AfxMessageBox("离屏表面锁定不成功！");
			return FALSE;
		}

		LPBYTE lpSurf=(LPBYTE)ddsd.lpSurface;
		LPBYTE lpY1=lpSurf;
		LPBYTE lpV1=lpY1+ddsd.lPitch*HEIGHT;
		LPBYTE lpU1=lpV1+ddsd.lPitch*HEIGHT/4;
		int nOffset=DRAW_TOP*WIDTH+DRAW_LEFT;
		//填充离屏表面
		if(lpSurf)
		{
			int i=0;
			//fill Y data
			lpY+=nOffset;
			for(i=0;i<ddsd.dwHeight;i++)
			{
				memcpy(lpSurf,lpY,ddsd.dwWidth);
				lpY+=WIDTH;
				lpSurf+=ddsd.lPitch;
			}
			//fill V data
			lpV+=DRAW_TOP*WIDTH/4+DRAW_LEFT/2;
			for(i=0;i<ddsd.dwHeight/2;i++)
			{
				memcpy(lpSurf,lpV,ddsd.dwWidth/2);
				lpV+=WIDTH/2;
				lpSurf+=ddsd.lPitch/2;
			}
			//file U data
			lpU+=DRAW_TOP*WIDTH/4+DRAW_LEFT/2;
			for(i=0;i<ddsd.dwHeight/2;i++)
			{
				memcpy(lpSurf,lpU,ddsd.dwWidth/2);
				lpU+=WIDTH/2;
				lpSurf+=ddsd.lPitch/2;
			}
		}
		lpDDSOffScr->Unlock(NULL);
		
		//Blt到主表面
		rctSour.left=0;
		rctSour.top=0;
		rctSour.right=ddsd.dwWidth;
		rctSour.bottom=ddsd.dwHeight;
		GetClientRect(hWnd,&rctDest);
		ClientToScreen(hWnd,(LPPOINT)&rctDest.left);
		ClientToScreen(hWnd,(LPPOINT)&rctDest.right);
		ddRval=lpDDSPrimary->Blt(&rctDest,lpDDSOffScr,&rctSour,DDBLT_WAIT,NULL);
		while(DDERR_WASSTILLDRAWING==ddRval);
		if(DD_OK!=ddRval)
		{
			AfxMessageBox("Blt到主表面不成功！");
			return FALSE;
		}
		/*else
		{
			AfxMessageBox("Blt到主表面成功！");			
		}*/
		Sleep(30);
		SetEvent(hEvent);
	}
	//释放DirectDraw对象
	fclose(fYUV);
	delete lpAllYUV;
	if(lpDD!=NULL)
	{
		if(lpDDSPrimary!=NULL)
		{
			lpDDSPrimary->Release();
			lpDDSPrimary=NULL;
		}
		if(lpDDSOffScr!=NULL)
		{
			lpDDSOffScr->Release();
			lpDDSOffScr=NULL;
		}
		lpDD->Release();
		lpDD=NULL;
	}
	return TRUE;
}




