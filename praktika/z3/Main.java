package org.example;

public class Main {
    public static void main(String[] args) {
        System.out.println("Тестирование SortedStringArray\n");

        // Создаем массив
        SortedStringArray array = new SortedStringArray();

        // Добавляем элементы
        array.add("яблоко");
        array.add("банан");
        array.add("вишня");
        array.add("да");
        array.add("электричество");

        // Выводим все элементы
        System.out.println("Элементы массива:");
        for (int i = 0; i < array.size(); i++) {
            System.out.println("  [" + i + "]: \"" + array.get(i) +
                    "\" (длина: " + array.get(i).length() + ")");
        }

        // Максимальный элемент
        System.out.println("\nМаксимальный элемент: \"" + array.getMax() +
                "\" (длина: " + array.getMax().length() + ")");

        // Средняя длина
        System.out.println("Средняя длина строк: " + array.getAverageLength());

        // Проверка с пустым массивом
        System.out.println("\n--- Проверка с пустым массивом ---");
        SortedStringArray emptyArray = new SortedStringArray();
        System.out.println("Максимальный в пустом массиве: " + emptyArray.getMax());
        System.out.println("Средняя длина в пустом массиве: " + emptyArray.getAverageLength());

        // Еще пример
        System.out.println("\n--- Еще один пример ---");
        SortedStringArray array2 = new SortedStringArray();
        array2.add("кот");
        array2.add("собака");
        array2.add("мышь");

        System.out.println("Элементы: ");
        for (int i = 0; i < array2.size(); i++) {
            System.out.println("  " + array2.get(i));
        }
        System.out.println("Максимальный: " + array2.getMax());
        System.out.println("Средняя длина: " + array2.getAverageLength());
    }
}