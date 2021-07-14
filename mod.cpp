#include "mod.h"

extern "C"
{
	const char* genericLines[] = { "DE0", 0, "JK0", "CE0", 0, "GSOL0" };

	//Matrix of idle animation mouths
	//NOTE: For acts that aren't visited normally (Eg. Tails WV1) the usual line is repeated, so there are faces included for them too.
	//Chao Garden code isn't implemented so they all use the same string.
	const char* sonicLines[43][6] = {
		{0},														//Hedgehog Hammer
		{"DESDE0", "DSE0", "DSE0"},									//Emerald Coast
		{"DEDE0", "DC0", "ZZED0"},									//Windy Valley
		{"DEDSD0", "CE0", "CE0"},									//Twinkle Park
		{"DCEP0", "PEDSE0", "ECEDEE0"},								//Speed Highway
		{"CE0", "IDSEED0", "IDSEED0"},								//Red Mountain
		{"IZDSEDE0", "ICE0", "DC0"},								//Sky Deck
		{"EC0", "DE0", "DE0"},										//Lost World
		{"DE0", "EDSE0", "PDE0"},									//Icecap
		{"PDE0", "DEIZCE0", "DEIZCE0", "DEIZCE0"},					//Casinopolis
		{"EC0", "DE0", "DED0"},										//Final Egg
		{0},														//11
		{0},														//Hot Shelter
		{0},														//13
		{0},														//14
		{"DCE0"},													//Chaos 0
		{0},														//Chaos 2
		{"PECD0"},													//Chaos 4
		{"SDED0"},													//Chaos 6
		{"DEPESC0"},												//Perfect Chaos
		{"CE0"},													//Egg Hornet
		{0},														//Egg Walker
		{"DELDSE0"},												//Egg Viper
		{0},														//ZERO
		{0},														//E-101
		{0},														//E-101mkII
		{"DEC0", "DED0", "DED0", "DSEDE0", "ZPEC0", "DESDSE0"},		//Station Square
		{0},														//27
		{0},														//28
		{"ECE0", "ECE0", "ECE0", "ECE0", "ECE0", "ECE0"},			//Egg Carrier Ext
		{0},														//30
		{0},														//31
		{"DESC0", "DESC0", "DESC0", "DESC0", "DESC0", "DESC0"},		//Egg Carrier Int
		{"DED0", "PDESD0", "DED0", "DESD0"},						//Mystic Ruins
		{"SEE0", "SEE0", "SEE0"},									//Mystic Ruins (Past)
		{0},														//Twinkle Circuit
		{0},														//Sky Chase 1
		{0},														//Sky Chase 2
		{"IBDBEB0"},												//Sand Hill
		{"DED0"},									//SS Chao
		{"DED0"},									//EC Chao
		{"DED0"},									//MR Chao
		{0}															//Chao Stadium
	};

	const char* tailsLines[43][6] = {
		{0},														//Hedgehog Hammer
		{0},														//Emerald Coast
		{"DEC0", "DEC0", "DEC0"},									//Windy Valley
		{0},														//Twinkle Park
		{"DSE0", "DSE0", "DSE0"},									//Speed Highway
		{0},														//Red Mountain
		{"DILCSE0", "DILCSE0", "DILCSE0"},							//Sky Deck
		{0},														//Lost World
		{"G0","G0", "G0"},											//Icecap
		{0},														//Casinopolis
		{0},														//Final Egg
		{0},														//11
		{0},														//Hot Shelter
		{0},														//13
		{0},														//14
		{0},														//Chaos 0
		{0},														//Chaos 2
		{"ESED0"},													//Chaos 4
		{0},														//Chaos 6
		{0},														//Perfect Chaos
		{"CD0"},													//Egg Hornet
		{"DSESC0"},													//Egg Walker
		{0},														//Egg Viper
		{0},														//ZERO
		{0},														//E-101
		{0},														//E-101mkII
		{"DE0", "DSE0", "DSE0", "DPE0", "DEP0", "SVVDESE0"},		//Station Square
		{0},														//27
		{0},														//28
		{"G0","G0", "G0", "G0", "G0", "G0"},						//Egg Carrier Ext
		{0},														//30
		{0},														//31
		{"DESD0", "DESD0", "DESD0", "DESD0", "DESD0", "DESD0"},		//Egg Carrier Int
		{"DECSDSE0", "DECSDSE0", "DSENL0", "DESC0"},				//Mystic Ruins
		{"DE0", "DE0", "DE0"},										//Mystic Ruins (Past)
		{0},														//Twinkle Circuit
		{0},														//Sky Chase 1
		{0},														//Sky Chase 2
		{"DESE0"},													//Sand Hill
		{"DED0"},									//SS Chao
		{"DED0"},									//EC Chao
		{"DED0"},									//MR Chao
		{0}															//Chao Stadium
	};

	const char* knucklesLines[43][6] = {
		{0},														//Hedgehog Hammer
		{0},														//Emerald Coast
		{0},														//Windy Valley
		{0},														//Twinkle Park
		{"DSCDESD0", "DSCDESD0", "DSCDESD0"},						//Speed Highway
		{"DSE0", "DSE0", "DSE0"},									//Red Mountain
		{"ESLCE0", "ESLCE0", "ESLCE0"},								//Sky Deck
		{"DSEED0", "DSEED0", "DSEED0"},								//Lost World
		{0},														//Icecap
		{"DE0", "DE0", "DE0"},										//Casinopolis
		{0},														//Final Egg
		{0},														//11
		{0},														//Hot Shelter
		{0},														//13
		{0},														//14
		{0},														//Chaos 0
		{"DLC0"},													//Chaos 2
		{"ESED0"},													//Chaos 4
		{"DLC0", "DLC0"},											//Chaos 6
		{0},														//Perfect Chaos
		{0},														//Egg Hornet
		{0},														//Egg Walker
		{0},														//Egg Viper
		{0},														//ZERO
		{0},														//E-101
		{0},														//E-101mkII
		{"DSEE0", "DSE0", "DSE0", "DPDE0", "PELCE0", "DSE0"},		//Station Square
		{0},														//27
		{0},														//28
		{"DSCE0","DSCE0", "DSCE0", "DSCE0", "DSCE0", "DSCE0"},		//Egg Carrier Ext
		{0},														//30
		{0},														//31
		{"DE0", "DE0", "DE0", "DE0", "DE0", "DE0"},					//Egg Carrier Int
		{"DESDCE0", "DECSD0", "DSLDESD0", "DEZSC0"},				//Mystic Ruins
		{"DE0", "DE0", "PS0"},										//Mystic Ruins (Past)
		{0},														//Twinkle Circuit
		{0},														//Sky Chase 1
		{0},														//Sky Chase 2
		{0},														//Sand Hill
		{"DED0"},									//SS Chao
		{"DED0"},									//EC Chao
		{"DED0"},									//MR Chao
		{0}															//Chao Stadium
	};

	const char* amyLines[43][6] = {
		{0},														//Hedgehog Hammer
		{0},														//Emerald Coast
		{0},														//Windy Valley
		{"DED0", "DED0", "DED0"},									//Twinkle Park
		{0},														//Speed Highway
		{0},														//Red Mountain
		{0},														//Sky Deck
		{0},														//Lost World
		{0},														//Icecap
		{0},														//Casinopolis
		{"DEBED0", "DEBED0", "DEBED0"},								//Final Egg
		{0},														//11
		{"CSE0", "PDED0", "PDED0"},									//Hot Shelter
		{0},														//13
		{0},														//14
		{0},														//Chaos 0
		{0},														//Chaos 2
		{0},														//Chaos 4
		{0},														//Chaos 6
		{0},														//Perfect Chaos
		{0},														//Egg Hornet
		{0},														//Egg Walker
		{0},														//Egg Viper
		{"DE0"},													//ZERO
		{0},														//E-101
		{0},														//E-101mkII
		{"DSE0", "DSED0", "DSED0", "EPDED0", "PECE0", "DSE0"},		//Station Square
		{0},														//27
		{0},														//28
		{"DSCDSDE0","DSCDSDE0", "DSCDSDE0", "DSCDSDE0", "DSCDSDE0", "DSCDSDE0"},		//Egg Carrier Ext
		{0},														//30
		{0},														//31
		{"DSCD0", "DSCD0", "DSCD0", "DSCD0", "DSCD0", "DSCD0"},		//Egg Carrier Int
		{"DEDSE0", "DECSD0", "DSbbb0", "DEZC0"},					//Mystic Ruins
		{"ELDE0", "ELDE0", "ELDE0"},								//Mystic Ruins (Past)
		{0},														//Twinkle Circuit
		{0},														//Sky Chase 1
		{0},														//Sky Chase 2
		{0},														//Sand Hill
		{"DEDED0"},					//SS Chao
		{"DEDED0"},					//EC Chao
		{"DEDED0"},					//MR Chao
		{0}
	};

	const char* stageSpecificLines[7][43][6];

	bool isUnderwater = false;
	facewk* face = 0;
	float eyeheight = 0;
	NJS_VECTOR eyelevel = { 0, 0, 0 };
	playerwk* playerwkptr = 0;

	int faceIdle();
	void faceDeath();
	void faceDrown();
	void faceSonicWin();
	void faceTailsWin();
	void underwaterMouth();
	void fixedFace(int old, int __new, int frame, int nbFrame);
	bool testEyeLevel();
	bool isBigTheCat();
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Initalize stage specific lines list
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 43; j++) {
				for (int k = 0; k < 6; k++) {
					switch (i) {
					case Characters_Sonic:
						stageSpecificLines[i][j][k] = sonicLines[j][k];
						break;
					case Characters_Tails:
						stageSpecificLines[i][j][k] = tailsLines[j][k];
						break;
					case Characters_Knuckles:
						stageSpecificLines[i][j][k] = knucklesLines[j][k];
						break;
					case Characters_Amy:
						stageSpecificLines[i][j][k] = amyLines[j][k];
						break;
					default:
						stageSpecificLines[i][j][k] = 0;
						break;
					}
				}
			}
		}

		WriteCall((int*)0x44241C, faceIdle);
		WriteCall((int*)0x450785, faceDeath);
		WriteJump((int*)0x446BE5, faceDrown);
		WriteCall((int*)0x4961EF, faceSonicWin);
		WriteCall((int*)0x45C321, faceTailsWin);
	}

	__declspec(dllexport) void __cdecl OnFrame() {
		if (PlayerPtrs[0] != nullptr) {
			playerwkptr = (playerwk*)CharObj2Ptrs[0];
			underwaterMouth();

			//Blinking animation
			if ((playerwkptr->waittimer % 700 == 0) && !EV_CheckCansel()
				&& (playerwkptr->waittimer != 0) && !isBigTheCat()) {
				EV_SetFace(PlayerPtrs[0], "B0");
			}
		}
	}

	//Stage Clear (Sonic)
	void faceSonicWin() {
		PlayerLookingAtDestructor(0);
		fixedFace(18, 18, 1, 90000);
	}

	//Stage Clear (Tails)
	void faceTailsWin() {
		PlayerLookingAtDestructor(0);
		fixedFace(17, 17, 1, 90000);
	}

	//Avoid out of range crash as Big. He has 6 useless "faces" (Weird ear flopping).
	bool isBigTheCat() {
		return GetCharacterID(0) == Characters_Big;
	}

	//Holding breath when underwater
	void underwaterMouth() {
		int shadowattr = (int)&playerwkptr->shadow.Attr_top;
		shadowattr = shadowattr + 2;

		if (*(unsigned int*)shadowattr & ColFlags_Water && testEyeLevel() && !isBigTheCat())
		{
			if (isUnderwater == false) {
				fixedFace(15, 15, 1, 30000);
				isUnderwater = true;
			} else {
				if (!face->nbFrame) {
					fixedFace(15, 15, 1, 30000);
				}
			}
		} else {
			if (isUnderwater) {
				EV_ClrFace(PlayerPtrs[0]);
				isUnderwater = false;
			}
		}
	}

	//Check the player is fully submerged in water.
	bool testEyeLevel() {
		eyeheight = playerwkptr->p.eyes_height;
		int eyeaddress = (int)&playerwkptr->p.eyes_height;
		eyeaddress = eyeaddress + 6;
		eyelevel.z = 0.0;
		eyelevel.x = 0.0;
		eyelevel.y = *(float*)eyeaddress + 1.5f;
		PConvertVector_G2N((taskwk*)PlayerPtrs[0]->Data1, &eyelevel);
		njAddVector(&eyelevel, &PlayerPtrs[0]->Data1->Position);


		int shadaddress = (int)&playerwkptr->shadow.y_top;
		shadaddress = shadaddress + 2;
		if ((*(float*)shadaddress) > eyelevel.y) {
			return true;
		}
		else {
			return false;
		}
	}

	//Dying from 0 Rings
	void faceDeath() {
		KillHimP(0);
		if (!isBigTheCat()) {
			fixedFace(6, 6, 1, 59); //9 will make it look more like vanilla but with the added death face afterwards
			EV_SetFace(PlayerPtrs[0], "UVVVVVVVVVVVVVVVVVVVV0");
		}
	}

	//Drowning
	void faceDrown() {
		StopMusic();
		if (!isBigTheCat()) {
			fixedFace(10, 10, 1, 80);
			EV_SetFace(PlayerPtrs[0], "UVVVVVVVVVVVVVVVVVVVV0");
		}
	}

	//Idle Lines
	int faceIdle() {
		int randresult = rand();
		if (randresult * 0.000030517578 >= 0.5f && stageSpecificLines[GetCharacterID(0)][CurrentLevel][CurrentAct] != 0) {
			//Stage Specific Line
			EV_SetFace(PlayerPtrs[0], stageSpecificLines[GetCharacterID(0)][CurrentLevel][CurrentAct]);
		} else {
			//Generics
			if (!isBigTheCat()) {
				EV_SetFace(PlayerPtrs[0], genericLines[GetCharacterID(0)]);
			}
		}
		return randresult;
	}

	void fixedFace(int old, int __new, int frame, int nbFrame) {
		task* player = (task*)PlayerPtrs[0];
		int faceaddress = (int)&player->twp->ewp->face;
		faceaddress = faceaddress + 8; //Adjust address because this is 8 bytes off
		face = (facewk*)faceaddress;
		face->old = old;
		face->__new = __new;
		face->frame = frame;
		face->nbFrame = nbFrame;
	}
}