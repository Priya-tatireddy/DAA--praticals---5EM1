
#include <stdio.h>

int main() {
    int a[50], n, i, j, k, t;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    for(i=n/2-1;i>=0;i--) {
        k=i;
        while(2*k+1<n) {
            j=2*k+1;
            if(j+1<n && a[j+1]>a[j]) j++;
            if(a[k]>=a[j]) break;
            t=a[k]; a[k]=a[j]; a[j]=t;
            k=j;
        }
    }
    for(i=n-1;i>0;i--) {
        t=a[0]; a[0]=a[i]; a[i]=t;
        k=0;
        while(2*k+1<i) {
            j=2*k+1;
            if(j+1<i && a[j+1]>a[j]) j++;
            if(a[k]>=a[j]) break;
            t=a[k]; a[k]=a[j]; a[j]=t;
            k=j;
        }
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}



