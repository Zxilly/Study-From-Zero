namespace Test.Homework2;

public class H2P2
{
    public static void TestMain()
    {
        Console.Write("输入被除数：");
        string str1 = Console.ReadLine() ?? "";
        Console.Write("请输入除数：");
        string str2 = Console.ReadLine() ?? "";
        try
        {
            int num1 = int.Parse(str1);
            int num2 = int.Parse(str2);
            Console.WriteLine("{0}/{1}={2}", num1, num2, num1 / num2);
            
        }
        catch (FormatException)
        {
            Console.WriteLine("输入格式不正确！");
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("除数不能为0！");
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }
    }
}