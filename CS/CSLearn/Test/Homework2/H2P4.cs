using System.Text.RegularExpressions;

namespace Test.Homework2;

public class H2P4
{
    public static void TestMain()
    {
        string s = Console.ReadLine() ?? "";
        
        var prefixSpaceRegex = new Regex(@"^\s+");
        var suffixSpaceRegex = new Regex(@"\s+$");
        var multipleSpaceRegex = new Regex(@"\s{2,}");
        
        s = prefixSpaceRegex.Replace(s, "");
        s = suffixSpaceRegex.Replace(s, "");
        s = multipleSpaceRegex.Replace(s, " ");
        
        Console.WriteLine(s);
    }
}