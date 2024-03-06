#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

const string QuenyaSeason[9] = {"Yestarë", "Tuilë", "Lairë", "Yávië", "Enderi", "Lasselanta", "Hrívë", "Coirë", "Mettarë"};
const string SindarinSeason[9] = {"Orvinui", "Ethuil", "Laer", "Iavas", "Enedhin", "Narbeleth", "Rhîw", "Echuir", "Penninor"};
const string EnglishSeason[9] = {"New year", "Spring", "Summer", "Autumn", "Mid Year", "Fade", "Winter", "Awake", "New year's eve"};
const string ChineseSeason[9] = {"新年", "春季", "夏季", "秋季", "年半", "落季", "冬季", "苏季", "除夕"};
const string QuenyaDay[6] = {"Elenya", "Anarya", "Isilya", "Aldúya", "Menelya", "Tárion"};
const string SindarinDay[6] = {"Orgilion", "Oranor", "Orithil", "Orgaladhad", "Ormenel", "Rodyn"};
const string EnglishDay[6] = {"StarDay", "Sunday", "Moonday", "Bitreeday", "Heavensday", "Valaday"};
const string ChineseDay[6] = {"星辰日", "太阳日", "月亮日", "双树日", "天穹日", "维拉日"};
int Season = -1, Day = -1, Ac = -1, Week = -1;

int main(){
	freopen("calendar.txt", "w" ,stdout);
	int M = 0, D = 0;
	scanf("%d %d", &M, &D);
	switch(M){
		case 1:{
			if (D >= 27) Season = 7;
			else Season = 6;
			break;
		}
		case 2:{
			Season = 7;
			break;
		}
		case 3:{
			if (D <= 21) Season = 7;
			else if (D == 22) Season = 8;
			else if (D == 23) Season = 0;
			else Season = 1;
			break;
		}
		case 4:{
			Season = 1;
			break;
		}
		case 5:{
			if (D <= 16) Season = 1;
			else Season = 2;
			break;
		}
		case 6:{
			Season = 2;
			break;
		}
		case 7:{
			if (D <= 27) Season =2;
			else Season = 3;
			break;
		}
		case 8:{
			Season = 3;
			break;
		}
		case 9:{
			if (D <= 19) Season = 3;
			else if (D > 19 && D <= 22) Season = 4;
			else Season = 5;
			break;
		}
		case 10:{
			Season = 5;
			break;
		}
		case 11:{
			if (D <= 15) Season = 5;
			else Season = 6;
			break;
		}
		case 12:{
			Season = 6;
			break;
		}
	}
	if (Season != 0 && Season != 4 && Season != 8){
		switch (Season){
			case 1:{
				if (M == 3) Ac = D - 24;
				else if (M == 4) Ac = D + 7;
				else if (M == 5) Ac = D + 37;
				break;
			}
			case 2:{
				if (M == 5) Ac = D - 17;
				else if (M == 6) Ac = D + 14;
				else if (M == 7) Ac = D + 44;
				break;
			}
			case 3:{
				if (M == 7) Ac = D - 28;
				else if (M == 8) Ac = D + 3;
				else if (M == 9) Ac = D + 34;
				break;
			}
			case 5:{
				if (M == 9) Ac = D - 23;
				else if (M == 10) Ac = D + 7;
				else if (M == 11) Ac = D + 38;
				break;
			}
			case 6:{
				if (M == 11) Ac = D - 16;
				else if (M == 12) Ac = D + 14;
				else if (M == 1) Ac = D + 45;
				break;
			}
			case 7:{
				if (M == 1) Ac = D - 27;
				else if (M == 2) Ac = D + 4;
				else if (M == 3) Ac = D + 32;
				break;
			}
		}
	}
	if (Ac != -1) {
		Week = Ac / 6 + 1;
		Day = Ac % 6;
	}
	printf("Quenya: Síra ná ");
	if (~Week && ~Day) {
		cout << QuenyaDay[Day];
		cout << ", Enquië ";
		if (Week == 10) cout << "01, ";
		else if (Week == 12) cout << "21, ";
		else cout << Week << ", ";
	}
	cout << QuenyaSeason[Season] << "." << endl;
	printf("Sindarin: Sír ");
	if (~Week && ~Day) {
		cout << SindarinDay[Day];
		cout << ", Odlad ";
		if (Week == 10) cout << "01, ";
		else if (Week == 12) cout << "21, ";
		else cout << Week << ", ";
	}
	cout << SindarinSeason[Season] << "." << endl;
	printf("English: Today is ");
	if (~Week && ~Day){
		cout << EnglishDay[Day];
		cout << ", Week " << Week << ", ";
	}
	cout << EnglishSeason[Season] << "." << endl;
	printf("汉语：今天是");
	cout << ChineseSeason[Season];
	if (~Week && ~Day){
		cout << "，第" << Week << "周，";
		cout << ChineseDay[Day];
	}
	cout << "。" << endl;
	fclose(stdout);
	return 0;
}