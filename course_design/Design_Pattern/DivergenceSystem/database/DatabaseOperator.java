import java.sql.*;
import java.util.ArrayList;

public class DatabaseOperator {
    private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_URL = "jdbc:mysql://42.193.107.194:3306/divergencesystem?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC";
    private static final String USER = "DivergenceSystem";
    private static final String PASS = "admin";

    private Connection conn = null;
    private Statement stmt = null;
    public ResultSet rs = null;

    DatabaseOperator() {
        try {
            Class.forName(JDBC_DRIVER);
            conn = DriverManager.getConnection(DB_URL, USER, PASS);
            stmt = conn.createStatement();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        try {
            if (conn != null) conn.close();
            if (stmt != null) stmt.close();
            if (rs != null) rs.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public boolean addUndivertedStudent(UndivertedStudent us) {
        try {
            String sql = "select number from stu_info_with_fill where number = " + String.valueOf(us.number) + ";";
            rs = stmt.executeQuery(sql);
            if (rs.getFetchSize() > 0) return false;
            rs = null;
            if (us.isFill) {
                sql = "insert into stu_info_with_fill (number, name, gender, is_fill, major_1, major_2, major_3) " + "values (" + String.format("%d, '%s', '%s', %b, '%s', '%s', '%s'", us.number, us.name, us.gender, us.isFill, us.major_1, us.major_2, us.major_3) + ");";
            }else {
                sql = "insert into stu_info_with_fill (number, name, gender, is_fill) " + "values (" + String.format("%d, '%s', '%s', %b", us.number, us.name, us.gender, us.isFill) + ");";
            }
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return true;
    }

    public void delUndivertedStudent(int number) {
        try {
            String sql = "delete from stu_info_with_fill where number = " + String.valueOf(number) + ";";
            stmt.executeUpdate(sql);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public void addUSList(ArrayList<UndivertedStudent> usList) {
        try{
            for(UndivertedStudent us : usList) {
                String sql = "select number from stu_info_with_fill where number = " + String.valueOf(us.number) + ";";
                rs = stmt.executeQuery(sql);
                if (rs.getFetchSize() > 0) continue;
                rs = null;
                if (us.isFill) {
                    sql = "insert into stu_info_with_fill (number, name, gender, is_fill, major_1, major_2, major_3) " + "values (" + String.format("%d, '%s', '%s', %b, '%s', '%s', '%s'", us.number, us.name, us.gender, us.isFill, us.major_1, us.major_2, us.major_3) + ");";
                }else {
                    sql = "insert into stu_info_with_fill (number, name, gender, is_fill) " + "values (" + String.format("%d, '%s', '%s', %b", us.number, us.name, us.gender, us.isFill) + ");";
                }
                stmt.executeUpdate(sql);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public static void main(String[] args) {
    }
}
