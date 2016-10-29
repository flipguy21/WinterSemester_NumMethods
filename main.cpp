//----------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

//----------------------------------------------------------------------

void toPrint(double *M[], int m, int n);

double myFUNC(double *A[], int s, int t);

double tmatrix(double E[3][3]);

//double fmax(double *A)[], int g, int h);

//======================================================================

#pragma argsused
int main(int argc, char* argv[])
{
//   char Name[30];
	FILE *pf = fopen("/Users/flipguy21/Downloads/mac_5x3.dat", "r");

	int i,j;
	int m,n;
	fscanf(pf,"%d %d", &m, &n);
 
// Kreowanie tablic dynamicznych;
	double **M;
	M = new double* [m];
	for(i=0; i<m; i++)
		M[i] = new double [n];

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {

                    double x;
			fscanf(pf,"%lf",&x);
			M[i][j] = x;
		}
	}
	fclose(pf);
        
	toPrint(M, m, n);
  
        cout << "Norma Wierszowa: " << myFUNC(M,m,n);
// Usuwanie tablic dynamicznych;
	for(i=0; i<m; i++)
		delete [] M[i];
	delete M;
       
    system("read");
    
	return 0;
}
//======================================================================
void toPrint(double *M[], int m, int n)
{
	printf("\nArray( %u x %u )\n\n", m, n);
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf(" %6.1lf", M[i][j]);
		}
		printf("\n");
	}
}
//----------------------------------------------------------------------

//======================================================================

double myFUNC(double *A[], int s, int t){
    
    double tempMAX = 0.0;
    double rowSUM = 0.0;
    
    for(int i=0; i<s; i++){
        rowSUM = 0.0;
        for(int j=0; j< t; j++){
            rowSUM += abs(A[i][j]);    
        }
        if (rowSUM > tempMAX) {tempMAX = rowSUM;}
    }
    return tempMAX; 
}

//========================================================================

double tmatrix(double E[3][3]){
    
    double answer = 0.0;
    
    answer = E[0][0] * ((E[1][1]*E[2][2]) - (E[2][1]*E[1][2])) -E[0][1] * (E[1][0]
   * E[2][2] - E[2][0] * E[1][2]) + E[0][2] * (E[1][0] * E[2][1] - E[2][0] * E[1][1]);
    
  return answer;  
    //return (B[0][1]*((B[2][2]*B[3][3])-(B[2][3]*B[3][2])));//-(B[1][2]*((B[2][1]*B[3][3])-(B[2][3]*B[3][1])))+(B[1][2]*((B[2][1]*B[3][2])-(B[2][2]*B[3][1])));
    
}
/*
   printf("\nName of input file: ");
   scanf("%s", Name);
//   strcat(Name, ".dat");
   FILE *pf = fopen(Name, "rt");
*/

