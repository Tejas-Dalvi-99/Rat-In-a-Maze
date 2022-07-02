#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std ; 

bool Rat_In_RightPath(int** arr ,int i , int j , int n){
    if(i<n && j<n && arr[i][j]==1){
        return true ; 
    }
    return false ; 
}

bool ratInMaze(int** arr , int i , int j , int n , int** PathMatrix){

    if(i==n-1 && j==n-1){
        PathMatrix[i][j]=1 ; 
        return true ; 
    }

    if (Rat_In_RightPath(arr , i , j,n)){
        PathMatrix[i][j]=1 ; 
        if (ratInMaze(arr , i+1 , j , n , PathMatrix))
        {
            return true ; 
        }

        if (ratInMaze(arr , i, j+1 , n , PathMatrix)){
                return true ; 
        }
        PathMatrix[i][j]=0 ; // BackTrack
        return false ; 
    }
    return false ; 
}

int main(){
    
    int n  , sec1=1; 
    system("CLS");
    cout<<"Enter Size of The Matrix : "; 
    cin>>n ; 

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE) ; 
    
    int** arr = new int*[n] ; 
    for(int i = 0 ; i<n ; i++){
        arr[i] = new int[n]; 
    }

    cout<<"Enter the Matrix Path : "<<endl ; 

    for(int i = 0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>arr[i][j]; 
        }
    }
    system("CLS");  
    int** PathMatrix = new int*[n] ; 
    for(int i = 0 ; i<n ; i++){
        PathMatrix[i] = new int[n]; 
        for(int j = 0 ; j<n ; j++){
            PathMatrix[i][j]=0 ; 
        }
    }

    cout<<"\t\t\t\t\t!<---This Might be One Path--->!"<<"\n\n"<<endl ; 

    if(ratInMaze(arr , 0 , 0 , n , PathMatrix)){

        for(int i = 0 ; i<n ; i++){
            cout<<"\t\t\t\t\t";
        for(int j=0 ; j<n ; j++){ 
            if(PathMatrix[i][j]==1){
            SetConsoleTextAttribute(h , 10); 
            cout<<PathMatrix[i][j]<<"\t"; 
            }
            else{
            SetConsoleTextAttribute(h , 12); 
            cout<<PathMatrix[i][j]<<"\t";
            }
            sleep(sec1) ; 
        }
        cout<<endl<<endl<<endl ; 
    }
    }
    SetConsoleTextAttribute(h , 7);
return 0 ; 
}


// 1 0 1 0 1              
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1  

// Sample Matrix
