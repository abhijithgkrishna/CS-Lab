public class ThrowExample {

    void Votingage(int age) {
        if (age < 18)
            throw new ArithmeticException("you can't vote as not Eligible to  vote");
        else
            System.out.println("Eligible for voting");
    }

    public static void main(String args[]) {
        ThrowExample obj = new ThrowExample();
        obj.Votingage(13);
        System.out.println("End Of Program");
    }
}