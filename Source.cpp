#include<string>
#include<fstream>
#include<iostream>
#include<Windows.h>
#include<regex>
using namespace std;

regex PERFECTIVEGERUND("(ав|авши|авшись|яв|явши|явшись|ив|ивши|ившись|ыв|ывши|ывшись)$");
regex REFLEXIVE("(ся|сь)$");
regex NOUN("(а|ев|ов|ие|ье|е|иями|ями|ами|еи|ии|и|ией|ей|ой|ий|й|иям|ям|ием|ем|ам|ом|о|у|ах|иях|ях|ы|ь|ию|ью|ю|ия|ья|я)$");
regex VERB("(ила|ла|ена|ейте|уйте|ите|или|ыли|ей|уй|ил|ыл|им|ым|ен|ило|ыло|ено|ят|ует|уют|ит|ыт|ены|ить|ыть|ишь|ую|ю|ала|ана|аете|айте|али|ай|ал|аем|ан|ало|ано|ает|ают|аны|ать|аешь|анно|яла|яна|яете|яйте|яли|яй|ял|яем|ян|яло|яно|яет|яют|яны|ять|яешь|янно)$");
regex ADJECTIVAL("(ее|ие|ые|ое|ими|ыми|ей|ий|ый|ой|ем|им|ым|ом|его|ого|ему|ому|их|ых|ую|юю|ая|яя|ою|ею|ившее|ившие|ившые|ившое|ившими|ившыми|ившей|ивший|ившый|ившой|ившем|ившим|ившым|ившом|ившего|ившого|ившему|ившому|ивших|ившых|ившую|ившюю|ившая|ившяя|ившою|ившею|ывшее|ывшие|ывшые|ывшое|ывшими|ывшыми|ывшей|ывший|ывшый|ывшой|ывшем|ывшим|ывшым|ывшом|ывшего|ывшого|ывшему|ывшому|ывших|ывшых|ывшую|ывшюю|ывшая|ывшяя|ывшою|ывшею|ующее|ующие|ующые|ующое|ующими|ующыми|ующей|ующий|ующый|ующой|ующем|ующим|ующым|ующом|ующего|ующого|ующему|ующому|ующих|ующых|ующую|ующюю|ующая|ующяя|ующою|ующею|аемее|аемие|аемые|аемое|аемими|аемыми|аемей|аемий|аемый|аемой|аемем|аемим|аемым|аемом|аемего|аемого|аемему|аемому|аемих|аемых|аемую|аемюю|аемая|аемяя|аемою|аемею|аннее|анние|анные|анное|анними|анными|анней|анний|анный|анной|аннем|анним|анным|анном|аннего|анного|аннему|анному|анних|анных|анную|аннюю|анная|анняя|анною|аннею|авшее|авшие|авшые|авшое|авшими|авшыми|авшей|авший|авшый|авшой|авшем|авшим|авшым|авшом|авшего|авшого|авшему|авшому|авших|авшых|авшую|авшюю|авшая|авшяя|авшою|авшею|ающее|ающие|ающые|ающое|ающими|ающыми|ающей|ающий|ающый|ающой|ающем|ающим|ающым|ающом|ающего|ающого|ающему|ающому|ающих|ающых|ающую|ающюю|ающая|ающяя|ающою|ающею|ащее|ащие|ащые|ащое|ащими|ащыми|ащей|ащий|ащый|ащой|ащем|ащим|ащым|ащом|ащего|ащого|ащему|ащому|ащих|ащых|ащую|ащюю|ащая|ащяя|ащою|ащею|яемее|яемие|яемые|яемое|яемими|яемыми|яемей|яемий|яемый|яемой|яемем|яемим|яемым|яемом|яемего|яемого|яемему|яемому|яемих|яемых|яемую|яемюю|яемая|яемяя|яемою|яемею|яннее|янние|янные|янное|янними|янными|янней|янний|янный|янной|яннем|янним|янным|янном|яннего|янного|яннему|янному|янних|янных|янную|яннюю|янная|янняя|янною|яннею|явшее|явшие|явшые|явшое|явшими|явшыми|явшей|явший|явшый|явшой|явшем|явшим|явшым|явшом|явшего|явшого|явшему|явшому|явших|явшых|явшую|явшюю|явшая|явшяя|явшою|явшею|яющее|яющие|яющые|яющое|яющими|яющыми|яющей|яющий|яющый|яющой|яющем|яющим|яющым|яющом|яющего|яющого|яющему|яющому|яющих|яющых|яющую|яющюю|яющая|яющяя|яющою|яющею|ящее|ящие|ящые|ящое|ящими|ящыми|ящей|ящий|ящый|ящой|ящем|ящим|ящым|ящом|ящего|ящого|ящему|ящому|ящих|ящых|ящую|ящюю|ящая|ящяя|ящою|ящею)$");
char vowels[] = {'а', 'о','у','ы','э','я','е','ю','и','А', 'О','У','Ы','Э','Я','Е','Ю','И'};
char consonants[]={'б','в','г','д','ж','з','й','к','л','м','н','п','р','с','т','ф','х','ц','ч','ш','щ','ъ','ь'};
regex DERIVATIONAL("(ост|ость)$");
regex SUPERLATIVE("(ейш|ейше)$");
regex NN("(нн)$");
regex SOFTSIGN("(ь)$");
regex AND("(и)$");
regex PREFIXES("^(без|бес|в|во|воз|вос|возо|вз|вс|вы|до|за|из|ис|изо|на|наи|недо|над|надо|не|низ|нис|низо|о|об|обо|обез|обес|от|ото|па|пра|по|под|подо|пере|пре|пред|предо|при|про|раз|рас|разо|с|со|су|через|черес|чрез)");

