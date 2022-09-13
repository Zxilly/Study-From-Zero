using System.Diagnostics;

namespace Test.Homework3;

public class H3P2
{
    // 设计一个名为Stock的类。这个类包括：
    //
    // 1.一个名为symbol的数字字符串私有字段表示股票代码。
    //
    // 2.一个名为Symbol的公有属性用于对symbol进行访问，其中在set方法中对赋值进行有效性检测，要求股票代码由5位数字字符构成。如果赋值非法则抛出异常。
    //
    // 3.一个名为Name的自动实现的公有属性用于访问股票名称。
    //
    // 4.一个名为price的私有数组用于表示股票最近三天的股票值。
    //
    // 5.为股票值设计公有的索引器用于对股票值进行访问，索引器的下标从1开始。
    //
    // 在测试程序的Main方法中创建一个Stock对象，对以上设计进行测试。
    
    public class Stock
    {
        private string symbol;
        public string Symbol
        {
            get { return symbol; }
            set
            {
                if (value.Length != 5)
                {
                    throw new Exception("股票代码必须由5位数字字符构成");
                }

                foreach (var c in value)
                {
                    if (!char.IsDigit(c))
                    {
                        throw new Exception("股票代码必须由5位数字字符构成");
                    }
                }
            }
        }
        public string Name { get; set; }
        private double[] price = new double[3];
        public double this[int index]
        {
            get
            {
                if (index < 1 || index > 3)
                {
                    throw new Exception("索引超出范围");
                }
                else
                {
                    return price[index - 1];
                }
            }
            set
            {
                if (index < 1 || index > 3)
                {
                    throw new Exception("索引超出范围");
                }
                else
                {
                    price[index - 1] = value;
                }
            }
        }
    }

    public static void TestMain()
    {
        var s = new Stock();
        s.Symbol = "12345";
        s.Name = "Test";
        s[1] = 1;
        s[2] = 2;
        s[3] = 3;
        Console.WriteLine(s.Symbol);
        Console.WriteLine(s.Name);
        Console.WriteLine(s[1]);
        Console.WriteLine(s[2]);
        Console.WriteLine(s[3]);
        try
        {
            s.Symbol = "1234";
        } catch (Exception e)
        {
            Debug.Assert(e.Message == "股票代码必须由5位数字字符构成");
        }
        try
        {
            s.Symbol = "1234a";
        } catch (Exception e)
        {
            Debug.Assert(e.Message == "股票代码必须由5位数字字符构成");
        }

        try
        {
            s[0] = 1;
        }
        catch (Exception e)
        {
            Debug.Assert(e.Message == "索引超出范围");
        }
    }
}