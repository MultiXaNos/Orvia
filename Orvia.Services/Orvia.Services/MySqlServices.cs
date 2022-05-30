using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace Orvia.Services
{
    public sealed class MySqlServices
    {
        #region Fields

        private static MySqlServices _instance;
        private MySqlConnection _connection;

        #endregion Fields

        #region Properties

        public static MySqlServices Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new MySqlServices();
                }

                return _instance;
            }
        }

        #endregion Properties

        #region Constructor

        private MySqlServices()
        {
            _connection = new MySqlConnection($"Server={Constants.DataBase.HostName};Database={Constants.DataBase.DataBaseName};Uid={Constants.DataBase.UID};Pwd={Constants.DataBase.Password};");
            _connection.Open();
        }

        #endregion Constructor

        #region Public Methods

        public void OpenCommunication()
        {
            if (Instance._connection.State != System.Data.ConnectionState.Open && Instance._connection.State != System.Data.ConnectionState.Connecting)
            {
                Instance._connection.Open();
            }
        }

        public void CloseCommunication()
        {
            if (Instance._connection.State != System.Data.ConnectionState.Closed)
            {
                Instance._connection.Close();
            }
        }

        public MySqlDataReader SendReadRequest(string request)
        {
            MySqlCommand command = new MySqlCommand(request, _connection);
            var result = command.ExecuteReader();
            while (result.Read());
            return result;
        }

        public void SendWriteRequest(string request)
        {
            MySqlCommand command = new MySqlCommand(request);
            while (command.ExecuteReader().Read()) ;
        }

        #endregion Public Methods
    }
}