string InputFileName(){
	string fileName;
	for (;;)
	{
		cout << "Имя файла:     ";
		cin >> fileName;
		ifstream fin(fileName);
		if(!fin.is_open())
			cout << "Ошибка!" << endl;
		else
		{
			fin.close();
			break;
		}
	}
	return fileName;
}

bool Repeating(){
	string s;
	for (;;)
	{
		cout << "Желаете повторить? (да/нет):     ";
		cin >> s;
		if (s == "да")
			return true;
		else
			if (s == "нет")
				return false;
			else
				cout << "Ошибка!" << endl;
	}
}

bool CreateOutputFile(){
	ifstream fout("d:\output.txt");
	if(!fout.is_open())
	{
		cout << "Ошибка создания выходного файла!" << endl;
		return false;
	}
	else
	{
		fout.close();
		return true;
	}
}

string RVFinding(const string &word){
	int position=-1;
	bool check = false;
	for (int i=0; i<word.length(); i++){
		for(int j=0; j<sizeof(vowels)/sizeof(vowels[0]); j++)
			if(word[i]==vowels[j]){
				position = i;
				check = true;
				break;
			}
		if(check)
			break;
	}
	if((position == -1) || (position == word.length()-1))
		return "";
	else{
		string rv="";
		for (int i=position+1; i<word.length(); i++)
			rv+=word[i];
		return rv;
	}
}

void Step1(string rv, string &word){
	if(regex_search(rv, PERFECTIVEGERUND))
		word = regex_replace(word,PERFECTIVEGERUND,"");
	else{
		word = regex_replace(word,REFLEXIVE,"");
		if(regex_search(rv, ADJECTIVAL))
			word = regex_replace(word,ADJECTIVAL,"");
		else
			if(regex_search(rv, VERB))
				word = regex_replace(word,VERB,"");
			else
				if(regex_search(rv, NOUN))
					word = regex_replace(word,NOUN,"");
	}
}

void Step2(string rv, string &word){
	word = regex_replace(word,AND,"");
}

void Step3(string &word, string r2){
	if(regex_search(r2, DERIVATIONAL))
		word = regex_replace(word,DERIVATIONAL,"");
}

void Step4(string rv, string &word){
	if(regex_search(rv, NN))
		word = regex_replace(word,NN,"н");
	else
		if(regex_search(rv, SUPERLATIVE)){
			word = regex_replace(word,SUPERLATIVE,"");
			if(regex_search(rv, NN))
				word = regex_replace(word,NN,"н");
		}
		else
			if(regex_search(rv, SOFTSIGN))
				word = regex_replace(word,SOFTSIGN,"");
}

string R1Finding(const string &word){
	string r1;
	bool check = false;
	int pos=-1;
	if(word.length()<2)
		return "";
	for(int i=0; i<word.length()-1; i++){
		for(int j=0; j<sizeof(vowels)/sizeof(vowels[0]); j++)
		 	if(word[i]==vowels[j]){
		 		check=true;
		 		break;
			 }
		if(check){
			for(int k=0;k<sizeof(consonants)/sizeof(consonants[0]); k++){
				if(word[i+1]==consonants[k]){
					pos = i+1;
					break;
				}

			}
		}
		if(pos != -1)
			break;
	}
	if(pos==-1)
		return "";
	for(int i=pos+1; i<word.length(); i++)
		r1+=word[i];
	return r1;
}

string RootFinding(string word){
	string rv = RVFinding(word);
	string r1 = R1Finding(word);
	string r2 = R1Finding(r1);
	if(rv=="")
		return "";
	Step1(rv, word);
	Step2(rv, word);
	Step3(word, r2);
	Step4(rv, word);
	return word;
}

void DeletePrefixes(string &word){
	word = regex_replace(word,PREFIXES,"");
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string fileName = InputFileName();
	for(;;)
	{
		if(!CreateOutputFile())
			break;
		string word;
		cout<<"Слово для поиска:   ";
		cin>>word;
		replace(word.begin(), word.end(), 'ё', 'е');
		string root = RootFinding(word);
		DeletePrefixes(root);
		bool check = false;
		if(root==""){
			cout<<"Ошибка. Неверное слово"<<endl;
			check = true;
		}
		if(!check){
			ofstream fout("d:\output.txt");
			ifstream fin(fileName);
			string str, wordFile;
			while(!fin.eof()){
				getline(fin, str);
				wordFile="";
				str+=" ";
				for(int i=0; i<str.length(); i++){
					if((str[i] != ' ') && (str[i] != '.') && (str[i] != ',') && (str[i] != ':') && (str[i] != ';') && (str[i] != '!') && (str[i] != '?')){
						wordFile+=str[i];
					}
					else{
						string rootFile = RootFinding(wordFile);
						DeletePrefixes(rootFile);
						if(rootFile == root){
							fout << wordFile<< endl;
						}
						wordFile="";
					}
				}
			}
			fin.close();
			fout.close();
		}
		if (!Repeating())
			break;
	}
	return 0;
}
