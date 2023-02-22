class OuterC1ass {
    int x = 10;

    class InnerC1ass {
        public int myInnerMethod() {
            return x;
        }
    }
}

public class MyMainClass {
    public static void main(String[] args) {
        OuterC1ass myOuter = new OuterC1ass();
        OuterC1ass.InnerC1ass mylnner = myOuter.new InnerC1ass();
        System.out.println(mylnner.myInnerMethod());
    }
}