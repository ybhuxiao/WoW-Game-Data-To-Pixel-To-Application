#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

int main(int argc, char** argv)
{

	while (true) {
		HWND desktop = GetDesktopWindow();
		HDC desktopHdc = GetDC(desktop);

		RECT desktopR;
		GetWindowRect(desktop, &desktopR);
		int horizontal = desktopR.right;
		int vertical = desktopR.bottom;
		horizontal = horizontal / 2 - 1;
		vertical = vertical / 2 - 1;

		COLORREF color = GetPixel(desktopHdc, horizontal, vertical);
		ReleaseDC(desktop, desktopHdc);

		int red, green, blue;
		red = green = blue = 0;

		blue = (color / 65536) & 255;
		green = (color / 256) & 255;
		red = color & 255;

		double pHealth = ceil(((double)red / (double)255)*100)/100;

		std::cout << "PlayerHealth = " << pHealth << std::endl;
	}
	return 0;
}