#include<stdio.h>

void merge_array(int ar[], int start, int mid, int end) {
    /*
    At fist we copy every element from the original array in the sorted way.
    Then replace the original array with temporary array and to get the sorted
    array[start to  end]
    */
    int temp_ar[end-start+1];
    int p = start, q = mid+1, k = 0;

    for(int i = start; i <= end; i++){
        if(q > end) { // if last part already copied
            temp_ar[k++] = ar[p++]; // so we should copy element from the first part
        }
        else if(p > mid) { // if first part already copied
            temp_ar[k++] = ar[q++]; // so copy from rest of the last part.
        }
        else if(ar[p] > ar[q]){ // if both parts exist then compare
            temp_ar[k++] = ar[q++];
        }
        else{
            temp_ar[k++] = ar[p++];
        }
    }
    // now copy from the temporary array
    for(int i = 0; i < k; i++){
        ar[start++] = temp_ar[i];
    }
}


void merge_sort(int ar[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort(ar, start, mid);
        merge_sort(ar, mid+1, end);

        /**
        Now we have two array [start, mid] and [mid+1, end].
        after calling merge_array function we will get a single array [start, end]
        that should be sorted because we have merged in sorted way.
        **/
        merge_array(ar, start, mid, end);
        /**
        Now array [start to end] is sorted.
        In this way every part of the divided array is merged and sorted.
        **/
    }
}

int main() {
    // 0 based array indexing
    int ar[] = {5, 4, 3, 8, 1, 6, 9, 5, 4, 3};
    merge_sort(ar, 0, 9);
    for(int i = 0; i < 10; i++) {
        printf("%d ", ar[i]);
    }
    return 0;
}
