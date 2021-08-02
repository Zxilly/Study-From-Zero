package top.learningman.experiment.a8;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class jdbc {
    public static void main(String[] args) {
        try {
            Class.forName("org.sqlite.JDBC");
            Connection con = DriverManager.getConnection("jdbc:sqlite://D://student.db");
            PreparedStatement stmt = con.prepareStatement("insert into emp values(?,?)");
            stmt.setInt(1, 101);// 1 specifies the first parameter in the query
            stmt.setString(2, "Ratan");
            int i = stmt.executeUpdate();
            System.out.println(i + " records inserted");
            // 3.执行 sql statement
            Statement stmt1 = con.createStatement();
            ResultSet rs = stmt1.executeQuery("select * from emp;");
            while (rs.next()) {
                String id = rs.getString(1);
                String name = rs.getString(2);
                System.out.print(id + "\t");
                System.out.print(name + "\t");
                System.out.println();
            }
            con.close();
            stmt.close();
            stmt1.close();
            rs.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
