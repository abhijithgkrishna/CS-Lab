import java.awt.event.*;
import javax.swing.*;

public class Q3 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Key Event Example");
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        panel.setFocusable(true);
        panel.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                System.out.println("Key pressed: " + e.getKeyChar());
            }

            public void keyReleased(KeyEvent e) {
                System.out.println("Key released: " + e.getKeyChar());
            }
        });
        frame.add(panel);
        frame.setVisible(true);
    }
}
