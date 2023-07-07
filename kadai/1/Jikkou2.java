class Jikkou2{
    public static void main(String[] args){
        Saifu mySaifu = new Saifu();
        int kodukai = 10;
        for(int i=1; i<=25; i++){
            mySaifu.setOkane(kodukai + mySaifu.getOkane());
            kodukai *= 2;
            System.out.println("day="+i+" okane="+mySaifu.getOkane());
        }
    }
}