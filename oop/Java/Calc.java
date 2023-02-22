import java.awt.event.*;
import javax.swing.*;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.*;

/**
 * Calc
 */
public class Calc extends JFrame implements ActionListener {

    public static void main(String[] args) {
        JFrame f = new JFrame("Calculator");
        f.setLayout(new GridLayout());
        Calc c = new Calc();
        JTextField l = new JTextField(16);
        l.setEditable(false);
        JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, ba, bd, bdi, bm, bp, beq, bclr;
        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        ba = new JButton("+");
        bd = new JButton("-");
        bm = new JButton("*");
        bdi = new JButton("/");
        beq = new JButton("=");
        bp = new JButton(".");
        bclr = new JButton("C");

        JPanel p = new JPanel();
        b0.addActionListener(c);
        b1.addActionListener(c);
        b2.addActionListener(c);
        b3.addActionListener(c);
        b4.addActionListener(c);
        b5.addActionListener(c);
        b6.addActionListener(c);
        b7.addActionListener(c);
        b8.addActionListener(c);
        b9.addActionListener(c);
        ba.addActionListener(c);
        bd.addActionListener(c);
        bm.addActionListener(c);
        bdi.addActionListener(c);
        beq.addActionListener(c);
        bclr.addActionListener(c);
        bp.addActionListener(c);

        p.add(l);
        p.add(b1);
        p.add(b2);
        p.add(b3);
        p.add(ba);
        p.add(b4);
        p.add(b5);
        p.add(b6);
        p.add(bd);
        p.add(b7);
        p.add(b8);
        p.add(b9);
        p.add(bm);

        p.add(b0);
        p.add(beq);
        p.add(bp);
        p.add(bclr);
        p.setBackground(Color.white);
        f.add(p);
        f.setSize(200, 250);
        f.show();
    }

    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();

    }

}