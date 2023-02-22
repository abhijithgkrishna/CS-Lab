import java.util.*;

class Bcd {
    int a = 5;
    int b = 6;

    Bcd() {
        a = 5;
        b = 6;
    }
}

class Cde extends Bcd {
    int a = 1;
    int b = 3;

    Cde() {

        this.a = 8;
    }

    void sum() {
        System.out.println(super.a + b);
    }
}

class Test {

    int x = 3;
    int y = 4;

    Test(int x, int y) {
        this.x = x;
        this.y = y;
    }

    void sum(Bcd A) {
        int sum = A.a + A.b;
        System.out.println(sum);
    }

    void sum(int a) {
        System.out.println(a);
    }

}

public class Classer {
    static void printer() {
        System.out.println("hello");
    }

    public static void main(String[] args) {
        Test obj = new Test(5, 7);
        Bcd obj1 = new Bcd();
        System.out.println(obj.x + "   " + obj.y);
        obj.sum(obj1);
        obj.sum(5);
        System.out.println(args[0] + args[1]);
        System.out.println(args[0].getClass());
        Integer num = Integer.parseInt(args[0]);
        System.out.println(num.getClass());
        printer();
        Cde ob = new Cde();
        ob.sum();

    }
}