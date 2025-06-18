#include<stdio.h>
int main(){
    int s[120][5];
    int sum = 0;
    scanf("%d", &sum);
    for(int i = 0; i < 120;){
        for(int i1 = 1; i1 <= 5; ++i1)
            for(int i2 = 1; i2 <= 5; ++i2)
                for(int i3 = 1; i3 <= 5; ++i3)
                    for(int i4 = 1; i4 <= 5; ++i4)
                        for(int i5 = 1; i5 <= 5; ++i5){
                            if(i1 != i2 && i1 != i3 && i1 != i4 && i1 != i5 && i2 != i3 && i2 != i4 && i2 != i5 && i3 != i4 && i3 != i5 && i4 != i5){
                                s[i][0] = i1, s[i][1] = i2, s[i][2] = i3, s[i][3] = i4, s[i][4] = i5;
                                i += 1; 
                            }
                        }
    }
    for(int j = 0; j < 120; ++j){
        if(sum == s[j][0] + 4*s[j][1] + 6*s[j][2] + 4*s[j][3] + s[j][4]){
            for(int k = 0; k < 5; ++k){
                printf("%d ", s[j][k]);
            }
            break;
        }
    }
return 0;
}
/*q w e r t
q+w w+e e+r r+t
q+2w+e w+2e+r e+2r+t
q+3w+3e+r + w+3e+3r+t
q+4w+6e+4r+t*/