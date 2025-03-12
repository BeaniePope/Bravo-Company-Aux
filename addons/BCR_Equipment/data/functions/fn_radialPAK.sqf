// For the record, I stole this from KND, thanks Jenna <3 ~ Queen

params ["_object","_duration"];


[_duration, [_object], 
{
	_this select 0 params ["_object"];
	private _squad = _object nearObjects ["CAManBase",25];
	{
		[ace_player,_x] call ace_medical_treatment_fnc_fullHeal;
	} foreach _squad;
}, {}, "Use Medical Cabinet"] call ace_common_fnc_progressBar