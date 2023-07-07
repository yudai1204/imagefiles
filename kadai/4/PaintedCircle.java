class PaintedCircle implements Circle, Painted{
    double r = 1.0;
    public void setR(double i){
        r = i;
    }
    public double getArea(){
        return Math.pow(r, 2) * Math.PI;
    }
    public boolean isFilled(){
        return true;
    }
    public static void main(String[] args){
        PaintedCircle pc = new PaintedCircle();
        pc.setR(10.0);
        System.out.println(pc.getArea());
    }
}
