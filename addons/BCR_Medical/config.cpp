class cfgPatches
{
    class BCR_Medical
    {
        author = "Queen";
        requiredAddons[] =
        {
            "kat_circulation",
            "ace_medical",
			"ace_medical_ai",
			"ace_medical_blood",
			"ace_medical_damage",
			"ace_medical_engine",
			"ace_medical_feedback",
			"ace_medical_gui",
			"ace_medical_statemachine",
			"ace_medical_status",
			"ace_medical_treatment",
			"ace_medical_vitals",
			"ace_dogtags",
			"cba_settings"
        };
        weapons[] =
        {
            "BCR_Coyote_Chew", //Painkiller
            "BCR_Coyote_Chew_Item",
            "BCR_Mysterious_Jar", //Ammonium Carbonate
            "BCR_Mysterious_Jar_Item", 
            "BCR_Fixer", //Nalaxone (works on ALL MEDICATION)
            "BCR_Diffused_Stimpak", //TXA
            "BCR_Super_Stimpak", //EACA 
            "BCR_Hydra", //Norepinephrine
            "BCR_Calmex", //Phenylepinephrine
            "BCR_Buffout", // Nitroglycerin
            //"BCR_Hypo", //Ketamine
        };
        units[] = 
        {
            "BCR_Coyote_Chew_Item",
            "BCR_Mysterious_Jar_Item"
        };

    };
};

class CfgFunctions
{
    class BCR
    {
        class functions
        {
            class treatmentAdvanced_Fixer
            {
                file = "BCR_Medical\functions\fnc_treatmentAdvanced_Fixer.sqf";
            };
            class treatmentAdvanced_FixerLocal
            {
                file = "BCR_Medical\functions\fnc_treatmentAdvanced_FixerLocal.sqf"
            };
        };
    };
};

class CfgWeapons
{
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class BCR_Hydra: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = "[1ST] Hydra";
        picture = "\BCR_Medical\data\ui\hydra_ca.paa";
        model = "";
        descriptionShort = "Raises HR and BP";
        descriptionUse = "";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Fixer: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = " [1ST] Fixer";
        picture = "\BCR_Medical\data\ui\fixer.paa";
        model = "";
        descriptionShort = "Cures all overdoses and addictions";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Diffused_Stimpak: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = " [1ST] Diffused Stimpack";
        picture = "\BCR_Medical\data\ui\diffusedstimpak.paa";
        model = "";
        descriptionShort = "Bandages wounds over time";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Calmex: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = "[1ST] Calmex";
        picture = "\BCR_Medical\data\ui\calmex.paa";
        model = "";
        descriptionShort = "Decreases HR Increases BP";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Buffout: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = "[1ST] Buffout";
        picture = "\BCR_Medical\data\ui\buffout.paa";
        model = "";
        descriptionShort = "Increases HR Decreases BP";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Super_Stimpak: ACE_ItemCore
    {
        scope = 2;
        author = "Queen";
        displayName = "[1ST] Super Stimpak";
        picture = "\BCR_Medical\data\ui\superstimpak.paa";
        models = "";
        ACE_isMedicalItem = 1;
        class itemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 0.2;
        };
    };
    class BCR_Mysterious_Jar_Item: ACE_ItemCore
    {
        scope = 2;
		author="Queen";
		displayName="[1ST] Mysterious Jar Item";

		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0;
		};
    };
    class BCR_Coyote_Chew_Item: ACE_ItemCore
    {
        scope = 1;
        author = "Queen";
        displayName="[1ST] Coyote Chew Bundle";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0;
		};
    }
};

class CfgVehicles
{
    class WeaponHolder_Single_limited_item_F;
    class BCR_Coyote_Chew_Item: WeaponHolder_Single_limited_item_F
	{
		scope = 1;
		scopeCurator=2;
		displayName="[1ST] Coyote Chew Bundle";
		author="Queen";
		vehicleClass="Magazines";
		class TransportItems
		{
			class _xx_BCR_Coyote_Chew
			{
				name="BCR_Coyote_Chew";
				count=1;
			};
		};
	};
};

