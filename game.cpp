#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

struct Arrow{
	int x1;
	int x2;
	int y;
};

struct Credit{
	int x;
	int y;
};

struct Player{ //P
	string name;
	char model;
	int x;
	int y;
	int level;
	int health;
	int maxhealth;
	int xp;
	int xpcap;
	int gold;
	int basedamage;
};

struct Enemy{ //X
	int health;
	int damage;
};

struct AW{
	int health;
	int shield;
	int damage;
};

struct LOD{
	int health;
	int shield;
	int damage;
};

struct Weapon{
	string name; //sword axe bow
	int damage;
};

void gotoxy(int x, int y){
   COORD k = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void Loading(){
	system("cls");
	string loadingtext("Loading...");
	gotoxy(1,1);
	cout<<loadingtext;

	int loadingcounter=1;
	int x=1;
	gotoxy(12,1);
	cout<<"   %";

	bool loading=true;
	do{
		for(int i=0;i<loadingtext.size();i++){
			if(i>0){
				gotoxy(i,0);
				cout<<" ";
				gotoxy(i,1);
				cout<<loadingtext.at(i-1);
			}
			gotoxy(i+1,1);
			cout<<" ";
			gotoxy(i+1,0);
			cout<<loadingtext.at(i);
			Sleep(20);
			if(i==loadingtext.size()-1){
				gotoxy(i+1,0);
				cout<<" ";
				gotoxy(i+1,1);
				cout<<loadingtext.at(i);
			}

			gotoxy(12,1);
            cout<<loadingcounter;
            loadingcounter++;
            if(loadingcounter%10==0){
            gotoxy(x,2);
            cout<<'/';
            x++;
            }
		}
		if(loadingcounter==101) loading=false;
		gotoxy(0,5);
	}while(loading);
}

void Confirmation(Arrow &arrow,char &key){
	system("cls");
	cout<<"You will enter point of no return. Are you sure?"<<endl;
	cout<<"   Yes   No"<<endl;
	cout<<"LEFT	: move left"<<endl;
	cout<<"RIGHT	: move right"<<endl;
	cout<<"SPACE	: select"<<endl;
	gotoxy(arrow.x1,arrow.y);
	cout<<'<';
	gotoxy(arrow.x2,arrow.y);
	cout<<'>';
	key=getch();
	gotoxy(arrow.x1,arrow.y);
	cout<<' ';
	gotoxy(arrow.x2,arrow.y);
	cout<<' ';
}

void EndingChoice(Arrow &arrow,char &key){
	system("cls");
	cout<<"   What will you choose?"<<endl;
	cout<<" (YOUR CHOICE DOES MATTER)"<<endl;
	cout<<endl;
	cout<<"   Face the Ancient Wisp"<<endl;
	cout<<"      Betray Narrator"<<endl;
	cout<<"       Trust Nobody"<<endl;
	cout<<endl;
	cout<<"UP	: move up"<<endl;
	cout<<"DOWN	: move down"<<endl;
	cout<<"SPACE	: select"<<endl;
	gotoxy(arrow.x1,arrow.y);
	cout<<'<';
	gotoxy(arrow.x2,arrow.y);
	cout<<'>';
	key=getch();
	gotoxy(arrow.x1,arrow.y);
	cout<<' ';
	gotoxy(arrow.x2,arrow.y);
	cout<<' ';
}

void MainMenu(Arrow &arrow,char &key){
	gotoxy(0,0);
	cout<<"  ===================="<<endl;
	cout<<" |                    |"<<endl;
	cout<<" | Castle of the Wisp |"<<endl;
	cout<<" |   STORY RPG GAME   |"<<endl;
	cout<<" |                    |"<<endl;
	cout<<" |      New Game      |"<<endl;
	cout<<" |      Continue      |"<<endl;
	cout<<" |       Credit       |"<<endl;
	cout<<" |        Exit        |"<<endl;
	cout<<" |                    |"<<endl;
	cout<<"  ===================="<<endl;
	cout<<"UP	: move up"<<endl;
	cout<<"DOWN	: move down"<<endl;
	cout<<"SPACE	: select"<<endl;
	gotoxy(arrow.x1,arrow.y);
	cout<<'<';
	gotoxy(arrow.x2,arrow.y);
	cout<<'>';
	key=getch();
	gotoxy(arrow.x1,arrow.y);
	cout<<' ';
	gotoxy(arrow.x2,arrow.y);
	cout<<' ';
}

void PauseMenu(Arrow &arrow,char &key){
	system("cls");
	gotoxy(0,0);
	cout<<"  ==================="<<endl;
	cout<<" |                   |"<<endl;
	cout<<" |       Paused      |"<<endl;
	cout<<" |                   |"<<endl;
	cout<<" |        Back       |"<<endl;
	cout<<" |       Status      |"<<endl;
	cout<<" |   Change Weapon   |"<<endl;
	cout<<" |    to Main Menu   |"<<endl;
	cout<<" |                   |"<<endl;
	cout<<"  ==================="<<endl;
	cout<<"UP	: move up"<<endl;
	cout<<"DOWN	: move down"<<endl;
	cout<<"SPACE	: select"<<endl;
	gotoxy(arrow.x1,arrow.y);
	cout<<'<';
	gotoxy(arrow.x2,arrow.y);
	cout<<'>';
	key=getch();
	gotoxy(arrow.x1,arrow.y);
	cout<<' ';
	gotoxy(arrow.x2,arrow.y);
	cout<<' ';
}

void StatusMenu(Player player,Weapon weapon){
	system("cls");
	cout<<player.name<<endl;
	cout<<"Level			: "<<player.level<<endl;
	cout<<"XP			: "<<player.xp<<"/"<<player.xpcap<<endl;
	cout<<"Health			: "<<player.health<<"/"<<player.maxhealth<<endl;
	cout<<"Gold			: "<<player.gold<<"G"<<endl;
	cout<<"Base Damage		: "<<player.basedamage<<endl;
	cout<<"Total Damage		: "<<player.basedamage+weapon.damage<<endl;
	system("pause");
}

void WeaponMenu(Weapon weapon){
	system("cls");
	if(weapon.name!=""){
		cout<<"Weapon: "<<weapon.name<<endl;
	}
	cout<<"Choose Your Weapon"<<endl;
	cout<<"1. Sword & Shield"<<endl;
	cout<<"2. Axe"<<endl;
	cout<<"3. Bow"<<endl;
	cout<<"4. Back"<<endl;
	cout<<">>> ";
}

void Copyright(Credit credit[]){
	credit[0].x=7;
	credit[1].x=14;
	credit[2].x=16;
	credit[0].y=5;
	credit[1].y=6;
	credit[2].y=7;
	system("cls");
	while(!kbhit()){
		gotoxy(0,0);
		cout<<" ======================================="<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<"|                                       |"<<endl;
		cout<<" ======================================="<<endl;
		cout<<"Press anything to stop (not SPACE)"<<endl;
		gotoxy(credit[0].x,credit[0].y);
		cout<<"Tugas Akhir Asistensi 2020"<<endl;
		gotoxy(credit[1].x,credit[1].y);
		cout<<"Ignatius Odi"<<endl;
		gotoxy(credit[2].x,credit[2].y);
		cout<<"220116919"<<endl;
		gotoxy(34,13);
		Sleep(200);
		gotoxy(credit[0].x,credit[0].y);
		cout<<"                  "<<endl;
		gotoxy(credit[1].x,credit[1].y);
		cout<<"            "<<endl;
		gotoxy(credit[2].x,credit[2].y);
		cout<<"         "<<endl;
		for(int i=0;i<3;i++){
			credit[i].y-=1;
			if(credit[i].y<1) credit[i].y=11;
		}
	}
	system("cls");
}

void Exit(){
	system("cls");
	cout<<"            __"<<endl;
	cout<<"           /oo\\"<<endl;
	cout<<"          /ooo|"<<endl;
	cout<<"         /oooo/"<<endl;
	cout<<"        /oooo/"<<endl;
	cout<<"       /oooo/"<<endl;
	cout<<"_____||oooo/___________"<<endl;
	cout<<"     ||oooooooooooooooo|"<<endl;
	cout<<"     ||ooooooo_________|"<<endl;
	cout<<"     ||ooooooooooooooo|"<<endl;
	cout<<"     ||oooooo_________|"<<endl;
	cout<<"     ||ooooooooooooo|"<<endl;
	cout<<"     ||ooooo________|"<<endl;
	cout<<"     ||ooooooooooo|"<<endl;
	cout<<"_____||___________|";
}

void Typed(string t){
	for(int i=0;i<t.size();i++){
		cout<<t.at(i);
		Sleep(10);
	}
}

void PauseDelete(){
	system("pause");
	system("cls");
}

void Prologue(Player &player){
	system("cls");
	string t("Hello, are you dead?\n");
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="What?! Where am I?\n";
	cout<<"?: "; Typed(t);
	PauseDelete();
	
	t="Hey, you're finally awake.\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="Who are you?\n";
	cout<<"?: "; Typed(t);
	PauseDelete();
	
	t="I am your narrator.\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="Narrator? Is it a God?\n";
	cout<<"?: "; Typed(t);
	PauseDelete();
	
	t="Well yes, but actually no.\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="Who am I?\n";
	cout<<"?: "; Typed(t);
	PauseDelete();
	
	t="I don't know. What should I call you?\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	cout<<"What's your name? "; getline(cin,player.name);
	system("cls");
	t=player.name;
	cout<<player.name<<": "; Typed(t); cout<<".\n";
	PauseDelete();
	
	t="Great, "+player.name+". Now let's start our adventure.\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
}

void Dialogue1(Player player){
	system("cls");
	string t("Hey, what should I do?\n");
	cout<<player.name<<": "; Typed(t);
	PauseDelete();
	t="Kill the Ancient Wisp\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="???\n";
	cout<<player.name<<": "; Typed(t);
	PauseDelete();
	t="Try press esc key to pause game to see your status and change weapon you want to use\n";
	cout<<"Narrator: "; Typed(t);
	t="\t  Type the word in the battle either attack / guard / heal / run\n"; Typed(t);
	t="\t  Try to slay an enemy there.\n"; Typed(t);
	PauseDelete();
}

void Dialogue2(){
	system("cls");
	string t("You will get exp and gold every time you slay a wisp\n");
	cout<<"Narrator: "; Typed(t);
	t="\t  You need exp to level up\n"; Typed(t);
	t="\t  Level up means increasing max health and base damage\n"; Typed(t);
	t="\t  Meet the Merchant in the castle to spend your gold\n"; Typed(t);
	t="\t  Anyway, you're the most talented adventurer I've ever seen.\n"; Typed(t);
	PauseDelete();
}

void Dialogue3(){
	system("cls");
	string t("Here we are, in the heart of the castle.\n");
	cout<<"Narrator: "; Typed(t);
	t="\t  Before you can enter the Ancient Wisp room you need to get stronger first.\n"; Typed(t);
	PauseDelete();
}

void Dialogue4(){
	system("cls");
	string t("Good job, now you're ready to face the Ancient Wisp.\n");
	cout<<"Narrator: "; Typed(t);
	t="\t  Enter the Ancient Wisp room whenever you're ready.\n"; Typed(t);
	PauseDelete();
}

void Dialogue5(Player player){
	system("cls");
	string t("Knight, you're finally here! What takes you so long?\n");
	cout<<"Ancient Wisp: "; Typed(t);
	PauseDelete();
	t="Knight?\n";
	cout<<player.name<<": "; Typed(t);
	PauseDelete();
	t="You nasty evil wisp, you shall die before this adventurer hand.\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="Who are you? What have you done to my beloved Knight?\n";
	cout<<"Ancient Wisp: "; Typed(t);
	PauseDelete();
	t="I don't understand this situation.\n";
	cout<<player.name<<": "; Typed(t);
	PauseDelete();
	t="Don't listen to this thing, "+player.name+". It will only confuse you, just trust me!\n";
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="The choice is yours, dear Knight.\n";
	cout<<"Ancient Wisp: "; Typed(t);
	PauseDelete();
}

void FaceWisp(Player player){
	system("cls");
	string t("Great "+player.name+", then I'll help you.\n");
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t=("Looks like you aren't trustworthy enough for me, farewell my old beloved Knight.\n");
	cout<<"Ancient Wisp: "; Typed(t);
	PauseDelete();
}

void BetrayNarrator(){
	system("cls");
	string t("After all I've done for you, you dare betray me?!\n");
	cout<<"Narrator: "; Typed(t);
	PauseDelete();
	t="*Narrator reveal itself as Lord of Death*\n"; Typed(t);
	PauseDelete();
	t="Let's see if you have enough power to beat me!\n";
	cout<<"Lord of Death: "; Typed(t);
	PauseDelete();
}

void TrustNobody(Player player){
	system("cls");
	string t("I'm not gonna trust anybody!!!\n");
	cout<<player.name<<": "; Typed(t);
	PauseDelete();
	t="You leave the castle immediately! And leave every last memories there\n"; Typed(t);
	PauseDelete();
}

void BadEnding(){
	system("cls");
	string t("It turns out that you're Guardian Knight of the Wisp\n"); Typed(t);
	PauseDelete();
	t="and... "; Typed(t);
	t="*Narrator reveal itself as Lord of Death*\n"; Typed(t);
	PauseDelete();
	t="Hahaha, fool Guardian you've fallen into my trap. You make my life easier.\n";
	cout<<"Lord of Death: "; Typed(t);
	PauseDelete();
	t="I'm the strongest here. Every one shall bow before me. Thou shall die here.\n";
	cout<<"Lord of Death: "; Typed(t);
	PauseDelete();
	t="Goodbye.\n";
	cout<<"Lord of Death: "; Typed(t);
	PauseDelete();
	t="Betraying good for helping evil might not a good idea\nsince you didn't receive any reward after all. Right?\n"; Typed(t);	
	PauseDelete();
}

void GoodEnding(){
	system("cls");
	string t("It turns out that you're Guardian Knight of the Wisp\n"); Typed(t);
	PauseDelete();
	t="You prove yourself trustworthy Guardian. I owe thou my life.\n";
	cout<<"Ancient Wisp: "; Typed(t);
	t="\t\tThank You\n"; Typed(t);
	PauseDelete();
}

void MistrustEnding(){
	system("cls");
	string t("You live wander around the world to find who you really are.\n"); Typed(t);
	t="Yet you find nothing for the rest of your life.\n"; Typed(t);
	PauseDelete();
}

void DeadEnding(){
	system("cls");
	string t("Sorry, but you've died.\n"); Typed(t);
	t="Maybe from the beginning you shouldn't act so tough.\n"; Typed(t);
	PauseDelete();
}

void Epilogue(){
	system("cls");
	string t("\n\t\e[1m'For there to be betrayal, there\n\twould have to have been trust first.'\n\t\t~ Suzanne Collins ~\e[0m\n\n"); Typed(t);
	t="\t<(_ _*)> Thank you for playing the game <(_ _*)>\n"; Typed(t);
	t="\t\tSee you in the next game\n\n";Typed(t);
	cout<<"\t";
	PauseDelete();
}

void Move(char key,char map[][20],Player &player){
    if(key=='w' && (map[player.y-1][player.x]!='#' && map[player.y-1][player.x]!='|')){
        player.y--;
    } else if(key=='s' && (map[player.y+1][player.x]!='#' && map[player.y+1][player.x]!='|')){
        player.y++;
    } else if(key=='a' && (map[player.y][player.x-1]!='#' && map[player.y][player.x-1]!='|')){
        player.x--;
    } else if(key=='d' && (map[player.y][player.x+1]!='#' && map[player.y][player.x+1]!='|')){
        player.x++;
    }
}

void EmptyMap(char map[][20]){
	for(int y=0;y<14;y++){
		for(int x=0;x<20;x++){
			map[y][x]=' ';
		}
	}
}

void PrintMap(char map[][20],Player player){
	for(int y=0;y<14;y++){
		for(int x=0;x<20;x++){
			if(x==player.x && y==player.y) cout<<player.model<<' ';
			else cout<<map[y][x]<<' ';
		}
		cout<<endl;
	}
}

void LoadStartingMap(char map[][20]){
	ifstream f("./asset/map/startingmap.txt");
	int y=0;
	string temp;
	if(f.is_open()){
		while(!f.eof()){
			getline(f,temp);
			for(int x=0;x<temp.size();x++){
				map[y][x]=temp.at(x);
			}
			y++;
		}
	}
	f.close();
}

void LoadTutorialMap(char map[][20]){
    ifstream f("./asset/map/tutorialmap.txt");
    int y=0;
    string temp;
    if(f.is_open()){
        while(!f.eof()){
            getline(f,temp);
            for(int x=0;x<temp.size();x++){
                map[y][x]=temp.at(x);
            }
            y++;
        }
    }
    f.close();
}

void LoadMainMap(char map[][20]){
    ifstream f("./asset/map/mainmap.txt");
    int y=0;
    string temp;
    if(f.is_open()){
        while(!f.eof()){
            getline(f,temp);
            for(int x=0;x<temp.size();x++){
                map[y][x]=temp.at(x);
            }
            y++;
        }
    }
    f.close();
}

void LoadMerchantMap(char map[][20]){
    ifstream f("./asset/map/merchantmap.txt");
    int y=0;
    string temp;
    if(f.is_open()){
        while(!f.eof()){
            getline(f,temp);
            for(int x=0;x<temp.size();x++){
                map[y][x]=temp.at(x);
            }
            y++;
        }
    }
    f.close();
}

void LoadBossMap(char map[][20]){
    ifstream f("./asset/map/bossmap.txt");
    int y=0;
    string temp;
    if(f.is_open()){
        while(!f.eof()){
            getline(f,temp);
            for(int x=0;x<temp.size();x++){
                map[y][x]=temp.at(x);
            }
            y++;
        }
    }
    f.close();
}

void Check(char map[][20],int &ctrmap,bool &startingmap,bool &tutorialmap,bool &mainmap,bool &merchantmap,bool &bossmap,Player &player){
	if(map[player.y][player.x]==']'){
		if(ctrmap==0){ //startingmap
			tutorialmap=true;
			ctrmap+=1;
			player.x=1;
			player.y=2;
		} else if(ctrmap==1){ //tutorialmap
			mainmap=true;
			ctrmap+=1;
			player.x=1;
			player.y=6;
		}
	} else if(map[player.y][player.x]=='-'){
		if(ctrmap==2){ //mainmap
			merchantmap=true;
			ctrmap+=1;
			player.x=2;
			player.y=1;
		} else if(ctrmap==3){ //merchantmap
			mainmap=true;
			ctrmap-=1;
			player.x=17;
			player.y=11;
		}
	}
}

void SwordShield(){ //attack 10% *maxhealth 100% defend
	ifstream f("./asset/pic/swordnshield.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
}

void Axe(){ //attack 25% *maxhealth 75% defend
	ifstream f("./asset/pic/axe.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
}

void Bow(){ //attack 40% *health 50% defend
	ifstream f("./asset/pic/bow.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
}

void VSEnemy(Enemy enemy,Player player){
	system("cls");
	ifstream f("./asset/pic/enemy.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
	cout<<"Enemy"<<endl;
	cout<<"health: "<<enemy.health<<endl;
	
	cout<<"\n\e[1mPlayer\e[0m"<<endl;
	cout<<"health: "<<player.health<<endl;
	cout<<"'attack','guard','heal','run'"<<endl;
}

void VSAW(AW aw,Player player){
	system("cls");
	ifstream f("./asset/pic/aw.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
	cout<<"Ancient Wisp"<<endl;
	cout<<"health: "<<aw.health<<endl;
	cout<<"shield: "<<aw.shield<<endl;
	cout<<"\n\e[1mPlayer\e[0m"<<endl;
	cout<<"health: "<<player.health<<endl;
	cout<<"'attack','guard','heal'"<<endl;
}

void VSLOD(LOD lod,Player player){
	system("cls");
	ifstream f("./asset/pic/lod.txt");
	if(f.is_open()){
		string temp;
		while(!f.eof()){
			getline(f,temp);
			cout<<temp<<endl;
		}
	}
	f.close();
	cout<<"Lord Of Death"<<endl;
	cout<<"health: "<<lod.health<<endl;
	cout<<"shield: "<<lod.shield<<endl;
	cout<<"\n\e[1mPlayer\e[0m"<<endl;
	cout<<"health: "<<player.health<<endl;
	cout<<"Type: 'attack','guard','heal'"<<endl;
}

void KeyHint(){
	cout<<"esc	: Pause Menu"<<endl;
	cout<<"w	: Move Up"<<endl;
	cout<<"a	: Move Left"<<endl;
	cout<<"s	: Move Down"<<endl;
	cout<<"d	: Move Right"<<endl;
	cout<<"#	: Wall"<<endl;
	cout<<"X	: Enemy"<<endl;
	cout<<"M	: Merchant"<<endl;
}

int main(){
	srand(time(0));
	bool isRunning=true;
	
	char key;
	Arrow arrow;
	Player player;
	player.model='P';
	player.level=0;
	player.maxhealth=player.level*2000+1000;
	player.health=player.maxhealth;
	player.xpcap=player.level*200+100;
	player.xp=0;
	player.gold=0;
	player.basedamage=0.1*player.maxhealth;
	
	Weapon weapon;
	Enemy enemy;
	AW aw;
	LOD lod;
	
	char map[14][20];
	Credit credit[3];
	while(isRunning){
		arrow.x1=5;
		arrow.x2=18;
		arrow.y=5;
		
		bool isMainMenu=true;
		bool isGame=false;
		
		int ctrmap=0;
		bool startingmap=false;
		bool tutorialmap=false;
		bool mainmap=false;
		bool merchantmap=false;
		bool bossmap=false;
		
		bool prologue=true;
		bool dialogue1=true;
		bool dialogue2=true;
		bool dialogue3=true;
		bool dialogue4=true;
		bool dialogue5=true;
		bool facewisp=false;
		bool betraynarrator=false;
		bool trustnobody=false;
		bool bad=false;
		bool good=false;
		bool mistrust=false;
		bool epilogue=false;
		
		while(isMainMenu){
			MainMenu(arrow,key);
			if(key==72 && arrow.y>5){ //UPARROW
				arrow.y-=1;
				if(arrow.y>5){
					arrow.x1-=1;
					arrow.x2+=1;
				}
			} else if(key==80 && arrow.y<8){ //DOWNARROW
				arrow.y+=1;
				if(arrow.y>6){
					arrow.x1+=1;
					arrow.x2-=1;
				}
			} else if(key==' '){ //SPACE
				if(arrow.y==5){ //NEW GAME
					isGame=true;
					isMainMenu=false;
					player.x=2;
					player.y=2;
					player.level=0;
					player.maxhealth=player.level*2000+1000;
					player.health=player.maxhealth;
					player.xpcap=player.level*200+100;
					player.xp=0;
					player.gold=0;
					player.basedamage=0.1*player.maxhealth;
					weapon.name="sword";
					weapon.damage=0;
					ctrmap=0;
				} else if(arrow.y==6){ //CONTINUE=LOAD
					isGame=true;
					isMainMenu=false;
					ifstream f("save.txt");
					if(f.is_open()){
						while(!f.eof()){
							f>>ctrmap;
							f>>player.x;
							f>>player.y;
							f>>player.name;
							f>>player.level;
							f>>player.health;
							f>>player.maxhealth;
							f>>player.xp;
							f>>player.xpcap;
							f>>player.gold;
							f>>player.basedamage;
							f>>weapon.name;
							f>>weapon.damage;
							f>>prologue;
							f>>dialogue1;
							f>>dialogue2;
							f>>dialogue3;
							f>>dialogue4;
							f>>dialogue5;
						}
					}
					f.close();
				} else if(arrow.y==7){ //CREDIT
					Copyright(credit);
				} else if(arrow.y==8){ //EXIT
					Exit();
					isMainMenu=false;
					isRunning=false;
				}
			}
		}
		
		if(ctrmap==0) startingmap=true; //startingmap
		else if(ctrmap==1) tutorialmap=true; //tutorialmap
		else if(ctrmap==2) mainmap=true; //mainmap
		else if(ctrmap==3) merchantmap=true; //merchantmap
		else if(ctrmap==4) bossmap=true; //bossmap
		
		while(isGame){
			system("cls");
			if(startingmap){
				Loading();
				gotoxy(1,3); PauseDelete();
				if(prologue){
					Prologue(player);
					prologue=false;
				}
				EmptyMap(map);
				LoadStartingMap(map);
				startingmap=false;
			} else if(tutorialmap){
				Loading();
				gotoxy(1,3); PauseDelete();
				if(dialogue1){
					Dialogue1(player);
					dialogue1=false;
				}
				EmptyMap(map);
				LoadTutorialMap(map);
				tutorialmap=false;
			} else if(mainmap){
				Loading();
				gotoxy(1,3); PauseDelete();
				if(dialogue3){
					Dialogue3();
					dialogue3=false;
				}
				EmptyMap(map);
				LoadMainMap(map);
				mainmap=false;
			} else if(merchantmap){
				Loading();
				gotoxy(1,3); PauseDelete();
				EmptyMap(map);
				LoadMerchantMap(map);
				merchantmap=false;
			} else if(bossmap){
				Loading();
				gotoxy(1,3); PauseDelete();
				if(dialogue5){
					Dialogue5(player);
					dialogue5=false;
				}
				EmptyMap(map);
				LoadBossMap(map);
				bossmap=false;
			}
			if(player.level>=5 && ctrmap==2){
				map[6][19]=']';
				if(dialogue4){
					Dialogue4();
					dialogue4=false;
				}
			}
			PrintMap(map,player);
			if(ctrmap==0) gotoxy(0,5); //startingmap
			else if(ctrmap==1) gotoxy(0,5); //tutorialmap
			else if(ctrmap==2) gotoxy(0,13); //mainmap
			else if(ctrmap==3) gotoxy(0,4); //merchantmap
			else if(ctrmap==4) gotoxy(0,11); //bossmap
			KeyHint();
			key=getch();
			if(key==27){
				bool isPause=true;
				arrow.x1=3;
				arrow.x2=19;
				arrow.y=4;
				while(isPause){
					PauseMenu(arrow,key);
					if(key==72 && arrow.y>4){ //UPARROW
						arrow.y-=1;
					} else if(key==80 && arrow.y<7){ //DOWNARROW
						arrow.y+=1;
					} else if(key==' '){ //SPACE
						if(arrow.y==4){ //BACK
							isPause=false;
						} else if(arrow.y==5){ //STATUS
							if(weapon.name=="sword"){
								weapon.damage=0.1*player.maxhealth;
							} else if(weapon.name=="axe"){
								weapon.damage=0.25*player.maxhealth;
							} else if(weapon.name=="bow"){
								weapon.damage=0.4*player.health;
							} else{
								weapon.damage=0;
							}
							StatusMenu(player,weapon);
						} else if(arrow.y==6){ //CHANGE WEAPON
							bool isWeapon=true;
							int choice;
							while(isWeapon){
								WeaponMenu(weapon); cin>>choice;
								if(choice==1){ //sword
									weapon.name="sword";
									cout<<"You've choosen sword & shield"<<endl;
									SwordShield();
									system("pause");
								} else if(choice==2){ //axe
									weapon.name="axe";
									cout<<"You've choosen axe"<<endl;
									Axe();
									system("pause");
								} else if(choice==3){ //bow
									weapon.name="bow";
									cout<<"You've choosen bow"<<endl;
									Bow();
									system("pause");
								} else if(choice==4){ //back
									isWeapon=false;
								}
							}
						} else if(arrow.y==7){ //to Main Menu (Save)
							isPause=false;
							isGame=false;
							//SAVE
							ofstream f("save.txt");
							if(f.is_open()){
								f<<ctrmap<<endl;
								f<<player.x<<endl;
								f<<player.y<<endl;
								f<<player.name<<endl;
								f<<player.level<<endl;
								f<<player.health<<endl;
								f<<player.maxhealth<<endl;
								f<<player.xp<<endl;
								f<<player.xpcap<<endl;
								f<<player.gold<<endl;
								f<<player.basedamage<<endl;
								f<<weapon.name<<endl;
								f<<weapon.damage<<endl;
								f<<prologue<<endl;
								f<<dialogue1<<endl;
								f<<dialogue2<<endl;
								f<<dialogue3<<endl;
								f<<dialogue4<<endl;
								f<<dialogue5;
							}
							f.close();
						}
					}
				}
			} else{
				Move(key,map,player);
				Check(map,ctrmap,startingmap,tutorialmap,mainmap,merchantmap,bossmap,player);
			}
			if(map[player.y][player.x]=='X'){
				bool isFight=true;
				int damage;
				int guard;
				int heal=0.2*player.maxhealth;
				string playerchoice;
				string enemychoice;
				enemy.health=1.5*player.maxhealth;
				enemy.damage=0.1*enemy.health;
				while(isFight){
					if(weapon.name=="sword"){
						weapon.damage=0.1*player.maxhealth;
						guard=0;
					} else if(weapon.name=="axe"){
						weapon.damage=0.25*player.maxhealth;
						guard=0.25*enemy.damage;
					} else if(weapon.name=="bow"){
						weapon.damage=0.4*player.health;
						guard=0.5*enemy.damage;
					}
					damage=player.basedamage+weapon.damage;
					
					VSEnemy(enemy,player); cin>>playerchoice;
					cout<<"\e[1mPlayer\e[0m choose "<<playerchoice<<endl;
					int random=rand()%10+1;
					if(random>=1 && random<=8){ //80% attack
						enemychoice="attack";
					} else{ //20% guard
						enemychoice="guard";
					}
					cout<<"Enemy choose "<<enemychoice<<endl;
					if(playerchoice=="run"){
						isFight=false;
						cout<<"\e[1mPlayer\e[0m ran away from the battle"<<endl;
					} else if(playerchoice=="win"){
						isFight=false;
						enemy.health=0;
						cout<<"\e[1mPlayer cheat to win!\e[0m"<<endl;
					} else if(playerchoice=="attack" && enemychoice=="attack"){
						player.health-=enemy.damage;
						enemy.health-=damage;
						cout<<"\e[1mPlayer\e[0m attack "<<damage<<" damage"<<endl;
						cout<<"Enemy attack "<<enemy.damage<<" damage"<<endl;
					} else if(playerchoice=="guard" && enemychoice=="attack"){
						player.health-=guard;
						cout<<"Enemy attack "<<enemy.damage<<" damage"<<endl;
					} else if(playerchoice=="heal"){
						cout<<"\e[1mPlayer\e[0m healed "<<heal<<" health"<<endl;
						player.health+=heal;
						if(enemychoice=="attack"){
							player.health-=enemy.damage;
							cout<<"Enemy attack "<<enemy.damage<<" damage"<<endl;
						}
						if(player.health>player.maxhealth){
							player.health=player.maxhealth;
						}
					}
					system("pause");
					if(player.health<=0){
						system("cls");
						cout<<"\e[1mPlayer\e[0m run out of health (\e[1mPlayer\e[0m Lose)"<<endl;
						isFight=false;
						player.health=player.maxhealth;
						system("pause");
					} else if(enemy.health<=0){
						system("cls");
						cout<<"Enemy run out of health (\e[1mPlayer\e[0m Win)"<<endl;
						isFight=false;
						player.xp+=150;
						int randomgold=rand()%150+player.level*200;
						player.gold+=randomgold;
						cout<<"+150xp & +"<<randomgold<<"G"<<endl;
						system("pause");
					}
				}
				map[player.y][player.x]=' ';
				if(dialogue2){
					Dialogue2();
					dialogue2=false;
					map[2][9]=']';
				}
			} else if(map[player.y][player.x]=='M'){
				bool isMerchant=true;
				system("cls");
				string t("Welcome Adventurer! I've been waiting for you! What do you need?\n");
				cout<<"Merchant: "; Typed(t);
				PauseDelete();
				while(isMerchant){
					string choice;
					system("cls");
					cout<<"Merchant Menu"<<endl;
					cout<<"Level "<<player.level<<endl;
					cout<<"Gold "<<player.gold<<endl;
					cout<<"1. Upgrade Level (Required "<<player.level*500<<"G)"<<endl;
					cout<<"0. Exit"<<endl;
					cout<<">>> "; cin>>choice;
					if(choice=="0"){
						isMerchant=false;
					} else if(choice=="1"){
						if(player.gold>=player.level*500){
							player.gold-=player.level*500;
							player.level+=1;
							player.xpcap=player.level*200+100;
							player.maxhealth=player.level*2000+1000;
							player.health=player.maxhealth;
							cout<<"\e[1mPlayer\e[0m Level Upgraded"<<endl;
						} else{
							cout<<"Not Enough Gold"<<endl;
						}
						system("pause");
					}
				}
				system("cls");
				t="Thank you! Come back later!\n";
				cout<<"Merchant: "; Typed(t);
				PauseDelete();
				player.x=2;
				player.y=1;
			} else if(ctrmap==2 && map[player.y][player.x]==']'){ //mainmap
				bool confirmation=true;
				arrow.x1=1;
				arrow.x2=7;
				arrow.y=1;
				while(confirmation){
					Confirmation(arrow,key);
					if(key==75 && arrow.x1>2){ //LEFT ARROW
						arrow.x1-=6;
						arrow.x2-=5;
					} else if(key==77 && arrow.x1<2){ //RIGHT ARROW
						arrow.x1+=6;
						arrow.x2+=5;
					} else if(key==' '){
						if(arrow.x1==1){
							confirmation=false;
							bossmap=true;
							ctrmap+=2;
							player.x=1;
							player.y=1;
						} else{
							confirmation=false;
							player.x-=1;
						}
					}
				}
			} else if(map[player.y][player.x]=='O'){
				bool isEnding=true;
				arrow.x1=1;
				arrow.x2=25;
				arrow.y=3;
				while(isEnding){
					EndingChoice(arrow,key);
					if(key==72 && arrow.y>3){ //UPARROW
						arrow.y-=1;
					} else if(key==80 && arrow.y<5){ //DOWNARROW
						arrow.y+=1;
					} else if(key==' '){ //SPACE
						if(arrow.y==3){ //FaceWisp
							facewisp=true;
						} else if(arrow.y==4){ //BetrayNarrator
							betraynarrator=true;
						} else if(arrow.y==5){ //TrustNobody
							trustnobody=true;
						}
						isEnding=false;
						isGame=false;
					}
				}
			}
			if(player.xp>=player.xpcap){
				player.level+=1;
				player.xp-=player.xpcap;
				player.xpcap=player.level*200+100;
				player.maxhealth=player.level*2000+1000;
				player.health=player.maxhealth;
				player.basedamage=0.1*player.maxhealth;
			}
		}
		
		bool isDied=false;
		if(facewisp){ //50% health ancient wisp died because of lod
			FaceWisp(player);
			//battle
			bool isFight=true;
			int damage;
			int guard;
			int heal=0.2*player.maxhealth;
			string playerchoice;
			string awchoice;
			aw.health=15000;
			aw.shield=5000;
			aw.damage=2000;
			while(isFight){
				if(weapon.name=="sword"){
					weapon.damage=0.1*player.maxhealth;
					guard=0;
				} else if(weapon.name=="axe"){
					weapon.damage=0.25*player.maxhealth;
					guard=0.25*aw.damage;
				} else if(weapon.name=="bow"){
					weapon.damage=0.4*player.health;
					guard=0.5*aw.damage;
				}
				damage=player.basedamage+weapon.damage;
				damage=damage*1.5; //LOD helps you
				
				VSAW(aw,player);
				if(aw.health<=7500){
					aw.health=0;
					cout<<"Narrator release its ultimate power and defeat Ancient Wisp instantly"<<endl;
				} else{
					int random=rand()%10+1;
					if(random>=1 && random<=9){ //90% attack
						awchoice="attack";
					} else{ //10% guard
						awchoice="guard";
					}
					cout<<"Ancient Wisp choose "<<awchoice<<endl;
					cin>>playerchoice;
					cout<<"\e[1mPlayer\e[0m choose "<<playerchoice<<endl;
					if(playerchoice=="attack" && awchoice=="attack"){
						player.health-=aw.damage;
						if(aw.shield>0){
							aw.shield-=damage;
							if(aw.shield<0){
								aw.health+=aw.shield;
								aw.shield=0;
							}
						} else{
							aw.health-=damage;
						}
						cout<<"Ancient Wisp attack "<<aw.damage<<" damage"<<endl;
						cout<<"\e[1mPlayer\e[0m attack "<<damage<<" damage"<<endl;
					} else if(playerchoice=="guard" && awchoice=="attack"){
						player.health-=guard;
						cout<<"Ancient Wisp attack "<<aw.damage<<" damage"<<endl;
					} else if(playerchoice=="heal"){
						cout<<"\e[1mPlayer\e[0m healed "<<heal<<" health"<<endl;
						player.health+=heal;
						if(awchoice=="attack"){
							player.health-=aw.damage;
							cout<<"Ancient Wisp attack "<<aw.damage<<" damage"<<endl;
						}
						if(player.health>player.maxhealth){
							player.health=player.maxhealth;
						}
					} else if(playerchoice=="run"){
						cout<<"Nowhere to run!"<<endl;
					} else if(playerchoice=="win"){
						cout<<"Do you think cheat make games fun?"<<endl;
					}
				}
				system("pause");
				if(player.health<=0){
					system("cls");
					cout<<"\e[1mPlayer\e[0m run out of health (\e[1mPlayer\e[0m Lose)"<<endl;
					isFight=false;
					isDied=true;
					system("pause");
				} else if(aw.health<=0){
					system("cls");
					cout<<"Ancient Wisp run out of health (\e[1mPlayer\e[0m Win)"<<endl;
					isFight=false;
					bad=true;
					system("pause");
				}
			}
		} else if(betraynarrator){
			BetrayNarrator();
			//battle
			bool isFight=true;
			bool isExplosion=true;
			int damage;
			int guard;
			int heal=0.2*player.maxhealth;
			string playerchoice;
			string lodchoice;
			lod.health=player.maxhealth;
			lod.shield=0.5*player.maxhealth;
			lod.damage=2000;
			while(isFight){
				if(weapon.name=="sword"){
					weapon.damage=0.1*player.maxhealth;
					guard=0;
				} else if(weapon.name=="axe"){
					weapon.damage=0.25*player.maxhealth;
					guard=0.25*lod.damage;
				} else if(weapon.name=="bow"){
					weapon.damage=0.4*player.health;
					guard=0.5*lod.damage;
				}
				damage=player.basedamage+weapon.damage;
				
				VSLOD(lod,player);
				if(lod.health<=0.5*player.maxhealth && isExplosion){
					isExplosion=false;
					cout<<"Lord of Death release a big explosion that kill you instantly"<<endl;
					cout<<"Seems like hide is a good option"<<endl;
					cin>>playerchoice;
					if(playerchoice=="attack" || playerchoice=="guard" || playerchoice=="heal" || playerchoice=="run"){
						player.health=0;
						cout<<"You failed to manage what to do"<<endl;
					} else if(playerchoice=="hide"){
						cout<<"You survived the explosion"<<endl;
					}
				} else{
					int random=rand()%10+1;
					if(random>=1 && random<=9){ //90% attack
						lodchoice="attack";
					} else{ //10% guard
						lodchoice="guard";
					}
					cout<<"Lord of Death choose "<<lodchoice<<endl;
					cin>>playerchoice;
					cout<<"\e[1mPlayer\e[0m choose "<<playerchoice<<endl;
					if(playerchoice=="attack" && lodchoice=="attack"){
						player.health-=lod.damage;
						if(lod.shield>0){
							lod.shield-=damage;
							if(lod.shield<0){
								lod.health+=lod.shield;
								lod.shield=0;
							}
						} else{
							lod.health-=damage;
						}
						cout<<"Lord of Death attack "<<lod.damage<<" damage"<<endl;
						cout<<"\e[1mPlayer\e[0m attack "<<damage<<" damage"<<endl;
					} else if(playerchoice=="guard" && lodchoice=="attack"){
						player.health-=guard;
						cout<<"Lord of Death attack "<<lod.damage<<" damage"<<endl;
					} else if(playerchoice=="heal"){
						cout<<"\e[1mPlayer\e[0m healed "<<heal<<" health"<<endl;
						player.health+=heal;
						if(lodchoice=="attack"){
							player.health-=lod.damage;
							cout<<"Lord of Death attack "<<lod.damage<<" damage"<<endl;
						}
						if(player.health>player.maxhealth){
							player.health=player.maxhealth;
						}
					} else if(playerchoice=="run"){
						cout<<"Nowhere to run!"<<endl;
					} else if(playerchoice=="win"){
						cout<<"Do you think cheat make games fun?"<<endl;
					}
				}
				system("pause");
				if(player.health<=0){
					system("cls");
					cout<<"\e[1mPlayer\e[0m run out of health (\e[1mPlayer\e[0m Lose)"<<endl;
					isFight=false;
					isDied=true;
					system("pause");
				} else if(lod.health<=0){
					system("cls");
					cout<<"Lord of Death run out of health (\e[1mPlayer\e[0m Win)"<<endl;
					isFight=false;
					good=true;
					system("pause");
				}
			}
		} else if(trustnobody){
			TrustNobody(player);
			mistrust=true;
		}
		
		if(bad){
			BadEnding();
			epilogue=true;
		} else if(good){
			GoodEnding();
			epilogue=true;
		} else if(mistrust){
			MistrustEnding();
			epilogue=true;
		} else if(isDied){
			DeadEnding();
			epilogue=true;
		}
		
		if(epilogue){
			Epilogue();
			isMainMenu=true;
		}
	}
	return 0;
}
