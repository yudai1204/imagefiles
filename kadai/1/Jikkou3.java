class Jikkou3{
    public static void main(String[] args){
        int max = 25;
        if(args.length != 0){
            max = Integer.parseInt(args[0]);
        }
        Saifu2 mySaifu = new Saifu2();
        long kodukai = 10;
        for(int i=1; i<=max; i++){
            mySaifu.setOkane(kodukai + mySaifu.getOkane());
            kodukai *= 2;
            System.out.println("day="+i+" okane="+mySaifu.getOkane());
        }
    }
}