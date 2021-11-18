import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySqlConnection {
    Connection  connection = null;

    public void connectToDatabase(String dbUrl, String user, String password) throws SQLException {
        try{
            connection = DriverManager.getConnection(dbUrl, user, password);
        } catch (SQLException e) {
            e.printStackTrace();
            throw new SQLException("Connection failed",e);
        }
    }

    public void closeConnection() throws SQLException {
        connection.close();
        System.out.println("Connection closed");
    }
}
