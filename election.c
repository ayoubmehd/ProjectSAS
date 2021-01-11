#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct President {
	char Nom[20];
	int NbVotes;
};

struct Voteur {
	char CIN[20];
	char Nom[20];
	int Voter;
};

struct President CreatePresident(char *nom, int NbVotes);
struct Voteur CreateVoteur(char *CIN, char *nom);
void MainMenuActions();
//struct President *CalculateResult(int Round);

struct President ListPresident[100];
int PresidentCount = 0;

struct Voteur ListVoteur[100];
int VoteurCount = 0;

int TotalVoteCount = 0;

char MenuItems[10][100];
int MenuItemCount = 0, MenuLevel = 2;



/********************************************
 *											*
 * 			  Helper Functions				*
 *											*
 ********************************************						
*/
void Reset() {
	// Clear Menu
	MenuItemCount = 0;
	// Clear Screen
	system("cls");
}
int GetUserInput() {
	int UserInput;
	printf("Choisire un element et clicker sur (Entrer): ");
	scanf("%d", &UserInput);
	return UserInput;
}
// Afficher un seul President
void PrintPresident(struct President president, int i) {
	
	printf("%d - Nom d'President: %s\n    Nombre des votes: %d\n\n\n", i + 1, president.Nom, president.NbVotes);
	
	
}

// Afficher un seul Voteur
void PrintVoteur(struct Voteur voteur, int i) {
	
	printf("%d - CIN du voteur: %s\n    Nom du voteur: %s\n\n\n", i + 1, voteur.CIN, voteur.Nom);

}

// Afficher tous les Presidents
void PrintPresidents(struct President *ListPresident,int size) {
	
	int i;
	
	for (i = 0; i < size; i++) {
		PrintPresident(ListPresident[i], i);
	}
	
}

//  Afficher yous les Voteurs
void PrintVoteurs(struct Voteur *ListVoteur,int size) {
	
	int i;
	
	for (i = 0; i < size; i++) {
		PrintVoteur(ListVoteur[i], i);
	}
	
}

void GenratePresidentData(struct President *ListPresident, int limit) {
	
	int i;
	
	struct President e;
	
	e = CreatePresident("dsadad", 0);

	for (i = 0; i < limit; i++) {
		ListPresident[i] = e;
	}
	
}

void GenrateVoteurData(struct Voteur *ListVoteur, int limit) {
	
	int i;
	
	struct Voteur v;
	
	v = CreateVoteur("HH32144324", "Aziz");
	
	for (i = 0; i < limit; i++) {
		ListVoteur[i] = v;
	}
	
}

void GenerateData(struct President *ListPresident, struct Voteur *ListVoteur) {
	
	
	PresidentCount = 7;
	VoteurCount = 8;
	
	GenratePresidentData(ListPresident, PresidentCount);
	GenrateVoteurData(ListVoteur, VoteurCount);
	
}


/********************************************
 *											*
 *			President Voteur Logic			*
 *											*
 ********************************************
*/

struct President CreatePresident(char *nom, int NbVotes) {
	struct President e;
	
	strcpy(e.Nom, nom);
	e.NbVotes = NbVotes;
	
	return e;
}

void AddPresident(struct President e) {
	ListPresident[PresidentCount] = e;
	PresidentCount++;
}

void DeletePresident(int PresidentIndex) {
	
	int i;
	
	for (i = PresidentIndex; i < PresidentCount - 1; i++) {
		ListPresident[i] = ListPresident[i + 1];
	}
	PresidentCount--;
}

struct Voteur CreateVoteur(char *CIN, char *nom) {
	
	struct Voteur v;
	
	strcpy(v.CIN, CIN);
	strcpy(v.Nom, nom);
	v.Voter = 0;
	return v;
}

void AddVoteur(struct Voteur v) {
	ListVoteur[VoteurCount] = v;
	VoteurCount++;
}

void CreateMenuItem(char *text) {
	
	strcpy(MenuItems[MenuItemCount], text);
	MenuItemCount++;
	
}

