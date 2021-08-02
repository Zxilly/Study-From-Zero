package top.learningman.experiment.a2;

public class b2 {
    static int[][] map = new int[11][11];

    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (i == 1 || i==j) {
                    map[i][j] = 1;
                } else {
                    if(j>i){
                        map[i][j]= map[i][j-1]+map[i-1][j-1];
                    }
                }
            }
        }
        for (int j=1;j<=10;j++){
            for (int i=1;i<=10;i++){
                System.out.print(map[i][j]+"\t");
            }
            System.out.print("\n");
        }
    }

}