class CfgMagazines
{
    class CA_Magazine;
    class BCR_Mysterious_Jar: CA_Magazine
    {
        author = "Queen";
        scope=2;
		displayName="[1ST] Mysterious Jar";
		descriptionShort="WAKE UP";
		//model="\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		picture="\BCR_Medical\data\ui\mysteriousjar.paa";
		ammo="";
		count=10;
		initSpeed=0;
		tracersEvery=0;
		lastRoundsTracer=0;
		mass=1;
    };
    class BCR_Coyote_Chew: CA_Magazine
    {
        author = "Queen";
        scope=2;
		displayName="[1ST] Coyote Chew";
		descriptionShort= "Soothes Pain";
		model="";
		picture="\BCR_Medical\data\ui\coyotechew.paa";
		ammo="";
		count=10;
		initSpeed=0;
		tracersEvery=0;
		lastRoundsTracer=0;
		mass=1;
    };
};

class ACE_Medical_Treatment
{
    class Medication
    {
        class Hydra 
        {
            painReduce=0;
			hrIncreaseLow[]={0,0};
			hrIncreaseNormal[]={0,0};
			hrIncreaseHigh[]={0,0};
			timeInSystem=360;
			timeTillMaxEffect=30;
			maxDose=12;
			incompatibleMedication[]={};
			viscosityChange=25;
        };
        class Calmex
        {
            painReduce=0;
			hrIncreaseLow[]={-5,-10};
			hrIncreaseNormal[]={-5,-10};
			hrIncreaseHigh[]={-10,-15};
			timeInSystem=360;
			timeTillMaxEffect=60;
			maxDose=12;
			incompatibleMedication[]={};
			viscosityChange=25;
        };
        class Diffused_Stimpak
        {
            painReduce=0;
			hrIncreaseLow[]={0,0};
			hrIncreaseNormal[]={0,0};
			hrIncreaseHigh[]={0,0};
			timeInSystem=600;
			timeTillMaxEffect=15;
			maxDose=3;
			incompatibleMedication[]={};
			viscosityChange=0;
        };
        class Super_Stimpak
        {
            painReduce=0;
			hrIncreaseLow[]={0,0};
			hrIncreaseNormal[]={0,0};
			hrIncreaseHigh[]={0,0};
			timeInSystem=360;
			timeTillMaxEffect=15;
			maxDose=10;
			incompatibleMedication[]={};
			viscosityChange=0;
        };
        class Mysterious_Jar
        {
            painReduce=0;
			hrIncreaseLow[]={5,10};
			hrIncreaseNormal[]={5,10};
			hrIncreaseHigh[]={10,15};
			timeInSystem=30;
			timeTillMaxEffect=10;
			maxDose=10;
			incompatibleMedication[]={};
			viscosityChange=0;
        };
    };
};

class ACE_Medical_Treatment_Actions
{
    class Morphine;

    class Mysterious_Jar: Morphine
    {
        displayName="Open Mysterious Jar";
		displayNameProgress="Pushing Brotherhood Chem";
		category="bandage";
		treatmentLocations=0;
		allowedSelections[]=
		{
			"Head"
		};
		allowSelfTreatment=1;
		medicRequired=1;
		treatmentTime=5;
		items[]={};
		condition="[_medic, 'BCR_Mysterious_Jar'] call ace_common_fnc_hasMagazine || [_patient,'BCR_Mysterious_Jar'] call ace_common_fnc_hasMagazine";
		patientStateCondition=0;
		callbackSuccess="[_player, _patient, 'Mysterious_Jar'] call aceP_circulation_fnc_treatmentAdvanced_Carbonate";
		animationMedic="AinvPknlMstpSnonWrflDnon_medic1";
		animationMedicProne="AinvPpneMstpSlayWpstDnon_medicOther";
		animationPatient="";
		animationPatientUnconscious="AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[]=
		{
			"ainjppnemstpsnonwrfldnon"
		};
    };
    class Hydra: Mysterious_Jar
    {
        displayName="Push Hydra";
		category="medication";
		allowedSelections[]=
		{
			"Body",
			"LeftArm",
			"RightArm",
			"LeftLeg",
			"RightLeg"
		};
		allowSelfTreatment=1;
		medicRequired="aceP_circulation_vasoDrugs";
		treatmentTime="aceP_circulation_PushTime";
		items[]=
		{
			"BCR_Hydra"
		};
		condition="aceP_circulation_fnc_removeIV";
		patientStateCondition=0;
		callbackSuccess="[_medic,_patient,_bodyPart,_className, _itemUser, _usedItem] call ace_medical_treatment_fnc_medication; [_medic,_patient,-0.3] call aceP_circulation_fnc_alphaAction;";
    };
    class Calmex: Morphine
	{
		category="bandage";
		displayName="Inject Calmex";
		displayNameProgress="Injecting Brotherhood Chem";
		items[]=
		{
			"BCR_Calmex"
		};
		callbackSuccess="[_medic,_patient,_bodyPart,_className, _itemUser, _usedItem] call ace_medical_treatment_fnc_medication; [_medic,_patient,-0.3] call aceP_circulation_fnc_alphaAction;";
	};
    class Diffused_Stimpak: Mysterious_Jar
    {
        displayName="Push Diffused Stimpak";
		category="medication";
		allowedSelections[]=
		{
			"Body",
			"LeftArm",
			"RightArm",
			"LeftLeg",
			"RightLeg"
		};
		allowSelfTreatment=1;
		medicRequired="aceP_circulation_factorDrugs";
		treatmentTime="aceP_circulation_PushTime";
		items[]=
		{
			"BCR_Diffused_Stimpak"
		};
		condition="aceP_circulation_fnc_removeIV";
		patientStateCondition=0;
		callbackSuccess="[_medic,_patient,_bodyPart,_classname, _itemUser, _usedItem] call aceP_circulation_fnc_treatmentAdvanced_TXA; [_medic,_patient,_bodyPart,_className, _itemUser, _usedItem] call ace_medical_treatment_fnc_medication;";
    };

