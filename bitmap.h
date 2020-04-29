#pragma 1

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

class bitmap
{
	public:
		int getsize(); // size in bytes (divide by 1024 for KB i.e KILOBYTES);
		int getwidth(); // width of pixels without padding;
		int getheight();// height of pixels from bottom to up (can be negative for top to bottom);
		int getbit();   // return the number of bits per pixel 
		int bmpopen(char* f);
		vector<vector<int> > getpixgrid();
		void setpixgrid();
	    bitmap();
		~bitmap();
		
	protected:
		vector< vector<int> > grid;
		char* filename;
		fstream FILE;
		int width,
			height,
			size,
			pixelstart,
			bit;
		
		
};


