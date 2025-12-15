package org.example;

public class SortedStringArray {
    private String[] array;
    private int size;

    public SortedStringArray() {
        array = new String[10];
        size = 0;
    }

    public void add(String str) {
        if (size >= array.length) {
            String[] newArray = new String[array.length * 2];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            array = newArray;
        }
        array[size] = str;
        size++;
    }

    public String getMax() {
        if (size == 0) return null;

        String max = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i].length() > max.length()) {
                max = array[i];
            }
        }
        return max;
    }

    public double getAverageLength() {
        if (size == 0) return 0;

        int total = 0;
        for (int i = 0; i < size; i++) {
            total += array[i].length();
        }
        return (double) total / size;
    }

    public int size() {
        return size;
    }

    public String get(int index) {
        if (index < 0 || index >= size) return null;
        return array[index];
    }
}