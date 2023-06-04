package com.KARTIK;
import java.io.*;
import java.sql.Array;
import java.util.Scanner;

public class data {

    static void arr_display(int [] arr){
        for (int j : arr) {
            System.out.print(j + "  ");
        }
        System.out.println();
    }
    static int maxele(int [] arr) {
        //Scanner inp = new Scanner(System.in);

        for (int i = 0; i < arr.length; i++) {
            if (i != 0) {
                int j = i;
                if ((i % 2) != 0) {while (j > 0 && arr[j] > arr[(j - 1) / 2]) {int temp = arr[j];arr[j] = arr[(j - 1) / 2];arr[(j - 1) / 2] = temp;j = (j - 1) / 2;}}
                else {while (j > 0 && arr[j] > arr[(j - 2) / 2]) {int temp = arr[j];arr[j] = arr[(j - 2) / 2];arr[(j - 2) / 2] = temp;j = (j - 2) / 2;}}
            }
        }
        return arr[0];
    }
    static int minele(int [] arr){
        for (int i = 0; i < arr.length; i++) {
            if (i != 0) {
                int j = i;
                if ((i % 2) != 0) {while (j > 0 && arr[j] < arr[(j - 1) / 2]) {int temp = arr[j];arr[j] = arr[(j - 1) / 2];arr[(j - 1) / 2] = temp;j = (j - 1) / 2;}}
                else {while (j > 0 && arr[j] < arr[(j - 2) / 2]) {int temp = arr[j];arr[j] = arr[(j - 2) / 2];arr[(j - 2) / 2] = temp;j = (j - 2) / 2;}}
            }
        }
        return arr[0];

    }

        public static void main (String[]args){
            System.out.println("Enter the Count of Students in Second Year Computer Engineering");
            int Count;
            Scanner inp = new Scanner(System.in);
            Count = inp.nextInt();
            int []heap=new int[Count];

            for(int i=0;i<Count;i++){
                System.out.println("Marks of Roll Number "+(i+1)+" -:");
                heap[i]= inp.nextInt();
            }

            System.out.println("Marks of "+Count+" Students");
            arr_display(heap);
            int Max,Min;
            Max=maxele(heap);
            Min=minele(heap);
            System.out.println("Highest Score-:"+Max);
            System.out.println("Lowest Score-:"+Min);

        }
}


