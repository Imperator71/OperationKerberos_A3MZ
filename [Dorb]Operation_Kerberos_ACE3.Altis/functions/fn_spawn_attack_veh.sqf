/*
	Author: Dorbedo
	
	Description:
	
	Requirements:
	
	Parameter(s):
		0 : ARRAY	- Example
		1 : ARRAY	- Example
		2 : STRIN	- Example
	
	Return
	BOOL
*/
#include "script_component.hpp"
CHECK(!isServer)

private ["_radius","_position","_anzahl_leicht","_anzahl_schwer","_gruppe","_units","_rand"];
_position = _this select 0;
_suchradius = [_this, 1, 400,[0]] call BIS_fnc_Param;
_anzahl_leicht = [_this, 2, 0,[0]] call BIS_fnc_Param;
_anzahl_schwer = [_this, 3, 0,[0]] call BIS_fnc_Param;
_radius = [_this, 4, 1700,[0]] call BIS_fnc_Param;

d_log(FORMAT_4("VEH ATTACK| Pos=%1 / Radius=%2 / Anzahl Leichte=%3 / Anzahl Schwere = %4 ",_position,_radius,_anzahl_leicht,_anzahl_schwer))

_vehicles=[];
_rand=[];
_einheit="";
for "_i" from 0 to (_anzahl_leicht) do {
	_rad = ((random 500) + 500);
	_pos = [_position, _radius,1] call dorb_fnc_random_pos;
	
	_rand = (floor(random 8));
	if (_rand < 2) then {
		_einheit = dorb_veh_aa call BIS_fnc_selectRandom;
	}else{
		_einheit = dorb_veh_unarmored call BIS_fnc_selectRandom;
	};
	sleep 3;
	_spawnpos = _pos findEmptyPosition [1,100,_einheit];
		
	if (count _spawnpos < 1) then {
		d_error(FORMAT_1("Keine Spawnposition | ",_spawnpos))
	}else{
		d_log(FORMAT_3("Spawnpos=%1 / einheit=%2 / dorb_side=%3",_spawnpos, _einheit, dorb_side))
		_return = [_spawnpos,(random(360)),_einheit,dorb_side] call BIS_fnc_spawnVehicle;
		_vehicles pushBack (_return select 0);
		[(_return select 2), _position, _suchradius] call CBA_fnc_taskAttack;
		[(_return select 2)] FCALL(moveToHC);
	};
};

for "_i" from 0 to (_anzahl_leicht) do {
	_rad = ((random 500) + 500);
	_pos = [_position, _radius,1] call dorb_fnc_random_pos;
	
	_rand = (floor(random 8));
	if (_rand<2) then {
		_einheit = dorb_veh_aa select floor random count dorb_veh_aa;
	}else{
		_einheit = dorb_veh_armored select floor random count dorb_veh_armored;
	};
	_spawnpos = _pos findEmptyPosition [1,100,_einheit];
	if (count _spawnpos < 1) then {
		d_error(FORMAT_1("Keine Spawnposition | ",_spawnpos))
	}else{
		d_log(FORMAT_3("Spawnpos=%1 / einheit=%2 / dorb_side=%3",_spawnpos, _einheit, dorb_side))
		_return = [_spawnpos,(random(360)),_einheit,dorb_side] call BIS_fnc_spawnVehicle;
		_vehicles pushBack (_return select 0);
		[(_return select 2), _position, _suchradius] call CBA_fnc_taskAttack;
		[(_return select 2)] FCALL(moveToHC);
	};
};

d_log(FORMAT_1("Spawned Vehicles| ",_vehicles))


if (dorb_debug) then {
	{
		_mrkr = createMarker [format["veh-%1",_x],getPos _x];
		_mrkr setMarkerShape "ICON";
		_mrkr setMarkerColor "ColorRed";
		_mrkr setMarkerType "o_mech_inf";
		
	}forEach _vehicles;
};