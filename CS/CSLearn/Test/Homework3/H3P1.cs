namespace Test.Homework3;
class Student
{
    public string Name { set; get; }
    public string gender;
    private int age;
    private int[] score = new int[4];
    public int Age
    {
        get { return age; }
        set
        {
            if (value > 0 && value < 100)
                age = value;
            else
                age = 18;
        }
    }
    public int this[string index]
    {
        get
        {
            if (index.CompareTo("数学") == 0)
                return score[0];
            else if (index.CompareTo("语文") == 0)
                return score[1];
            else if (index.CompareTo("英语") == 0)
                return score[2];
            else
                return score[3];
        }
        set
        {
            if (index.CompareTo("数学") == 0)
                score[0] = value;
            else if (index.CompareTo("语文") == 0)
                score[1] = value;
            else if (index.CompareTo("英语") == 0)
                score[2] = value;
            else
                score[3] = value;
        }
    }
}

public class H3P1
{
    public static void TestMain()
    {
        Student s1 = new Student();
        s1.Name = "王皓";
        s1.Age = 21;
        s1.gender = "男";
        s1["数学"] = 78;
        s1["语文"] = 85;
        s1["英语"] = 66;
        s1["计算机"] = 93;
        Console.WriteLine("姓名：{0}，性别：{1}，年龄：{2}", s1.Name, s1.gender, s1.Age);
        Console.Write("成绩是：");
        Console.WriteLine("{0},{1},{2},{3}", s1["数学"], s1["语文"], s1["英语"], s1["计算机"]);
        Console.ReadLine();
    }
}