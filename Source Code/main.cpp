#include <Windows.h>
#include <iostream>
#include <gdiplus.h>
#define MYRGB(r,g,b) (r | g << 8 | b << 16)
using namespace std;
VOID WINAPI sound1() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22000, 22000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[22000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t>>6^t&t>>9^t>>12|(t<<(t>>6)%4^-t&-t>>13)%128^-t>>1);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound2() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[8000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t*(t&16384?6:5)*(3+(3&t>>(t&2048?7:14)))>>(2&t>>9)|t>>3*t);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound3() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11000, 11000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t>>4|(t>>0)*(t>>6));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound4() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[8000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>((t*9)&(t>>4))|(t*5&t>>7)|(t*3&t/1024)-4;

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound5() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11000, 11000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t*(0xCA98>>(t>>9&14)&15)|t>>-1);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound6() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[8000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(rand()*t);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
DWORD WINAPI radius(LPVOID lpParam) {
    int cx = 600, cy = 400, radius = 400;
    float angle = 0;
    while (true) {
        HDC hdc = GetDC(0);
        int x = cx + static_cast<int>(radius * cos(angle * M_PI / 180));
        int y = cy + static_cast<int>(radius * sin(angle * M_PI / 180));
        HBRUSH brush = CreateSolidBrush(RGB(500,000,000));
        SelectObject(hdc, brush);
        RoundRect(hdc, x - 40, y - 40, x + 40, y + 40, x / 2, y / 2);
        angle += 1;
        Sleep(10);
        DeleteObject(brush);
        ReleaseDC(0, hdc);
    };
}
DWORD WINAPI gray(LPVOID lpParam) {
    const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);
    HDC hdc, memdc;
    HBITMAP hbit;

    BLENDFUNCTION blendFunc = {0, 0, 65, 0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hbit = CreateCompatibleBitmap(hdc, HDCX, HDCY);
        (HBITMAP)SelectObject(memdc, hbit);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, NOTSRCCOPY);
        AlphaBlend(hdc, (rand()%11)-5, (rand()%11)-5, HDCX, HDCY, memdc, 0, 0, HDCX, HDCY, blendFunc);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hbit);
    }
}
DWORD WINAPI shake(LPVOID lpParam) {
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, NOTSRCCOPY);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI sinewaves(LPVOID lpParam) {
  HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
  int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
  double angle = 0;
  while (1) {
    desk = GetDC(0);
    for (float i = 0; i < sw + sh; i += 0.99f) {
      int a = sin(angle) * 20;
      BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCINVERT);
      angle += M_PI / 40;
      DeleteObject(&i); DeleteObject(&a);
    }
    ReleaseDC(wnd, desk);
    DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
  }
}
DWORD WINAPI glitch(LPVOID lpParam) {
	const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);
	HDC hdc, memdc;
    HBITMAP hbit;

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hbit = CreateCompatibleBitmap(hdc, HDCX, HDCY);
        (HBITMAP)SelectObject(memdc, hbit);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int y = 0; y <= HDCY; y++) {
            BitBlt(memdc, (rand()%11)-5, y, HDCX, 1, memdc, 0, y, SRCCOPY);
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hbit);
    }
}
VOID WINAPI ci(int x, int y, int w, int h)
{
    HDC hdc = GetDC(0);
    HRGN hrgn = CreateEllipticRgn(x, y, w+x, h+y);
    SelectClipRgn(hdc, hrgn);
    BitBlt(hdc, x, y, w, h, hdc, x, y, SRCINVERT);
    DeleteObject(hrgn);
    ReleaseDC(NULL, hdc);
}
DWORD WINAPI wef(LPVOID lpParam) {
    RECT rect;
    GetWindowRect(GetDesktopWindow(), &rect);
    int w = rect.right - rect.left - 500, h = rect.bottom - rect.top - 500;
 
    for (int t = 0;; t++)
    {
        const int size = 1000;
        int x = rand()%(w+size)-size/2, y = rand()%(h+size)-size/2;
 
        for (int i = 0; i < size; i+=100)
        {
            ci(x-i/2, y-i/2, i, i);
            Sleep(25);
        }
    }
}
DWORD WINAPI rgbquad(LPVOID lpParam) {
	const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);
    HDC hdc, memdc;
    HBITMAP hdib;

    BITMAPINFO bInfo = {0};
    bInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.bmiHeader.biBitCount = 32;
    bInfo.bmiHeader.biPlanes = 1;
    bInfo.bmiHeader.biWidth = HDCX;
    bInfo.bmiHeader.biHeight = HDCY;
    bInfo.bmiHeader.biCompression = BI_RGB;
    bInfo.bmiHeader.biSizeImage = 0;

    RGBQUAD *pixel = {0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            pixel[i].rgbGreen += 30;
            pixel[i].rgbBlue += 15;
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hdib);
    }
}
DWORD WINAPI textout(LPVOID lpParam) {
	LPCWSTR lptext = L"mp4.exe";
	while (true) {

		HDC hdc;
		hdc = GetWindowDC(GetDesktopWindow());
		int sw = GetSystemMetrics(0);
		int sh = GetSystemMetrics(1);
		SetTextColor(hdc, MYRGB(0, 0, 255));
		SetBkColor(hdc, MYRGB(255, 0, 0));
		TextOutW(hdc, rand() % sw, rand() % sh, lptext, wcslen(lptext));
		TextOutW(hdc, rand() % sw, rand() % sh, lptext, wcslen(lptext));
		TextOutW(hdc, rand() % sw, rand() % sh, lptext, wcslen(lptext));
	}
}
DWORD WINAPI stat(LPVOID lpParam) {
	const int HDCX = GetSystemMetrics(0), HDCY = GetSystemMetrics(1);
	HDC hdc, memdc;
    HBITMAP hdib;

    BITMAPINFO bInfo = {0};
    bInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bInfo.bmiHeader.biBitCount = 32;
    bInfo.bmiHeader.biPlanes = 1;
    bInfo.bmiHeader.biWidth = HDCX;
    bInfo.bmiHeader.biHeight = HDCY;
    bInfo.bmiHeader.biCompression = BI_RGB;
    bInfo.bmiHeader.biSizeImage = 0;

    RGBQUAD *pixel = {0};

    while (1) {
        hdc = GetDC(0); memdc = CreateCompatibleDC(hdc);
        hdib = CreateDIBSection(hdc, &bInfo, NULL, (void**)&pixel, 0, 0);
        SelectObject(memdc, hdib);

        //BitBlt(memdc, 0, 0, HDCX, HDCY, hdc, 0, 0, SRCCOPY);

        for (int i = 0; i < HDCX * HDCY; i++) {
            int c = rand()%256;
            pixel[i].rgbBlue = c;
            pixel[i].rgbGreen = c;
            pixel[i].rgbRed = c;
        }

        BitBlt(hdc, 0, 0, HDCX, HDCY, memdc, 0, 0, SRCCOPY);

        ReleaseDC(0, hdc); DeleteDC(memdc); DeleteObject(hdib);
    }
}
int main(){
	    if (MessageBoxW(NULL, L"Run Malware?", L"mp4.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"Are You Sure?", L"mp4.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else{
        	HANDLE t1 = CreateThread(0, 0, gray, 0, 0, 0);
            sound1();
        	Sleep(30000);
            TerminateThread(t1, 0);
            CloseHandle(t1);
       	    HANDLE tt1 = CreateThread(0, 0, radius, 0, 0, 0);
            HANDLE t2 = CreateThread(0, 0, shake, 0, 0, 0);
            sound2();
        	Sleep(30000);
            TerminateThread(t2, 0);
            CloseHandle(t2);
            HANDLE t3 = CreateThread(0, 0, sinewaves, 0, 0, 0);
            sound3();
        	Sleep(30000);
            TerminateThread(t3, 0);
            CloseHandle(t3);
            HANDLE tt4 = CreateThread(0, 0, wef, 0, 0, 0);
            HANDLE t4 = CreateThread(0, 0, glitch, 0, 0, 0);
            sound4();
        	Sleep(30000);
            TerminateThread(t4, 0);
            CloseHandle(t4);
            TerminateThread(tt4, 0);
            CloseHandle(tt4);
            HANDLE t5 = CreateThread(0, 0, rgbquad, 0, 0, 0);
            sound5();
        	Sleep(30000);
            TerminateThread(t5, 0);
            CloseHandle(t5);
            HANDLE ttt6 = CreateThread(0, 0, wef, 0, 0, 0);
            HANDLE tt6 = CreateThread(0, 0, textout, 0, 0, 0);
            HANDLE t6 = CreateThread(0, 0, stat, 0, 0, 0);
            sound6();
        	Sleep(30000);
            TerminateThread(t6, 0);
            CloseHandle(t6);
            TerminateThread(tt6, 0);
            CloseHandle(tt6);
            TerminateThread(ttt6, 0);
            CloseHandle(ttt6);
            TerminateThread(tt1, 0);
            CloseHandle(tt1);
        }
    }
}
