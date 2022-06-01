namespace Orvia.Services;

public static class Constants
{
    public static class DLL
    {
        public const string DllPath =
            @"ThreadDLL\x64\Debug\ThreadDLL.dll";

        public const string CreateThreadEntryPoint = "?CreateThread@@YAPEAVThreadNid@@PEAD0HHHH00NNNNH0@Z";
        public const string KillThreadEntryPoint = "?KillThread@@YAXPEAVThreadNid@@@Z";
        public const string WakeUpThreadEntryPoint = "?WakeUpThread@@YAHPEAVThreadNid@@@Z";
        public const string GetErrorEntryPoint = "?getError@@YAPEBDPEAVThreadNid@@@Z";
        public const string GetNbOeufEntryPoint = "?getNbOeuf@@YAHPEAVThreadNid@@@Z";
        public const string GetPontesEntryPoint = "?getPontes@@YAHPEAVThreadNid@@PEAPEAPEAD@Z";
        public const string GetStatutEntryPoint = "?getStatut@@YAHPEAVThreadNid@@@Z";
    }

    public static class DataBase
    {
        public const string HostName = "sql698.main-hosting.eu";
        public const string DataBaseName = "u482894532_projet_orvia";
        public const string UID = "u482894532_orvia_admin";
        public const string Password = "OrviaBDD37";
    }

    public static class XmlFile
    {
        public const string NidsFilePath = "Resources/Nids.xml";
    }

}