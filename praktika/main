package org.example;

import figures.*;

public class Main {
    public static void main(String[] args) {
        try {
            // Создаем фигуры
            Rectangle rectangle = new Rectangle(5, 3);
            Circle circle = new Circle(4);
            Triangle triangle = new Triangle(3, 4, 5);

            // Вычисляем площади
            System.out.println("Rectangle area: " + rectangle.calculateArea());
            System.out.println("Rectangle perimeter: " + rectangle.calculatePerimeter());

            System.out.println("Circle area: " + circle.calculateArea());
            System.out.println("Circle perimeter: " + circle.calculatePerimeter());

            System.out.println("Triangle area: " + triangle.calculateArea());
            System.out.println("Triangle perimeter: " + triangle.calculatePerimeter());

            // Пример с некорректными параметрами
            // Triangle invalidTriangle = new Triangle(1, 2, 10); // Выбросит исключение

        } catch (RuntimeException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
