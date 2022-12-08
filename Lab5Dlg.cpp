
// Lab5Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab5.h"
#include "Lab5Dlg.h"
#include "afxdialogex.h"
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab5Dlg dialog



CLab5Dlg::CLab5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB5_DIALOG, pParent)
	, Volum(0)
	, Serie()
	, copie()
	, LinVal(0)
	, BinVal(0)
	, LinOut(0)
	, BinOut(0)
	, LinText(_T(""))
	, BinText(_T(""))
	, ListB()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_LVAL, LinVal);
	DDX_Text(pDX, IDC_LTEXT, LinText);
	DDX_Text(pDX, IDC_LOUT, LinOut);
	DDX_Text(pDX, IDC_BVAL, BinVal);
	DDX_Text(pDX, IDC_BOUT, BinOut);
	DDX_Text(pDX, IDC_BTEXT, BinText);
	DDX_Control(pDX, IDC_LISTB, ListB);
}

BEGIN_MESSAGE_MAP(CLab5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CLab5Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_CALC, &CLab5Dlg::OnBnClickedCalc)
	ON_BN_CLICKED(IDC_SORT, &CLab5Dlg::OnBnClickedSort)
	ON_BN_CLICKED(IDC_LSEA, &CLab5Dlg::OnBnClickedLsea)
	ON_BN_CLICKED(IDC_BSEA, &CLab5Dlg::OnBnClickedBsea)
	ON_BN_CLICKED(IDC_UNIQ, &CLab5Dlg::OnBnClickedUniq)
END_MESSAGE_MAP()


// CLab5Dlg message handlers

BOOL CLab5Dlg::OnInitDialog()
{
	Volum = 0;
	return TRUE;
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CLab5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab5Dlg::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	if (Volum == MAX)
	{
		CString Text;
		Text.Format((LPCWSTR)L"Seria de date are maxim %d de valori!", MAX);
		AfxMessageBox(Text);
		return;
	}

	CString Data;
	GetDlgItemText(IDC_DATA, Data);
	((CListBox*)GetDlgItem(IDC_LISTA))->AddString(Data);
	Serie[Volum++] = wcstod(Data, NULL);
	SetDlgItemInt(IDC_VOLUM, Volum);
}


void CLab5Dlg::OnBnClickedCalc()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	double Medie = 0, Disp = 0;
	double mini = Serie[0], maxi = Serie[0], ampi;
	for (int i = 0; i < Volum; i++) {
		if (mini > Serie[i])
			mini = Serie[i];
		if (maxi < Serie[i])
			maxi = Serie[i];
		Medie += Serie[i];
	}
	ampi = maxi - mini;
	Medie /= Volum;
	for (int i = 0; i < Volum; i++)
		Disp += pow(Serie[i] - Medie, 2);

	Disp /= pow((double)Volum, 2);
	CString Text;
	Text.Format((LPCWSTR)L"%.2lf", Medie);
	SetDlgItemText(IDC_MEDIE, Text);

	Text.Format((LPCWSTR)L"%.2lf", Disp);
	SetDlgItemText(IDC_DISPERSIE, Text);

	Text.Format((LPCWSTR)L"%.2lf", maxi);
	SetDlgItemText(IDC_MAXI, Text);

	Text.Format((LPCWSTR)L"%.2lf", mini);
	SetDlgItemText(IDC_MINI, Text);

	Text.Format((LPCWSTR)L"%.2lf", ampi);
	SetDlgItemText(IDC_AMPLI, Text);
}

void CLab5Dlg::OnBnClickedSort()
{
	copy(Serie, Serie + Volum, copie);
	sort(copie, copie + Volum);
	for (int i = 0; i < Volum; i++) {
		CString aux;
		aux.Format(_T("%f"), copie[i]);
		ListB.AddString(aux);
	}
}


void CLab5Dlg::OnBnClickedUniq()
{
	// TODO: Add your control notification handler code here

}

void CLab5Dlg::OnBnClickedLsea()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	for (int i = 0; i < Volum; i++) {
		if (Serie[i] == LinVal)
		{
			LinText = "Prin LS am gasit la index:";
			LinOut = i + 1;
			break;
		}
		if (i + 1 == Volum) {
			LinText = "Prin LS n-am gasit valoarea";
			LinOut = 0;
		}
	}
	UpdateData(FALSE);
}


void CLab5Dlg::OnBnClickedBsea()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	//copy(begin(Serie), end(Serie), begin(copie));
	//sort(begin(copie), end(copie));
	int low = 0, high = Volum - 1, mid = 0;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (Serie[mid] == BinVal) {
			BinText = "Prin BS am gasit la index:";
			BinOut = mid + 1;
			break;
		}
		if (Serie[mid] < BinVal)
			low = mid + 1;
		else
			high = mid - 1;
	}
	BinText = "Prin BS n-am gasit valoarea";
	BinOut = 0;
	UpdateData(FALSE);
}

