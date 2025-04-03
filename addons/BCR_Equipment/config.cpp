#define MAG_XX(a,b) class _xx_##a {magazine = a; count = b;}
#define WEAP_XX(a,b) class _xx_##a {weapon = a; count = b;}
#define ITEM_XX(a,b) class _xx_##a {name = a; count = b;}


class CfgPatches
{
	class BCR_Equipment
	{
		author="Queen"; 
        requiredAddons[]=
        {
            "fallout_uniform_02",
			"am_firearms",
			"PSC_Equipment"
        };
        requiredVersion= 0.1;
        units[]=
		{
			"BCR_MinigunBackpack_B",
			"BCR_ANPRC76_B",
			"BCR_ANPRC23_B",
			"BCR_ANPRC2141_B",
			"BCR_Radio_Backpack_1",
			"BCR_Trooper_CLUB_U",
			"BCR_Trooper_DIAMOND_U",
			"BCR_Trooper_HEART_U",
			"BCR_Trooper_SPADE_U",
			"BCR_Trooper_CLUB_MED_U",
			"BCR_Trooper_DIAMOND_MED_U",
			"BCR_Trooper_HEART_MED_U",
			"BCR_Trooper_SPADE_MED_U",
			"BCR_Trooper_CLUB_UN",
			"BCR_Trooper_DIAMOND_UN",
			"BCR_Trooper_HEART_UN",
			"BCR_Trooper_SPADE_UN",
			"BCR_Trooper_CLUB_MED_UN",
			"BCR_Trooper_DIAMOND_MED_UN",
			"BCR_Trooper_HEART_MED_UN",
			"BCR_Trooper_SPADE_MED_UN"
		};
        weapons[]= 
        {
			"BCR_Rockwell_Launcher",
			"BCR_Trooper_HELM_H",
			"BCR_Trooper_HELM_MED_H",
			"BCR_HuntingShotgun"
        };
	};
};

class Components;
class SensorTemplateVisual;

class CfgFunctions
{
	class BCR
	{
		class functions
		{
			class radialPAK
			{
				file = "BCR_Equipment\data\functions\fn_radialPAK.sqf";
			};
		};
	};
};

class CfgAmmo
{
	class B_12Gauge_Slug;
	class Sh_125mm_APFSDS;
	class M_Titan_AT;
	class BCR_Ammo_AT_penetrator: Sh_125mm_APFSDS
	{
		caliber=6.6666698;
		warheadName="HEAT";
		typicalSpeed=1000;
		deflecting=0;
		deflectionDirDistribution=0;
		penetrationDirDistribution=0;
		timeToLive=0.0099999998;
		simulationStep=0.00050000002;
		airFriction=-0.5;
		whistleOnFire=0;
		whistleDist=0;
		submunitionConeType[]=
		{
			"randomcenter",
			30
		};
		// submunitionAmmo="rhs_ammo_spall";
		// submunitionDirectionType="SubmunitionModelDirection";
		// submunitionInitialOffset[]={0,0,-0.40000001};
		// submunitionParentSpeedCoef=0;
		// submunitionInitSpeed=200;
		deleteParentWhenTriggered=0;
		triggerTime=0.003;
		model="\A3\Weapons_f\empty";
		SoundSetExplosion[]=
		{
			"Silence_SoundSet"
		};
	};
	class BCR_Rockwell_Ammo_AT_penetrator: BCR_Ammo_AT_penetrator
	{
		warheadName="TandemHEAT";
		caliber=50.666698;
	};	

