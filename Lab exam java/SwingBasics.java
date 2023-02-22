import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Frame extends JFrame implements ActionListener {

    String value;

    JTextField val = new JTextField();
    JLabel label = new JLabel();
    JButton button = new JButton("Click");

    Frame(String title) {
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(300, 300, 800, 600);
        setTitle(title);

        val.setBounds(30, 30, 200, 30);
        label.setBounds(250, 30, 200, 30);
        button.setBounds(230, 80, 100, 50);

        val.addActionListener(this);
        button.addActionListener(this);

        add(label);
        add(button);
        add(val);
    }

    public void actionPerformed(ActionEvent actionEvent) {
        if (actionEvent.getSource() == button) {
            value = val.getText();
            label.setText(value);
        }
    }
}

public class SwingBasics {
    public static void main(String[] args) {
        Frame fr = new Frame("Swing");
        fr.setVisible(true);
    }
}