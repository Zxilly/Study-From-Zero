package top.learningman.homework;

public class cubeEndEqual {
    public static void main(String[] args){
        int count=0;
        for(long i=1;i<=10000;i++){
            String tmp = i+"";
            if(i==(i*i*i)%((int)Math.pow(10,tmp.length()))){
                count++;
                System.out.print(i+" ");
            }
        }
        System.out.print("\n");
        System.out.println(count);
    }
}
