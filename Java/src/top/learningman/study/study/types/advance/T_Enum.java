package top.learningman.study.study.types.advance;

public enum T_Enum {
    EE(1),
    EE2(2),
    EE3(3),
    EE4(4),
    EE5(5);

    public int dayValue = 0;

    private T_Enum(int dayValue) {
        this.dayValue = dayValue;
    }
}