	class BCR_Rockwell_Ammo_AT: M_Titan_AT
	{
		afMax=200;
		aiAmmoUsageFlags="128 + 512";
		audibleFire=32;
		caliber=1;
		warheadName="TandemHEAT";
		submunitionAmmo="BCR_Ammo_AT_penetrator";
		submunitionDirectionType="SubmunitionModelDirection";
		submunitionInitialOffset[]={0,0,-0.1};
		submunitionParentSpeedCoef=0;
		submunitionInitSpeed=1053;
		triggerOnImpact=1;
        manualControl=1;
        maxControlRange=5000;
		deleteParentWhenTriggered=0;
        model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at";
		hit=350;
		indirectHit=40;
		indirectHitRange=4;
		explosive=0.64999998;
		flightProfiles[]=
		{
			"Direct",
			"TopDown",
			"Cruise"
		};
		class Direct
		{
		};
		class TopDown
		{
			ascendHeight=160;
			descendDistance=200;
			minDistance=150;
			ascendAngle=45;
		};
		class Cruise
		{
			preferredFlightAltitude=60;
			lockDistanceToTarget=1000;
		};
		irLock=1;
		laserLock=1;
		nvLock=0;
		airLock=1;
		autoSeekTarget=0;
		allowAgainstInfantry=0;
		airFriction=0.2;
		sideAirFriction=0.34999999;
		trackOversteer=1.4;
		trackLead=1;
		maxSpeed=460;
		maneuvrability=32;
		fuseDistance=30;
		thrust=75;
		thrustTime=5.1999998;
		initTime=0;
		timeToLive=60;
		whistleDist=4;
		deflecting=0;
		simulationStep=0.001;
		cmImmunity=0.89999998;
		cost=1000;
		effectsMissile="missile3";
		effectsMissileInit="RocketBackEffectsRPG";
		effectsSmoke="SmokeShellWhite";
		missileLockMaxDistance=3000;
		missileLockMinDistance=100;
		missileLockMaxSpeed=41;
		missileLockCone=10;
		weaponLockSystem="2 + 16";
	};
	class M_Titan_AA;
	class BCR_Rockwell_Ammo_AA: M_Titan_AA
	{
		cmImmunity=1;
		hit=800;
		indirectHit=200;
		indirectHitRange=4;
		explosive=1;
		effectsMissile="missile3";
		warheadName="AA";
		missileLockMaxDistance=4000;
		manueuvrability=30;
		sideAirFriction=0.02;
		missileKeepLockedCone=360;
	};

	class BCR_12g_slug: B_12Gauge_Slug
	{
		hit = 69;
		typicalSpeed = 800;
		cost = 8;
	};
};	

class CfgMagazines
{
	class NLAW_F;
	class Titan_AT;
	class Titan_AA;
    class BCR_Rockwell_AT_mag: Titan_AT
	{
		ammo="BCR_Rockwell_Ammo_AT";
		displaynameshort="AT";
		author="AR121";
		scope=2;
		mass=50;
		scopeArsenal=2;
		displayName="[1ST] LGAW AT Rocket";
		descriptionShort="AT Rocket";
		model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at";
		picture="\A3\Weapons_F_beta\Launchers\titan\Data\UI\gear_titan_missile_at_CA.paa";
		count=1;
	};
    class BCR_Rockwell_AA_mag: Titan_AA
	{
		ammo="BCR_Rockwell_Ammo_AA";
		author="AR121";
		displaynameshort="AA";
		scope=2;
		mass=40;
		scopeArsenal=2;
		displayName="[1ST] LGAW AA Rocket";
		descriptionShort="AA Rocket";
		model="\A3\Weapons_F_beta\Launchers\titan\titan_missile_at";
		picture="\A3\Weapons_F_beta\Launchers\titan\Data\UI\gear_titan_missile_atl_CA.paa";
		count=1;
	};

	class 10Rnd_12ga_sl_Mag;
	class 12Rnd_12ga_sl_Mag;
	class 6Rnd_12ga_sl_Mag;
	class BCR_5Rnd_HuntingShotgun_Mag: 6Rnd_12ga_sl_Mag
	{
		ammo="BCR_12g_slug";
		author="SadBear";
		displayName="[1ST] 5Rnd 12ga Hunting Shotgun Mag";
		scope=2;
		count=5;
	};
};

class CfgMagazineWells
{
	class BCR_HuntingShotgun_Well
	{
		magazines[] =
		{
			"BCR_5Rnd_HuntingShotgun_Mag"
		};
	};
	class BCR_MissileTube_Well
	{
		magazines[] = 
		{
			"BCR_MissileLauncher_Mag"
		};
	};
};

class CfgWeapons
{
	class ItemInfo;
	class AM_launch_MissileLauncher;
	class AM_launch_MissileLauncherSight;
	class AM_launch_MissileLauncherSight_Shark;
	class AM_HuntingShotgun;
	class AM_ComShot_Classic;
	class AM_CAWS;
	class PSC_NCR_Trooper_Brown_U;
	class PSC_NCR_Trooper_Brown_H;

