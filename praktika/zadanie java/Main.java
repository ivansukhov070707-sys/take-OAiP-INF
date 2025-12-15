public class Main {
    public static void main(String[] args) {
        Product laptop = new Product("Ноутбук", 75000.0);
        Product mouse = new Product("Мышка", 1500.0);
        Product keyboard = new Product("Клавиатура", 3000.0);
        Cart cart = new Cart();
        cart.addProduct(laptop);
        cart.addProduct(mouse);
        cart.addProduct(keyboard);
        cart.printCart();
        System.out.println("\nУдаляем: Мышка\n");
        cart.removeProduct("Мышка");
        cart.printCart();
    }
}