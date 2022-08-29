using System;
using System.Windows.Forms;
using System.Drawing;

namespace UI;

public class MyForm : Form //窗体
{
    private TextBox box; //文本框
    private Button button; //按钮

    public MyForm()
    {
        box = new TextBox(); //新建文本框
        box.BackColor = Color.Cyan; //设置背景色为青绿色
        box.Size = new Size(100, 100); //设置文本框大小
        box.Location = new Point(50, 50); //设置文本框位置
        box.Text = "Hello"; //设置文本框文本内容
        button = new Button(); //新建按钮
        button.Location = new Point(50, 100); //设置按钮位置
        button.Text = "Click Me"; //设置按钮文本内容
        //通过+=向多播事件委托实例封装的调用列表中添加事件处理方法
        button.Click += Button_Click; //按钮单击事件
        Controls.Add(box);
        Controls.Add(button);
    }

    private void Button_Click(object sender, EventArgs e) // 声明按钮单击事件处理方法
    {
        box.BackColor = Color.Green; // 文本框背景色改为绿色
    }

    [STAThread]
    public static void Main(string[] args)
    {
        Application.Run(new MyForm());
    }
}