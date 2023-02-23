import javax.swing.*;
import java.awt.*;

class frame extends JFrame {
    JPanel p1 = new JPanel();
    JPanel p2 = new JPanel();
    JTextField textfield;

    frame() {
        setTitle("calculator");
        setSize(800, 800);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        JButton b1 = new JButton("1");
        JButton b2 = new JButton("2");

        JButton b3 = new JButton("3");
        JButton b4 = new JButton("4");
        JButton b5 = new JButton("5");
        JButton b6 = new JButton("6");
        JButton b7 = new JButton("7");
        JButton b8 = new JButton("8");
        JButton b9 = new JButton("9");
        JButton b10 = new JButton("+");
        JButton b11 = new JButton("-");
        JButton b12 = new JButton("x");
        JButton b13 = new JButton("/");
        JButton b14 = new JButton("=");
        JButton b15 = new JButton("CLR");

        // adding buttons to the frame
        p2.setLayout(new GridLayout(3, 3));
        p2.add(b1);
        p2.add(b2);
        p2.add(b3);
        p2.add(b4);
        p2.add(b5);
        p2.add(b6);
        p2.add(b7);
        p2.add(b8);
        p2.add(b9);
        p2.add(b10);
        p2.add(b11);
        p2.add(b12);
        p2.add(b13);
        p2.add(b14);

        // Textfiled
        textfield = new JTextField();
        textfield.setBounds(0, 0, 400, 100);
        textfield.setSize(400, 100);

        p1.add(textfield);

        setVisible(true);
        p1.setBounds(200, 100, 400, 100);
        add(p1);
        p2.setBounds(0, 400, 800, 400);
        add(p2);
    }
    // public void actionPerformed(ActionEvent e)
    // {

    // }
}

public class calculator {
    public static void main(String args[]) {
        new frame();
    }

}