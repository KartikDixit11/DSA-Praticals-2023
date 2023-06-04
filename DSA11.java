package com.KARTIK;
import java.util.Arrays;
import java.util.Scanner;

public class heapsort {
    //display

    static void display(int [] arr){
        for (int j : arr) {
            System.out.print(j+" ");
        }
        System.out.println();
    }

    static void create_heap (int [] arr,int count){

        for(int i=0;i<count;i++){
            int j;
            if(i!=0) {
                j = i;
                if (i % 2 == 0) {
                    while (j > 0 && arr[j] > arr[(j - 2) / 2]) {
                        int temp=arr[j];
                        arr[j]=arr[(j-2)/2];
                        arr[(j-2)/2]=temp;
                        j = (j - 2) / 2;
                    }
                }

                else {
                    while (j > 0 && arr[j] > arr[(j - 1) / 2]) {
                        int temp=arr[j];
                        arr[j]=arr[(j-1)/2];
                        arr[(j-1)/2]=temp;

                        j = (j - 1) / 2;
                    }
                }
            }
        }

    }
    static int[] heapsort(int [] ar){
        int [] cal=new int [ar.length];
        int n= ar.length;
        int t= -1;
        for(int i=0;i<ar.length;i++){
            cal[i]=ar[0];
            ar[0]=-1;
            create_heap(ar,n);

        }
        return cal;
    }


    public static void main(String [] args) {
        System.out.println("Enter The Count of Array ");
        Scanner inp=new Scanner(System.in);
        int count=inp.nextInt();
        int arr[]=new int [count];
        for(int i=0;i<count;i++){
            System.out.println("Enter Element:");
            arr[i]=inp.nextInt();
        }
        create_heap(arr,count);
        int []heaps=heapsort(arr);
        display(heaps);








    }


}
