import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Q2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Mouse Event Example");
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel label = new JLabel("No Mouse Events Detected");
        frame.add(label);
        frame.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                label.setText("Mouse Pressed at (" + e.getX() + ", " + e.getY() + ")");
            }

            public void mouseReleased(MouseEvent e) {
                label.setText("Mouse Released at (" + e.getX() + ", " + e.getY() + ")");
            }

            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse Entered at (" + e.getX() + ", " + e.getY() + ")");
            }

            public void mouseExited(MouseEvent e) {
                label.setText("Mouse Exited at (" + e.getX() + ", " + e.getY() + ")");
            }
        });
        frame.setVisible(true);
    }
}
