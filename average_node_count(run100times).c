/*計算100次跑測資後的平均值*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *tinput, *resultFile;

int calculate (float num, float sum, int value)
{
    float average = 0;
    char inputFileName[1000]={0}; 
    char outputFileName[1000]={0}; 
    sum = 0;

    sprintf(inputFileName,"calculate/MMDIS_averageCountBA%d.txt",value); //*change fileName*//
    tinput = fopen(inputFileName, "r"); 
    sprintf(outputFileName,"result/MMDIS_result_BA%d.txt",value);   
    resultFile=fopen(outputFileName,"w"); 

    for (int i = 0; i< 100; i++) 
    {            
        fscanf(tinput,"%f",&num);
        sum += num;
    } 
     average = sum / 100;
    printf("average: %f\n",average); 
    fprintf(resultFile,"%f\n",average);

    fclose(tinput); 
    fclose(resultFile); 

}
int main ()
{
	float num = 0;
	float sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        calculate(num, sum, i); 
    }
}