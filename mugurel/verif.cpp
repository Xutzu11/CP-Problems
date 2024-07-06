#include <bits/stdc++.h>
using namespace std;

ifstream fok;
ifstream fout;
ifstream fin;

int boxes[2000005];
int minst[2000005], maxst[2000005], mindr[2000005], maxdr[2000005];
char tipuri[2000005];
int fruits[1005][1005][3];
int n,m,k,a,b,c;
long long suma0, suma1;
int disc0, disc1;
int nboxes;
int ind,kgport,kgban,kgmixt;
int maxkgport,maxkgban,maxkgmixt;

void Msg(int pct, string msg)
{
	/// pct = un numar intre 0 si 100 reprezentand scorul pe test (valorile negative au inteles special)
    cout << pct << ' ' << msg;
    try
    {
        fok.close();
        fout.close();
    }
    catch (string ex) {}
    exit(0);
}

int main(int argc, char* argv[])
{

	if ( argc != 4 )
        Msg(-2, "Eroare la evaluare: Lansare incorecta verif");

	fin.open(argv[1]); // deschid fisierul in
	fout.open (argv[2]); // deschid fisierul out
	fok.open (argv[3]); // deschid fisierul ok

	if ( !fin )
		Msg(-2, "Eroare la evaluare: Nu exista fisierul " + string(argv[1]) );

    if ( !fok )
		Msg(-2, "Eroare la evaluare: Nu exista fisierul " + string(argv[3]) );

	if ( !fout )
        Msg(0, "Nu exista fisierul " + string(argv[2]));
    
  fin >> n >> m;
    fin >> k >> a >> b >> c;

    /// cod
    fok >> suma0;
    fout >> suma1 >> nboxes;

    if(!(0 <= nboxes && nboxes <= 2 * k)) {
      Msg(0, "Raspuns gresit");
    }

    for (int i=1;i<=nboxes;i++) {
        fout >> boxes[i] >> tipuri[i];
    }
    fout >> disc1;
    minst[0] = mindr[nboxes+1] = INT_MAX;
    maxst[0] = maxdr[nboxes+1] = -1;
    for (int i=1;i<=nboxes;i++) {
        minst[i] = min(minst[i-1], boxes[i]);
        maxst[i] = max(maxst[i-1], boxes[i]);
    }
    for (int i=nboxes;i>=1;i--) {
        mindr[i] = min(mindr[i+1], boxes[i]);
        maxdr[i] = max(maxdr[i+1], boxes[i]);
    }
    int mindisc = INT_MAX;
    for (int i=1;i<nboxes;i++) {
        mindisc = min(mindisc, maxst[i]-minst[i]+maxdr[i+1]-mindr[i+1]);
    }
    disc0 = mindisc;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            fin >> fruits[i][j][0];
            fruits[i][j][2] = fruits[i][j][0];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            fin >> fruits[i][j][1];
            fruits[i][j][2] += fruits[i][j][1];
        }
    }
    ind=1, kgport=0, kgban=0, kgmixt=0;
    int method = (tipuri[1]=='M');
    int ok=1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            kgport += fruits[i][j][0];
            kgban += fruits[i][j][1];
            kgmixt += fruits[i][j][2];
            maxkgport = max(maxkgport, kgport);
            maxkgban = max(maxkgban, kgban);
            maxkgmixt = max(maxkgmixt, kgmixt);
            if (ind>nboxes) ok=0;
            if (!method && tipuri[ind]=='P' && kgport==boxes[ind]) {
                ind++; kgport=0;
            }
            if (!method && tipuri[ind]=='B' && kgban==boxes[ind]) {
                ind++; kgban=0;
            }
            if (method && tipuri[ind]=='M' && kgmixt==boxes[ind]) {
                ind++; kgmixt=0;
            }
        }
        if (method && kgmixt) ok=0;
        if (!method && (kgport || kgban)) ok=0;
    }
    if (ind<=nboxes) ok=0;
    if (ok==1 && method && (suma0 != 1LL*c*maxkgmixt)) ok=0;
    if (ok==1 && !method && (suma0 != 1LL*a*maxkgport + 1LL*b*maxkgban)) ok=0;
    if (suma0 != suma1) Msg(0, "Suma incorecta");
    else if (ok==0) Msg(0, "Cutii incorecte");
    else if (disc0 != disc1) Msg(0, "Discrepanta incorecta");
    else Msg(100, "Raspuns corect");
    return 0;
}
