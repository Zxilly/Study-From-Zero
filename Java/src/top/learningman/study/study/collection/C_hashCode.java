package top.learningman.study.study.collection;

public class C_hashCode {
    int anInt;
    boolean aBoolean;
    float aFloat;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        C_hashCode that = (C_hashCode) o;
        return anInt == that.anInt && aBoolean == that.aBoolean && Float.compare(that.aFloat, aFloat) == 0;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
