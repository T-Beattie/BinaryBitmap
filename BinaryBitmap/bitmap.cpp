#include <fstream>
#include "bitmap.h"

void bitmap::set_pixel(int x, int y, pixel p)
{
    int idx = y * width + x;

    pixels[idx] = p;
}

void bitmap::set_row(int rownum, pixel p)
{
    for (int i = 0; i < width; i++)
    {
        set_pixel(i, rownum, p);
    }
}

void bitmap::set_all(pixel p)
{
    for (int i = 0; i < height; i++)
    {
        set_row(i, p);
    }
}

bool bitmap::write()
{
    bitmap_file_header file_header;
    bitmap_info_header info_header;

    file_header.file_size = sizeof(bitmap_file_header) 
        + sizeof(bitmap_info_header) 
        + width * height * sizeof(pixel);
    file_header.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);


    info_header.width = width;
    info_header.height = height;

    std::ofstream ofile(filename, std::fstream::out | std::fstream::binary);

    if (!ofile.is_open())
        return false;

    ofile.write(reinterpret_cast<char*>(&file_header), sizeof(bitmap_file_header));

    ofile.write(reinterpret_cast<char*>(&info_header), sizeof(bitmap_info_header));

    ofile.write(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(pixel));

    if (!ofile)
        return false;

    ofile.close();


    return true;
}
