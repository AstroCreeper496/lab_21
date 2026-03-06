#include <windows.h>
#include <stdio.h>
#include <string>

	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
    HWND hwndbutton1;
    HWND hwndbutton2;
    HWND hwndbutton3;
    HWND hwndbutton4;
    HWND hwndinput1;
    HWND hwndinput2;
    HWND hwndtextbox1;

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_COMMAND:
            // Check if the message is a button click notification
            {
                if (LOWORD(wParam) == 1) // เมื่อปุ่มถูกคลิก
                {
                    char szBuffer1[256];
                    char szBuffer2[256];
                    // 1. ดึงข้อความจาก Textbox (hWnd คือ handle ของหน้าต่างหลัก/Dialog)
                    GetWindowText(hwndinput1, szBuffer1, 256);
                    GetWindowText(hwndinput2, szBuffer2, 256);
                    try {
                        double val1 = std::stod(szBuffer1);
                        double val2 = std::stod(szBuffer2);
                        char t[100];
                        sprintf(t, "%f", val1+val2);
                        MessageBox(hwnd, t, "Result", NULL);
                    }
                    catch (...) {
                        MessageBox(hwnd, "#NUM!", "Error", MB_ICONERROR);
                    }
                }
                if (LOWORD(wParam) == 2) // เมื่อปุ่มถูกคลิก
                {
                    char szBuffer1[256];
                    char szBuffer2[256];
                    // 1. ดึงข้อความจาก Textbox (hWnd คือ handle ของหน้าต่างหลัก/Dialog)
                    GetWindowText(hwndinput1, szBuffer1, 256);
                    GetWindowText(hwndinput2, szBuffer2, 256);
                    try {
                        double val1 = std::stod(szBuffer1);
                        double val2 = std::stod(szBuffer2);
                        char t[100];
                        sprintf(t, "%f", val1-val2);
                        MessageBox(hwnd, t, "Result", NULL);
                    }
                    catch (...) {
                        MessageBox(hwnd, "#NUM!", "Error", MB_ICONERROR);
                    }
                }
                if (LOWORD(wParam) == 3) // เมื่อปุ่มถูกคลิก
                {
                    char szBuffer1[256];
                    char szBuffer2[256];
                    // 1. ดึงข้อความจาก Textbox (hWnd คือ handle ของหน้าต่างหลัก/Dialog)
                    GetWindowText(hwndinput1, szBuffer1, 256);
                    GetWindowText(hwndinput2, szBuffer2, 256);
                    try {
                        double val1 = std::stod(szBuffer1);
                        double val2 = std::stod(szBuffer2);
                        char t[100];
                        sprintf(t, "%f", val1*val2);
                        MessageBox(hwnd, t, "Result", NULL);
                    }
                    catch (...) {
                        MessageBox(hwnd,"#NUM!", "Error", MB_ICONERROR);
                    }
                }
                if (LOWORD(wParam) == 4) // เมื่อปุ่มถูกคลิก
                {
                    char szBuffer1[256];
                    char szBuffer2[256];
                    // 1. ดึงข้อความจาก Textbox (hWnd คือ handle ของหน้าต่างหลัก/Dialog)
                    GetWindowText(hwndinput1, szBuffer1, 256);
                    GetWindowText(hwndinput2, szBuffer2, 256);
                    try {
                        double val1 = std::stod(szBuffer1);
                        double val2 = std::stod(szBuffer2);
                        char t[100];
                        sprintf(t, "%f", val1/val2);
                        MessageBox(hwnd, t, "Result", NULL);
                    }
                    catch (...) {
                        MessageBox(hwnd,"#NUM!", "Error", MB_ICONERROR);
                    }
                }
            }
            break;
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(14);
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = {CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL)};

        hwndbutton1 = {CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "+",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    20,         // x position 
    110,         // y position 
    20,        // Button width
    20,        // Button height
    hwnd,     // Parent window
    (HMENU)1,       // button ID.
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
    NULL)};      // Pointer not needed.
        hwndbutton2 = {CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "-",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    50,         // x position 
    110,         // y position 
    20,        // Button width
    20,        // Button height
    hwnd,     // Parent window
    (HMENU)2,       // button ID.
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
    NULL)};      // Pointer not needed.
        hwndbutton3 = {CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "*",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    80,         // x position 
    110,         // y position 
    20,        // Button width
    20,        // Button height
    hwnd,     // Parent window
    (HMENU)3,       // button ID.
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
    NULL)};      // Pointer not needed.
        hwndbutton4 = {CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "/",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    110,         // x position 
    110,         // y position 
    20,        // Button width
    20,        // Button height
    hwnd,     // Parent window
    (HMENU)4,       // button ID.
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
    NULL)};      // Pointer not needed.
        hwndtextbox1 = {CreateWindow(
    TEXT("STATIC"),             // Predefined class; EDIT control
    TEXT("Please input two numbers."),     // Initial text
    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, // Styles
    20, 20, 180, 20,         // x, y, width, height
    hwnd,               // Parent window handle
    NULL,     // Control ID (for identification in parent's WM_COMMAND)
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
    NULL                      // Pointer not needed
    )};
        hwndinput1 = {CreateWindow(
    TEXT("EDIT"),             // Predefined class; EDIT control
    TEXT(""),     // Initial text
    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, // Styles
    20, 50, 140, 20,         // x, y, width, height
    hwnd,               // Parent window handle
    NULL,     // Control ID (for identification in parent's WM_COMMAND)
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
    NULL                      // Pointer not needed
    )};
        hwndinput2 = {CreateWindow(
    TEXT("EDIT"),             // Predefined class; EDIT control
    TEXT(""),     // Initial text
    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, // Styles
    20, 80, 140, 20,         // x, y, width, height
    hwnd,               // Parent window handle
    NULL,     // Control ID (for identification in parent's WM_COMMAND)
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), // Instance handle
    NULL                      // Pointer not needed
    )};     
    if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}

	return msg.wParam;
}

