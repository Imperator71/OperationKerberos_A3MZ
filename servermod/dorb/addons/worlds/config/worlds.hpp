/*
 * workaround, since the cofig seems to be limited to 4089 subclasses wich can be added in on class
 * inhertition seems to skip this issue
 */

class worlds {
    class altis {
        class locations {
            #include "altis\locations.hpp"
        };
        class waypoints_1 {
            #include "altis\waypoints.hpp"
        };
        class waypoints_2 : waypoints_1 {
            #include "altis\waypoints2.hpp"
        };
        class waypoints : waypoints_2 {
            #include "altis\waypoints3.hpp"
        };
    };
    class takistan {
        class locations {
            #include "takistan\locations.hpp"
        };
        class waypoints {
            #include "takistan\waypoints.hpp"
        };
    };
    class pja310 {
        class locations {
            #include "pja310\locations.hpp"
        };
        class waypoints_1 {
            #include "pja310\waypoints.hpp"
        };
        class waypoints : waypoints_1 {
            #include "pja310\waypoints2.hpp"
        };
    };
};
