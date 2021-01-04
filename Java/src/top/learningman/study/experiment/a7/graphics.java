package top.learningman.study.experiment.a7;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class graphics extends JFrame {

    JButton btn;
    JTextField text;

    //初始化窗口
    public void init() {
        this.setTitle("Test");
        this.setSize(300, 300);
        this.setLocationRelativeTo(null);
        this.setResizable(true);

    }


    //构造方法
    public graphics() {
        init();
        text = new JTextField("str", 20);

        btn = new JButton("提交");
        btn.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent event) {

                //点击弹框显示
                JOptionPane.showMessageDialog(null, "提交失败");
                System.out.println("hhhh");
            }
        });


        this.getContentPane().setLayout(new FlowLayout());
        this.getContentPane().add(text);
        this.getContentPane().add(btn);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        new graphics();
    }
}
