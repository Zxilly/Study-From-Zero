package top.learningman.study.study.object;


public class O_lambda {
    public static void main(String[] args){
        String name = "a";
        anshout(new Animal() {
            @Override
            public void shout() {
                System.out.println(name);
            }

            @Override
            public void shout2() {
                
            }
        });
    }

    public static void anshout(Animal a){
        a.shout();
    }
}
