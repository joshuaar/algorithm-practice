//Quicksort with index 0 always as pivot choice
//O(n^2) worst case, O(nlog(n)) average case (if pivot roughly divides array in half)
//good pivot choice ensures nlog(n)
import java.util.Arrays;
class SorterApp {
    public static int[] arr = {3,6,-1,10,14,32,-100};

    public static int[] quicksort(int[] arr){
        return quicksort(arr,0,0,arr.length-1);
    }
    private static int[] quicksort(int[] arr, int pivot, int fst, int lst){
        if(fst >= lst | arr.length == 0)
            return arr;
        if(fst - lst == 1){
            if(arr[fst] > arr[lst])
                swap(arr,fst,lst);
            return arr;
        }
        swap(arr, pivot, lst);//move pivot to last position
        pivot = lst;//
        int marker = fst;//put a swap spot in first position
        for(int i=fst;i<lst;i++){//go through array checking for values smaller than pivot
            if(arr[i] < arr[pivot]){
                swap(arr,marker,i);//swap smaller values with marker (always ahead or equal to marker)
                marker += 1;//incriment marker to get to new swap spot
            }
        }
        swap(arr,marker,pivot);//put pivot in final place
        pivot = marker;//retrack pivot
        quicksort(arr,pivot+1,pivot+1,lst);//quicksort the right side
        quicksort(arr,fst,fst,pivot-1);//quicksort the left side
        return arr;
    };
    
    public static void swap(int[] arr,int i,int j){
        int holder = arr[i];
        arr[i] = arr[j];
        arr[j] = holder;
    };
    
    public static void main(String[] args){
        System.out.println(Arrays.toString(arr));
        quicksort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
