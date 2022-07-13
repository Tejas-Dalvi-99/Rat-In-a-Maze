#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

bool Rat_In_RightPath(int **arr, int i, int j, int n)
{
    if (i < n && j < n && arr[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int i, int j, int n, int **SolutionMatrix)
{

    if (i == n - 1 && j == n - 1)
    {
        SolutionMatrix[i][j] = 1;
        return true;
    }

    if (Rat_In_RightPath(arr, i, j, n))
    {
        SolutionMatrix[i][j] = 1;
        if (ratInMaze(arr, i + 1, j, n, SolutionMatrix))
        {
            return true;
        }

        if (ratInMaze(arr, i, j + 1, n, SolutionMatrix))
        {
            return true;
        }
        SolutionMatrix[i][j] = 0; // BackTrack
        return false;
    }
    return false;
}

int main()
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int n, sec1 = 1;
    system("CLS");
    SetConsoleTextAttribute(h, 1);
    cout << "Enter Size of The Matrix : ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    cout << "\n\nEnter the Matrix Path : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<("\t\t\t "); 
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    system("CLS");
    int **SolutionMatrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        SolutionMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            SolutionMatrix[i][j] = 0;
        }
    }
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t\t\t       ====================================";
    SetConsoleTextAttribute(h , 11); 
    cout << "\n\t\t\t\t\t!<--- This Might be One Path --->!\n";
    SetConsoleTextAttribute(h , 14); 
    cout << "\t\t\t\t       ====================================\n";
    cout << "\n\n"
         << endl;
    SetConsoleTextAttribute(h , 14);      
    cout << "\t\t\t\t       ------------------------------------\n";
    if (ratInMaze(arr, 0, 0, n, SolutionMatrix))
    {

        for (int i = 0; i < n; i++)
        {
            cout << "\t\t\t\t\t ";
            for (int j = 0; j < n; j++)
            {
                if (SolutionMatrix[i][j] == 1)
                {
                    SetConsoleTextAttribute(h, 10);
                    cout << SolutionMatrix[i][j] << "\t";
                }
                else
                {
                    SetConsoleTextAttribute(h, 12);
                    cout << SolutionMatrix[i][j] << "\t";
                }
                Sleep(600);
            }
            if (i == n - 1)
            {
                SetConsoleTextAttribute(h, 14);
                cout << "\n";
                cout << "\t\t\t\t       ------------------------------------\n";
            }
            cout << endl
                 << endl
                 << endl;
        }
    }
    else
    {
        cout << "No Path Found ";
    }
    SetConsoleTextAttribute(h, 7);
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

// 1 0 0 0 0
// 1 0 0 0 0
// 1 0 0 0 0
// 1 0 0 0 0
// 1 1 1 1 1

// Sample Matrix
