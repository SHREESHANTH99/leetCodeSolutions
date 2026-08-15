class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9) return k;
        k-=9;
        long long d=2;
        long long p=10;
        while(true){
            long long blocks=9*(p/10);;
            long long digitsPrBlock=10*d;
            long long count =0;
            if(LLONG_MAX/digitsPrBlock<blocks){
                count=LLONG_MAX;
            }else{
                count=blocks*digitsPrBlock;
            }
            if(k>count){
                k-=count;d++;
                p*=10;
            }else{
                break;
            }
        }
        k--;
        long long b_str=p/10;
        long long b_off=k/(10*d);
        long long b=b_str+b_off;
        long long rem=k%(10*d);
        long long num_id=rem/d;
        long  long dg_id=rem%d;
        long long num=0;
        if(b%2==0){
            num=10*b+num_id;
        }else{
            num=10*b+9-num_id;
        }
        string s=to_string(num);
        return s[dg_id]-'0';
    }
};