void PrintMenu() {
	
	int i;
	
	for (i = 0; i < MenuItemCount; i++) {
		printf("%d - %s\n", i + 1, MenuItems[i]);
	}
	
	printf("0 - Quitter");
	
	if (MenuLevel > 1) {
		printf("\n-1 - <<== Menu principale");
	}
	
	printf("\n");
}

/********************************************
 *											*
 *				Election Logic				*
 *											*
 ********************************************
*/
void Vote(int VoteurIndex, int PresidentIndex) {
	
	ListPresident[PresidentIndex].NbVotes ++;
	ListVoteur[VoteurIndex].Voter = 1;
	TotalVoteCount++;
	
}

void FirstRound() {
	
	int i;
	float Perc;
	
   	printf("HELL %d\n", TotalVoteCount);
	for (i = 0; i < PresidentCount; i++) {
		if (TotalVoteCount != 0) {
		    Perc =  (float)((float)ListPresident[i].NbVotes / TotalVoteCount) * 100;			
		}
		
		if (Perc < 15) {
		
			printf("%.2f %d - %s exclu\n", Perc, i + 1, ListPresident[i].Nom);
			DeletePresident(i);
		}
		printf("%.2f %d - %s Qualified\n", Perc, i + 1, ListPresident[i].Nom);
	}
//	float Result = 
	
}

void CalculateResult(int Round) {
    if (Round == 1) {
    	FirstRound();
	} else if (Round == 2) {
//	    SecondRound();
	} else {
//		FinalRound();
	}
}


/********************************************
 *											*
 * 				Menu Creation				*
 *											*
 ********************************************
*/
void CreateMainMenu() {
	
	CreateMenuItem("Les Voteurs");
	CreateMenuItem("Les Presidents");
	CreateMenuItem("Resultat d'election");
	
}


void CreatePresidentMenu() {
	
	CreateMenuItem("Ajouter Un President");
	CreateMenuItem("Lister Tous Les President");
	
}

void CreateVoteurMenu() {
	
	CreateMenuItem("Ajouter Un Voteur");
	CreateMenuItem("Lister Tous Les votuers");
	
}

void CreateSingleMenuActions() {
	
	CreateMenuItem("Voter");
	CreateMenuItem("Modifier");
	CreateMenuItem("Supprimer");
	
}


/********************************************
 *											*
 * 				Menu Actions 				*
 *											*
 ********************************************
*/
void SinglePresidentMenuActions(int EIndex) {
	
	int UserInput = GetUserInput();
	
	switch (UserInput) {
		case 1: {
			
			Reset();
			PrintVoteurs(ListVoteur, VoteurCount);
			int UserInput = GetUserInput();
			
			Vote(UserInput - 1, EIndex);
			
			Reset();
			PrintPresidents(ListPresident, PresidentCount);
			break;
		}
		case -1: {
			Reset();
			MainMenuActions();
			break;
		}
	}
}

void ListPresidentMenuActions() {
	
	PrintPresidents(ListPresident, PresidentCount);
	PrintMenu();
	
	int UserInput = GetUserInput();
	
	switch(UserInput) {
		case 0: {
			printf("Bey\n");
			return;
			break;
		}
		case -1: {
			
			Reset();
			MainMenuActions();
			break;
		}
	}
	
	if (UserInput > PresidentCount || UserInput <= 0) return;
	
	Reset();
	PrintPresident(ListPresident[UserInput - 1], UserInput - 1);
	CreateSingleMenuActions();
	PrintMenu();
	SinglePresidentMenuActions(UserInput - 1);
	
}


