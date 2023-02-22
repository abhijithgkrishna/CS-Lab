import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class register implements ActionListener
{
    String name,gender,course;
    JLabel l1,l2,l3;
    JTextField name_field;
    JRadioButton male,female;
    JComboBox combo;

    register(JTextField name_field,JRadioButton male,JRadioButton female,JComboBox combo,JLabel l1,JLabel l2,JLabel l3)
    {
        this.name_field = name_field;
        this.male=male;
        this.female=female;
        this.combo=combo;
        this.l1=l1;
        this.l2=l2;
        this.l3=l3; 
    }

    public void actionPerformed(ActionEvent e)
    {
        l1.setText("Name:"+name_field.getText());;
        if(male.isSelected())
            gender="Male";
        else if(female.isSelected())
            gender="Female";
        else
            gender="Other";
        course=""+combo.getItemAt(combo.getSelectedIndex());
        l2.setText("Gender:"+gender);
        l3.setText("Course:"+course);

    }

}

public class demo {
    public static void main(String[] args)
    {
        JFrame frame = new JFrame("Registration");
        frame.setSize(400,500);
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        String[] program= {"Btech","BArch","BS","BE"};

        JLabel name=new JLabel("Name:");
        name.setSize(30,10);
        JLabel gn=new JLabel("Gender");
        gn.setSize(30,10);
        JLabel course = new JLabel("Course");
        course.setSize(30,10);
        JLabel l1 = new JLabel();
        l1.setSize(30,10);
        JLabel l2 = new JLabel();
        l2.setSize(30,10);
        JLabel l3=new JLabel();
        l3.setSize(30,10);

        JTextField name_field = new JTextField(20);
        JRadioButton male = new JRadioButton("Male");
        JRadioButton female = new JRadioButton("Female");
        ButtonGroup group = new ButtonGroup();
        JButton s = new JButton("Submit");
        JComboBox combo = new JComboBox<String>(program);
        s.addActionListener(new register(name_field,male,female,combo,l1,l2,l3));

        group.add(male);
        group.add(female);

        frame.add(name);
        frame.add(name_field);
        frame.add(gn);
        frame.add(male);
        frame.add(female);
        frame.add(course);
        frame.add(combo);
        frame.add(s);
        frame.add(l1);
        frame.add(l2);
        frame.add(l3);
    }
}
