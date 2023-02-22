import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Q1 extends JPanel {
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.WHITE);

        g.setColor(Color.BLUE);
        g.drawLine(10, 10, 10, 100);

        g.setColor(Color.BLUE);
        g.drawRect(100, 100, 50, 75);

        g.setColor(Color.BLUE);
        g.drawOval(200, 200, 50, 75);
    }

    public static void main(String[] args) {

        JFrame frame = new JFrame();
        frame.setSize(500, 500);
        frame.setTitle("Drawing Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Q1 panel = new Q1();
        frame.add(panel);

        frame.setVisible(true);
    }
}
