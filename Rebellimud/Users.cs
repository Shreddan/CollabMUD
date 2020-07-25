using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Data.Sqlite;

namespace Rebellimud
{
    class Users
    {
        public static SqliteConnectionStringBuilder connectionStringBuilder;
        public static SqliteConnection conn;
        public static SqliteCommand dropTable;
        public static SqliteCommand delTable;
        public static SqliteCommand createTable;
        public static SqliteCommand checkTable;
        public static SqliteCommand updateTable;
        public static SqliteCommand insertTable;
        public static SqliteCommand selectTable;
        public static SqliteTransaction transaction;
        public static string message = string.Empty;

        public static void Setup()
        {
            connectionStringBuilder = new SqliteConnectionStringBuilder();
            connectionStringBuilder.DataSource = "./User.db";
            OpenDB();
        }

        public static void OpenDB()
        {
            Console.WriteLine("Checking Database.....");
            using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
            {
                conn.Open();
                CheckExist();
            }
        }

        public static void CheckExist()
        {
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    conn.Open();
                    dropTable = conn.CreateCommand();
                    dropTable.CommandText = "DROP TABLE IF EXISTS User";
                    var num = dropTable.ExecuteNonQuery();
                    Console.WriteLine("Entries changed : " + num);
                    if (num < 1)
                    {
                        CreateTable();
                    }
                }
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static void CreateTable()
        {
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    conn.Open();
                    createTable = conn.CreateCommand();
                    createTable.CommandText = "CREATE TABLE User(Username VARCHAR(12), Pass VARCHAR(12), Level int, Class char(12))";
                    createTable.ExecuteNonQuery();
                }
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static bool CheckTable(string name)
        {
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    conn.Open();
                    checkTable = conn.CreateCommand();
                    checkTable.CommandText = "SELECT Username FROM User WHERE EXISTS (SELECT Username FROM User WHERE User.Username = @username)";

                    checkTable.Parameters.AddWithValue("@username", name);
                    checkTable.Prepare();

                    using (var reader = checkTable.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            var message = reader.GetString(0);
                            Console.WriteLine(message);
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
                return false;
            }
            
        }

        public static void DeleteTable()
        {

        }

        public static void InsertTable(string name, string pass, string aclass)
        {
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    conn.Open();
                    using (transaction = conn.BeginTransaction())
                    {
                        insertTable = conn.CreateCommand();

                        insertTable.CommandText = "INSERT INTO User(Username, Pass, Level, Class) VALUES(@name, @pass, 1, @class)";

                        insertTable.Parameters.AddWithValue("@name", name);
                        insertTable.Parameters.AddWithValue("@pass", pass);
                        insertTable.Parameters.AddWithValue("@class", aclass);

                        insertTable.Prepare();

                        var num = insertTable.ExecuteNonQuery();
                        Console.WriteLine("Entries changed : " + num);

                        transaction.Commit();
                    }
                }
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static string ReadTable()
        {
            
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    object[] obj = new object[5];
                    conn.Open();
                    selectTable = conn.CreateCommand();
                    selectTable.CommandText = "SELECT * FROM User";

                    using (var reader = selectTable.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            reader.GetValues(obj);
                        }
                    }
                    string temp = obj.ToString();
                    return temp;
                }

            }
            catch(SqliteException e)
            {
                Console.WriteLine(e);
                return string.Empty;
            }

        }

        public static string ReadTable(string tableName)
        {
            object[] obj = new object[5];
            try
            {
                using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
                {
                    conn.Open();
                    selectTable = conn.CreateCommand();
                    selectTable.CommandText = "SELECT @tablename FROM User";

                    selectTable.Parameters.AddWithValue("@tablename", tableName);

                    using (var reader = selectTable.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            reader.GetValues(obj);
                        }
                        message = obj.ToString();
                        return message;
                    }
                }
            }
            catch(SqliteException e)
            {
                Console.WriteLine(e);
                return string.Empty;
            }
        }

    }
}
