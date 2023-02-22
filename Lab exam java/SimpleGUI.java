import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class DrawSec extends JPanel {
    int choice;
    int x1, y1;

    // public void paint(Graphics g) {
    // switch (choice) {
    // case 1:
    // g.setColor(Color.red);
    // g.fillRect(0, 0, 100, 100);
    // break;
    // case 2:
    // g.setColor(Color.green);
    // g.fillRect(0, 0, 100, 100);
    // break;
    // case 3:
    // g.setColor(Color.yellow);
    // g.fillRect(0, 0, 100, 100);
    // break;
    // case 4:
    // g.dispose();
    // break;
    // default:
    // System.out.println("wrong choice");
    // }
    // }
    public void paint(Graphics g) {
        System.out.println(x1 + y1);
        g.setColor(Color.black);
        g.drawRect(x1, y1, 10, 10);
    }
}

class GUICalc extends JFrame implements ItemListener, ActionListener, MouseListener {
    JLabel l1;
    JRadioButton b1 = new JRadioButton("Red");
    JRadioButton b2 = new JRadioButton("Green");
    JRadioButton b3 = new JRadioButton("Yellow");

    JButton clr = new JButton("Clear");

    ButtonGroup g = new ButtonGroup();

    DrawSec ob;

    GUICalc() {
        b1.addItemListener(this);
        b2.addItemListener(this);
        b3.addItemListener(this);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);
        ob = new DrawSec();
        ob.addMouseListener(this);
        g.add(b1);
        g.add(b2);
        g.add(b3);
        l1 = new JLabel("Color Filler");
        l1.setFont(new Font("Times New Roman", Font.BOLD, 36));
        l1.setBackground(Color.black);
        l1.setBounds(200, 100, 300, 50);
        add(l1);
        ob.setBounds(300, 300, 100, 200);
        add(ob);
        b1.setBounds(150, 20, 100, 50);
        b2.setBounds(300, 20, 100, 50);
        b3.setBounds(450, 20, 100, 50);

        clr.setBounds(200, 200, 100, 50);
        clr.addActionListener(this);
        add(clr);

        add(b1);
        add(b2);
        add(b3);
    }

    public void itemStateChanged(ItemEvent itemEvent) {
        if (itemEvent.getSource() == b1) {
            if (itemEvent.getStateChange() == 1) {
                System.out.println("green");
                ob.choice = 1;
                ob.repaint();
            }
        }
        if (itemEvent.getSource() == b2) {
            if (itemEvent.getStateChange() == 1) {
                System.out.println("red");
                ob.choice = 2;
                ob.repaint();
            }
        }
        if (itemEvent.getSource() == b3) {
            if (itemEvent.getStateChange() == 1) {
                System.out.println("yellow");
                ob.choice = 3;
                ob.repaint();
            }
        }
    }

    public void actionPerformed(ActionEvent aEvent) {
        if (aEvent.getSource() == clr) {
            ob.choice = 4;
            System.out.println("Clear");
            ob.repaint();
        }
    }

    public void mousePressed(MouseEvent mouseEvent) {
        System.out.println("mouse pressed");
        int x;
        int y;
        x = mouseEvent.getX();
        y = mouseEvent.getY();
        System.out.println(x);
        System.out.println(y);
        ob.x1 = x;
        ob.y1 = y;
        repaint();

    }

    public void mouseReleased(MouseEvent mouseEvent) {

    }

    public void mouseEntered(MouseEvent mouseEvent) {

    }

    public void mouseExited(MouseEvent mouseEvent) {

    }

    public void mouseClicked(MouseEvent mouseEvent) {

    }
}

public class SimpleGUI {

    public static void main(String[] args) {
        GUICalc obj = new GUICalc();
        obj.setBounds(300, 100, 800, 600);
        obj.setVisible(true);
    }
}