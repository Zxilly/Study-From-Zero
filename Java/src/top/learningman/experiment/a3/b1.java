package top.learningman.experiment.a3;

import java.awt.*;
import javax.swing.JFrame;

public class b1 extends JFrame {
    int x0 = 300;
    int y0 = 300;
    int r = 150;

    public void paint(Graphics g) {
        g.setColor(Color.RED);
        g.setFont(new Font("宋体", Font.BOLD, 30));
        double one = Math.PI / 180;
        for (int i = 0; i < 360; i++) {
            int x = (int) (x0 + r * Math.cos(one * i));
            int y = (int) (y0 - r * Math.sin(one * i));
            g.drawString(".", x, y);
        }
        for (int i = 0; i < 5; i++) {
            int x1 = (int) (x0 + r * Math.cos((90 + i * 72) * one));
            int y1 = (int) (y0 - r * Math.sin((90 + i * 72) * one));
            int x3 = (int) (x0 + r * Math.cos((90 + i * 72 + 144) * one));
            int y3 = (int) (y0 - r * Math.sin((90 + i * 72 + 144) * one));
            g.drawLine(x1, y1, x3, y3);
        }
    }

    public static void main(String[] args) {
        b1 JF = new b1();
        JF.setSize(600, 800);
        JF.setVisible(true);
        JF.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}