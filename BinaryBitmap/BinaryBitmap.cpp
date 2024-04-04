#include "bitmap.h"
#include <iostream>

int main()
{
    const int width{ 800 };
    const int height{ 600 };
    const int x_mid = width / 2;
    const int y_mid = height / 2;
    const int x_unit = x_mid / 4;
    const int y_unit = y_mid / 4;

    bitmap bmp("test.bmp");
    pixel background{ 127,127,127 };
    bmp.set_all(background);

    pixel red{ 0,0,255 };

    for (int x = 0; x < x_unit; x++)
    {
        for (int y = 0; y < height; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }
    
    for (int x = x_unit; x < x_mid; x++) {
        for (int y = 0; y < y_unit; y++)
        {
            bmp.set_pixel(x, y, red);
        }
        for (int y = height-y_unit; y < height; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }

    // first plus
    for (int x = x_mid-2*x_unit; x < x_mid; x++)
    {
        for (int y = y_mid-y_unit/2; y < y_mid+y_unit/2; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }
    for (int x = x_mid - 3 * x_unit/2; x < x_mid-x_unit/2; x++)
    {
        for (int y = 3*y_unit; y < 5*y_unit; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }

    // second plus
    for (int x = 5*x_unit; x < 7*x_unit; x++)
    {
        for (int y = y_mid - y_unit / 2; y < y_mid + y_unit / 2; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }
    for (int x = x_mid + 3 * x_unit / 2; x < x_mid + 5*x_unit/2; x++)
    {
        for (int y = 3 * y_unit; y < 5 * y_unit; y++)
        {
            bmp.set_pixel(x, y, red);
        }
    }

    if (bmp.write())
        std::cout << "Succeeded\n";
    else
        std::cout << "Failed\n";
}
