#pragma once

class Bitmap {
    unsigned char * image;
    
    const char * filename;
    int idx = 0;
    public:
        const int height;
        const int width;
        const int size;
        Bitmap(const char * filename, const int height, const int width);

        ~Bitmap();

        void operator<<(float input);
        void fill(float clr);
        void add(int x, int y, float r, float g, float b);
};