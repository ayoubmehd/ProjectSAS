#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Electeur {
	char Nom[20];
	int NbVotes;
};

struct Voteur {
	char CIN[20];
	char Nom[20];
	int Voter;
};

struct Electeur CreateElecteur(char *nom, int NbVotes);
struct Voteur CreateVoteur(char *CIN, char *nom);

struct Electeur ListElecteur[100];
int ElecteurCount = 0;

struct Voteur ListVoteur[100];
int VoteurCount = 0;

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
// Afficher un seul Electeur
void PrintElecteur(struct Electeur electeur, int i) {
	
	printf("%d - Nom d'electeur: %s\n    Nombre des votes: %d\n\n\n", i + 1, electeur.Nom, electeur.NbVotes);
	
	
}

// Afficher un seul Voteur
void PrintVoteur(struct Voteur voteur, int i) {
	
	printf("%d - CIN du voteur: %s\n    Nom du voteur: %s\n\n\n", i + 1, voteur.CIN, voteur.Nom);

}

// Afficher tous les Electeurs
void PrintElecteurs(struct Electeur *ListElecteur,int size) {
	
	int i;
	
	for (i = 0; i < size; i++) {
		PrintElecteur(ListElecteur[i], i);
	}
	
}

//  Afficher yous les Voteurs
void PrintVoteurs(struct Voteur *ListVoteur,int size) {
	
	int i;
	
	for (i = 0; i < size; i++) {
		PrintVoteur(ListVoteur[i], i);
	}
	
}

void GenrateElecteurData(struct Electeur *ListElecteur, int limit) {
	
	int i;
	
	struct Electeur e;
	
	e = CreateElecteur("dsadad", 0);

	for (i = 0; i < limit; i++) {
		ListElecteur[i] = e;
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

void GenerateData(struct Electeur *ListElecteur, struct Voteur *ListVoteur) {
	
	
	ElecteurCount = 7;
	VoteurCount = 8;
	
	GenrateElecteurData(ListElecteur, ElecteurCount);
	GenrateVoteurData(ListVoteur, VoteurCount);
	
}


/********************************************
 *											*
 *			Electeur Voteur Logic			*
 *											*
 ********************************************
*/

struct Electeur CreateElecteur(char *nom, int NbVotes) {
	struct Electeur e;
	
	strcpy(e.Nom, nom);
	e.NbVotes = NbVotes;
	
	return e;
}

void AddElecteur(struct Electeur e) {
	ListElecteur[ElecteurCount] = e;
	ElecteurCount++;
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
		printf("\n-1 - << Precedent");
	}
	
	printf("\n");
}

/********************************************
 *											*
 *				Election Logic				*
 *											*
 ********************************************
*/



/********************************************
 *											*
 * 				Menu Creation				*
 *											*
 ********************************************
*/
void CreateMainMenu() {
	
	CreateMenuItem("Les Voteurs");
	CreateMenuItem("Les Electeurs");
	CreateMenuItem("Resultat d'election");
	
}


void CreateElecteurMenu() {
	
	CreateMenuItem("Ajouter Un Electeur");
	CreateMenuItem("Lister Tous Les Electeur");
	
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
void SingleElecteurMenuActions() {
	Reset();
	CreateSingleMenuActions();
	PrintMenu();
	
	int UserInput = GetUserInput();
	
	switch (UserInput) {
		case 1: {
			
			break;
		}
	}
}

void ListElecteurMenuActions() {
		
	
	PrintElecteurs(ListElecteur, ElecteurCount);
	int UserInput = GetUserInput();
}


void ElecteurMenuActions() {
		
	CreateElecteurMenu();
	PrintMenu();
	
	int UserInput = GetUserInput();
	
	switch(UserInput) {
		case 1:{
			// Action 1
			break;
		}
		case 2:{
			// Action 2
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
//			MainMenuActions();
			break;
		}
		default: {
			// Not a valid Chose Try Again
			break;
		}
	}
}

/********** End Electeur ***********/

/********** Start Voteur ***********/
void SingleVoteurMenuActions(int VIndex) {
	
	int UserInput = GetUserInput();
	
	switch (UserInput) {
		case 1: {
			if (ListVoteur[VIndex].Voter == 1) return;
			
			Reset();
			PrintElecteurs(ListElecteur, ElecteurCount);
			int UserInput = GetUserInput();
			
			ListElecteur[UserInput - 1].NbVotes++;
			ListVoteur[VIndex].Voter = 1;
			
			Reset();
			PrintElecteurs(ListElecteur, ElecteurCount);
			
			break;
		}
	}
}

void ListVoteurMenuActions() {
	
	PrintVoteurs(ListVoteur, VoteurCount);
	int UserInput = GetUserInput();
	
	if (UserInput > VoteurCount || UserInput < 0) return;
	
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
			ElecteurMenuActions();
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
	
//	struct Electeur ListElecteur[100];
//	
//	struct Voteur ListVoteur[100];
//	
//	
	GenerateData(ListElecteur, ListVoteur);
//	
//	PrintElecteurs(ListElecteur, 7);
//	PrintVoteurs(ListVoteur, 8);

	MainMenuActions();

	
	return 0;
	
}

