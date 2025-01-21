class CfgPatches
{
	class BCR_Equipment
	{
		author="Queen"; 
        requiredAddons[]=
        {
            "fallout_uniform_02",
			"am_firearms"
        };
        requiredVersion= 0.1;
        units[]=
		{
			"BCR_MinigunBackpack_B",
			"BCR_ANPRC76_B",
			"BCR_ANPRC23_B",
			"BCR_ANPRC2141_B"
		};
        weapons[]= 
        {
			"BCR_MissileLauncher",
			"BCR_MissileLauncherSight",
			"BCR_MissileLauncherSight_Shark"
        };
	};
};

class CfgAmmo
{
	class M_NLAW_AT_F;
	class BCR_Missile_AT: M_NLAW_AT_F
	{
		hit = 50;
		indirectHit = 25;
		indirectHitRange = 2.4;
		proximityExplosionDistance = 5;
		explosive = 0.5;
		maneuvrability = 2;
		simulationStep = 0.002;
		trackOversteer = 0.8;
		trackLead = 1;
		irLock = 1;
		aiAmmoUsageFlags = "128 + 512";
		maxControlRange = 11;
		model = "\A3\weapons_f\launchers\nlaw\nlaw_rocket";
		cost = 400;
		timeToLive = 8;
		airFriction = 0.09;
		sideAirFriction = 0.5;
		maxSpeed = 180;
		initTime = 0.2;
		thrustTime = 0.8;
		thrust = 200;
		fuseDistance = 20;
		effectsMissile = "missile3";
		whistleDist = 16;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		effectsMissileInit = "";
		allowAgainstInfantry = 0;
		soundHit[] = {"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\NLAW_Hit",1.7782794,1,1500};
		soundFly[] = {"A3\Sounds_F\arsenal\weapons\Launchers\NLAW\Fly_NLAW",0.56234133,1.5,700};
		class CamShakeExplode
		{
			power = 11;
			duration = 1.4;
			frequency = 20;
			distance = 91.3296;
		};
		class CamShakeHit
		{
			power = 110;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 2.51487;
			duration = 1.2;
			frequency = 20;
			distance = 50.5964;
		};
		class CamShakePlayerFire
		{
			power = 2;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
		submunitionAmmo = "ammo_Penetrator_NLAW";
		submunitionDirectionType = "SubmunitionTargetDirection";
		submunitionInitSpeed = 1000;
		submunitionParentSpeedCoef = 0.0;
		submunitionInitialOffset[] = {0,0,-0.5};
		triggerOnImpact = 1;
		triggerDistance = 2.5;
		deleteParentWhenTriggered = 0;
		flightProfiles[] = {"Direct","Overfly"};
		class Direct{};
		class Overfly: Direct
		{
			overflyElevation = 2.5;
		};
		airLock = 1;
		missileLockCone = 5;
		missileKeepLockedCone = 300;
		missileLockMaxDistance = 800;
		missileLockMinDistance = 20;
		missileLockMaxSpeed = 35;
		weaponLockSystem = "1 + 16";
		cmImmunity = 0.2;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 800;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 800;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						maxTrackableSpeed = 35;
						nightRangeCoef = 0.8;
						angleRangeHorizontal = 5;
						angleRangeVertical = 5;
						maxTrackableATL = 20;
					};
				};
			};
		};
	};
};	

class CfgMagazines
{
	class NLAW_F;
	class BCR_MissileLauncher_Mag: NLAW_F
	{
		displayName = "[1ST] Missile MK2";
		ammo = "BCR_Missile_AT";
	};
};

class CfgMagazineWells
{
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
	class AM_launch_MissileLauncher;
	class AM_launch_MissileLauncherSight;
	class AM_launch_MissileLauncherSight_Shark;

	class BCR_MissileLauncher: AM_launch_MissileLauncher
	{
		displayName = "[1ST] LGAW MK2"
		ace_reloadlaunchers_enabled = 1;
		magazines[]=
		{
			"BCR_MissileLauncher_Mag"
		};
		magazineWell[]=
		{
			"BCR_MissileTube_Well"
		};
		descriptionShort = "NCR's newest Last Generation AT weapon.";
	};

	class BCR_MissileLauncherSight: AM_launch_MissileLauncherSight
	{
		displayName = "[1ST] LGAW MK2 (Guided)"
		ace_reloadlaunchers_enabled = 1;
		magazines[]=
		{
			"BCR_MissileLauncher_Mag"
		};
		magazineWell[]=
		{
			"BCR_MissileTube_Well"
		};
		descriptionShort = "NCR's newest Last Generation AT weapon.";
	};
	class BCR_MissileLauncherSight_Shark: AM_launch_MissileLauncherSight_Shark
	{
		displayName = "[1ST] LGAW MK2 (Guided/Painted)"
		ace_reloadlaunchers_enabled = 1;
		magazines[]=
		{
			"BCR_MissileLauncher_Mag"
		};
		magazineWell[]=
		{
			"BCR_MissileTube_Well"
		};
		descriptionShort = "NCR's newest Last Generation AT weapon.";
	};

};
class CfgVehicles
{
	class prc77_mod;
	class milrad_mod;
	class am_radio_tactical_grn;

	//Radio Packs
	class BCR_Radio_Backpack_B: am_radio_tactical_grn
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
	class BCR_Radio_Backpack_B: milrad_mod
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
	class BCR__Radio_Backpack_B: prc77_mod
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

	//Backpacks
	class minigunbackpack;
    class BCR_MinigunBackpack_B: minigunbackpack
    {
        displayName = "[1ST] Minigun Backpack";
        maximumLoad=650;
    };
};
