#include <iostream>

using namespace std;

/*
No of Rows in Matrix A = No of Columns in Matrix B
Matrix A = 3 x 2
Matrix B = 2 x 3
Then multiplication is possible
*/
int main(int argc, char** argv) {
     int matA[3][2] = {{4,2}
                       ,{7,1}
                       ,{2,3}}; // No of Rows = 3
    int matB[2][3] = {{4,6,7}
                      ,{7,1,2}}; // No of Columns = 3


    cout<<"Matrix A:"<<endl;  // Printing value of Matrix A
    for( int i = 0 ; i< 3; i++) {
        for (int j = 0;  j<2; j++) {
            cout<<matA[i][j]<<"\t";  // \t used for tab
        }
        cout<<endl;  // for printing next row in new line
    }


    cout<<"Matrix B:"<<endl;  // Printing value of Matrix B
    for( int i = 0 ; i< 2; i++) {
        for (int j = 0;  j<3; j++) {
            cout<<matB[i][j]<<"\t";  // \t used for tab
        }
        cout<<endl;  // for printing next row in new line
    }

    int sum;
    cout<<"Matrix Multiplication:"<<endl;

    for( int i = 0 ; i< 3; i++) {  // Iteration upto no of rows in Matrix A
        for (int j = 0;  j<3; j++) {  // Iteration upto no of columns in Matrix B

            sum = 0; // assigning 0 to save new result every time


            for (int k = 0;  k< 2;  k++) {  // Iteration upto no of columns in Matrix A

                  sum = sum + matA[i][k] * matB[k][j];

            }
            cout<<sum<<"\t";  // \t used for tab
        }
        cout<<endl;  // for printing next row in new line
    }

return 0;
}
