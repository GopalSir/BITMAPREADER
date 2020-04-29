#include "bitmap.h"

bitmap::bmpopen(char* f)
{
	char check[2];
	FILE.open(f,ios::binary|ios::in|ios::out);
	FILE.read((char*)&check,2);
	
	if(check[0]=='B' && check[1]=='M')
	{
		FILE.seekg(28,ios::beg);
		FILE.read((char*)&bit,4);
		
		FILE.seekg(18,ios::beg);
		FILE.read((char*)&width,4);
		
		FILE.seekg(22,ios::beg);
		FILE.read((char*)&height,4);
		
		FILE.seekg(2,ios::beg);
		FILE.read((char*)&size,4);
		
		FILE.seekg(10,ios::beg);
		FILE.read((char*)&pixelstart,4);
		
		
		
		return 1;
	}
	else
	{
		cout<<"failed";
		return 0;
	}
}

bitmap::getbit()
{
	
	return bit;
}

bitmap::getwidth()
{
	
	return width;
}
bitmap::getheight()
{
	
	return height;
}
bitmap::getsize()
{

	return size;
}
vector<vector<int> > bitmap::getpixgrid()
{	
	unsigned char pval=(int)(0);
	
	int colbytes = getwidth()*getbit()/8;
	int rowbytes = getheight();
	grid.resize(rowbytes);
	int padding = (4 - colbytes%4)%4;
	FILE.seekg(pixelstart,ios::beg);
	

	for(int i=0;i<rowbytes;++i)
	{
		 
		 
		for(int j=0;j<getwidth();++j)
		{
		   
		    
			FILE.read((char*)&pval,1);
			grid[i].push_back((int)(pval));
			FILE.read((char*)&pval,1);
			grid[i].push_back((int)(pval));   
			FILE.read((char*)&pval,1);
			grid[i].push_back((int)(pval));
			
		}
		
		for(int j=0;j<padding;++j)
		FILE.read((char*)&pval,1);
	}
	 reverse(grid.begin(),grid.end());
	 return grid;
	 
}

void bitmap::setpixgrid()
{
	
}

bitmap::bitmap(void)
{
	cout<<"Oject now Live!!"<<endl;    //destructor
}
bitmap::~bitmap()
{
   	FILE.close();         //destructor closing the file
	cout<<"FILE CLOSED";
}



