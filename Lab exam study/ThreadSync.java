class square {
    synchronized void printSquare(int n) {
        for (int i = 1; i <= n; i++) {
            System.out.println(i * i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class mythread1 extends Thread {
    square s;

    mythread1(square def) {
        s = def;
    }

    public void run() {
        s.printSquare(5);
    }
}

class mythread2 extends Thread {
    square h;

    mythread2(square klm) {
        h = klm;
    }

    public void run() {
        h.printSquare(10);
    }
}

class ThreadSync {
    public static void main(String[] args) {
        square abc = new square();
        mythread1 t1 = new mythread1(abc);
        mythread2 t2 = new mythread2(abc);
        t1.start();
        t2.start();
    }
}