	class BCR_HuntingShotgun: AM_HuntingShotgun
	{
		displayName = "[1ST] Hunting Shotgun";
		author = "SadBear";
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		magazines[] = 
		{
			"BCR_5Rnd_HuntingShotgun_Mag"
		};
		magazineWell[]=
		{
			"BCR_HuntingShotgun_Well"
		};
	};

	class launch_Titan_base;
	class launch_Titan_short_base: launch_Titan_base
	{
		class WeaponSlotsInfo;
	};
	class Rockwell_AT: launch_Titan_short_base
	{
		class WeaponSlotsInfo;
	};
	class BCR_Rockwell_Launcher: Rockwell_AT
	{
		picture = "\Sterben_TOP\am_firearms\launchers\missilelauncher\ui\MISSILELAUNCHER_ca.paa";
		author="AR121";
		scope=2;
		scopeArsenal=2;
        canLock=2;
		opticsZoomMin=0.1083;
		opticsZoomMax=0.1083;
		opticsZoomInit=0.1083;
		cameraDir="look";
		cursor="missile";
		ace_overpressure_angle=45;
		ace_overpressure_damage=0.40000001;
		ace_overpresssure_priority=1;
		ace_overpressure_range=10;
		displayName="[1ST] LGAW MK2";
		descriptionShort="Guided Missile Launcher";
        model = "\Sterben_TOP\am_firearms\launchers\missilelauncher\AM_missilelauncher.p3d";
		modelspecial = "\Sterben_TOP\am_firearms\launchers\missilelauncher\AM_missilelauncher_Loaded.p3d";
        handAnim[] = {"OFP2_ManSkeleton","\a3\Weapons_F_Tank\Launchers\MRAWS\Data\Anim\MRAWS.rtm"};
		magazines[]=
		{
			"BCR_Rockwell_AT_mag",
			"BCR_Rockwell_AA_mag"
		};
		magazineWell[]=
		{
			"BCR_MissileTube_Well"
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=220;
		};
	};
	

	class BCR_Trooper_CLUB_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Club)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_CLUB_UN";
		};
	};

	class BCR_Trooper_CLUB_MED_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Club Medic)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_CLUB_MED_UN";
		};
	};

	class BCR_Trooper_DIAMOND_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Diamond)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_DIAMOND_UN";
		};
	};

	class BCR_Trooper_DIAMOND_MED_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Diamond Medic)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_DIAMOND_MED_UN";
		};
	};

	class BCR_Trooper_HEART_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Heart)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_HEART_UN";
		};
	};

	class BCR_Trooper_HEART_MED_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Heart Medic)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_HEART_MED_UN";
		};
	};

	class BCR_Trooper_SPADE_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Spade)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_SPADE_UN";
		};
	};

	class BCR_Trooper_SPADE_MED_U:PSC_NCR_Trooper_Brown_U{
		displayName = "[1ST] NCR Trooper Uniform (Spade Medic)";
		scope = 2;
		class ItemInfo: ItemInfo {
			uniformClass = "BCR_Trooper_SPADE_MED_UN";
		};
	};

	class BCR_Trooper_HELM_H:PSC_NCR_Trooper_Brown_H{
		displayName = "[1ST] NCR Trooper Helmet (Helm)";
		scope = 2;
		hiddenSelectionsTextures[]={
			"BCR_Equipment\data\textures\HELM.paa"
		};
	};

	class BCR_Trooper_HELM_MED_H:PSC_NCR_Trooper_Brown_H{
		displayName = "[1ST] NCR Trooper Helmet (Helm Medic)";
		scope = 2;
		hiddenSelectionsTextures[]={
			"BCR_Equipment\data\textures\HELM_MED.paa"
		};
	};

};

class CfgVehicles
{
	class ItemInfo;
	class prc77_mod;
	class milrad_mod;
	class am_radio_tactical_grn;
	class PSC_NCR_Trooper_Brown_UN;

