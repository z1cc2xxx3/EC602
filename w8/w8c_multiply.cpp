
 // AUTHOR johnkeisling jfkeis@bu.edu
 // AUTHOR Sigurdur Egill Thorvaldsson sigurdur@bu.edu
 //
 // w8c_muliply.cpp
 // g++ -std=c++14 -O2 ./output2 source.cpp
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//w8c_multiply dtype M N L file1 file2 file3

/*
void multMatD(int i, int j, vector<vector<double>> mat1, vector<vector<double>> mat2) {
    
    vector<vector<double>> mat3;
    for (int r = 0; r < i; r++) {
        for (int c = 0; c < j; c++) {
            for (int in = 0; in < i; in++) {
                mat3[r][c] += mat1[r][in] * mat2[in][c];
            }
            cout << mat3[r][c] << "  ";
        }
        cout << "\n";
    }
}
*/
template <typename T>
T multMatI(int i, int j, T mat1, T mat2) {
    
    vector<int> v(i, 0);
    T mat3(j,v);
    for (int r = 0; r < i-1; r++) {  //added -1 to fix
        for (int c = 0; c < j; c++) {
            for (int in = 0; in < i; in++) {
                mat3[r][c] += mat1[r][in] * mat2[in][c];
            }
            cout << mat3[r][c] << "  ";
        }
        cout << "\n";
    }
    return mat3;
}

 int main(int argc, char *argv[]){
     
     /*
     for(int i=0; i<argc; i++){
         if(argc != 6 || argc != 8){
             return 1;
         }
     }
     */
     
     ifstream file1, file2;
     ofstream file3;
     //if(argc==8){
         file1.open(argv[5]);
         file2.open(argv[6]);
         file3.open(argv[7]);
         int m = atoi(argv[2]);
         int n = atoi(argv[3]);
         int l = atoi(argv[4]);
     //}
     /*
     else if(argc==6){
         file1.open(argv[3]);
         file2.open(argv[4]);
         file3.open(argv[5]);
         int m = argv[2];
     }
    */
     //else{
     //    return code 1;
     //}
     
     
     
     string dtype = argv[1];
     
     //file1.open("xtest1.txt");
     //file2.open("xtest2.txt");
     //file3.open("xtest3.txt");
     //bool dtype = true;
     
     //int m = 3;
     //int n = 4;
     //int l = 3;
     
     /*
     if(dtype){
        vector<vector<int>> data1;
        vector<vector<int>> data2;
        cout << "this  ";
     }
     else if (!dtype){
         vector<vector<double>> data1;
         vector<vector<double>> data2;
     }
      */
     
     vector<vector<int>> data1;
     vector<vector<int>> data2;

     //while (!myRfile1.eof()) {
         for(int i = 0; i < m; i++){  //row
             vector<int> tmpVec;
             int tmpString;
             
             for (int j = 0; j < n; j++){  //col
                 file1  >> tmpString;
                 //myfile1 << tmpString << " ";
                 tmpVec.push_back(tmpString);
             }
             data1.push_back(tmpVec);
             //myfile1 << endl;
         }
     //}
     file1.close();
     
     //zero vector 1
     vector<int> z1(n, 0);
     vector<vector<int>> zer1(m,z1);
     //cout << zer1.size() << "\n" << zer1[0].size() << "\n";
     
     
     //if all zero then file does not exist
     if(data1 == zer1)
     {
         return 3;
     }
     
     
     //while (!myRfile2.eof()) {
         for(int i = 0; i < n; i++){ //row
             vector<int> tmpVec;
             int tmpString;
             
             for (int j = 0; j < l; j++){  //col
                 file2  >> tmpString;
                 //myfile2 << tmpString << " ";
                 tmpVec.push_back(tmpString);
             }
             data2.push_back(tmpVec);
             //myfile2 << endl;
         }
     //}
     file2.close();
     
     //zero vector 2
     vector<int> z2(l, 0);
     vector<vector<int>> zer2(n,z2);

     //if all zero then file does not exist    //note this one does not really work because instead of the nonexistent one being all zeros, it instead is all 32767 for some reason
     if(data2 == zer2)
     {
         return 3;
     }
     
     
     int M = int(data1.size());
     //int N = int(data1[0].size());
     int L = int(data2[0].size());
     
     vector<vector<int>> result = multMatI(M+1, L, data1, data2);
     
     //zero vector 3
     vector<int> z3(M, 0);
     vector<vector<int>> zer3(L,z3);
     
     // if last file cannot be created (this doesnt really work either)
     if(result == zer3)
     {
         return 4;
     }
     
     for(int i = 0; i < M; i++){ //row
         vector<int> tmpVec;
         for (int j = 0; j < L; j++){  //col
             file3 << result[i][j] << " ";
         }
         file3 << endl;
     }
          file3.close();
     
     //cout << "fin ";
     return 0;
 }

//exit(1)
// g++ -std=c++14 main.cpp
//  ./a.out xtest1.txt xtest2.txt xtest3.txt
