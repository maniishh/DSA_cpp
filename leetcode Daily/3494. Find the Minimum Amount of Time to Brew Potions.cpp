long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vector<long long>v(n,0);
        for(int potion=0;potion<m;potion++){
            for(int wiz=0;wiz<n;wiz++){
                if(wiz==0)
                    v[wiz]=v[wiz]+1LL*mana[potion]*skill[wiz];
            else
            v[wiz]=max(v[wiz],v[wiz-1])+1LL* mana[potion]*skill[wiz];
            }
            for(int i=n-2;i>=0;i--){
                v[i]=v[i+1]-1LL*mana[potion]*skill[i+1];
            }
        }
return v[n-1];
    }