import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;

class getbill implements ActionListener {
    JTextField billno, last, curr;
    JLabel l1, l2;
    int consumption, amt, n1, n2;

    getbill(JTextField billno, JTextField last, JTextField curr, JLabel l1, JLabel l2) {
        this.billno = billno;
        this.last = last;
        this.curr = curr;
        this.l1 = l1;
        this.l2 = l2;
    }

    // @Override
    public void actionPerformed(ActionEvent e) {
        l1.setText("Billno: " + billno.getText());
        n1 = Integer.parseInt(last.getText());
        n2 = Integer.parseInt(curr.getText());
        consumption = n2 - n1;
        if (consumption > 5)
            amt = consumption * 1000;
        else
            amt = consumption * 500;
        l2.setText("Electricity Bill Amount: " + amt);

    }

}

public class Bill {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setLayout(new FlowLayout());
        f.setSize(400, 400);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel no = new JLabel("Bill no");
        JTextField billno = new JTextField(20);
        JLabel meter1 = new JLabel("Last meter reading");
        JTextField last = new JTextField(20);
        JLabel meter2 = new JLabel("Current meter reading");
        JTextField curr = new JTextField(20);
        JButton b = new JButton("GET BILL");
        JLabel l1 = new JLabel();
        JLabel l2 = new JLabel();

        no.setSize(30, 10);
        // billno.setSize(30,10);
        meter1.setSize(30, 10);
        // last.setSize(30,10);
        meter2.setSize(30, 10);
        // curr.setSize(30,10);

        b.addActionListener(new getbill(billno, last, curr, l1, l2));
        f.add(no);
        f.add(billno);
        f.add(meter1);
        f.add(last);
        f.add(meter2);
        f.add(curr);
        f.add(b);
        f.add(l1);
        f.add(l2);

    }
}