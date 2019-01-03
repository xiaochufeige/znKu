// 开机自启动Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "开机自启动.h"
#include "开机自启动Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_lujing = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_lujing);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	if((m_lujing=="")||(m_filenamennn==""))
		return;

//开机自启动
	CString ZQDszFilePathExe = "";//绝对路径包含文件名
	CString ZQDszFilePath = "";//路径名，到执行文件目录
	CString ZQDszFile = "";//只有文件名

	CString ZQDszFilePathzj;//中间容器
	GetModuleFileName(NULL,ZQDszFilePathzj.GetBuffer(MAX_PATH),MAX_PATH);
	ZQDszFilePathzj.ReleaseBuffer();//Must ReleaseBuffer, or GetLength=0
	int pos= ZQDszFilePathzj.ReverseFind(_T('\\'));
	int len = ZQDszFilePathzj.GetLength();
	ZQDszFilePathExe = ZQDszFilePathzj;
	ZQDszFilePath = ZQDszFilePathzj.Left(pos+1);
	ZQDszFile = ZQDszFilePathzj.Right(len-pos-1);


	CString filepath222 = m_lujing;    //双斜杠路径用来写入文件
	filepath222.Replace("\\", "\\\\");

	CString strW = "";
	CFile file1;
	file1.Open(ZQDszFilePath + "开机自启.reg", CFile::modeWrite | CFile::modeCreate);

	strW = strW + "Windows Registry Editor Version 5.00\r\n\r\n[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run]\r\n";
	strW = strW + "\"" + m_filenamennn + "\"=\"" + filepath222 + "\"\r\n\r\n";

	file1.Write(strW, strW.GetLength());
	file1.Close();

	system(ZQDszFilePath + "开机自启.reg");		
}

void CMyDlg::OnButton2() 
{
	if((m_lujing=="")||(m_filenamennn==""))
		return;
//取消开机自启

	CString ZQDszFilePathExe = "";//绝对路径包含文件名
	CString ZQDszFilePath = "";//路径名，到执行文件目录
	CString ZQDszFile = "";//只有文件名

	CString ZQDszFilePathzj;//中间容器
	GetModuleFileName(NULL,ZQDszFilePathzj.GetBuffer(MAX_PATH),MAX_PATH);
	ZQDszFilePathzj.ReleaseBuffer();//Must ReleaseBuffer, or GetLength=0
	int pos= ZQDszFilePathzj.ReverseFind(_T('\\'));
	int len = ZQDszFilePathzj.GetLength();
	ZQDszFilePathExe = ZQDszFilePathzj;
	ZQDszFilePath = ZQDszFilePathzj.Left(pos+1);
	ZQDszFile = ZQDszFilePathzj.Right(len-pos-1);

	CString strW = "";
	CFile file1;
	file1.Open(ZQDszFilePath + "取消开机自启.reg", CFile::modeWrite | CFile::modeCreate);

//	strW = strW + "Windows Registry Editor Version 5.00\r\n\r\n");
	strW = strW + "Windows Registry Editor Version 5.00\r\n\r\n[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run]\r\n";
	strW = strW + "\"" + m_filenamennn + "\"=-\r\n\r\n";

	file1.Write(strW, strW.GetLength());
	file1.Close();

	system(ZQDszFilePath + "取消开机自启.reg");		
}

void CMyDlg::OnButton3() 
{
	
	CString filePath;
	char szFilter[] = {"All Files(*.*)|*.*||"};
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	
	if(dlg.DoModal() == IDOK)
	{
		filePath = dlg.GetPathName();
		m_filenamennn = dlg.GetFileName(); //得到文件名
		if(m_filenamennn.Right(4) == ".exe")
			m_filenamennn = m_filenamennn.Left(m_filenamennn.GetLength() - 4); //得到文件名不含扩展名
		m_lujing = (LPCTSTR)filePath.GetBuffer(0);  //lpszFileName是一个全局变量
		UpdateData(FALSE);
	}
	else
	{
	}
	
}

void CMyDlg::OnChangeEdit1() 
{
		UpdateData(TRUE);
}