    class Fixer: Mysterious_Jar
    {
        displayName="Push Fixer";
		category="bandage";
		allowedSelections[]=
		{
			"Head"
		};
		allowSelfTreatment=1;
		medicRequired=1;
		treatmentTime=5;
		items[]=
		{
			"BCR_Fixer"
		};
		condition="true";
		patientStateCondition=0;
		callbackSuccess="[_player, _patient, 'Fixer'] call BCR_fnc_treatmentAdvanced_Fixer";

    };
    class Super_Stimpak: Mysterious_Jar
    {
        displayName = "Push Super Stimpak";
        category="medication";
		allowedSelections[]=
		{
			"Body",
			"LeftArm",
			"RightArm",
			"LeftLeg",
			"RightLeg"
		};
		allowSelfTreatment=1;
		medicRequired="aceP_circulation_factorDrugs";
		treatmentTime="aceP_circulation_PushTime";
		items[]=
		{
			"BCR_Super_Stimpak"
		};
		condition="aceP_circulation_fnc_removeIV";
		patientStateCondition=0;
		callbackSuccess="[_medic,_patient,_bodyPart] call aceP_circulation_fnc_treatmentAdvanced_EACA; [_medic,_patient,_bodyPart,_className, _itemUser, _usedItem] call ace_medical_treatment_fnc_medication;";
    };
    class Coyote_Chew: Morphine
    {
        displayName="Administer Coyote Chew";
		category="bandage";
		displayNameProgress="Chewing Coyote Tobacco";
		allowedSelections[]=
		{
			"Head"
		};
		items[]={};
		callbackSuccess="['kat_Painkiller', _medic, _patient, _bodyPart, 'Painkillers'] call aceP_circulation_fnc_removeItemfromMag";
		condition="[_medic, 'kat_Painkiller'] call ace_common_fnc_hasMagazine || [_patient,'kat_Painkiller'] call ace_common_fnc_hasMagazine";
		litter[]={};
		icon="\x\aceP\addons\circulation\ui\icon_painkillers_action.paa";
		animationPatient="";
		animationPatientUnconscious="AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[]=
		{
			"ainjppnemstpsnonwrfldnon"
		};
    };
};

class ACE_Medical_Advanced
{
    class Treatment
    {
        class Medication
        {
            class Mysterious_Jar
            {
                painReduce=0;
				timeInSystem=120;
				maxDose=10;
				inCompatableMedication[]={};
				viscosityChange=2;
				itemClassName="BCR_Mysterious_Jar_Item";
            };
            class BCR_Coyote_Chew
            {
                painReduce=1.1;
				timeInSystem=120;
				maxDose=10;
				inCompatableMedication[]={};
				viscosityChange=2;
				itemClassName="BCR_Coyote_Chew_Item";
            };
        };

    };
};
/*
class Extended_PostInit_EventHandlers
{
	class BCR_Medical
	{
		init="call compile preProcessFileLineNumbers '\BCR_Medical\XEH_postInit.sqf'";
	};
};

*/