package top.learningman.study.experiment.a4;

public class fibonacci {
    static class node {
        int value;
        int prev_value;

        public node(int value, int prev_value) {
            this.value = value;
            this.prev_value = prev_value;
        }
    }

    public static void main(String[] args) {
        node[] node_list = new node[200];
        for (int i = 0; i <= 10; i++) {
            if (i == 0) {
                node_list[i] = new node(1, 0);
            } else {
                node_list[i] = new node(node_list[i - 1].value + node_list[i - 1].prev_value, node_list[i - 1].value);
            }
        }
        for (node singlenode :
                node_list) {
            if(singlenode!=null){
                System.out.println(singlenode.value);
            } else {
                break;
            }
        }
    }
}
