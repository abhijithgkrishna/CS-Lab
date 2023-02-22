import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawSec extends JPanel {
    int choice;
    int x[] = new int[] { 2, 3, 5 };
    int y[] = new int[] { 2, 3, 5 };

    DrawSec(int choice) {
        this.choice = choice;
    }

    public void paint(Graphics g) {
        switch (choice) {
            case 1:
                g.setColor(Color.green);
                g.fillRect(0, 0, 100, 100);
                break;
            case 2:
                g.setColor(Color.red);
                g.fillRect(0, 0, 100, 100);
                break;
            case 3:
                g.fillPolygon(x, y, 3);
                break;
            default:
                System.out.println("wrong choice");
        }
    }
}

class GUICalc extends JFrame implements ItemListener {
    JLabel l1;
    JRadioButton b1 = new JRadioButton("Red");
    JRadioButton b2 = new JRadioButton("Green");
    JRadioButton b3 = new JRadioButton("Yellow");

    ButtonGroup g = new ButtonGroup();

    DrawSec ob;

    GUICalc() {
        b1.addItemListener(this);
        b2.addItemListener(this);
        b3.addItemListener(this);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);
        ob = new DrawSec(1);
        g.add(b1);
        g.add(b2);
        g.add(b2);
        l1 = new JLabel("Simple calculator");
        l1.setFont(new Font("Times New Roman", Font.BOLD, 36));
        l1.setBackground(Color.black);
        l1.setBounds(300, 100, 300, 50);
        add(l1);
        ob.setBounds(300, 300, 100, 200);
        add(ob);
        b1.setBounds(20, 20, 100, 100);
        b2.setBounds(300, 20, 100, 100);
        b3.setBounds(450, 20, 100, 100);
        add(b1);
        add(b2);
        add(b3);
    }

    public void itemStateChanged(ItemEvent e) {
        if (e.getSource() == b1) {
            if (e.getStateChange() == 1) {
                System.out.println("green");
                ob.choice = 1;
                ob.repaint();
            }
        }
        if (e.getSource() == b2) {
            if (e.getStateChange() == 1) {
                System.out.println("red");
                ob.choice = 2;
                ob.repaint();
            }
        }
        if (e.getSource() == b3) {
            if (e.getStateChange() == 1) {
                System.out.println("yellow");
                ob.choice = 3;
                ob.repaint();
            }
        }
    }

}

public class Calculator {

    public static void main(String[] args) {
        GUICalc obj = new GUICalc();
        obj.setBounds(300, 100, 800, 600);
        obj.setVisible(true);
    }
}