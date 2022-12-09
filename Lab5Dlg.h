
// Lab5Dlg.h : header file
//

#pragma once


// CLab5Dlg dialog
class CLab5Dlg : public CDialogEx
{
// Construction
public:
	CLab5Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

#define MAX 50
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedCalc();
public:
	int Volum;
	double Serie[MAX];
	double copie[MAX];
	afx_msg void OnBnClickedSort();
	afx_msg void OnBnClickedLsea();
	double LinVal;
	CString LinText;
	int LinOut;
	afx_msg void OnBnClickedBsea();
	double BinVal;
	int BinOut;
	CString BinText;
	afx_msg void OnBnClickedUniq();

};
