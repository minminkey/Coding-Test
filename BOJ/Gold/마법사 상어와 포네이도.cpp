#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
int A[501][501];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void Print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
}
bool ck(int r, int c){
    if(r>=0&&c>=0&&r<N&&c<N)    return true;
    else return false;
}
void spread(int d, int r, int c){
    int sand = A[r][c];
    int rest = 0;
    A[r][c] = 0;
    int nr = r + dr[d];             //a   55
    int nc = c + dc[d];
    int nnr = r + 2*dr[d];             //5
    int nnc = c + 2*dc[d];
    int nlr = nr + dr[(d+3)%4];         //l10
    int nlc = nc + dc[(d+3)%4];
    int nrr = nr + dr[(d+1)%4];         //r10
    int nrc = nc + dc[(d+1)%4];
    int lr = r + dr[(d+3)%4];           //l7
    int lc = c + dc[(d+3)%4];
    int llr = r + 2*dr[(d+3)%4];        //l2
    int llc = c + 2*dc[(d+3)%4];
    int rr = r + dr[(d+1)%4];           //r7
    int rc = c + dc[(d+1)%4];
    int rrr = r + 2*dr[(d+1)%4];        //r2
    int rrc = c + 2*dc[(d+1)%4];
    int brr = rr + dr[(d+2)%4];         //r1
    int brc = rc + dc[(d+2)%4];
    int blr = lr + dr[(d+2)%4];         //l1
    int blc = lc + dc[(d+2)%4];
    if(ck(nr, nc)){
        rest = (sand*5/100)+2*(sand*10/100)+2*(sand*7/100)+2*(sand*2/100)+2*(sand*1/100);
        // cout<<"rest : "<<rest<<sand*5/100<<sand*10/100<<sand*10/100<<sand*7/100<<sand*2/100<<sand*1/100<<endl;
        A[nr][nc] += sand-rest;
    }
    if(ck(nnr, nnc))    A[nnr][nnc] += sand*0.05;
    if(ck(nlr, nlc))    A[nlr][nlc] += sand*0.1;
    if(ck(nrr, nrc))    A[nrr][nrc] += sand*0.1;
    if(ck(lr, lc))      A[lr][lc]   += sand*0.07;
    if(ck(llr, llc))    A[llr][llc] += sand*0.02;
    if(ck(rr, rc))      A[rr][rc]   += sand*0.07;
    if(ck(rrr, rrc))     A[rrr][rrc] += sand*0.02;
    if(ck(brr, brc))    A[brr][brc] += sand*0.01;
    if(ck(blr, blc))    A[blr][blc] += sand*0.01;

}
void move(int r, int c){
    // cout<<r<<"   "<<c<<endl;
    int n = 1;
    int d = 3;
    int nr = r;
    int nc = c;
    while(1){
        for(int i=0; i<n; i++){
            nr += dr[d];
            nc += dc[d];
            // cout<<nr<<' '<<nc<<endl;
            spread(d, nr, nc);
            // Print();
            if(nr==0&&nc==0)    return;
        }
        d = (d+3)%4;
        
        for(int i=0; i<n; i++){
            nr += dr[d];
            nc += dc[d];
            // cout<<nr<<' '<<nc<<endl;
            spread(d, nr, nc);
            // Print();
            if(nr==0&&nc==0)    return;
        }
        d = (d+3)%4;
        n++;
    }
}

int main(){
    cin>>N;
    long long sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>A[i][j];
            sum += A[i][j];
        }
    }
    move(N/2,N/2);
    long long tmp = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp += A[i][j];
        }
    }
    
    cout<<sum-tmp<<'\n';
}
