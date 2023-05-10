#include <iostream>
#include <list>
using namespace std;

// Check the non-zero in the box of the target cell to remove them from the checklist
list <int> checkInBox(int array [][9], int startRowInd, int startColumnInd, list<int> numList){
    for(int i=startRowInd; i<(startRowInd+3); i++){
        for(int j=startColumnInd; j<(startColumnInd+3); j++){
            if(array[i][j]>0)
            numList.remove(array[i][j]);
        }
    }
    return numList;
}
// Check the non-zero in the row of the target cell to remove them from the checklist
list <int> checkInRow(int array [][9], int startRowInd, list<int> numList){
    for(int j=0; j<9; j++){
        if(array[startRowInd][j]>0)
        numList.remove(array[startRowInd][j]);
    }
    return numList;
}


// Check the non-zero in the column of the target cell to remove them from the checklist
list <int> checkInColumn(int array [][9], int startColumnInd, list<int> numList){
    for(int i=0; i<9; i++){
        if(array[i][startColumnInd]>0)
        numList.remove(array[i][startColumnInd]);
    }
    return numList;
}

// Check if the sudoku problem get solved
bool checkIfFinish(int arr [][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j]==0)
            return false;
        }
    }
    return true;
}

int main() {
   
    int array [9][9] = {
      {5,3,0,0,7,0,0,0,0},
      {6,0,0,1,9,5,0,0,0},
      {0,9,8,0,0,0,0,6,0},
      {8,0,0,0,6,0,0,0,3},
      {4,0,0,8,0,3,0,0,1},
      {7,0,0,0,2,0,0,0,6},
      {0,6,0,0,0,0,2,8,0},
      {0,0,0,4,1,9,0,0,5},
      {0,0,0,0,8,0,0,7,9}
    };
   
    int startRowInd=0, startColumnInd=0;
    list<int> numList, checkList;
 
    
// Fill the numList with all the cell possible values 
for (int i = 1; i < 10; ++i) {
        numList.push_front(i);
    }
    while (!checkIfFinish(array)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(array[i][j]==0){
                    startRowInd=0;
                    startColumnInd=0;
                    if(i!=0){
                        startRowInd= int((i/3)*3);
                       
                    }
                    if(j!=0){
                        startColumnInd= int((j/3)*3);
                    }
                   
                    checkList=checkInBox(array, startRowInd, startColumnInd, numList);
                    checkList= checkInRow(array, i, checkList);
                    checkList= checkInColumn(array, j, checkList);
                    if(checkList.size()==1){
                        array[i][j]=checkList.front();
                    }
                }
            }
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}