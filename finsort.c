#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        perror("Error opening input file");
        return 1;
    }

    while (fscanf(inputFile, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(inputFile);


    insertionSort(arr, n);

    outputFile = fopen("abc.text", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }
    fclose(outputFile);

    printf("Sorted data written to abc.text\n");

    return 0;
}