void PresidentMenuActions() {
		
	CreatePresidentMenu();
	PrintMenu();
	
	int UserInput = GetUserInput();
	
	switch(UserInput) {
		case 1:{
			// Action 1
			
			struct President e;
			
			printf("Entrer le Nom: ");
			scanf("%s", &e.Nom);
			e.NbVotes = 0;
						
			AddPresident(e);
			Reset();
			PrintPresident(e, 0);
			PresidentMenuActions();
			break;
		}
		case 2:{
			// Action 2
			Reset();
			ListPresidentMenuActions();
			break;
		}
		case 3: {
			// Action 3
			break;
		}
		case 0: {
			// Quite
			break;
		}
		case -1: {
			Reset();
			MainMenuActions();
			break;
		}
		default: {
			// Not a valid Chose Try Again
			break;
		}
	}
}
/********** End Presidents ***********/

/********** Start Voteur ***********/
void SingleVoteurMenuActions(int VIndex) {
	
	int UserInput = GetUserInput();
	
	switch (UserInput) {
		case 1: {
			if (ListVoteur[VIndex].Voter == 1) return;
			
			Reset();
			PrintPresidents(ListPresident, PresidentCount);
			int UserInput = GetUserInput();
			
			Vote(VIndex, UserInput - 1);
			
			Reset();
			PrintPresidents(ListPresident, PresidentCount);
			
			MainMenuActions();
			
			break;
		}
		case -1: {
			Reset();
			MainMenuActions();
			break;
		}
	}
}

void ListVoteurMenuActions() {
	
	PrintVoteurs(ListVoteur, VoteurCount);
	PrintMenu();
	int UserInput = GetUserInput();
	
	switch(UserInput) {
		case 0: {
			printf("Bey\n");
			return;
			break;
		}
		case -1: {
			
			Reset();
			MainMenuActions();
			break;
		}
	}
	
	if (UserInput > VoteurCount || UserInput <= 0) return;
	
	Reset();
	PrintVoteur(ListVoteur[UserInput - 1], UserInput - 1);
	CreateSingleMenuActions();
	PrintMenu();
	SingleVoteurMenuActions(UserInput - 1);
}

void VoteurMenuActions() {
		
	CreateVoteurMenu();
	PrintMenu();
	
	int UserInput = GetUserInput();
	
	switch(UserInput) {
		case 1:{
			// Action 1
			
			struct Voteur v;
			
			printf("Entrer le CIN: ");
			scanf("%s", &v.CIN);
			v.Voter = 0;
						
			printf("Entrer le Nom: ");
			scanf("%s", &v.Nom);
			AddVoteur(v);
			Reset();
			PrintVoteur(v, 0);
			VoteurMenuActions();
			
			break;
		}
		case 2:{
			// Action 2
			Reset();
			ListVoteurMenuActions();
			break;
		}
		case 3: {
			// Action 3
			break;
		}
		case 0: {
			// Quite
			printf("Bye\n");
			break;
		}
		case -1: {
			Reset();
			MainMenuActions();
			break;
		}
		default: {
			// Not a valid Chose Try Again
			Reset();
			printf("Choix introuvable\n");
			VoteurMenuActions();
			break;
		}
	}
	
}
/********** End Voteur ***********/

// Main Menu
void MainMenuActions() {
	
	int UserInput;
		
	CreateMainMenu();
	PrintMenu();
	
	UserInput = GetUserInput();
	
//	printf("%d", UserInput);
	
	switch(UserInput) {
		case 1:{
			// Action 1
			Reset();
			VoteurMenuActions();
			break;
		}
		case 2:{
			// Action 2
			Reset();
			PresidentMenuActions();
			break;
		}
		case 3: {
			// Action 3
			Reset();
			CalculateResult(1);
			break;
		}
		case 0: {
			// Quite
			printf("Bye\n");
			break;
		}
		default: {
			// Not a valid Chose Try Again
			Reset();
			printf("Choix introuvable\n");
			MainMenuActions();
			break;
		}
	}
}

int main() {
	
//	struct Presidents ListPresident[100];
//	
//	struct Voteur ListVoteur[100];
//	
//	
	GenerateData(ListPresident, ListVoteur);
//	
//	PrintPresidents(ListPresident, 7);
//	PrintVoteurs(ListVoteur, 8);

	MainMenuActions();

	
	return 0;
	
}

