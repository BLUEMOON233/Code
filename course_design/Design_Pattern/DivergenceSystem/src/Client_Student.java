import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.*;
import javax.swing.*;
/*
 * Created by JFormDesigner on Fri Apr 19 22:44:35 CST 2024
 */


/**
 * @author liuwy
 */
public class Client_Student extends JFrame {
    private Client client;
    private int number;
    private UndivertedStudent us;

    public Client_Student(int number) throws IOException {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.number = number;
        client = new Client();
        initComponents();
        initInfo();
    }

    private void initInfo() {
        us = client.getUndivertedStudent(number);
        LB_name.setText(us.name);
        LB_gender.setText(us.gender);
        LB_number.setText(String.valueOf(number));
        LB_isFill.setText(us.isFill ? "是" : "否");
        comboBox1.removeAllItems();
        comboBox2.removeAllItems();
        comboBox3.removeAllItems();
        comboBox1.addItem("NULL");
        comboBox2.addItem("NULL");
        comboBox3.addItem("NULL");
        String[] majorList = client.getMajorList();
        for (String major : majorList) {
            comboBox1.addItem(major);
            comboBox2.addItem(major);
            comboBox3.addItem(major);
        }
        comboBox1.setSelectedItem("NULL");
        for (String major : majorList)
            if (major.equals(us.major_1)) {
                comboBox1.setSelectedItem(major);
                break;
            }
        comboBox2.setSelectedItem("NULL");
        for (String major : majorList)
            if (major.equals(us.major_2)) {
                comboBox2.setSelectedItem(major);
                break;
            }
        comboBox3.setSelectedItem("NULL");
        for (String major : majorList)
            if (major.equals(us.major_3)) {
                comboBox3.setSelectedItem(major);
                break;
            }

    }

    private void button1(ActionEvent e) {
        us.major_1 = comboBox1.getSelectedItem().toString();
        us.major_2 = comboBox2.getSelectedItem().toString();
        us.major_3 = comboBox3.getSelectedItem().toString();
        us.isFill = !us.major_1.equals("NULL") || !us.major_2.equals("NULL") || !us.major_3.equals("NULL");
        client.modifyUndivertedStudent(us);
        initInfo();
    }


    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        ResourceBundle bundle = ResourceBundle.getBundle("Client_Student");
        label1 = new JLabel();
        label2 = new JLabel();
        label3 = new JLabel();
        label4 = new JLabel();
        label5 = new JLabel();
        label6 = new JLabel();
        label7 = new JLabel();
        button1 = new JButton();
        comboBox1 = new JComboBox();
        comboBox2 = new JComboBox();
        comboBox3 = new JComboBox();
        label8 = new JLabel();
        LB_name = new JLabel();
        LB_number = new JLabel();
        LB_gender = new JLabel();
        LB_isFill = new JLabel();

        //======== this ========
        var contentPane = getContentPane();
        contentPane.setLayout(null);

        //---- label1 ----
        label1.setText(bundle.getString("label1.text_3"));
        contentPane.add(label1);
        label1.setBounds(135, 85, 105, 45);

        //---- label2 ----
        label2.setText(bundle.getString("label2.text_3"));
        contentPane.add(label2);
        label2.setBounds(135, 130, 105, 45);

        //---- label3 ----
        label3.setText(bundle.getString("label3.text_3"));
        contentPane.add(label3);
        label3.setBounds(135, 175, 105, 45);

        //---- label4 ----
        label4.setText(bundle.getString("label4.text"));
        contentPane.add(label4);
        label4.setBounds(135, 220, 105, 45);

        //---- label5 ----
        label5.setText(bundle.getString("label5.text"));
        contentPane.add(label5);
        label5.setBounds(135, 270, 105, 45);

        //---- label6 ----
        label6.setText(bundle.getString("label6.text"));
        contentPane.add(label6);
        label6.setBounds(135, 320, 105, 45);

        //---- label7 ----
        label7.setText(bundle.getString("label7.text"));
        contentPane.add(label7);
        label7.setBounds(135, 370, 105, 45);

        //---- button1 ----
        button1.setText(bundle.getString("button1.text_2"));
        button1.addActionListener(e -> button1(e));
        contentPane.add(button1);
        button1.setBounds(340, 505, 145, 60);
        contentPane.add(comboBox1);
        comboBox1.setBounds(225, 275, 240, comboBox1.getPreferredSize().height);
        contentPane.add(comboBox2);
        comboBox2.setBounds(225, 325, 240, 38);
        contentPane.add(comboBox3);
        comboBox3.setBounds(225, 375, 240, 38);

        //---- label8 ----
        label8.setText(bundle.getString("label8.text"));
        contentPane.add(label8);
        label8.setBounds(295, 30, 245, 30);

        //---- LB_name ----
        LB_name.setText(bundle.getString("LB_name.text"));
        contentPane.add(LB_name);
        LB_name.setBounds(285, 90, 190, 40);

        //---- LB_number ----
        LB_number.setText(bundle.getString("LB_number.text"));
        contentPane.add(LB_number);
        LB_number.setBounds(285, 130, 190, 40);

        //---- LB_gender ----
        LB_gender.setText(bundle.getString("LB_gender.text"));
        contentPane.add(LB_gender);
        LB_gender.setBounds(280, 175, 190, 40);

        //---- LB_isFill ----
        LB_isFill.setText(bundle.getString("LB_isFill.text"));
        contentPane.add(LB_isFill);
        LB_isFill.setBounds(275, 220, 190, 40);

        {
            // compute preferred size
            Dimension preferredSize = new Dimension();
            for(int i = 0; i < contentPane.getComponentCount(); i++) {
                Rectangle bounds = contentPane.getComponent(i).getBounds();
                preferredSize.width = Math.max(bounds.x + bounds.width, preferredSize.width);
                preferredSize.height = Math.max(bounds.y + bounds.height, preferredSize.height);
            }
            Insets insets = contentPane.getInsets();
            preferredSize.width += insets.right;
            preferredSize.height += insets.bottom;
            contentPane.setMinimumSize(preferredSize);
            contentPane.setPreferredSize(preferredSize);
        }
        setSize(826, 657);
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JLabel label1;
    private JLabel label2;
    private JLabel label3;
    private JLabel label4;
    private JLabel label5;
    private JLabel label6;
    private JLabel label7;
    private JButton button1;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private JComboBox comboBox3;
    private JLabel label8;
    private JLabel LB_name;
    private JLabel LB_number;
    private JLabel LB_gender;
    private JLabel LB_isFill;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on
}