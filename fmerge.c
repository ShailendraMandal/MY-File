#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int size = 1000; 
    int arr[size];
    int n = 0; 

    FILE *fp;
    int a[10]={2,8,9,1,6,5,7,3,4,11};
    fp=fopen("ab.txt","w");

    
    for(int i=0;i<10;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
    
    fclose(fp);

    inputFile = fopen("ab.txt", "r");
    if (inputFile == NULL) {
        return 1;
    }

    
    while (fscanf(inputFile, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(inputFile);


    selectionSort(arr, n);


    outputFile = fopen("abc.text", "w");
    if (outputFile == NULL) {
        
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }
    fclose(outputFile);

    printf("Sorted data written to abc.text\n");

    return 0;
}
