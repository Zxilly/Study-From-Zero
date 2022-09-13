class Program 

{

    static void Main(string[] args) 

    {
        MyClass obj=new MyClass( );

    }

}

public class B

{

    protected B()

    {

        Console.Write("B");

    }

}

public class MyClass:B

{

    public MyClass ( )

    {

        Console.Write("A");

    }

}