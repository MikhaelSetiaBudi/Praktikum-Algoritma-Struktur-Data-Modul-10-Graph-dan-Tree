#include<iostream> 
#include<iomanip> 
using namespace std; 

string simpul[7] = {"ciamis", "Bandung","Bekasi","Tasikmalaya","cianjur","Purwokerto", "Yogyakarta"}; 

int busur [7][7] = { 
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph(){ 
    for(int i = 0; i < 7; i++){ 
        cout<<simpul[i]<<" : "<<endl; 
        for(int j = 0; j < 7; j++){ 
            if(busur[i][j] != 0 ) 
            cout<<"-->"<<simpul[j]<<" ("<<busur[i][j]<<")"<<endl; 
        }
        cout<<endl; 
    }
}

int main(){ 
    tampilGraph(); 
    return 0; 
}