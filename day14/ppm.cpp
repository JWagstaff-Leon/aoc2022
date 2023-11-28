#include <vector>
#include <utility>
#include <fstream>
#include <iostream>

#include "rocks.h"
#include "sands.h"

int main()
{
    bool rocka[400][200];
    bool sanda[400][200];
    for(int x = 0; x < 400; x++)
        for(int y = 0; y < 200; y++)
        {
            rocka[x][y] = false;
            sanda[x][y] = false;
        }
    for(auto rock : rocks)
        rocka[rock.first - 300][rock.second] = true;
    for(auto grain : sands)
        sanda[grain.first - 300][grain.second] = true;
    
    std::ofstream fout("output.ppm");
    fout << "P3\n400 200\n255\n";
    for(int y = 0; y < 200; y++)
        for(int x = 0; x < 400; x++)
            fout << (rocka[x][y] ? "80 80 80 " : (sanda[x][y] ? "180 180 0 " : "255 255 255 "));

    fout.close();
    return 0;
};