	//Radio Packs
	class BCR_ANPRC76_B: am_radio_tactical_grn
	{
		author="Queen";
		displayName="[1ST] AN/PRC 76";
		scope=2;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=75000;
		tf_dialog="anarc164_radio_dialog";
		tf_subtype="digital_lr";
		maximumLoad=300;
	};
	class BCR_ANPRC23_B: milrad_mod
	{
		author="Queen";
		displayName="[1ST] AN/PRC 23";
		scope=2;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=75000;
		tf_dialog="anarc164_radio_dialog";
		tf_subtype="digital_lr";
		maximumLoad=300;
	};
	class BCR_ANPRC2141_B: prc77_mod
	{
		author="Queen";
		displayName="[1ST] AN/PRC 2141";
		scope=2;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=75000;
		tf_dialog="anarc164_radio_dialog";
		tf_subtype="digital_lr";
		maximumLoad=300;
	};

	class  BCR_Radio_Backpack_1: BCR_ANPRC2141_B
	{
		scope = 0;
	};

	//Backpacks
	class minigunbackpack;
    class BCR_MinigunBackpack_B: minigunbackpack
    {
        displayName = "[1ST] Minigun Backpack";
        maximumLoad=650;
    };


	class BCR_Trooper_CLUB_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\CLUB.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_CLUB_U";
	};

	class BCR_Trooper_CLUB_MED_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\CLUB_MED.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_CLUB_MED_U";
	};

	class BCR_Trooper_DIAMOND_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\DIAMOND.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_DIAMOND_U";
	};

	class BCR_Trooper_DIAMOND_MED_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\DIAMOND_MED.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_DIAMOND_MED_U";
	};

	class BCR_Trooper_HEART_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\HEART.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_HEART_U";
	};

	class BCR_Trooper_HEART_MED_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\HEART_MED.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_HEART_MED_U";
	};

	class BCR_Trooper_SPADE_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\SPADE.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_SPADE_U";
	};

	class BCR_Trooper_SPADE_MED_UN:PSC_NCR_Trooper_Brown_UN{
		hiddenSelectionsTextures[]={ 
			"BCR_Equipment\data\textures\SPADE_MED.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperBelt_CO.paa",
			"PSC_Equipment\NCR\data\uniforms\brown\NCRTrooperGlovesBoots_CO.paa"
		};
		uniformClass="BCR_Trooper_SPADE_MED_U";
	};

	class ACE_fastropingSupplyCrate;
	class XV_VehResupplyBox: ACE_fastropingSupplyCrate
    {
        displayName = "[1ST] Resupply Box";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = "EdSubcat_Military";
        scope = 2;
        ace_repair_canRepair=1;
        ace_rearm_defaultSupply=1200;
        ace_refuel_fuelCargo=3000;
        maximumLoad = 100000000;
		ace_dragging_ignoreWeight=1;
        ace_dragging_ignoreWeightCarry=1;
        ace_cargo_size = 4;  // Cargo space the object takes
        ace_cargo_canLoad = 1;  // Enables the object to be loaded (1-yes, 0-no)
        ace_cargo_noRename = 0;  // Blocks renaming object (1-blocked, 0-allowed)
        ace_cargo_blockUnloadCarry = 1; // Blocks object from being automatically picked up by player on unload
        class TransportMagazines
		{
			MAG_XX(20Rnd_556x45_Mag,40);

		};
        class TransportItems
        {
            ITEM_XX(ACE_packingBandage,60);
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(ACE_quikclot,60);
            ITEM_XX(ACE_splint,40);
            ITEM_XX(ACE_epinephrine,20);
            ITEM_XX(ACE_morphine,20);
            ITEM_XX(ACE_tourniquet,40);
            ITEM_XX(dev_enzymeCapsule_refined,20);
            ITEM_XX(ACE_salineIV,60);
            ITEM_XX(ACE_salineIV_500,60);
            ITEM_XX(ACE_salineIV_250,60);
            ITEM_XX(ACE_EntrenchingTool,5);
            ITEM_XX(ACE_IR_Strobe_Item,20);
            ITEM_XX(ACE_CableTie,30);
        };
		class TransportWeapons
		{
			
		};
        class ACE_Actions
        {
            class ACE_MainActions
            {
                condition = "true";
                displayName = "Interactions";
                distance = 5;
                selection = "";
                class BCR_healEveryone
                {
                    condition = "alive _target";
                    displayName = "PAK within 5 meters";
                    showDisabled = 0;
                    statement = "[_target,10] call BCR_FNC_radialPAK";
                };
            };
        }; 
    };

};
