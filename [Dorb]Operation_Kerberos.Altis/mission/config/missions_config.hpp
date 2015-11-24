#define CBA_OFF
#include "script_component.hpp"
class missions_config {
	class side_base {
		class task {
			name = "";
			description = "";
			tasktype = "";
			taskmarker = "";
		};
		class location {
			areas[] = {QGVAR(town),QGVAR(industrie),QGVAR(military),QGVAR(other)};
			distance = 500;
			areas_minDistance = 500;
			areas_maxDistance = 2500;
		};
		delay_spawn = 600;
		delay_reveal = 300;
		probability = 1;
	};
	class main_base {
		class task {
			name = "";
			description = "";
			tasktype = "";
			taskmarker = "";
		};
		class location {
			areas[] = {QGVAR(town),QGVAR(industrie),QGVAR(military),QGVAR(other)};
			distance = 1500;
		};
		probability = 1;
		armys[] = {{"regular",1},{"armored",1},{"infanterie",1},{"airborne",1},{"specops",1},{"droneoperations",1},{"guards",1}};
	};
	class side_arty : side_base {
		type = "artillery";
		class location : location {
			areas[] = {QGVAR(industrie),QGVAR(military),QGVAR(other)};
			distance = 500;
			areas_minDistance = 3000;
			areas_maxDistance = 25000;
		};
		delay_spawn = 0;
		delay_reveal = 1800; // delay until the mission is revealed
	};
	class side_ugv : side_base {
		type = "ugv";
		class location : location {
			areas[] = {QGVAR(water),QGVAR(military),QGVAR(other)};
			distance = 500;
		};
	};
	class side_convoi : side_base {
		type = "convoi";
		class location : location {
			areas[] = {QGVAR(water),QGVAR(military),QGVAR(other)};
			distance = 200;
		};
		delay_spawn = 600;
		delay_reveal = 60;
	};
	class side_radar : side_base {
		type = "radar";
		class location {
			areas[] = {}; /// empty array leads to position of Main Target
			distance = 600;
		};
		delay_spawn = 1;
		delay_reveal = 1;
		probability = 1;
	};
	class main {
		class scarab : main_base {
			class task {
				name = CSTRING(scarab_task);
				description = CSTRING(scarab_desc);
			};
			class sidemissions : side_base {
				class artillery : side_arty {};
				class ugv : side_ugv{};
				class convoi1 : side_convoi {};
				class convoi2 : side_convoi {delay_spawn = 1200;};
			};
		};
		class tower : main_base {
			class task {
				name = CSTRING(tower_task);
				description = CSTRING(tower_desc);
			};
			class location : location {
				distance = 1500;
			};
		};
		class device : main_base {
			class task {
				name = CSTRING(device_task);
				description = CSTRING(device_desc);
			};
			class location : location {
				areas[] = {QGVAR(industrie),QGVAR(military),QGVAR(other)};
			};
		};
		class emp : main_base {
			class task {
				name = CSTRING(emp_task);
				description = CSTRING(emp_desc);
			};
			class location : location {
				areas[] = {QGVAR(industrie),QGVAR(military),QGVAR(other)};
			};
		};
		class prototype : main_base {
			class task {
				name = CSTRING(prototype_task);
				description = CSTRING(prototype_desc);
			};
		};
		class clear : main_base {
			class task {
				name = CSTRING(clear_task);
				description = CSTRING(clear_desc);
			};
			class location : location {
				areas[] = {QGVAR(industrie),QGVAR(military),QGVAR(other)};
			};
		};
		
		class hostage : main_base {
			class task {
				name = CSTRING(hostage_task);
				description = CSTRING(hostage_desc);
			};
			class location : location {
				areas[] = {QGVAR(town)};
			};
		};
		class kill : main_base {
			class task {
				name = CSTRING(kill_task);
				description = CSTRING(kill_desc);
			};
			class location : location {
				areas[] = {QGVAR(town)};
			};
		};
		class intel : main_base {
			class task {
				name = CSTRING(intel_task);
				description = CSTRING(intel_desc);
			};
			class location : location {
				areas[] = {QGVAR(town)};
			};
		};
		class weaponcaches : main_base {
			class task {
				name = CSTRING(weaponcaches_task);
				description = CSTRING(weaponcaches_desc);
			};
			class location : location {
				areas[] = {QGVAR(town)};
			};
		};
		class dronecommando : main_base {
			class task {
				name = CSTRING(dronecommando_task);
				description = CSTRING(dronecommando_desc);
			};
			armys[] = {{"specops",1},{"droneoperations",1},{"guards",1}};
		};
		class specops : main_base {
			class task {
				name = CSTRING(specops_task);
				description = CSTRING(specops_desc);
			};
			armys[] = {{"specops",1}};
		};
		class outpost : main_base {
			class task {
				name = CSTRING(outpost_task);
				description = CSTRING(outpost_desc);
			};
			class location : location {
				areas[] = {QGVAR(military)};
			};
		};
		class radarsetup : main_base {
			class task {
				name = CSTRING(radarsetup_task);
				description = CSTRING(radarsetup_desc);
			};
			class location : location {
				areas[] = {QGVAR(industrie),QGVAR(military),QGVAR(other)};
			};
		};
	};
};