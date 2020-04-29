#include <iostream>
#include <fstream>
#include "bitmap.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

  char fl[]="test3.bmp";
  bitmap B;
  B.bmpopen(fl);
  cout<<B.getbit()<<endl;
  cout<<B.getwidth()<<endl;
  cout<<B.getheight()<<endl;
  cout<<B.getsize()<<endl;
  vector<vector<int> >data;
    data = B.getpixgrid();
    for(int i=0;i<data.size();++i)
    {
    	for(int j=0;j<data[0].size();++j)
    	{
    		cout<<data[i][j]<<" ";
		}
		cout<<"\n";
	}
  
   
  return 0;
}


