package top.learningman.experiment.a5;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class jdbc {
    public static void main(String[] args) {
        jdbc test = new jdbc();
    }

    public jdbc() {
        this.prac();
    }

    public void prac() {

        PreparedStatement ps = null;
        Connection ct = null;
        ResultSet rs = null;
        try {
            Class.forName("com.microsoft.jdbc.sqlserver.SQLServerDriver");
            ct = DriverManager.getConnection("jdbc:microsoft:sqlserver://localhost:1433;databaseName=shen", "sa", "Anxin062039");
            ps = ct.prepareStatement("create database vvv");
            ps = ct.prepareStatement("create table xxx");
            ps = ct.prepareStatement("backup database shen to disk='F:/123.bak'");
            boolean b = ps.execute();
            if (b) {
                System.out.println("创建成功！");
            } else {
                System.out.println("失败");
            }
        } catch (Exception e) {
        } finally {
            try {
                if (ps != null)
                    ps.close();
                if (ct != null)
                    ct.close();
            } catch (Exception e2) {
            }
        }
    }
}