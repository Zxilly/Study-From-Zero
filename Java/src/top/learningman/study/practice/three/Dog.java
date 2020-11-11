package top.learningman.study.practice.three;


class DogBig {
    String name;
    String says;

    public void setName(String name) {
        this.name = name;
    }

    public void setSays(String says) {
        this.says = says;
    }

    public String getName() {
        return name;
    }

    public String getSays() {
        return says;
    }

    public void speak() {
        System.out.println(name);
        System.out.println(says);
    }

    @Override
    public String toString(){
        return name+":"+says;
    }
}

public class Dog {

    public static void main(String[] args){
        DogBig a = new DogBig();
        a.setName("spot");
        a.setSays("Ruff!");

        DogBig b = new DogBig();
        b.setName("scruffy");
        b.setSays("Wurf!");

        a.speak();
        b.speak();

    }
}
