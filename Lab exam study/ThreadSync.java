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
    int n;

    mythread1(square def, int n) {
        s = def;
        this.n = n;
    }

    public void run() {
        s.printSquare(n);
    }
}

class ThreadSync {
    public static void main(String[] args) {
        square abc = new square();
        mythread1 t1 = new mythread1(abc, 5);
        mythread1 t2 = new mythread1(abc, 6);
        t1.start();
        t2.start();
    }
}