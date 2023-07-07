#pragma once

#include <Windows.h>
// fungsi: xyColor()
// Meletakkan kursor pada posisi x, y di layar konsol dan memberikan warna.
// tipe: void
// arg.: SHORT x - posisi x
//       SHORT y - posisi y
//       WORD fc - warna depan (0-15)
//       WORD bc - warna latar (0-15)
void xyColor(SHORT x, SHORT y, WORD fc, WORD bc)
{
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hwnd, {x, y});
    SetConsoleTextAttribute(hwnd, fc + (bc << 4));
}